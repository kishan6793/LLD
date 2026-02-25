#ifndef logger_h
#define logger_h

#include<string>
#include<mutex>
using namespace std;

class Logger {
    private:

    static int cnt; //to count total inctances of the class
    static Logger* loggerInstance;
    static mutex mtx;   //to make getLogger threadsafe
    Logger();   //private constructor

    //now we want to restrict users from calling Logger()
    //so we will make private copy const and 
    //  private '=' operator overloading
    Logger operator=(const Logger &);
    
    public:

        Logger(const Logger &) = delete;    //new way to restrict users from calling it 
                                            //from cpp11
        static Logger* getLogger();
        void log(string msg);
};

#endif


// The Singleton Design Pattern ensures that
// a class has only one instance and provides a global access point to it.
// It is used when we want centralized control of resources, 
//such as managing database connections, configuration settings or logging.