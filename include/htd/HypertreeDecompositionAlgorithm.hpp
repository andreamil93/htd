/* 
 * File:   HypertreeDecompositionAlgorithm.hpp
 *
 * Author: ABSEHER Michael (abseher@dbai.tuwien.ac.at)
 * 
 * Copyright 2015, Michael Abseher
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

#ifndef HTD_HTD_HYPERTREEDECOMPOSITIONALGORITHM_HPP
#define	HTD_HTD_HYPERTREEDECOMPOSITIONALGORITHM_HPP

#include <htd/Globals.hpp>
#include <htd/IHypergraph.hpp>
#include <htd/IHypertreeDecomposition.hpp>
#include <htd/ITreeDecompositionAlgorithm.hpp>
#include <htd/IHypertreeDecompositionAlgorithm.hpp>
#include <htd/ISetCoverAlgorithm.hpp>

#include <cstdarg>
#include <vector>

namespace htd
{
    class HypertreeDecompositionAlgorithm : public virtual htd::IHypertreeDecompositionAlgorithm
    {
        public:
            HypertreeDecompositionAlgorithm(const htd::ITreeDecompositionAlgorithm & treeDecompositionAlgorithm);

            HypertreeDecompositionAlgorithm(const htd::ITreeDecompositionAlgorithm & treeDecompositionAlgorithm, const std::vector<htd::ILabelingFunction *> & labelingFunctions);

            ~HypertreeDecompositionAlgorithm();
            
            htd::IHypertreeDecomposition * computeDecomposition(const htd::IHypergraph & graph) const HTD_OVERRIDE;

            htd::IHypertreeDecomposition * computeDecomposition(const htd::IHypergraph & graph, const std::vector<htd::ILabelingFunction *> & labelingFunctions) const HTD_OVERRIDE;

            htd::IHypertreeDecomposition * computeDecomposition(const htd::IHypergraph & graph, int labelingFunctionCount, ...) const; //TODO HTD_OVERRIDE;

        protected:
            HypertreeDecompositionAlgorithm & operator=(const HypertreeDecompositionAlgorithm &) { return *this; }

        private:
            const htd::ITreeDecompositionAlgorithm & treeDecompositionAlgorithm_;
    };
}

#endif /* HTD_HTD_HYPERTREEDECOMPOSITIONALGORITHM_HPP */