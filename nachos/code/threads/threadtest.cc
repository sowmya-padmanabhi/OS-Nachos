#include "kernel.h"
#include "main.h"
#include "thread.h"
#include "person.h"
#include "../lib/list.h"

void
SimpleThread(int which)
{
    int num;
    
    for (num = 0; num < 5; num++) {
        printf("*** thread %d looped %d times\n", which, num);
	printf("Hello World!");
        kernel->currentThread->Yield();
    }
}

// ---- Compare function to compare higher priority between two person----
int comparePriority(Person per1, Person per2){
    if(per1.getPersonPriority() < per2.getPersonPriority())
        return -1;
    else if(per1.getPersonPriority() > per2.getPersonPriority())
        return 1;
    else return 0;
}
// ---- Print function to print out each person and associated information of the person ----
void print(Person per){
    std::cout << "Person with the sequence number: " << per.getPersonSequence() << ", priority number: " << per.getPersonPriority() << ", has  " << per.getTotalClothes() << "  number of clothes and needs total of " << per.getTimeWash() << " time to finish washing the clothes\n";
}
// ---- Simunation 1 ----
void simulation1(int numb){
    // ---- Using the existing SortedList function to sort the Person list- highest priority to lowest priority----
    SortedList<Person> *sortPerson = new SortedList<Person>(comparePriority);
    int seq = 0;
    int timeTotal = 0;
    //----Generating 20 Persons----
    for(int i=0; i<numb; i++){
        Person per(seq++, rand()%20, rand()%30, rand()%50);
        sortPerson->Insert(per);
    }
    //---- Printing the Person order ----
    std::cout << "\n***************Simulation 1 Running *****************\n \n Laundry line up according to priority \n \n ";
    ListIterator<Person> list = sortPerson;
    sortPerson->Apply(print);
    std::cout << "\n _________ Simulation 1 begins.....__________\n\n";
    int order = 0;
    Person prevPerson;
    while (!list.IsDone()){
        Person per = sortPerson->Front();
        timeTotal += per.getTimeWash();
        std::cout << "The order is " << order++ << ": ";
        print(per);
        if(prevPerson.getPersonSequence() != NULL)
            std::cout << "Person with the sequence number" << prevPerson.getPersonSequence() << " leaves the room. This person took a total time of " << prevPerson.getTimeWash() << " to finish washing all the clothes.\n";
        else
            std::cout << "\n";
        prevPerson = per;
        list.Next();
        sortPerson->RemoveFront();
    }
    std::cout << "\nThe Total time taken for washing clothes of all 20 people are: " << timeTotal << "\n";
}

//---- Function to determine the highest priority for Simulation 2 ----
Person highPriorityPerson(List<Person> *list){
    int highest = 0;
    Person newHigh;
    List<Person> *temp = list;
    ListIterator<Person> list1 = temp;
    while (!list1.IsDone()) {
        Person per = list1.Item();
        if (per.getPersonPriority() >=  highest) {
            newHigh = per;
            highest = per.getPersonPriority();
        }
        list1.Next();
    }
    return newHigh;
}
//---- Simulation 2 ----
void simulation2(int numb){
    List<Person> *newPerson = new List<Person>();
    int seq = 0;
    int timeTotal = 0;
    //---- Generation 20 Persons
    for(int i=0; i<numb; i++){
        Person per(seq++, rand()%10, rand()%30, rand()%50);
        newPerson->Append(per);
    }
    //----Printing the Person oreder ----
    std::cout << "\n*************** Simulation 2 Running *******************\n \n Laundry line up according to priority \n \n Highest Priority = 0 Lowest Priority = 9 \n\n";
    ListIterator<Person> list = newPerson;
    newPerson->Apply(print);
    std::cout << "\n____________Simulation 2 begins.....______________\n\n";
    int order = 0;
    Person prevPerson;
    while(!list.IsDone() && newPerson->NumInList()!=0){
        Person current = highPriorityPerson(newPerson);
        timeTotal += current.getTimeWash();
        std::cout << "The order is " << order++ << ": ";
        print(current);
        if(prevPerson.getPersonSequence() != NULL)
            std::cout << "Person with the sequence number " << prevPerson.getPersonSequence() << " leaves the room. This person took a total time of " << prevPerson.getTimeWash() << " to finish washing all the clothes.\n";
        else
        std::cout << "\n";
        newPerson->Remove(current);
//	list.Next();
        prevPerson = current;

    }
    std::cout << "\nThe total time taken for washing clothes of all 20 people are: " << timeTotal  << "\n";
}

void
ThreadTest()
{
    //Thread *t = new Thread("forked thread");
    //t->Fork((VoidFunctionPtr) SimpleThread, (void *) 1);

    //---- Calling Simulation 1 ----
    simulation1(20);
    //---- Calling Simulation 2 ----
    simulation2(20);

    //SimpleThread(0);
}
