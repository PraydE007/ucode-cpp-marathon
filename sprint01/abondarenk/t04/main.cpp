#include "src/stdAlgo.h"

static void output(Data*& db) {
    std::cout << "size: " << db->size << std::endl;
    std::cout << "contains 'rich': "
              << (db->rich ? "true" : "false") << std::endl;
    std::cout << "none of lengths is 15: "
              << (db->fift ? "true" : "false") << std::endl;
    std::cout << "all end with 'vel': "
              << (db->vel ? "true" : "false") << std::endl;
    std::cout << "without 'mel': " << db->mel << std::endl;
}

static void cexit(Data*& db, std::string msg) {
    delete db;
    std::cerr << msg << std::endl;
    std::exit(1);
}

int main(int argc, char *argv[]) {
    std::ifstream ost;
    std::string line;
    std::forward_list<std::string> flst;
    Data* db = createDB();

    if (argc != 2)
        cexit(db, USAGE);
    ost.open(argv[1]);
    if (!ost.is_open())
        cexit(db, ERROR);
    while (getline(ost, line)) {
        if (line.size() > 0) {
            db->size += 1;
            flst.push_front(line);
        }
    }
    if (db->size == 0)
        cexit(db, ERROR);
    for (auto str : flst)
        readStats(db, str);
    ost.close();
    output(db);
    delete db;
    return 0;
}
