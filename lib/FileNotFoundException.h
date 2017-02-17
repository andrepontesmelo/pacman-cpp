#ifndef FILE_NOT_FOUND_EXCEPTION_H
#define FILE_NOT_FOUND_EXCEPTION_H

#include "Exception.h"

class FileNotFoundException : public Exception
{
public:
FileNotFoundException(string file);
};

#endif
