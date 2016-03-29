/*
 * Variable.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#include "Variable.h"

namespace expressions
{
Variable::Variable(std::string&& name) :
   mName(std::move(name))
{
}

double Variable::evaluate() const
{
   return 0;
}

void Variable::print(std::ostream& out) const
{
   out << mName;
}

} /* namespace expressions */
