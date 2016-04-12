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
	Ladder
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
int main() {
	void initBoard(int w, int h  /*, Entity[] e*/);
	void constructCreatures(int magnitude);
	void constructBoard(int w, int h);
	int roll();
	bool battle(Player p, Entity e, int boardSize);
	void playerStats(Player player);

	bool playing = true;	

	//initBoard(20,20);
	
	Player player;

	
	Entity gameBoard[25];

	for (int i = 0; i < 5; i++) {
		gameBoard[i].setMagnitude(1);
		gameBoard[i].setType(Ladder);
	}


	// Game Loop
	while (playing) {

		playerStats(player);
		
		player.nextTurn(roll());

		if (gameBoard[player.getLocation()].getType() != NULL) {

			if (battle(player, gameBoard[player.getLocation()], (sizeof(gameBoard) / sizeof(*gameBoard)))) {
				cout << "You Won! Congratulations!\n\n";
				playing = false; 
				break;
			}
		}

	}
	system("pause");




/*
		
*/
	return 0;
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
bool battle(Player p, Entity e, int boardSize){
	int initialLoc = p.getLocation();
	bool didJaWin = false; 

	// Players location = current location + magnitude of entity
	if (e.getType() == Snake) {
		p.setLocation(p.getLocation() - e.getMagnitude());
		cout << "You hit a snake at location: " << initialLoc << " with a magnitude of " << e.getMagnitude() << "\n";
	}
	else {
		p.setLocation(p.getLocation() + e.getMagnitude());
		cout << "You a found a ladder at location: " << initialLoc << " with a magnitude of " << e.getMagnitude() << "\n";

	}
	
	// If player reaches end of board, win
	if (p.getLocation() >=  boardSize){
		didJaWin = true; 
		return didJaWin;
	}
		
	// If snake sends player below location 0, fix it
	if (p.getLocation() < 0 ){
		p.setLocation(0);
	}

	return didJaWin;
}	
