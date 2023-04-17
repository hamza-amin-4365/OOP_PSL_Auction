#include "player.h"
#include <iostream>

Player::Player(std::string name, std::string team, double price)
    : name(name), team(team), price(price) {}

std::string Player::getName() {
    return name;
}

std::string Player::getTeam() {
    return team;
}

double Player::getPrice() {
    return price;
}

void Player::setPrice(double newPrice) {
    price = newPrice;
}

void Player::print() {
    std::cout << "Name: " << name << ", Team: " << team << ", Price: " << price << "\n";
}
