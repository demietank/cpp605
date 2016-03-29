/*
 * Variable.h
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#ifndef VARIABLE_H_
#define VARIABLE_H_

#include <string>

#include "Node.h"

namespace expressions
{

class Variable : public Node
{
public:
   Variable(std::string&& name);

   double evaluate() const;

   /// @copydoc Node::print
   void print(std::ostream& out) const;

private:
   std::string mName;
};

} /* namespace expressions */

#endif /* VARIABLE_H_ */
