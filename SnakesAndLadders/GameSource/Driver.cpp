#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;
////////////////////////////////////////////
class  Player{

public:	
	Player()
		: turn(1), location(0)
	{}

	void setLocation(int l){
		location = l;
	}

	int getLocation() {
		return location;
	}

	void nextTurn(int roll){
		turn++;
		location += roll;
	}

	int getTurn(){
		return turn;
	}

	//void playerRoll() {
	//	location += roll();
	//}

private:
	int location;
	int turn;
};

enum entityEnum {

	Snake,
	Ladder,
	Vacant
};

////////////////////////////////////////////
class Entity {

public:	
	Entity()
	{}

	Entity(int m, entityEnum e)
		: magnitude(m), entityType(e)
	{}

	void setMagnitude(int m){
		magnitude = m;
	}

	int getMagnitude() {
		return magnitude;
	}

	void setType(entityEnum e) {
		entityType = e;
	}

	entityEnum getType() {
		return entityType;
	}

private:
	int magnitude;
	entityEnum entityType;
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
void initBoard(int w, int h  /*, Entity[] e*/);
void constructCreatures(int magnitude);
void constructBoard(int w, int h);
int roll();
bool battle(Player &p, Entity e, int boardSize);
void playerStats(Player player);
bool processTurn(Entity currentEntity, int boardSize, entityEnum entType);

Player player;

int main() {
	

	bool playing = true;	

	//initBoard(20,20);
	
	

	
	//Entity *gameBoard = new Entity[2]; 
	Entity gameBoard[10];

	gameBoard[0].setMagnitude(1);
	gameBoard[0].setType(Snake);

	gameBoard[1].setMagnitude(2);
	gameBoard[1].setType(Snake);

	gameBoard[2].setMagnitude(3);
	gameBoard[2].setType(Snake);

	gameBoard[3].setMagnitude(4);
	gameBoard[3].setType(Ladder);

	gameBoard[4].setMagnitude(5);
	gameBoard[4].setType(Snake);

	gameBoard[5].setMagnitude(6);
	gameBoard[5].setType(Snake);

	gameBoard[6].setMagnitude(7);
	gameBoard[6].setType(Ladder);

	gameBoard[7].setMagnitude(8);
	gameBoard[7].setType(Snake);

	gameBoard[8].setMagnitude(9);
	gameBoard[8].setType(Snake);

	gameBoard[9].setMagnitude(10);
	gameBoard[9].setType(Snake);
	
/*	for (int i = 0; i < 20 ; i++) {
		gameBoard[i].setMagnitude(4);
		gameBoard[i].setType(Snake);

		 if (i % 3 == 0) {
			gameBoard[i].setType(Ladder);
		}
		else if (i % 2 == 0) {
			gameBoard[i].setType(Snake);
		}
		
	}
*/
	
	int boardSize = (sizeof(gameBoard) / sizeof(*gameBoard));

	// Game Loop
	while (playing) {
		Entity currentEntity = gameBoard[player.getLocation()];

		playerStats(player);
		
		player.nextTurn(roll());

		

		// processTurn = true,
		if (processTurn(currentEntity, boardSize, currentEntity.getType())) {
			cout << "You Won in " << player.getTurn() << " turns!! Congratulations!\n\n";
			playing = false;
			break;
		}
		
	}
	//system("pause");

	return 0;
}

bool processTurn(Entity currentEntity, int boardSize, entityEnum entType) {
	//if (entType != NULL) {

		if (battle(player, currentEntity, boardSize)) {
			return true;
		}
	//}
	
	return false;
}

void playerStats(Player player) {

	cout << "\nStats!\n" << "Players location: " << player.getLocation() << "\n";
	cout << "Current Turn: " << player.getTurn() << "\n\n\n";

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
	
	cout << "You rolled a " << roll << "!\n";
	return roll;
}

// In the event that a player reaches an entity, adjust location based on entity type
bool battle(Player &p, Entity e, int boardSize){
	int initialLoc = p.getLocation();
	int entityMag = e.getMagnitude();
	entityEnum entityType = e.getType();
	bool didJaWin = false; 

	// Fix this... Calling this twice is stupid.	
	// If player reaches end of board, win
	if (p.getLocation() >= boardSize) {
		didJaWin = true;
		return didJaWin;
	}

	
	// Players location = current location + magnitude of entity
	if (entityType == Snake) {
		cout << "You hit a snake at location: " << initialLoc << " with a magnitude of " << entityMag << "\n";
		p.setLocation(p.getLocation() - entityMag);
	}
	if (entityType == Ladder) {
		cout << "You a found a ladder at location: " << initialLoc << " with a magnitude of " << entityMag << "\n";
		p.setLocation(p.getLocation() + entityMag);

	}if (entityType == Vacant) {
		cout << "NOTHINGS HERE, FREDDIE!!!";
	}


	// If snake sends player below location 0, fix it
	if (p.getLocation() < 0) {
		p.setLocation(0);
	}


	// If player reaches end of board, win
	if (p.getLocation() >= boardSize) {
		didJaWin = true;
		return didJaWin;
	}


	return didJaWin;
}	
