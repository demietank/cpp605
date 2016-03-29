/*
 * Expression.h
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#ifndef EXPRESSION_H_
#define EXPRESSION_H_

#include <memory>

#include "Node.h"

namespace expressions
{

class Expression: public Node
{
public:
   Expression(std::unique_ptr<Node> left, std::unique_ptr<Node> right);

   virtual ~Expression() {};

protected:
   std::unique_ptr<Node> mLeft;
   std::unique_ptr<Node> mRight;
};

class Add: public Expression
{
public:
   Add(std::unique_ptr<Node> left, std::unique_ptr<Node> right);

   double evaluate() const;

   void print(std::ostream& out) const;
};

class Sub: public Expression
{
public:
   Sub(std::unique_ptr<Node> left, std::unique_ptr<Node> right);

   double evaluate() const;

   void print(std::ostream& out) const;
};

class Mul: public Expression
{
public:
   Mul(std::unique_ptr<Node> left, std::unique_ptr<Node> right);

   double evaluate() const;

   void print(std::ostream& out) const;
};

class Div: public Expression
{
public:
   Div(std::unique_ptr<Node> left, std::unique_ptr<Node> right);

   double evaluate() const;

   void print(std::ostream& out) const;
};

} /* namespace expressions */

#endif /* EXPRESSION_H_ */
