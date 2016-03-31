/*
 * Expression.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#include "Expression.h"

namespace expressions
{

Expression::Expression(Node_ptr left,
                       Node_ptr right) :
      mLeft(std::move(left)),
      mRight(std::move(right))
{
}

Add::Add(Node_ptr left, Node_ptr right) :
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

Sub::Sub(Node_ptr left, Node_ptr right) :
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

Mul::Mul(Node_ptr left, Node_ptr right) :
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

Div::Div(Node_ptr left, Node_ptr right) :
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
