#include "stdAlgo.h"

Data* createDB(void) {
    Data* db = new Data;

    db->size = 0;
    db->rich = false;
    db->fift = true;
    db->vel = true;
    db->mel = 0;
    return db;
}

bool findSubstr(std::string src, std::string substr) {
    auto it = std::search(
        src.begin(), src.end(),
        substr.begin(), substr.end(),
        [](char ch1, char ch2) { return ch1 == ch2; }
    );
    return it != src.end();
}

bool findVel(std::string src, std::string substr) {
    auto it = std::find_end(
        src.begin(), src.end(),
        substr.begin(), substr.end()
    );
    if (it + 3 == src.end())
        return true;
    return false;
}

void readStats(Data*& db, std::string line) {
    if (findSubstr(line, "rich"))
        db->rich = true;
    if (line.size() == 15)
        db->fift = false;
    if (db->vel && !findVel(line, "vel"))
        db->vel = false;
    if (!findSubstr(line, "mel"))
        db->mel += 1;
}
