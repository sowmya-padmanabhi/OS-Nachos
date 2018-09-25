//
// Created by sowmya on 9/20/2018.
//

#ifndef NACHOS_PERSON_H
#define NACHOS_PERSON_H

#include "../lib/list.h"


class Person {
public:
    Person(int sequence, int priority, int timeWash, int totalClothes);
    Person();
    virtual ~Person();
    int getPersonPriority() const;
    int getPersonSequence() const;
    int getTotalClothes() const;
    int getTimeWash() const ;

    bool operator == (Person per) {
        if(this->getPersonSequence() == per.getPersonSequence())
            return true;
        else return false;
    }
private:
    int priority;
    int sequence;
    long washTime;
    int clothes;
};

#endif //NACHOS_PERSON_H
