#include <iostream>
#include <string>

using namespace std;

class Log {
private:
    static Log* inst;
    Log() {}

public:
    static Log* getInst() {
        if (!inst) {
            inst = new Log();
        }
        return inst;
    }

    void logMsg(const string& msg) {
        cout << "Log: " << msg << endl;
    }
};

Log* Log::inst = nullptr;

int main() {

    Log* l = Log::getInst();

    l->logMsg("Logging message from part 1");
    l->logMsg("Logging message from part 2");

    return 0;
}

