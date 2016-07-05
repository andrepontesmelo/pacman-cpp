#ifndef NULL_ARGUMENT_EXCEPTION_H
#define NULL_ARGUMENT_EXCEPTION_H

#include "Exception.h"

class NullArgumentException: public Exception
{
	public:
		NullArgumentException(string argument, string method);
};

#endif
