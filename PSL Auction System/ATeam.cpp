#include "ATeam.h"

ATeam::ATeam(std::string name, int budget) {
    this->name = name;
    this->budget = budget;
}

std::string ATeam::get_name() {
    return name;
}
