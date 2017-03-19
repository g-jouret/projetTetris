#include "subject.h"
#include "observer.h"

//namespace GJ_GW {

void Subject::addObserver(Observer * observer)
{
    observers_.insert(observer);
}

void Subject::removeObserver(Observer * observer)
{
    observers_.erase(observer);
}

void Subject::notifyObservers()
{
    for (Observer * o : observers_)
    {
        o->update(this);
    }
}

//} //namespace GJ_GW
