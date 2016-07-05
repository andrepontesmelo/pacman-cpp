#ifndef ALARM_CLOCK_H
#define ALARM_CLOCK_H

#include "Subject.h"

class AlarmClock : public Subject
{
	public:
		void Verify();
		AlarmClock();

	private:
		int interval_segs;
};

#endif
