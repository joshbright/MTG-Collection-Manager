#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;

class Card
{
     private:
          int id;
          string name;
          int cost;
          string rules;
          int atk;
          int def;

     public:	
          Card(){} //may need to change default for SQLite
          int getId();
          string getName();
          int getCost();
          string getRules();
          int getAtk();
          int getDef();
          void setID(int newID);
		void setName(string newName);
          void setCost(int newCost);
          void setRules(string newRules);
          void setAtk(int newAtk);
          void setDef(int newDef);
};

int Card::getId()
{
     return id;
}
string Card::getName()
{
	return name;
}

int Card::getCost()
{
	return cost;
}

string Card::getRules()
{
	return rules;
}

int Card::getAtk()
{
	return atk;
}
int Card::getDef()
{
	return def;
}

void Card::setID(int newID)
{
     id = newID;
}

void Card::setName(string newName)
{
     name = newName;
}

void Card::setCost(int newCost)
{
     cost = newCost;
}

void Card::setRules(string newRules)
{
     rules = newRules;
}

void Card::setAtk(int newAtk)
{
     atk = newAtk;
}
void Card::setDef(int newDef)
{
     def = newDef;
}

#endif