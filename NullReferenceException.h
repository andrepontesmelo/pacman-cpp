#ifndef NULL_REFERENCE_EXCEPTION_H

#define NULL_REFERENCE_EXCEPTION_H

#include "Exception.h"

class NullReferenceException: public Exception
{
public:
	NullReferenceException(string variable, string method);
};

#endif


