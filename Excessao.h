#ifndef EXCESSAO_H
#include <iostream>
#define EXCESSAO_H
using std::string;
using std::cout;
class Excessao
{
	public:
		Excessao(string msg);
		string Msg();

	protected:
		string msg;
		
};
#endif
