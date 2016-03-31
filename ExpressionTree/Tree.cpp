/*
 * Tree.cpp
 *
 *  Created on: Mar 30, 2016
 *      Author: j23210
 */

#include "Tree.h"

namespace expressions
{

Tree::Tree(Node_ptr node) :
         mNode(std::move(node))
{
}

double Tree::evaluate() const
{
   return mNode->evaluate();
}

void Tree::print(std::ostream& out) const
{
   out << *mNode;
}

} /* namespace expressions */
