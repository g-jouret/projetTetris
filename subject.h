#ifndef SUBJECT_H
#define SUBJECT_H

#include <set>

//namespace GJ_GW{

class Observer;

class Subject{
public:
    virtual ~Subject() = default;

    virtual void addObserver(Observer * observer);

    virtual void removeObserver(Observer * observer);

protected:
    Subject() = default;

    virtual void notifyObservers();

protected:
    std::set<Observer *> observers_;
};

//} //namespace GJ_GW

#endif // SUBJECT_H
