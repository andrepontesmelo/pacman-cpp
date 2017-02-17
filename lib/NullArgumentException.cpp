#include "NullArgumentException.h"

NullArgumentException::NullArgumentException(string argument, string method) :
								Exception("Null argument: '" + argument + "' @ method: " + method)
{
}
