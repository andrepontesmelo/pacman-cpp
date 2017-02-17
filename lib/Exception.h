#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

using std::string;
using std::cout;
class Exception
{
public:
Exception(string msg);
string Msg();

protected:
string msg;

};
#endif
