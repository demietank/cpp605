/*
 * Constant.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#include "Constant.h"

namespace expressions
{

Constant::Constant(const double value) :
      mValue(value)
{
}

Node_ptr Constant::clone() const
{
   return make_unique<Constant>(mValue);
}

double Constant::evaluate() const
{
   return mValue;
}

void Constant::print(std::ostream& out) const
{
   out << mValue;
}

} /* namespace expressions */
