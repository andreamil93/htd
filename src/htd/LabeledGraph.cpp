/* 
 * File:   LabeledGraph.cpp
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

#ifndef HTD_HTD_LABELEDGRAPH_CPP
#define	HTD_HTD_LABELEDGRAPH_CPP

#include <htd/LabeledGraph.hpp>
#include <htd/ILabelingCollection.hpp>
#include <htd/LabelingCollection.hpp>
#include <htd/GraphLabeling.hpp>

htd::LabeledGraph::LabeledGraph(void) : htd::Graph::Graph(), labelings_(new htd::LabelingCollection())
{

}

htd::LabeledGraph::LabeledGraph(const htd::LabeledGraph & original) : htd::Graph::Graph(original), labelings_(original.labelings_->clone())
{

}

htd::LabeledGraph::LabeledGraph(const htd::ILabeledGraph & original) : htd::Graph::Graph(original), labelings_(original.labelings().clone())
{

}

htd::LabeledGraph::~LabeledGraph()
{
    if (labelings_ != nullptr)
    {
        delete labelings_;

        labelings_ = nullptr;
    }
}

void htd::LabeledGraph::removeVertex(htd::vertex_t vertex)
{
    htd::LabeledGraph::removeVertex(vertex);

    labelings_->removeVertexLabels(vertex);
}

void htd::LabeledGraph::removeEdge(htd::id_t edgeId)
{
    htd::LabeledGraph::removeEdge(edgeId);

    labelings_->removeEdgeLabels(edgeId);
}

const htd::ILabelingCollection & htd::LabeledGraph::labelings(void) const
{
    return *labelings_;
}

std::size_t htd::LabeledGraph::labelCount(void) const
{
    return labelings_->labelCount();
}

htd::ConstCollection<std::string> htd::LabeledGraph::labelNames(void) const
{
    return labelings_->labelNames();
}

const std::string & htd::LabeledGraph::labelName(htd::index_t index) const
{
    return labelings_->labelName(index);
}

bool htd::LabeledGraph::isLabeledVertex(const std::string & labelName, htd::vertex_t vertex) const
{
    return labelings_->isLabelingName(labelName) && labelings_->labeling(labelName).isLabeledVertex(vertex);
}

bool htd::LabeledGraph::isLabeledEdge(const std::string & labelName, htd::id_t edgeId) const
{
    return labelings_->isLabelingName(labelName) && labelings_->labeling(labelName).isLabeledEdge(edgeId);
}

const htd::ILabel & htd::LabeledGraph::vertexLabel(const std::string & labelName, htd::vertex_t vertex) const
{
    return labelings_->labeling(labelName).vertexLabel(vertex);
}

const htd::ILabel & htd::LabeledGraph::edgeLabel(const std::string & labelName, htd::id_t edgeId) const
{
    return labelings_->labeling(labelName).edgeLabel(edgeId);
}

void htd::LabeledGraph::setVertexLabel(const std::string & labelName, htd::vertex_t vertex, htd::ILabel * label)
{
    if (!labelings_->isLabelingName(labelName))
    {
        labelings_->setLabeling(labelName, new htd::GraphLabeling());
    }

    labelings_->labeling(labelName).setVertexLabel(vertex, label);
}

void htd::LabeledGraph::setEdgeLabel(const std::string & labelName, htd::id_t edgeId, htd::ILabel * label)
{
    if (!labelings_->isLabelingName(labelName))
    {
        labelings_->setLabeling(labelName, new htd::GraphLabeling());
    }

    labelings_->labeling(labelName).setEdgeLabel(edgeId, label);
}

void htd::LabeledGraph::removeVertexLabel(const std::string & labelName, htd::vertex_t vertex)
{
    if (labelings_->isLabelingName(labelName))
    {
        labelings_->labeling(labelName).removeVertexLabel(vertex);
    }
}

void htd::LabeledGraph::removeEdgeLabel(const std::string & labelName, htd::id_t edgeId)
{
    if (labelings_->isLabelingName(labelName))
    {
        labelings_->labeling(labelName).removeEdgeLabel(edgeId);
    }
}

void htd::LabeledGraph::swapVertexLabels(htd::vertex_t vertex1, htd::vertex_t vertex2)
{
    labelings_->swapVertexLabels(vertex1, vertex2);
}

void htd::LabeledGraph::swapEdgeLabels(htd::id_t edgeId1, htd::id_t edgeId2)
{
    labelings_->swapEdgeLabels(edgeId1, edgeId2);
}

void htd::LabeledGraph::swapVertexLabel(const std::string & labelName, htd::vertex_t vertex1, htd::vertex_t vertex2)
{
    if (!labelings_->isLabelingName(labelName))
    {
        throw std::logic_error("void htd::LabeledGraph::swapVertexLabel(const std::string &, htd::vertex_t, htd::vertex_t)");
    }

    labelings_->labeling(labelName).swapVertexLabels(vertex1, vertex2);
}

void htd::LabeledGraph::swapEdgeLabel(const std::string & labelName, htd::id_t edgeId1, htd::id_t edgeId2)
{
    if (!labelings_->isLabelingName(labelName))
    {
        throw std::logic_error("void htd::LabeledGraph::swapEdgeLabel(const std::string &, htd::id_t, htd::id_t)");
    }

    labelings_->labeling(labelName).swapEdgeLabels(edgeId1, edgeId2);
}

htd::LabeledGraph * htd::LabeledGraph::clone(void) const
{
    return new htd::LabeledGraph(*this);
}

#endif /* HTD_HTD_LABELEDGRAPH_CPP */
