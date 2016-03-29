/*
 * Node.h
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#ifndef NODE_H_
#define NODE_H_

#include <ostream>

namespace expressions
{

class Node
{
public:
   virtual ~Node() {};

   virtual double evaluate() const = 0;

   /// Outputs an ASCII representation of the node.
   /// This is used to pseudo-overload the ostream& operator<<
   virtual void print(std::ostream& out) const = 0;
};

/// Outputs an ASCII representation of the Node.
std::ostream& operator<<(std::ostream& out,
                         const Node& node);

} /* namespace expressions */

#endif /* NODE_H_ */
