/*
 * Expression.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#include "Expression.h"

namespace expressions
{

Expression::Expression(std::unique_ptr<Node> left,
                       std::unique_ptr<Node> right) :
      mLeft(std::move(left)),
      mRight(std::move(right))
{
}

Add::Add(std::unique_ptr<Node> left, std::unique_ptr<Node> right) :
      Expression(std::move(left), std::move(right))
{
}

double Add::evaluate() const
{
   return mLeft->evaluate() + mRight->evaluate();
}

void Add::print(std::ostream& out) const
{
   out << "(" << *mLeft << " + " << *mRight << ")";
}

Sub::Sub(std::unique_ptr<Node> left, std::unique_ptr<Node> right) :
      Expression(std::move(left), std::move(right))
{
}

double Sub::evaluate() const
{
   return mLeft->evaluate() - mRight->evaluate();
}

void Sub::print(std::ostream& out) const
{
   out << "(" << *mLeft << " - " << *mRight << ")";
}

Mul::Mul(std::unique_ptr<Node> left, std::unique_ptr<Node> right) :
      Expression(std::move(left), std::move(right))
{
}

double Mul::evaluate() const
{
   return mLeft->evaluate() * mRight->evaluate();
}

void Mul::print(std::ostream& out) const
{
   out << "(" << *mLeft << " * " << *mRight << ")";
}

Div::Div(std::unique_ptr<Node> left, std::unique_ptr<Node> right) :
      Expression(std::move(left), std::move(right))
{
}

double Div::evaluate() const
{
   return mLeft->evaluate() / mRight->evaluate();
}

void Div::print(std::ostream& out) const
{
   out << "(" << *mLeft << " / " << *mRight << ")";
}

}
/* namespace expressions */
