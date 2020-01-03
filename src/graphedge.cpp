#include "graphnode.h"
#include "graphedge.h"

GraphEdge::GraphEdge(int id)
{
    _id = id;
}

GraphEdge::~GraphEdge() {
  
}

GraphEdge::GraphEdge(const GraphEdge& other) // copy constructor
{
  _childNode = other._childNode;
  _parentNode = other._parentNode;
  _id = other._id;
  _keywords = other._keywords;
}

GraphEdge::GraphEdge(GraphEdge&& other) noexcept // move constructor
{
  _childNode = std::move(other._childNode);
  _parentNode = std::move(other._parentNode);
  _id = std::move(other._id);
  _keywords = std::move(other._keywords);
}

GraphEdge& GraphEdge::operator=(const GraphEdge& other) // copy assignment
{
    return *this = GraphEdge(other);
}

GraphEdge& GraphEdge::operator=(GraphEdge&& other) noexcept // move assignment
{
  std::swap(_childNode, other._childNode);
  std::swap(_parentNode, other._parentNode);
  std::swap(_id, other._id);
  std::swap(_keywords, other._keywords);
  return *this;
}

void GraphEdge::SetChildNode(GraphNode *childNode)
{
    _childNode = childNode;
}

void GraphEdge::SetParentNode(GraphNode *parentNode)
{
    _parentNode = parentNode;
}

void GraphEdge::AddToken(std::string token)
{
    _keywords.push_back(token);
}
