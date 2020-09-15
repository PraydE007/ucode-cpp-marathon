#include "visitAll.h"

void moveFront(std::deque<Town*>& lst) {
    lst.push_back(lst[0]);
    lst.pop_front();
}

Town* createTown(int id, std::string name, int stamina, int distance) {
    Town* town = new Town;

    town->id = id;
    town->name = name;
    town->stamina = stamina;
    town->distance = distance;
    return town;
}

void deleteTowns(std::deque<Town*>& lst) {
    while (lst.size() != 0) {
        delete lst[0];
        lst.pop_front();
    }
}

static int countChars(std::string str, char ch) {
    int count = 0;

    for (char i : str) {
        if (ch == i)
            count++;
    }
    return count;
}

static bool checkParams(std::string str, Town& buf) {
    int f = 0;
    int s = 0;
    int t = 0;

    for (; str[f] != ',' && str[f] != '\0'; f++);
    if (f == 0)
        return false;
    s = f + 1;
    for (; str[s] != ','; s++) {
        if (str[s] < 48 || str[s] > 57)
            return false;
    }
    if (s == f + 1)
        return false;
    t = s + 1;
    for (; str[t] != '\0'; t++) {
        if (str[t] < 48 || str[t] > 57)
            return false;
    }
    if (t == s + 1)
        return false;
    buf.name = str.substr(0, f);
    buf.stamina = std::stoi(str.substr(f + 1, s - 1));
    buf.distance = std::stoi(str.substr(s + 1, t - 1));
    return true;
}

bool validate(int argc, char *argv[], std::deque<Town*>& lst) {
    Town buf;

    for (int i = 1; i < argc; i++) {
        if (countChars(argv[i], ',') == 2
            && checkParams(argv[i], buf))
        {
            lst.push_back(createTown(i - 1, buf.name, buf.stamina, buf.distance));
        }
        else {
            std::cerr << ARGV1 << argv[i] << ARGV2 << std::endl;
            deleteTowns(lst);
            return false;
        }
    }
    return true;
}

bool tryToRotate(int startId, std::deque<Town*>& lst) {
    int stamina = 0;

    do {
        stamina += lst[0]->stamina;
        stamina -= lst[0]->distance;
        if (stamina >= 0)
            moveFront(lst);
        else {
            // Return lst to start position
            while (lst[0]->id != startId)
                moveFront(lst);
            return false;
        }
    }
    while (lst[0]->id != startId);
    return true;
}
