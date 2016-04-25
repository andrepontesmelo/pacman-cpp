#include "FileNotFoundException.h"

FileNotFoundException::FileNotFoundException(string file) : 
	Exception("File not found: " + file)
{
}	
