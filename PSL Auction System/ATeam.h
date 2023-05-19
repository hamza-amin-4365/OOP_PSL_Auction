#ifndef ATEAM_H
#define ATEAM_H

#include <string>

class ATeam {
public:
    ATeam(std::string name, int budget);
    std::string get_name();
private:
    std::string name;
    int budget;
};

#endif
