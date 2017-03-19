#ifndef OBSERVER_H
#define OBSERVER_H

//namespace GJ_GW {

class Subject;

class Observer{
public:
    virtual void update(Subject * subject) = 0;

    virtual ~Observer() = default;

};

//} //namespace GJ_GW

#endif // OBSERVER_H
