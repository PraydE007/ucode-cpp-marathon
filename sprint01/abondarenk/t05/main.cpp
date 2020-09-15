#include "src/stdAlgo.h"

static void cexit(std::string msg) {
    std::cerr << msg << std::endl;
    std::exit(1);
}

static std::string getModeName(char *filename) {
    std::string fn(filename);
    int d = 0;

    for (d = fn.size(); d > 0 && fn[d] != '.'; d--);
    if (d == 0)
        fn += "_mod";
    else
        fn.insert(d, "_mod");
    return fn;
}

static void read(std::forward_list<std::string>& flst, char *argv[]) {
    std::ifstream rst;
    std::string line;
    int size = 0;

    rst.open(argv[1]);
    if (!rst.is_open())
        cexit(ERROR);
    while (getline(rst, line)) {
        if (line.size() > 0) {
            flst.push_front(line);
            size++;
        }
    }
    rst.close();
    if (size == 0)
        cexit(ERROR);
}

static void write(std::forward_list<std::string>& flst, char *filename) {
    std::ofstream wst;

    wst.open(getModeName(filename));
    for (auto x : flst)
        wst << x << std::endl;
    wst.close();
}

int main(int argc, char *argv[]) {
    std::forward_list<std::string> flst;

    if (argc != 2)
        cexit(USAGE);
    read(flst, argv);
    redit(flst);
    write(flst, argv[1]);
    return 0;
}
