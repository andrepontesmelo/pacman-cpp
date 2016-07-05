#ifndef SUBJECT_H
#define SUBJECT_H
#include "IObserver.h"
#include <vector>

using std::vector;
class Subject
{
public:
	void AddObserver(IObserver *o);
	void RemoverObserver(IObserver *o);
	
protected:
	void Notify(int action);
	
private:
	vector<IObserver*> observers;
};

#endif
