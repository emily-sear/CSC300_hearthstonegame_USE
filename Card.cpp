#include "Card.hpp"
#include <iostream>

using namespace std;
Card::Card(string name, string type, int mana_cost, int attack, int health)
{
    this->name = name;
    this->type = type;
    this->mana_cost = mana_cost;
    this->attack = attack;
    this->health = health;
}

void Card::display()
{
    cout << "Name: " << this->name << endl;
    cout << "Type: " << this->type << endl;
    cout << "Cost: " << this->mana_cost << endl;
    cout << "Attack: " <<this->attack << endl;
    cout << "Health: " << this->health << endl;
    cout << "" << endl;

}

string Card::getType()
{
    return this->type;
}

int Card::getHealth()
{
    return this->health;
}