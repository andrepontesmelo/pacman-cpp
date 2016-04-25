#ifndef CRONOMETER_H
#define CRONOMETER_H
#include <sys/time.h>
#define ONE_MILION 1000000

class Cronometer
{
public:
	Cronometer() {}
	void Start();
	void Refresh();
	int ReadMs();
private:
	struct timeval start, end;

};
#endif
