#include <iostream>
using namespace std;

class Snake {

};

class Entity {

private:
	int magnitude;
	enum entityType;
};

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

int main() {
	void initBoard(int w, int h  /*, Entity[] e*/);
	void constructCreatures();
	void constructBoard(int w, int h);




	initBoard(20,20);
	
	return 0;
}



void constructBoard(int w, int h) {
	Board gameBoard(w, h);
	cout << "The board is: " << gameBoard.getSize() << "\n";

	system("pause");
}


void constructCreatures(int boardSize) {

	
	Entity gameBoard[*a];

	for (int i = 0; i < boardSize - 1; i++) {

	}

	return gameBoard;



}


/*Use this to initialize the game - should only take in the board size and location of entities */
void initBoard(int w, int h  /*, Entity[] e*/) {

	constructBoard(w, h);
	//constructCreatures(e);

}


