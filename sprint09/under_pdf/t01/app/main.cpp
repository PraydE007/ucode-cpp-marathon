#include "Worker.h"
#include "MultithreadedClass.h"

#include <iostream>

void cexit(std::string msg) {
    std::cerr << msg << std::endl;
    std::exit(1);
}

void parseArgs(char *argv[], int& count, int& addValue, int& subtractValue) {
    try {
        count = std::stoi(argv[3]);
        addValue = std::stoi(argv[1]);
        subtractValue = std::stoi(argv[2]);
    }
    catch (...) {
        cexit("usage: ./simpleWorkerV2 [addValue] [subtractValue] [count]");
    }
    if (count < 5 || count > 10)
        cexit("Incorrect values");
    if (addValue < -2000 || addValue > 2000)
        cexit("Incorrect values");
    if (subtractValue < -2000 || subtractValue > 2000)
        cexit("Incorrect values");
}

int main(int argc, char *argv[]) {
    int count = 0;
    int addValue = 0;
    int subtractValue = 0;

    if (argc != 4)
        cexit("usage: ./simpleWorkerV2 [addValue] [subtractValue] [count]");
    parseArgs(argv, count, addValue, subtractValue);

    MultithreadedClass obj;

    Worker worker;

    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::add, &obj, addValue);
    }

    for (auto i = 0; i < count; ++i) {
        worker.startNewThread(&MultithreadedClass::subtract, &obj, subtractValue);
    }

    worker.joinAllThreads();

    std::cout << obj.getInt() << std::endl;

    return 0;
}
