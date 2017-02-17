#ifndef ALARM_CLOCKS_H

#include "IObserver.h"
#include "AlarmClock.h"

#define ALARM_CLOCKS_H

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
