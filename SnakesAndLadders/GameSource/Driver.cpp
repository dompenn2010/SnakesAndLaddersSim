#include <iostream>
using namespace std;

////////////////////////////////////////////
class Entity {

public:	
	Entity(int m)
		: magnitude(m)
	{}

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

	int boardSize = width*height;
	
};
///////////////////////////////////////////
int main() {
	void initBoard(int w, int h  /*, Entity[] e*/);
	void constructCreatures(int magnitude);
	void constructBoard(int w, int h);
	
	//constructCreatures(69);

	initBoard(20,20);
	
	return 0;
}



void constructBoard(int w, int h) {
	Board gameBoard(w, h);
	cout << "The board is: " << gameBoard.getSize() << "\n";


	int input;
	cin >> input; 
	
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


