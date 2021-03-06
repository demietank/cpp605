/*
 * Variable.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#include "Constant.h"
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

Node_ptr Variable::clone() const
{
   return make_unique<Variable>(mName, mVarMap);
}

Node_ptr Variable::derivative(const std::string& dVarName) const
{
   if (dVarName == mName)
   {
      return make_unique<Constant>(1.0);
   }
   else
   {
      return make_unique<Constant>(0.0);
   }
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
