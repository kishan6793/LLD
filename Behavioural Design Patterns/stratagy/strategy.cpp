#include<bits/stdc++.h>
using namespace std;


//abstract class duck
class Duck {
    public:

    FlyBehaviour flybehaviour;
    QuackBehaviour quackbehavior;

    //every duck will have unique display behaviour
    virtual void display() = 0;


    //many ducks can have same flying algos but different quacking algos
    //we dont want to implement behaviour in base class or inherited class bcz it cant be reused then
    //and we have to write maybe same code again and again
    //so the best way is to assign it on runtime by making interface for the behaviours that are changing
    //will make the code losely coupled,resuable,extendable,maintainable
    void performFly() {
        flybehaviour.fly();
    }

    void performQuack() {
        quackbehavior.quack();
    }

    //every duck will have this same swim implementation
    void swim() {
        cout << "All Ducks Float, even decoys!" << endl;
    }
};

class FlyBehaviour {
    virtual void fly() = 0;
};