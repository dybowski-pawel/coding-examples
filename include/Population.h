//    This file is part of Examples repository by Pawe³ Dybowski.
//
//    Copyright (C) 2020 Pawe³ Dybowski <dybowski015 at gmail dot com>
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

#ifndef EXAMPLES_GENETICLEARNING_H
#define EXAMPLES_GENETICLEARNING_H

#include <vector>

namespace dbs {

    /*******************************************************************************
     *
     ******************************************************************************/

    template<typename PopulationMember, typename ScoringFunction>
    class Population {
    public:

        /*******************************************************************************
         *
         ******************************************************************************/
        Population(unsigned int size, ScoringFunction scoringFunction) : scoringFunction_(scoringFunction), size_(size) {
            static_assert(size > 0, "Size of the population has to be positive");
            members.reserve(size_);
            scoringFunction_.newChallenge();
            for (unsigned int = 0; i < size_; i++) {
                members.emplace_back(PopulationMember());
            }
        }

        /*******************************************************************************
         *
         ******************************************************************************/
        Population(Population previousPopulation) : scoringFunction_(previousPopulation.GetScoringFunction()), size_(previousPopulation.GetSize()) {
            members_.reserve(size_);
            scoringFunction_.newChallenge();
            auto bestMember = previousPopulation.GetBestMember();
            for (unsigned int i = 0; i < size; i++) {
                members_.emplace_back(bestMember.TryToMutate());
            }
        }

        /*******************************************************************************
         *
         ******************************************************************************/
        unsigned int ScoreMembers() {
            for (auto member : members_) {
                scoringFunction_.score(member);
            }
            Sort();
        }

        /*******************************************************************************
         *
         ******************************************************************************/
        PopulationMember GetBestMember() {
            Sort();
            return *members_.begin();
        }

        /*******************************************************************************
         *
         ******************************************************************************/
        bool IsGoodEnough() {
            //
        }

        /*******************************************************************************
         *
         ******************************************************************************/
        unsigned int GetSize() {
            return size_;
        }

        ScoringFunction GetScoringFunction() {
            return scoringFunction_;
        }

    private:

        /*******************************************************************************
         *
         ******************************************************************************/
        void Sort() {
            if (!sorted_) {
                std::sort(members_.begin(), members_.end());
                sorted_ = true;
            }
        }

        const scoringFunction scoringFunction_;
        const unsigned int size_;
        bool sorted_;
        std::vector<PopulationMember> members_;

    }

#endif //EXAMPLES_GENETICLEARNING_H