#ifndef OBSERVER_H
#define OBSERVER_H

class Subject;

class Observer{
public:
    virtual void update(Subject * subject) = 0;

    virtual ~Observer() = default;

};

#endif // OBSERVER_H
