#include "NullReferenceException.h"

NullReferenceException::NullReferenceException(string variable, string method) :
								Exception("Null reference: '" + variable + "' @ method: " + method)
{
}
