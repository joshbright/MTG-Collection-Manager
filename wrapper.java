
public class wrapper {

	/*int id;
	String name;
	int cost;
	String rules;
	int atk;
	int def;
	String location;
    Vector<Card> cards;
	*/
	
	// 
	//Native method declarations
	//
	
	
	//public native Card(){}; 
	
	public native int getId();
	
	public native String getName();
	
	public native int getCost();
	
	public native String getRules();
	
	public native int getAtk();
	
	public native int getDef();
	
	public native void setID(int newID);
	
	public native void setCost(int newCost);
		
	public native void setRules(String newRules);
		
	public native void setAtk(int newAtk);
		
	public native void setDef(int newDef);
	
	
	
	//public native Deck(){};
	
	public native void getCardsFromFile(String fileName);
	
	public native void setName(String newName);
		
	public native void setLocation(String newLocation);
	
	//public native void addCard(Card addition); 
		 
	//public native void removeCard(Card &out); 
	
	public native String getTerm();
	
	public native String getOption();
	
	public native int outputNumberofCards();
		
	public native String outputDeckName();
	
	public native String outputLocation();
	
    //public native static int callback(void *data, int argc, char **argv, char **colName);

    //public native String catchSearch(String input, String option);
	

	
	public native void openDeck(String fileName);
	
	public native void attachDeck(String deckName);
	
	public native void detachDeck(String deckName);
	
	public native void addCardToDeck(int id, String deckName);
	
	public native void removeCardFromDeck(int id, String deckName);
	
	
	static
	{
	  System.loadLibrary("wrapper");
		
	}
	
	
}
	
	

	
	


