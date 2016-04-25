#ifndef ALARM_CLOCKS_H

#include "IObserver.h"
#include "AlarmClock.h"

#define DESPERTADORES_H

class AlarmClocks
{
public:
	AlarmClocks * GetInstance();
	AlarmClock* AddAlarmClock(int interval, IObserver *object);
	void Verify();

private:
	AlarmClocks();
};

#endif
