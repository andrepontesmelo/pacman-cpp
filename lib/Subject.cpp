#include "Subject.h"

void Subject::AddObserver(IObserver *o)
{
	observers.push_back(o);
}

void Subject::Notify(int action)
{
	vector<IObserver*>::iterator iterador = observers.begin();

	for (; iterador < observers.end(); iterador++)
		(*iterador)->Refresh(action);
}
