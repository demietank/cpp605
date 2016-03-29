/*
 * Node.cpp
 *
 *  Created on: Mar 27, 2016
 *      Author: Chris
 */

#include "Node.h"

namespace expressions
{

std::ostream& operator<<(std::ostream& out,
                         const Node& node)
{
   node.print(out);
   return out;
}

} /* namespace expressions */
