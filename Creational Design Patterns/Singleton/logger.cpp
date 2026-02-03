#include<iostream>
#include"logger.hpp"
using namespace std;

int Logger::cnt = 0;
Logger* Logger::loggerInstance = nullptr;
mutex Logger::mtx;

Logger :: Logger(){
    cnt++;
    cout << "new inctance of logger created! No of inctances: " << cnt << endl;
}

void Logger::log(string msg) {
    cout << msg << endl;
}

//classic - not thread safe
//1-> make constructor private
//2-> create a private static instance
//3-> create a static getInstance()
// Logger* Logger::getLogger() {
//     if(loggerInstance == nullptr) {
//         loggerInstance = new Logger();
//     }
//     return loggerInstance;
// }


//threadsafe - using mutex
//question - do u need this lock all the time?
//No. only when first instance is being created.
// Logger* Logger::getLogger() {
//     mtx.lock();
//     if(loggerInstance == nullptr) {
//         loggerInstance = new Logger();
//     }
//     mtx.unlock();
//     return loggerInstance;
// }

//double checked locking
//check if it is the first instance then only put lock
//bcz locks are really expensive so we will put lock only once
Logger* Logger::getLogger() {
    if(loggerInstance == nullptr)
    {
        mtx.lock();
        if(loggerInstance == nullptr) {
            loggerInstance = new Logger();
        }
        mtx.unlock();
    }
    return loggerInstance;
}