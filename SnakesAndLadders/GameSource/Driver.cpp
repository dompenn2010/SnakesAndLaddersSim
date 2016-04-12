#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
////////////////////////////////////////////
class  Player{

public:	
	Player()
		: turn(0), location(0)
	{}

	void setLocation(int l){
		location = l;
	}

	int getLocation() {
		return location;
	}

	void nextTurn(){
		turn ++;
	}

	int getTurn(){
		return turn;
	}

private:
	int location;
	int turn;
};


////////////////////////////////////////////
class Entity {

public:	
//	Entity(int m)
//		: magnitude(m)
//	{}

	void setMagnitude(int m){
		magnitude = m;
	}

	int getMagnitude() {
		return magnitude;
	}

private:
	int magnitude;

//	enum entityType;
};

///////////////////////////////////////////
/*class Ladder: public Entity {

public:
	Ladder(int m)
		:Entity(int m) 
	{}
};
////////////////////////////////////////////
class Snake: public Entity {

public:

	Snake(int m)
		: magnitude(m) 
	{}
};*/
/////////////////////////////////////////////
class Board{

public:
	Board(int w, int h)
		: width(w), height(h) 
	{}


	int getSize() {
		return boardSize;
	}

		

	

private:
	int width;
	int height;
//	const int numOfEntities;

	int boardSize = width*height;
	
};
///////////////////////////////////////////
int main() {
	void initBoard(int w, int h  /*, Entity[] e*/);
	void constructCreatures(int magnitude);
	void constructBoard(int w, int h);
	int roll();
	bool playing = true;	


	//constructCreatures(69);

	initBoard(20,20);

	Player playerReady1;
	cout << "Player is at location: " << playerReady1.getLocation() << " and we are on turn: " << playerReady1.getTurn() << "\n";
	
	playerReady1.nextTurn();
	playerReady1.nextTurn();
	playerReady1.setLocation(69);
	
	cout << "Player is at location: " << playerReady1.getLocation() << " and we are on turn: " << playerReady1.getTurn() << "\n";
	
/*
	Entity entityArr[5];

	for (int i = 0; i < 5; i++){
		entityArr[i].setMagnitude(roll());
		cout << "Entity " << i << "'s magnitude is " << entityArr[i].getMagnitude() << "\n";		
	}		
*/	
	while (playing){
	
	
	}	







	return 0;
}



void constructBoard(int w, int h) {
	Board gameBoard(w, h);
	cout << "The board is: " << gameBoard.getSize() << "\n";


//	int input;
//	cin >> input; 
	
}


void constructCreatures(int magnitude) {
/*
	Snake snake1(magnitude);
	cout << "The snake is: " << snake1.getMagnitude() << "\n";

	Ladder ladder1(magnitude);
	cout << "The ladder is: " << ladder1.getMagnitude() << "\n";
*/	
// Implement this later
//	Entity gameBoard[*a];

//	for (int i = 0; i < boardSize - 1; i++) {

//	}

//	return gameBoard;
}


/*Use this to initialize the game - should only take in the board size and location of entities */
void initBoard(int w, int h  /*, Entity[] e*/) {

	constructBoard(w, h);
	//constructCreatures(e);

}

int roll(){

	int roll;
	srand (time(NULL) + clock()); // It just didn't look random enough with one or the other so I used both?

	roll = rand() % 6 + 1;
	

	return roll;
}

bool battle(Player p, Entity e, Board b){
	
	bool didJaWin = false; 

	// Players location = current location + magnitude of entity
	p.setLocation(p.getLocation() + e.getMagnitude());
	
	// If player reaches end of board, win
	if (p.getLocation() >=  b.getSize()){
		didJaWin = true; 
		return didJaWin;
	}
		
	// If snake sends player below location 0, fix it
	if (p.getLocation() < 0 ){
		p.setLocation(0);
	}

	return didJaWin;
}	
