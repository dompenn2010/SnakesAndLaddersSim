#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std; // Shouldn't do this...


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
///////////////////////////////////////////
/*
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
*/
///////////////////////////////////////////
bool readInput(int &boardSize, int &gamesToPlay, Entity gameBoard[]) {

	string line;
	ifstream myfile("input.txt");
	if (myfile.is_open())
	{
		int inlineCount = 0;
		int linecount = 0 ;
		int loc = 0;
		int mag;
		string type;

		while (getline(myfile, line, ' '))
		{
			linecount++;
			istringstream iss(line);

			// First line = number of games to play
			if (linecount == 1) {
				gamesToPlay = stoi(line);
			//	cout << line << "\n";
				linecount ++;
			}
			
			// Second = boardSize
			else if (linecount == 2) {
				boardSize = stoi(line);
				Entity *gameBoard = new Entity[boardSize];
			//	cout << "second" << line << "\n";

			}
			 
			else{
				if (iss >> line){	
				
					

					switch (inlineCount){
						case 0 : { 
								loc = stoi(line);
								inlineCount++;
								break;
							}
						case 1 : {
								type = line;
								inlineCount++;
								break;
							}
						default: {	
								mag = stoi(line);
								gameBoard[loc].setMagnitude(mag);
	
								if (type.compare("Snake")){
									gameBoard[loc].setType(Snake);
								}else{
									gameBoard[loc].setType(Ladder);
								}
								cout << "loc: " << loc << " " << "type " << gameBoard[loc].getType() << " " << "mag: " << gameBoard[loc].getMagnitude() << "\n";								
								inlineCount = 0;
								break;
							}
					}		
	



				}
		

				/*
				cout << "!!!!!!!!!" << (iss >> first_on_line);
				gameBoard[first_on_line].setMagnitude(third_on_line);
				gameBoard[first_on_line].setType(Ladder);

				cout << "magnitude is: " << gameBoard[6].getMagnitude();
				*/
			}





		}
		myfile.close();
		return true;
	}

	else cout << "Unable to open file";
	return false;
}
//////////////////////////////////////////

void initBoard(int w, int h  /*, Entity[] e*/);
void constructCreatures(int magnitude);
//void constructBoard(int w, int h);
int roll();
bool battle(Player &p, Entity e, int boardSize);
void playerStats(Player player);
bool processTurn(Entity currentEntity, int boardSize, entityEnum entType);
bool readInput(int &boardSize, int &gamesToPlay/*, Entity &gameBoard[]*/); 

Player player;


int main() {
	
	int gamesPlayed = 0;
	int totalTurns = 0;
	int gamesToPlay;
	int boardSize;

	Entity gameBoard [] = {};

	//Entity gameBoard [] = 

	readInput(boardSize, gamesToPlay, gameBoard);
	system("pause");
	
	

	//Entity *gameBoard = new Entity[]; 
	//Entity gameBoard[];
/*
	gameBoard[6].setMagnitude(8);
	gameBoard[6].setType(Ladder);

	gameBoard[13].setMagnitude(6);
	gameBoard[13].setType(Snake);

	gameBoard[17].setMagnitude(8);
	gameBoard[17].setType(Ladder);

	gameBoard[21].setMagnitude(2);
	gameBoard[21].setType(Snake);

	gameBoard[29].setMagnitude(4);
	gameBoard[29].setType(Ladder);

	gameBoard[35].setMagnitude(8);
	gameBoard[35].setType(Snake);

	gameBoard[40].setMagnitude(5);
	gameBoard[40].setType(Ladder);

*/	
	//int boardSize = (sizeof(gameBoard) / sizeof(*gameBoard));

	for (int i = 0; i < gamesToPlay; i++){

		bool playing = true;			
		gamesPlayed ++;

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
	totalTurns += player.getTurn();
	}

	cout << "Total Turns: " << totalTurns << "\n";
	cout << "Games played: " << gamesPlayed << "\nAverage turns per game: " << ((double)totalTurns/(double)gamesPlayed) << "\n";
	system("pause");
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

/*
void constructBoard(int w, int h) {
	Board gameBoard(w, h);
	cout << "The board is: " << gameBoard.getSize() << "\n";


//	int input;
//	cin >> input; 
	
}
*/

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
/*
void initBoard(int w, int h ) {

	constructBoard(w, h);
	//constructCreatures(e);

}
*/
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
