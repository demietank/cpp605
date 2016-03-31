/** Constant.h
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#ifndef CONSTANT_H_
#define CONSTANT_H_

#include "Node.h"

namespace expressions
{

/// Represents a node of constant value in an expression tree.
class Constant: public Node
{
public:
   /// Constructs a node that holds a constant value.
   Constant(const double value);

   /// Returns the value held within the node.
   double evaluate() const;

   /// @copydoc Node::print
   void print(std::ostream& out) const;

private:
   /// Value of the constant
   double mValue;
};

} /* namespace expressions */

#endif /* CONSTANT_H_ */
