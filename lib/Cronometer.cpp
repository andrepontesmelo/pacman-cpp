#include "Cronometer.h"

void Cronometer::Start()
{
								gettimeofday(&start, 0);
}

void Cronometer::Refresh()
{
								gettimeofday(&end, 0);
}

int Cronometer::ReadMs()
{
								int read_ms = end.tv_usec - start.tv_usec;

								read_ms += (end.tv_sec - start.tv_sec) * ONE_MILION;

								return read_ms;
}
