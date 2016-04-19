#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std; // Shouldn't do this...

////////////////////////////////////////////
class  Player {

public:
	Player()
		: turn(1), location(0)
	{}

	void setLocation(int l) {
		location = l;
	}

	int getLocation() {
		return location;
	}

	void nextTurn(int roll) {
		turn++;
		location += roll;
	}

	int getTurn() {
		return turn;
	}

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

	void setMagnitude(int m) {
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
bool readInput(int &boardSize, int &gamesToPlay, Entity gameBoard[]) {

	string line;
	ifstream myfile("input.txt");
	if (myfile.is_open())
	{
		int inlineCount = 0;
		int linecount = 0;
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
					cout << "One: " << line << "\n";

					linecount++;
			}else if(linecount == 2) {
				boardSize = stoi(line);
				Entity *gameBoard = new Entity[boardSize];

				cout << "Two: " << line << "\n";

			}else {
				if (iss >> line) {

					switch (inlineCount) {
					case 0: {
						loc = stoi(line);
						inlineCount++;
						break;
					}
					case 1: {
						type = line;
						inlineCount++;
						break;
					}
					default: {
						mag = stoi(line);
						gameBoard[loc].setMagnitude(mag);

						if (type.compare("Snake")) {
							gameBoard[loc].setType(Snake);
						}
						else if (type.compare("Ladder")) {
							gameBoard[loc].setType(Ladder);
						}
						cout << "loc: " << loc << " " << "type " << gameBoard[loc].getType() << " " << "mag: " << gameBoard[loc].getMagnitude() << "\n";
						inlineCount = 0;
						break;
					}
					}
				}
			}
		}
		myfile.close();
		return true;
	}

	else cout << "Unable to open file";
	return false;
}
//////////////////////////////////////////
int roll();
bool battle(Player &p, Entity e, int boardSize);
void playerStats(Player player);
bool processTurn(Entity currentEntity, int boardSize, entityEnum entType);
bool readInput(int &boardSize, int &gamesToPlay, Entity gameBoard[]);

Player player;


int main() {

	bool boardConstructed = false;
	int gamesPlayed = 0;
	int totalTurns = 0;
	int gamesToPlay;
	int boardSize;
	Entity *gameBoard;

	readInput(boardSize, gamesToPlay, gameBoard);


	for (int i = 0; i < gamesToPlay; i++) {

		bool playing = true;
		gamesPlayed++;

		// Game Loop
		while (playing) {
			Entity currentEntity = gameBoard[player.getLocation()];

			playerStats(player);

			player.nextTurn(roll());

			if (processTurn(currentEntity, boardSize, currentEntity.getType())) {
				cout << "You Won in " << player.getTurn() << " turns!! Congratulations!\n\n";
				playing = false;
				break;
			}

		}
		totalTurns += player.getTurn();
	}

	cout << "Total Turns: " << totalTurns << "\n";
	cout << "Games played: " << gamesPlayed << "\nAverage turns per game: " << ((double)totalTurns / (double)gamesPlayed) << "\n";

	system("pause");
	return 0;
}

bool processTurn(Entity currentEntity, int boardSize, entityEnum entType) {

	if (battle(player, currentEntity, boardSize)) {
		return true;
	}

	return false;
}

void playerStats(Player player) {

	cout << "\nStats!\n" << "Players location: " << player.getLocation() << "\n";
	cout << "Current Turn: " << player.getTurn() << "\n\n\n";

}

int roll() {

	int roll;
	srand(time(NULL) + clock()); // It just didn't look random enough with one or the other so I used both?

	roll = rand() % 6 + 1;

	cout << "You rolled a " << roll << "!\n";
	return roll;
}

// In the event that a player reaches an entity, adjust location based on entity type
bool battle(Player &p, Entity e, int boardSize) {
	int initialLoc = p.getLocation();
	int entityMag = e.getMagnitude();
	entityEnum entityType = e.getType();
	bool didJaWin = false;

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
