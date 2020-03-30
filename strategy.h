#ifndef STRATEDY_H
#define STRATEGY_H

#include <iostream>;
#include "player.h";

//x - colmns
//y - rows

bool putVertical(Player& p, int shipSize, int dir, int x, int y) {
	if (dir == 1) { //down
		if ((x + shipSize) < 0 || y < 0 || (x + shipSize) > 9 || y > 9)
			return false;
		else {
			for (int i = 0; i < shipSize; i++) {
				if (p.cell[x + i][y] == 0 && p.cell[x + i][y + 1] == 0 && p.cell[x + i][y - 1] == 0 && p.cell[x - 1][y] == 0 && p.cell[x - 1][y + 1] == 0 && p.cell[x - 1][y - 1] == 0 && p.cell[x + i + 1][y] == 0 && p.cell[x + i + 1][y + 1] == 0 && p.cell[x + i + 1][y - 1] == 0) {}
				else
					return false;
			}
			return true;
		}
	}
	else { //up
		if ((x - shipSize) < 0 || y < 0 || (x - shipSize) > 9 || y > 9)
			return false;
		else {
			for (int i = 0; i < shipSize; i++) {
				if (p.cell[x - i][y] == 0 && p.cell[x - i][y + 1] == 0 && p.cell[x - i][y - 1] == 0 && p.cell[x - i - 1][y] == 0 && p.cell[x - i - 1][y + 1] == 0 && p.cell[x - i - 1][y - 1] == 0 && p.cell[x + 1][y] == 0 && p.cell[x + 1][y + 1] == 0 && p.cell[x + 1][y - 1] == 0) {}
				else
					return false;
			}
			return true;
		}
	}
}

bool putHorizontal(Player& p, int shipSize, int dir, int x, int y) {
	if (dir == 1) { //right
		if (x < 0 || (y + shipSize) < 0 || x > 9 || (y + shipSize) > 9)
			return false;
		else {
			for (int i = 0; i < shipSize; i++) {
				if (p.cell[x][y + i] == 0 && p.cell[x + 1][y + i] == 0 && p.cell[x - 1][y + i] == 0 && p.cell[x + 1][y - 1] == 0 && p.cell[x - 1][y - 1] == 0 && p.cell[x][y - 1] == 0 && p.cell[x - 1][y + i + 1] == 0 && p.cell[x][y + i + 1] == 0 && p.cell[x + 1][y + i + 1] == 0) {}
				else
					return false;
			}
			return true;
		}
	}
	else { //left
		if (x < 0 || (y - shipSize) < 0 || x > 9 || (y - shipSize) > 9)
			return false;
		else {
			for (int i = 0; i < shipSize; i++) {
				if (p.cell[x][y - i] == 0 && p.cell[x + 1][y - i] == 0 && p.cell[x - 1][y - i] == 0 && p.cell[x + 1][y - i - 1] == 0 && p.cell[x][y - i - 1] == 0 && p.cell[x - 1][y - i - 1] == 0 && p.cell[x + 1][y + 1] == 0 && p.cell[x - 1][y + 1] == 0 && p.cell[x][y + 1] == 0) {}
				else
					return false;
			}
			return true;
		}
	}
}

void MegaStrategy(Player& p) { // y, x
	p.cell[0][0] = 1;
	p.cell[9][9] = 1;
	p.cell[0][9] = 1;
	p.cell[9][0] = 1;
	p.cell[0][2] = 2;
	p.cell[1][2] = 2;
	p.cell[9][7] = 2;
	p.cell[8][7] = 2;
	p.cell[0][7] = 2;
	p.cell[1][7] = 2;
	p.cell[3][8] = 3;
	p.cell[4][8] = 3;
	p.cell[5][8] = 3;
	p.cell[4][5] = 3;
	p.cell[4][3] = 3;
	p.cell[4][4] = 3;
	p.cell[7][3] = 3;
	p.cell[7][4] = 3;
	p.cell[7][5] = 3;
	p.cell[4][1] = 4;
	p.cell[5][1] = 4;
	p.cell[6][1] = 4;
	p.cell[7][1] = 4;
}

void randomPlaceShip(Player & p, int shipSize, int x, int y) { 
	int random = rand() % 2 + 1;
	int dir = rand() % 2 + 1;
	if (random == 1) {
		if (dir == 1) {
			if (putVertical(p, shipSize, dir, x, y)) {
				for (int k = 0; k < shipSize; k++)
					p.cell[x + k][y] = shipSize;
			}
			else {
				randomPlaceShip(p, shipSize, x, y);
			}
		}
		if (dir == 2) {
			if (putVertical(p, shipSize, dir, x, y)) {
				for (int k = 0; k < shipSize; k++)
					p.cell[x - k][y] = shipSize;
			}
			else {
				randomPlaceShip(p, shipSize, x, y);
			}
		}
	}
	if (random == 2) {
		if (dir == 1) {
			if (putHorizontal(p, shipSize, dir, x, y)) {
				for (int k = 0; k < shipSize; k++)
					p.cell[x][y + k] = shipSize;
			}
			else {
				randomPlaceShip(p, shipSize, x, y);
			}
		}
		if (dir == 2) {
			if (putHorizontal(p, shipSize, dir, x, y)) {
				for (int k = 0; k < shipSize; k++)
					p.cell[x][y - k] = shipSize;

			}
			else {
				randomPlaceShip(p, shipSize, x, y);
			}
		}
	}
}

