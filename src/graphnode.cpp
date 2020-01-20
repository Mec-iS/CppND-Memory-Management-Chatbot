#include <memory>
#include <iostream>

#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
  std::cout << "GraphNode destructor" << std::endl;
    //// STUDENT CODE
    ////

    // _chatBot = nullptr;

    ////
    //// EOF STUDENT CODE
}

// GraphNode::GraphNode(const GraphNode& other) // copy constructor
// {
//   std::cout << "GraphNode copy constructor" << std::endl;
//
//   throw 10;
// }
//
// GraphNode::GraphNode(GraphNode&& other) noexcept // move constructor
// {
//   std::cout << "GraphNode move constructor" << std::endl;
//
//   _childEdges = std::move(other._childEdges);
//   _parentEdges = std::move(other._parentEdges);
//   _chatBot = std::move(other._chatBot);
//   _id = std::move(other._id);
//   _answers = std::move(other._answers);
// }
//
// GraphNode& GraphNode::operator=(const GraphNode& other) // copy assignment
// {
//   std::cout << "GraphNode copy assignment" << std::endl;
//
//   return *this = GraphNode(other);
// }
//
// GraphNode& GraphNode::operator=(GraphNode&& other) noexcept // move assignment
// {
//   std::cout << "GraphNode move assignment" << std::endl;
//
//   std::swap(_childEdges, other._childEdges);
//   std::swap(_parentEdges, other._parentEdges);
//   std::swap(_chatBot, other._chatBot);
//   std::swap(_id, other._id);
//   std::swap(_answers, other._answers);
//   return *this;
// }

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
    newNode->MoveChatbotHere(std::move(_chatBot));
    // _chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return (_childEdges[index]).get();

    ////
    //// EOF STUDENT CODE
}
