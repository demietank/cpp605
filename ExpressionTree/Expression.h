/*
 * Expression.h
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include "Node.h"

namespace expressions
{

/// Represents an expression node of an expression tree. This is the base class for a node
/// that holds two leaves. The expression's value is determined by the leaves' values and the
/// derived expression's operator.
class Expression: public Node
{
public:
   /// Constructs a base expression consisting of two nodes, transferring ownership.
   Expression(Node_ptr left, Node_ptr right);

   /// Move assignment and constructor
   Expression(Expression&&) = default;
   Expression& operator=(Expression&&) = default;

   /// Cleans up the Expression - necessary for derived classes.
   virtual ~Expression() {};

protected:
   /// Pointer to the left node
   Node_ptr mLeft;

   /// Pointer to the right node
   Node_ptr mRight;
};

/// Class that represents an addition expression.
class Add: public Expression
{
public:
   /// Constructs an addition expression consisting of two nodes, transferring ownership.
   Add(Node_ptr left, Node_ptr right);

   /// Move assignment and constructor
   Add(Add&&) = default;
   Add& operator=(Add&&) = default;

   /// @copydoc Node::derivative
   /// d = left node; du = derivative of left node; v = right node; dv = derivative of right node.
   /// du + dv
   Node_ptr derivative(const std::string& dVarName) const;

   /// @copydoc Node::clone
   Node_ptr clone() const;

   /// Returns the value of the left leaf added with the right leaf.
   double evaluate() const;

   /// @copydoc Node::print
   void print(std::ostream& out) const;
};

/// Class that represents a subtraction expression.
class Sub: public Expression
{
public:
   /// Constructs a subtraction expression consisting of two nodes, transferring ownership.
   Sub(Node_ptr left, Node_ptr right);

   /// Move assignment and constructor
   Sub(Sub&&) = default;
   Sub& operator=(Sub&&) = default;

   /// @copydoc Node::clone
   Node_ptr clone() const;

   /// @copydoc Node::derivative
   /// d = left node; du = derivative of left node; v = right node; dv = derivative of right node.
   /// du - dv
   Node_ptr derivative(const std::string& dVarName) const;

   /// Returns the value of the right leaf subtracted from the left leaf.
   double evaluate() const;

   /// @copydoc Node::print
   void print(std::ostream& out) const;
};

/// Class that represents a multiplication expression.
class Mul: public Expression
{
public:
   /// Constructs a multiplication expression consisting of two nodes, transferring ownership.
   Mul(Node_ptr left, Node_ptr right);

   /// Move assignment and constructor
   Mul(Mul&&) = default;
   Mul& operator=(Mul&&) = default;

   /// @copydoc Node::clone
   Node_ptr clone() const;

   /// @copydoc Node::derivative
   /// d = left node; du = derivative of left node; v = right node; dv = derivative of right node.
   /// u*dv + v*du
   Node_ptr derivative(const std::string& dVarName) const;

   /// Returns the value of the left leaf multiplied with the right leaf.
   double evaluate() const;

   /// @copydoc Node::print
   void print(std::ostream& out) const;
};

/// Class that represents a division expression.
class Div: public Expression
{
public:
   /// Constructs a division expression consisting of two nodes, transferring ownership.
   Div(Node_ptr left, Node_ptr right);

   /// Move assignment and constructor
   Div(Div&&) = default;
   Div& operator=(Div&&) = default;

   /// @copydoc Node::clone
   Node_ptr clone() const;

   /// @copydoc Node::derivative
   /// d = left node; du = derivative of left node; v = right node; dv = derivative of right node.
   /// (v*du - u*dv) / (v*v)
   Node_ptr derivative(const std::string& dVarName) const;

   /// Returns the value of the left leaf divided by the right leaf.
   double evaluate() const;

   /// @copydoc Node::print
   void print(std::ostream& out) const;
};

} /* namespace expressions */

#endif /* EXPRESSION_H_ */
