#include <bangtal>
#include <iostream>
using namespace std;
using namespace bangtal;

ObjectPtr board[8][8];

enum class State {
	BLANK,
	POSSIBLE,
	BLACK,
	WHITE
};

State board_state[8][8];

enum class Turn {
	BLACK,
	WHITE
};

Turn turn = Turn::BLACK;

void setState(int x, int y, State state)
{
	switch (state) {
	case State::BLANK: board[y][x]->setImage("Images/blank.png"); break;
	case State::POSSIBLE: board[y][x]->setImage(turn == Turn::BLACK?"Images/black possible.png":"Images/white possible.png"); break;
	case State::BLACK: board[y][x]->setImage("Images/black.png"); break;
	case State::WHITE: board[y][x]->setImage("Images/white.png"); break;
	}
	board_state[y][x] = state;
}

bool checkPossible(int x, int y, int dx, int dy) {

	State self = turn == Turn::BLACK ? State::BLACK : State::WHITE;
	State other = turn == Turn::BLACK ? State::WHITE : State::BLACK;

	bool possible = false;
	for (x += dx, y+= dy; x >= 0 && x < 8 && y >= 0 && y < 8; x += dx, y += dy) {
		if (board_state[y][x] == other) {
			possible = true;
		}
		else if (board_state[y][x] == self) {
			return possible;
		}
		else {
			return false;
		}
	}
	return false;
}

bool checkPossible(int x, int y) {
	if (board_state[y][x] == State::BLACK) return false;
	if (board_state[y][x] == State::WHITE) return false;
	setState(x, y, State::BLANK);

	int delta[8][2] = {
		{0, 1},
		{1, 1},
		{1, 0},
		{1, -1},
		{0, -1},
		{-1, -1},
		{-1, 0},
		{-1, 1},
	};
	/*
	for (int i = 0; i < 8; i++) {
		checkPossible(x, y, delta[i][0], delta[i][1]);
	}
	*/
	bool possible = false;
	for (auto d : delta) {
		if(checkPossible(x, y, d[0], d[1])) possible = true;
	}

	return possible;
}
void reverse(int x, int y, int dx, int dy) {
	State self = turn == Turn::BLACK ? State::BLACK : State::WHITE;
	State other = turn == Turn::BLACK ? State::WHITE : State::BLACK;

	bool possible = false;
	for (x += dx, y += dy; x >= 0 && x < 8 && y >= 0 && y < 8; x += dx, y += dy) {
		if (board_state[y][x] == other) {
			possible = true;
		}
		else if (board_state[y][x] == self) {
			if (possible) {
				for (x -= dx, y -= dy; x >= 0 && x < 8 && y >= 0 && y < 8; x -= dx, y -= dy) {
					if (board_state[y][x] == other) {
						setState(x, y, self);
					}
					else {
						return;
					}
				}
			}
		}
		else {
			return;
		}
	}

}

void reverse(int x, int y) {
	int delta[8][2] = {
	{0, 1},
	{1, 1},
	{1, 0},
	{1, -1},
	{0, -1},
	{-1, -1},
	{-1, 0},
	{-1, 1},
	};

	bool possible = false;
	for (auto d : delta) {
		reverse(x, y, d[0], d[1]);
	}

}
bool setPossible() {
	//8*8의 모든 위치에 대해서 놓여질 수 있으면 POSSIBLE로 바꾼다.
	bool possible = false;
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (checkPossible(x, y)) {
				setState(x, y, State::POSSIBLE);
				possible = true;
			}
		}
	}
	return possible;
}

int main() {


	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);

	auto scene = Scene::create("Othello", "Images/background.png");
	auto bnum = 0, wnum = 0;
	auto bnum2 = 0, wnum2 = 0;
	auto bnum1 = 0, wnum1 = 0;


	ObjectPtr B2[10];
	ObjectPtr B1[10];
	ObjectPtr W2[10];
	ObjectPtr W1[10];

	for (int i = 0; i < 10; i++) {
		string filename = "Images/L" + to_string(i) + ".png";

		B2[i] = Object::create(filename, scene, 750, 220);
		B1[i] = Object::create(filename, scene, 830, 220);
		B2[i]->hide();
		B1[i]->hide();


		W2[i] = Object::create(filename, scene, 1070, 220);
		W1[i] = Object::create(filename, scene, 1150, 220);
		W2[i]->hide();
		W1[i]->hide();

	}
	B1[2]->show();
	W2[2]->show();

	for (int p = 0; p < 8; p++) {
		for (int q = 0; q < 8; q++) {
			if (board_state[p][q] == State::POSSIBLE) {
				if (turn == Turn::WHITE) {
					setState(p, q, State::WHITE);
					reverse(p, q);
					turn = Turn::BLACK;
				}
			}
		}
	}
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			board[y][x] = Object::create("Images/blank.png", scene, 40 + x * 80, 40 + y * 80);
			board[y][x]->setOnMouseCallback([&, x, y](ObjectPtr object, int mx, int my, MouseAction action) -> bool {
				if (board_state[y][x] == State::POSSIBLE) {
					if (turn == Turn::BLACK) {
						setState(x, y, State::BLACK);
						reverse(x, y);
						turn = Turn::WHITE;

					}
					else {
						setState(x, y, State::WHITE);
						reverse(x, y);
						turn = Turn::BLACK;
					}
					if (!setPossible()) { 
						turn = turn == Turn::BLACK ? Turn::WHITE : Turn::BLACK; //toggle
						if (!setPossible()) {
							showMessage("End Game");
						}
					}
				}

				for (int a = 0; a < 8; a++) {
					for (int b = 0; b < 8; b++) {
						if (board_state[a][b] == State::BLACK) {
							bnum++;
							bnum2 = bnum;
							bnum1 = bnum;
						}
						else if (board_state[a][b] == State::WHITE) {
							wnum++;
							wnum2 = wnum;
							wnum1 = wnum;
						}
					}
				}
				cout << bnum;
				cout << wnum << endl;
				for (int k = 0; k < 10; k++) {
					B2[k]->hide();
					B1[k]->hide();
					W2[k]->hide();
					W1[k]->hide();
				}

				bnum2 /= 10;
				wnum2 /= 10;

				bnum1 %= 10;
				wnum1 %= 10;

				if (bnum2 < 1 && wnum2 < 1) {
					B2[bnum2]->hide();
					W2[wnum1]->show();
				}
				else if(bnum2 >=1 && wnum2 >= 1){
					B2[bnum2]->show();
					W2[wnum2]->show();
				}
				else if (bnum2 >= 1 && wnum2 < 1) {
					B2[bnum2]->show();
					W2[wnum1]->show();
				}
				else if (wnum2 >= 1 && bnum2 < 1) {
					W2[wnum2]->show();
					B2[bnum2]->hide();
				}

				B1[bnum1]->show();
				if (wnum >= 10) {
					W1[wnum1]->show();
				}
				bnum = 0, bnum1 =0, bnum2 = 0;
				wnum = 0, wnum1 = 0,wnum2 = 0;
				return true;
				});
			board_state[y][x] = State::BLANK;
			
		}
	}




	setState(3, 3, State::BLACK);
	setState(4, 4, State::BLACK);
	setState(3, 4, State::WHITE);
	setState(4, 3, State::WHITE);

	setPossible();

	startGame(scene);
	
}