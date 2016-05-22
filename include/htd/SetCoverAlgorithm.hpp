/* 
 * File:   SetCoverAlgorithm.hpp
 *
 * Author: ABSEHER Michael (abseher@dbai.tuwien.ac.at)
 * 
 * Copyright 2015-2016, Michael Abseher
 *    E-Mail: <abseher@dbai.tuwien.ac.at>
 * 
 * This file is part of htd.
 * 
 * htd is free software: you can redistribute it and/or modify it under 
 * the terms of the GNU General Public License as published by the Free 
 * Software Foundation, either version 3 of the License, or (at your 
 * option) any later version.
 * 
 * htd is distributed in the hope that it will be useful, but WITHOUT 
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public 
 * License for more details.

 * You should have received a copy of the GNU General Public License
 * along with htd.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef HTD_HTD_SETCOVERALGORITHM_HPP
#define	HTD_HTD_SETCOVERALGORITHM_HPP

#include <htd/Globals.hpp>
#include <htd/ISetCoverAlgorithm.hpp>

#include <vector>

namespace htd
{
    class SetCoverAlgorithm : public virtual htd::ISetCoverAlgorithm
    {
        public:
            SetCoverAlgorithm(void);
            
            ~SetCoverAlgorithm();
            
            void computeSetCover(const std::vector<htd::id_t> & elements, const std::vector<std::vector<htd::id_t>> & containers, std::vector<htd::index_t> & target) const HTD_OVERRIDE;

            void computeSetCover(const htd::ConstCollection<htd::id_t> & elements, const htd::ConstCollection<std::vector<htd::id_t>> & containers, std::vector<htd::index_t> & target) const HTD_OVERRIDE;

            SetCoverAlgorithm * clone(void) const HTD_OVERRIDE;

        protected:
            /**
             *  Copy assignment operator for a set cover algorithm.
             *
             *  @note This operator is protected to prevent assignments to an already initialized algorithm.
             */
            SetCoverAlgorithm & operator=(const SetCoverAlgorithm &) { return *this; }

        private:

            struct HistoryEntry
            {
                htd::index_t selectedIndex;

                std::vector<htd::id_t> remainder;

                std::vector<htd::id_t> containers;

                HistoryEntry(htd::index_t selectedIndex, const std::vector<htd::id_t> & remainder, const std::vector<htd::id_t> & containers) : selectedIndex(selectedIndex), remainder(remainder), containers(containers)
                {

                }
            };

            class Compare
            {
                public:
                    bool operator() (const std::vector<htd::index_t> & solution1, const std::vector<htd::index_t> & solution2)
                    {
                        return solution1.size() < solution2.size();
                    }
            };
    };
}

#endif /* HTD_HTD_SETCOVERALGORITHM_HPP */
