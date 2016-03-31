/*
 * Variable.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#include "Variable.h"

namespace expressions
{

Variable::Variable(const std::string& name, const VarMap& varMap) :
      mName(name),
      mVarMap(varMap)
{
}

Variable::Variable(std::string&& name, const VarMap& varMap) :
   mName(std::move(name)),
   mVarMap(varMap)
{
}

double Variable::evaluate() const
{
   return mVarMap.at(mName);
}

void Variable::print(std::ostream& out) const
{
   out << mName;
}

} /* namespace expressions */
