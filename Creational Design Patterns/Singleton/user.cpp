#include<iostream>
#include "logger.hpp"
#include<thread>
using namespace std;

void user1Logs(){
    Logger* l1 = Logger::getLogger();
    l1->log("this msg is from user1");
}

void user2Logs(){
    Logger* l2 = Logger::getLogger();
    l2->log("this msg is from user2");
}

int main(){

    thread t1(user1Logs);
    thread t2(user2Logs);

    t1.join();
    t2.join();

    return 0;
}