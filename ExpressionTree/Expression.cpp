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

Node_ptr Add::clone() const
{
   return make_unique<Add>(mLeft->clone(), mRight->clone());
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

Node_ptr Sub::clone() const
{
   return make_unique<Sub>(mLeft->clone(), mRight->clone());
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

Node_ptr Mul::clone() const
{
   return make_unique<Mul>(mLeft->clone(), mRight->clone());
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

Node_ptr Div::clone() const
{
   return make_unique<Div>(mLeft->clone(), mRight->clone());
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