bool check(Player & p, int x, int y) {
	if (p.cell[x][y] == 0 && p.cell[x + 1][y] == 0 && p.cell[x - 1][y] == 0 && p.cell[x][y + 1] == 0 && p.cell[x][y - 1] == 0 && p.cell[x - 1][y + 1] == 0 && p.cell[x - 1][y - 1] == 0 && p.cell[x + 1][y + 1] == 0 && p.cell[x + 1][y - 1] == 0) {
		return true;
	}
	else {
		return false;
	}
}

void randomPutShips(Player& p) {
	int x = rand() % M;
	int y = rand() % N;
	for (int i = 0; i < 10; i++) {
		int shipSize = refHP[i];
		while (!check(p, x, y)) {
			x = rand() % M;
			y = rand() % N;
		}
	randomPlaceShip(p, shipSize, x, y);
	}
}

void userPlaceShip(Player& p, int shipSize, int x, int y) {
		int orient, dir;
		std::cout << "\nHow ? (ver - 1; hor - 2) ";
		std::cin >> orient;
		if (orient == 1) {
			std::cout << "\nIn which side ? (down - 1; up - 2) ";
			std::cin >> dir;
			if (dir == 1) {
				for (int j = 0; j < shipSize; j++) {
					if (putVertical(p, shipSize, dir, x, y)) {
						for (int k = 0; k < shipSize; k++)
							p.cell[x + k][y] = shipSize;
					}
					else {
						std::cout << "\nYou went beyond the field\n" << std::endl;
						userPlaceShip(p, shipSize, x, y);
					}
				}
				printBoard(p);
			}
			if (dir == 2) {
				for (int j = 0; j < shipSize; j++) {
					if (putVertical(p, shipSize, dir, x, y)) {
						for (int k = 0; k < shipSize; k++)
							p.cell[x - k][y] = shipSize;
					}
					else {
						std::cout << "\nYou went beyond the field\n" << std::endl;
						userPlaceShip(p, shipSize, x, y);
					}
				}
				printBoard(p);
			}
		}
		if (orient == 2) {
			std::cout << "\nIn which side ? (right - 1; left - 2) ";
			std::cin >> dir;
			if (dir == 1) {
				for (int j = 0; j < shipSize; j++) {
					if (putHorizontal(p, shipSize, dir, x, y)) {
						for (int k = 0; k < shipSize; k++)
							p.cell[x][y + k] = shipSize;
					}
					else {
						std::cout << "\nYou went beyond the field\n" << std::endl;
						userPlaceShip(p, shipSize, x, y);
					}
				}
				printBoard(p);
			}
			if (dir == 2) {
				for (int j = 0; j < shipSize; j++) {
					if (putHorizontal(p, shipSize, dir, x, y)) {
						for (int k = 0; k < shipSize; k++)
							p.cell[x][y - k] = shipSize;
					}
					else {
						std::cout << "\nYou went beyond the field\n" << std::endl;
						userPlaceShip(p, shipSize, x, y);
					}
				}
				printBoard(p);
			}
		}
}

void userPutShips(Player& p) {
	int shipSize, x, y;
	for (int i = 0; i < 10; i++) {
		int shipSize = refHP[i];
		std::cout << "Now you place " << shipSize << " deck ship " << std::endl;
		std::cout << "Where? (write coordinats from 0 to 9 twice - VER/HOR) ";
		std::cin >> x >> y;
		if (p.cell[x][y] == 0 && p.cell[x + 1][y] == 0 && p.cell[x - 1][y] == 0 && p.cell[x][y + 1] == 0 && p.cell[x][y - 1] == 0 && p.cell[x - 1][y + 1] == 0 && p.cell[x - 1][y - 1] == 0 && p.cell[x + 1][y + 1] == 0 && p.cell[x + 1][y - 1] == 0) {
			userPlaceShip(p, shipSize, x, y);
		}
		else {
			std::cout << "\nYou can't use this coordinates(because there are full or near full coordinates), please try another coordinates\n" << std::endl;
			std::cout << "Now you place " << shipSize << " deck ship " << std::endl;
			std::cout << "Where? (write coordinats from 0 to 9 twice - VER/HOR) ";
			std::cin >> x >> y;
			userPlaceShip(p, shipSize, x, y);
		}
	}
}

	void putShips(int i, Player& p) {
		std::cout << "Hi, Player " << i << "!" << std::endl;
		p.initPlayer(p); //clear field
		std::cout << "Choose strategy: User - 1/ Random - 2/ MegaStrategy - 3" << std::endl;
		int strategy;
		std::cin >> strategy;
		if (strategy == 1) {
			userPutShips(p);
		}
		if (strategy == 2) {
			randomPutShips(p);
		}
		if (strategy == 3) {
			MegaStrategy(p);
			std::cin.get();
		}
		printBoard(p);
		std::cin.get();
		system("cls");
	}	

#endif 
