#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "sqlite3.h"
#include "Card.H"
#include "Deck.H"



void openDeck( string fileName ); //this will also create a new deck
void attachDeck( string deckName );
void detachDeck( string deckName );
void addCardToDeck( int id, string deckName );
void removeCardFromDeck( int id, string deckName );

int main()
{
    string fileName;
    cout << "Ensure that your database is in the same location as the executable" << endl;
    cout << "Input the name of the database you want to open or create: ";
    cin >> fileName;
    openDeck(fileName);
    //All the other function are intended to be called upon by the java.
    return 0;
}

//opens/creates a deck
void openDeck(string fileName)
{
  sqlite3 * db;
  char *err = 0;
  const char* data = "";
  string stringCommand = "CREATE TABLE test.cards( id integer primary key, set_id integer not null, id_text text not null, name text not null, type_id integer not null, faction_id integer, rarity_id integer, cost int, attack int, health int, text text, flavor text, artist text, durability int, collectible int, how_to_get text, how_to_get_gold text, mechanics text, player_class_id integer, race_id integer, in_play_text text, elite int, foreign key(set_id) references sets(id), foreign key(type_id) references types(id), foreign key(faction_id) references factions(id), foreign key(rarity_id) references rarities(id), foreign key(player_class_id) references player_classes(id), foreign key(race_id) references races(id) );";
  

     if( strcmp( fileName.c_str(), "sqlhearthstone.db" ) != 0 )
     {
         attachDeck( fileName.c_str() );
         int connection = sqlite3_exec( db, stringCommand.c_str(), 0, (void*)data, &err );
         cout << "Deck was created" << endl;
         detachDeck( fileName.c_str() );
     }
     
     else
     {
          int connection = sqlite3_open(fileName.c_str(), &db);
      
          if(connection)
          {
               cout << "Didn't open because of " << sqlite3_errmsg(db) << endl;
               return;
          }
      
          else
          {
               cout << "Deck Opened" << endl;
          }
     }
}

void attachDeck( string deckName )
{
    sqlite3 * db;
    char *err = 0;
    const char* data = "";
    string attach = "ATTACH '" + deckName + "' as 'mytmp'";
    
    int connection = sqlite3_exec( db, attach.c_str(), 0, (void*)data, &err );
    
}

void detachDeck( string deckName )
{
    sqlite3 * db;
    char *err = 0;
    const char* data = "";
    string detach = "detach DATABASE '" + deckName + "'";
    int connection = sqlite3_exec( db, detach.c_str(), 0, (void*)data, &err );
}

void addCardToDeck( int id, string deckName )
{
    sqlite3 * db;
    char *err = 0;
    const char* data = "";
    stringstream out;
    out << id;
    string sId = out.str();

    attachDeck( deckName );
    
    string in = "INSERT INTO '" + deckName + "' SELECT FROM main.cards WHERE id = '" + sId + "'";
    int connection = sqlite3_exec( db, in.c_str(), 0, (void*)data, &err );
    
    detachDeck( deckName );
    
}

void removeCardFromDeck( int id, string deckName )
{
    sqlite3 * db;
    char *err = 0;
    const char* data = "";
    stringstream out;
    out << id;
    string sId = out.str();
    
    attachDeck( deckName );
    
    string in = "DELETE FROM main.cards WHERE id = '" + sId +"'";
 
    int connection = sqlite3_exec( db, in.c_str(), 0, (void*)data, &err );
    
    detachDeck( deckName );
  //Remove the card based on the id
}
