#ifndef SUBJECT_H
#define SUBJECT_H

#include <set>

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

#endif // SUBJECT_H
