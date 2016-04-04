/*
 * Tree.h
 *
 *  Created on: Mar 30, 2016
 *      Author: j23210
 */

#ifndef TREE_H_
#define TREE_H_

#include "Constant.h"
#include "Expression.h"
#include "Node.h"
#include "Variable.h"

namespace expressions
{

/// Represents an expression tree containing a root node and possibly a number of interior
/// nodes and leaves.
class Tree: public Node
{
public:
   /// Constructs the top of the tree based on a single root node, transferring ownership.
   Tree(Node_ptr node);

   /// Copy assignment and constructor
   Tree(const Tree& other);
   Tree& operator=(const Tree& other) = default;

   /// Move assignment and constructor
   Tree(Tree&&) = default;
   Tree& operator=(Tree&&) = default;

   /// @copydoc Node::clone
   Node_ptr clone() const;

   /// @copydoc Node::evaluate
   double evaluate() const;

   /// @copydoc Node::print
   void print(std::ostream& out) const;

private:
   /// Pointer to the root node.
   Node_ptr mNode;
};

} /* namespace expressions */

#endif /* TREE_H_ */
