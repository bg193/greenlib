//   GreenControl framework
//
// LICENSETEXT
//
//   Copyright (C) 2009 : GreenSocs Ltd
// 	 http://www.greensocs.com/ , email: info@greensocs.com
//
//   Developed by :
//   
//   Michael Ruetz <m.ruetz@tu-bs.de>,
//   Christian Schroeder <schroeder@eis.cs.tu-bs.de>
//     Technical University of Braunschweig, Dept. E.I.S.
//     http://www.eis.cs.tu-bs.de
//
//
// The contents of this file are subject to the licensing terms specified
// in the file LICENSE. Please consult this file for restrictions and
// limitations that may apply.
// 
// ENDLICENSETEXT

// doxygen comments

#ifndef __STRING_VECTOR_H__
#define __STRING_VECTOR_H__

#include "greencontrol/core/log_if.h"

namespace gs {
namespace cnf {


/// This is an extended std::vector<std::string> with additional log_if methods.
/**
 * This class extends an std::vector<std::string> by adding the methods demanded by the log_if interface.
 */
class string_vector
  : public std::vector<std::string>
  , public log_if
{
public:

  /// Copy operator.
  string_vector& operator = (const vector<string>& v)
  {
    vector<string>::operator=(v);
    return *this;
  }

  /// Returns a string representation of the vector.
  std::string toString()
  {
    std::stringstream ss;
    ss << getTypeLog() << " = { " << getValueLog() << " }";
    return ss.str();
  }

  /// Returns a string representation of the payload.
  std::string getValueLog()
  {
    std::stringstream ss;
    unsigned int i=0;

    for(vector<string>::iterator it = this->begin(); it != this->end(); ++it)
    {
      i++;
      ss << *it;
      if(i < this->size())
        ss << ", ";
    }

    return ss.str();
  }

  /// Returns the datatype of the vector.
  std::string getTypeLog()
  {
    return std::string("vector<string>");
  }

  /// Should return the name of the vector.
  std::string getNameLog()
  {
    return std::string("N/A");
  }
};


} // end namespace cnf
} // end namespace gs

#endif
