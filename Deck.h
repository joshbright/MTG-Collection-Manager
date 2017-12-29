#ifndef DECK_H
#define DECK_H

#include <iterator>
#include <iostream>
#include <algorithm>
#include <vector>
#include "Card.h"
using namespace std;

class Deck
{
     private:
          string name;
          string location; //file location of 
          vector<Card> cards;

     public:
          Deck(){} //May need to change default constructor 
          void getCardsFromFile(string fileName);
          void setName(string newName);
          void setLocation(string newLocation);
          void addCard(Card addition);
          void removeCard(Card out);
          int outputNumberOfCards();
          string outputDeckName();
          string outputLocation();

          static int callback(void *data, int argc, char **argv, char **colName);
          string catchSearch(string input, string option);


};

void Deck::getCardsFromFile(string fileName)
{
     Card fileCard;
     sqlite3 * db;
     char * sql;
     sqlite3_stmt * stmt;
     int nrecs;
     char * errmsg;
     int i;
     const char* data = "";


     int connection = sqlite3_open(fileName.c_str(), &db);
      
      if(connection)
      {
           cout << "Didn't open because of " << sqlite3_errmsg(db) << endl;
            
            // needs exception (error massage)
           return;
      }
      
      else
      {
           cout << "Deck Opened" << endl;
      }

      const char *in;
     string thing, opt;
     char *err = 0;
      
     cout << "Enter Search Term:" << endl;
     cin >> thing;
     cout << endl << "and ordered by?" << endl;
     cin >> opt ;
      
     thing = catchSearch(thing, opt);
     in = thing.c_str(); //converts the string into a c string
     //This executes the sql code
     connection = sqlite3_exec(db, in, callback, (void*)data, &err);
    
     cout << data << endl;
    return;
      


}
//Stuff for SQL

int Deck::callback(void *data, int argc, char **argv, char **colName)
{
   Deck testDeck;
   Card tempCard;
   string temp;
   int i;
   int tempid;
   int tempCost;
   int tempAtk;
   int tempDef;
   cout << (const char*)data << ": " << (const char*)data;
   for(i=0; i<argc; i++)
   {
      temp = argv[i];    
      switch(i)
      {
          case 0:
               tempid = atoi (temp.c_str());
               tempCard.setID(tempid);
               break;
          case 1:
               tempCard.setName(temp);
               break;
          case 2:
               tempCost = atoi (temp.c_str());
               tempCard.setCost(tempCost);
               break;
          case 3:
               tempAtk = atoi (temp.c_str());
               tempCard.setAtk(tempAtk);
               break;
          case 4:
               tempDef = atoi (temp.c_str());
               tempCard.setDef(tempDef);
               break;
          case 5:
               tempCard.setRules(temp);
               break;
     }
   }
   testDeck.addCard(tempCard);
   return 0;
}

string Deck::catchSearch(string input, string option)
{
     string find = "SELECT id, name, cost, attack, health, text FROM cards WHERE name LIKE '%" + input + "%' order by " + option;
     return find;
}


void Deck::setName(string newName)
{
     name = newName;
}

void Deck::setLocation(string newLocation)
{
     location = newLocation;
}

void Deck::addCard(Card addition)
{
     cards.push_back(addition);
}

void Deck::removeCard(Card out)
{
    int outID = out.getId();
    int temp;
    for(int n = 0; n >= cards.size(); n++)
    {
      temp = cards[0].getId();
      if(outID == temp)
      {
          cards.erase(cards.begin()+n);
          return;
      }
      else
      {
        n++;
      }
    }
}

string Deck::outputDeckName()
{
	return name;
}
int Deck::outputNumberOfCards()
{
	return cards.size();
}
string Deck::outputLocation()
{
	return location;
}


#endif