//    This file is part of Examples repository by Paweł Dybowski.
//
//    Copyright (C) 2020 Paweł Dybowski <dybowski015 at gmail dot com>
//    https://github.com/dybowski-pawel/coding-examples
//
//    Examples is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    Examples is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with Examples.  If not, see <https://www.gnu.org/licenses/>.

//
// Created by pawel on 02.09.20.
//

#include "Thread.h"

Thread::Thread(int numberOfLoops, bool startImmediately, unsigned long timeoutInMilliseconds)
        : loop_count_(numberOfLoops)
        , timeout_(timeoutInMilliseconds) {
    if(startImmediately) {
        Start();
    }
}

bool Thread::Start() {
    if (IsStarted()) {
        if(IsDone()) {
            StopAndWait();
        } else {
            return false;
        }
    }
    std::unique_lock<std::mutex> lock(mutex_);
    thread_ = new std::thread(&Thread::operator(), this);
    started_ = true;
    return true;
}

bool Thread::WaitUntilReady() {
    if(!IsStarted()) {
        return false;
    }
    while(!IsReady()) {
        Sleep();
    }
    return true;
}

bool Thread::Stop() {
    if(!IsStarted()) {
        return false;
    } else {
        std::unique_lock<std::mutex> lock(mutex_);
        return (stopRequested_ = true);
    }
}

bool Thread::StopAndWait() {
    if(!Stop()) {
        return false;
    } else {
        WaitUntilDone();
        CleanUp();
        return true;
    }
}

bool Thread::WaitUntilDone() {
    if(!IsStarted() || !IsStopRequested()) {
        return false;
    } else {
        while(!IsDone()) {
            Sleep();
        }
    }
}


void Thread::CleanUp() {
    std::unique_lock<std::mutex> lock(mutex_);
    thread_->join();
    delete thread_;
    started_ = false;
    stopRequested_ = false;
    pauseRequested_ = false;
    resumeRequested_ = false;
    ready_ = false;
    paused_ = false;
    done_ = false;
}

bool Thread::Pause() {
    std::unique_lock<std::mutex> lock(mutex_);
    return pauseRequested_ ? false : (pauseRequested_ = true);
}

bool Thread::PauseAndWait() {
    if(!Pause()) {
        return false;
    } else {
        while(!IsPaused()) {
            Sleep();
        }
        return true;
    }
}

bool Thread::Resume() {
    std::unique_lock<std::mutex> lock(mutex_);
    return resumeRequested_ ? false : (resumeRequested_ = true);
}

bool Thread::ResumeAndWait() {
    if(!Resume()) {
        return false;
    } else {
        while(IsPaused()) {
            Sleep();
        }
        return true;
    }
}

bool Thread::IsStarted() {
    std::unique_lock<std::mutex> lock(mutex_);
    return started_;
}

bool Thread::IsReady() {
    std::unique_lock<std::mutex> lock(mutex_);
    return ready_;
}

bool Thread::IsPaused() {
    std::unique_lock<std::mutex> lock(mutex_);
    return paused_;
}

bool Thread::IsPauseRequested() {
    std::unique_lock<std::mutex> lock(mutex_);
    return pauseRequested_;
}

bool Thread::IsResumeRequested() {
    std::unique_lock<std::mutex> lock(mutex_);
    return resumeRequested_;
}

bool Thread::IsStopRequested() {
    std::unique_lock<std::mutex> lock(mutex_);
    return stopRequested_;
}

bool Thread::IsDone() {
    std::unique_lock<std::mutex> lock(mutex_);
    return done_;
}

void Thread::SetReady() {
    std::unique_lock<std::mutex> lock(mutex_);
    ready_ = true;
}

void Thread::SetDone() {
    std::unique_lock<std::mutex> lock(mutex_);
    done_ = true;
}

void Thread::operator()() {
    Init();
    SetReady();
    unsigned int loops_done = 0;
    while(!IsStopRequested() && (loop_count_ == -1 || loops_done < loop_count_)) {
        if(IsPaused()) {
            if(IsResumeRequested()) {
                std::unique_lock<std::mutex> lock(mutex_);
                paused_ = false;
                resumeRequested_ = false;
            }
        } else {
            if(IsPauseRequested()) {
                std::unique_lock<std::mutex> lock(mutex_);
                paused_ = true;
                pauseRequested_ = false;
            } else {
                Loop();
                loops_done++;
            }
        }
        Sleep(timeout_);
    }
    DeInit();
    SetDone();
}

void Thread::Sleep(const unsigned long & timeoutInMilliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(timeoutInMilliseconds));
};