#include "Excessao.h"

Excessao::Excessao(string msg)
{
	this->msg = msg;
	cout << "Excessao: " + msg + "\n";
}

string Excessao::Msg()
{
	return msg;
}
