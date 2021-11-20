# 1. Introduction 
This is supposed to be an automated intelligent auto-clicker for minigames in the Legends of Idleon MMO game.
Of course, it will never be perfect, but I am making it mostly for myself to get easy and good score in minigames without having to pay much attention.
Those minigames give more resources when the score is higher, so it's worth to get it to some nice score.

# 2. General idea
The general plan is to take a screenshot, determine if a minigame is in play, and try to milk it.

# 3. Why C++ and not python?
For a few reasons:
- I like C++
     I am used to it, most of my work is around C++ and it really has a lot of power hidden in the smallest things.
- I don't like python
     My start in programming was a java. 
     Then I started working in C++. 
     When I saw the rules governing the python.. Let's say I'll avoid it when I can.
- C++ is faster (in general)
     I am not fully sure if taking a screenshot is fast in C++, and I know that underneath python uses a lot of C++ and in general python is not that bad, but all in all, C++ is indeed faster.


# 4. Roadmap
1. [ ] Proof of concept (for just one minigame)
     This is going to be a dirty, ugly code, which only purpose is to test is this whole thing is possible.
2. [ ] Nice and clean code 
     If PoC works, that means it's worth to invest some time in making it nicer and cleaner.
3. [ ] Optimizations
     Since PoC is dirty code to just see if it works, and clean code is the same code, just polished, there most probably will be a lot of improvement places.
4. [ ] More minigames
     The fist minigame I want to start with is chopping, since this one should be the easiest to automate. Next will be mining, fishing, then catching. Those are all minigames I know of right now.\
5. [ ] Linux support
     If all is done, I might as well make it linux compatible.