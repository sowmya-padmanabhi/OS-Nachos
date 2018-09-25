//
// Created by sowmya on 9/20/2018.
//
#include "person.h"
#include <iostream>
#include <stdlib.h>

Person::Person(int sequence, int priority, int timeWash, int totalClothes) {
    this->sequence = sequence;
    this->priority = priority;
    this->clothes = totalClothes;
    this->washTime = timeWash;
}
int Person::getPersonPriority() const {
    return priority;
}
int Person::getPersonSequence() const {
    return sequence;
}
int Person::getTimeWash() const {
    return washTime;
}
int Person::getTotalClothes() const {
    return clothes;
}
Person::Person(){}
Person::~Person(){}
