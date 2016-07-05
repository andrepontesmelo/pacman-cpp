#include "Exception.h"

Exception::Exception(string msg)
{
	this->msg = msg;
	cout << "Exception: " + msg + "\n";
}

string Exception::Msg()
{
	return msg;
}
