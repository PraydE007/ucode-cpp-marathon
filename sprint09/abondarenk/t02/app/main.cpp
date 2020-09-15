#include <iostream>
#include <fstream>
#include <chrono>

#include "Worker.h"
#include "MultithreadedFileHandler.h"

void cexit(std::string msg) {
    std::cerr << msg << std::endl;
    std::exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3)
        cexit("usage: ./multithreadedFileHandler [file1] [file2]");

    // Files check
    std::ifstream fd1(argv[1]);
    std::ifstream fd2(argv[2]);
    std::string buf1;
    std::string buf2;
    if (!fd1.is_open() || !fd2.is_open()) {
        fd1.close();
        fd2.close();
        cexit("error");
    }
    getline(fd1, buf1, '\0');
    getline(fd2, buf2, '\0');
    if (buf1.empty() || buf2.empty()) {
        fd1.close();
        fd2.close();
        cexit("error");
    }
    fd1.close();
    fd2.close();

    MultithreadedFileHandler obj;
    Worker worker;

    worker.startNewThread(&MultithreadedFileHandler::processFile, &obj);
    worker.startNewThread(&MultithreadedFileHandler::loadFile, &obj, argv[1]);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "-----1 second sleep-----" << std::endl;

    worker.startNewThread(&MultithreadedFileHandler::processFile, &obj);
    worker.startNewThread(&MultithreadedFileHandler::loadFile, &obj, argv[2]);

    worker.joinAllThreads();
    return 0;
}
