/*
 * Node.h
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#ifndef NODE_H_
#define NODE_H_

#include <memory>
#include <ostream>

namespace expressions
{

#if __cplusplus > 201103L
using std::make_unique;
#else
/// Create and return a unique pointer using the specified type's new operator.
template< class T, class... Args >
std::unique_ptr<T> make_unique( Args&&... args )
{
   return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
#endif

/// Used for convenience
class Node;
using Node_ptr = std::unique_ptr<Node>;

/// Represents a node of an expression tree. This can be an interior node or a leaf.
class Node
{
public:
   /// Cleans up the Node - necessary for derived classes.
   virtual ~Node() {};

   /// Returns a smart pointer to a clone (deeply copied) of this node.
   virtual Node_ptr clone() const = 0;

   /// Returns the value of the node, or the aggregate of child nodes.
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
