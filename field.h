#ifndef FIELD_H
#define FIELD_H

#include <iostream>;
#include <cstdlib>;
#include "player.h";
//#include "shoot.h";


//INTERFACE	
void printBoard(Player & p)  //Print the board with the boats placed on it
{
	std::cout << "   0|1|2|3|4|5|6|7|8|9" << std::endl << std::endl;
	for (int i = 0; i < 10; i++)  //column loop
	{
		for (int j = 0; j < 10; j++)  //row loop
		{
			if (j == 0)
			{
				std::cout << i << "  "; //print row number and spaces before new row
			}
			std::cout << p.cell[i][j];
			if (j != 9)
			{
				std::cout << "|";
			}
		}
		std::cout << std::endl; //new line at end of column
	}
	std::cout << std::endl;
	system("pause");
}

//const char EmtyChar = '.', MissedChar = 'o', DestroyedChar = 'X';

void printGameBoard(Player& p1, bool open1, Player& p2, bool open2) //This is the board that is printed for playing the game.  You cannot see the boats
{
	std::cout << "  0|1|2|3|4|5|6|7|8|9" << std::endl << std::endl;
	if (open2) {
		for (int i = 0; i < 10; i++)  //column loop
		{
			for (int j = 0; j < 10; j++)  //row loop
			{
				if (j == 0)
				{
					std::cout << i << '.'; //print row number and spaces before new row
				}
				if (p1.cell[i][j] == 7 || p1.cell[i][j] == 6)  //if the space is a hit, print it
				{
					std::cout<< "X";
				}
				else
					if (p1.cell[i][j] == 9)  //if the space is a miss, print it
					{
						std::cout << "*";
					}
					else
					{
						std::cout << 0;  //otherwise, just print a 0
					}

				if (j != 9)
				{
					std::cout << "|";
				}
			}
			std::cout << std::endl; //new line at end of column
		}
		std::cout << std::endl;
	}
	if (open1) {
		for (int i = 0; i < 10; i++)  //column loop
		{
			for (int j = 0; j < 10; j++)  //row loop
			{
				if (j == 0)
				{
					std::cout << i << '.'; //print row number and spaces before new row
				}
				if (p2.cell[i][j] == 7 || p2.cell[i][j] == 6)  //if the space is a hit, print it
				{
					std::cout << "X";
				}
				else {
					if (p2.cell[i][j] == 9)  //if the space is a miss, print it
					{
						std::cout << "*";
					}
					else
					{
						std::cout << 0;  //otherwise, just print a 0
					}
				}
				if (j != 9)
				{
					std::cout << "|";
				}
			}
			std::cout << std::endl; //new line at end of column
		}
		std::cout << std::endl;
	}
}

/*
//convert row/column number to symbol
char cipher(int n) {
	if ((unsigned)n < 10)
		return '0' + n;
	if ((unsigned)n < 36)
		return 'A' + (n - 10);
	return '?';
}

//print a sequence of column numbers
void drawNumbers() {
	std::cout << "  ";
	for (int i = 0; i < M; i++)
		std::cout << cipher(i);
}

void drawRow(const Player& p, int line, bool open) {
	if (open) {
		std::cout << ' ' << cipher(line);
		for (int j = 0; j < M; ++j) {
			std::cout << ' ';
			cipher(j);
		}
		std::cout << ' ';
	}
}

void draw(const Player& p) {
	drawNumbers();
	drawRow(p, 0, true);
	p.cell;
}

void draw(const Player& p1, bool open1, const Player& p2, bool open2) {
	if (open1) {
		drawNumbers();
		drawRow(p1, 0, open1);
		p1.cell;
	};
	if (open2) {
		drawNumbers();
		drawRow(p2, 0, open2);
		p2.cell;
	};
}
*/

#endif
