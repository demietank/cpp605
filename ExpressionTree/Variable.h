/*
 * Variable.h
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#ifndef VARIABLE_H_
#define VARIABLE_H_

#include <map>
#include <string>

#include "Node.h"

namespace expressions
{

/// For convenience
using VarMap = std::map<std::string, double>;

/// Represents a node of variable value in an expression tree. The current value is held in a
/// referenced map.
class Variable : public Node
{
public:
   /// Constructs a variable based on a name and a variable map.
   Variable(const std::string& name, const VarMap& varMap);
   Variable(std::string&& name, const VarMap& varMap);

   /// Returns the value of the variable as held in mVarMap. Exception thrown if not in map.
   double evaluate() const;

   /// @copydoc Node::print
   void print(std::ostream& out) const;

private:
   /// Identifying variable name
   std::string mName;

   /// Reference to the variable map
   const VarMap& mVarMap;
};

} /* namespace expressions */

#endif /* VARIABLE_H_ */
