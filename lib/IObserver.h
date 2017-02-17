#ifndef IOBSERVER_H
#define IOBSERVER_H

class IObserver
{
public:
void virtual Refresh(int action) = 0;
virtual ~IObserver() {
}
};

#endif
