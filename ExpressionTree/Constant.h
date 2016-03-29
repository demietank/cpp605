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

class Constant: public Node
{
public:
   Constant(const double value);

   double evaluate() const;

   /// @copydoc Node::print
   void print(std::ostream& out) const;

private:
   double mValue;
};

} /* namespace expressions */

#endif /* CONSTANT_H_ */
