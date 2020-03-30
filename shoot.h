#ifndef SHOOT_H
#define SHOOT_H

#include <iostream>;
#include "player.h";
#include "field.h";

void shootResult(Player & p1, Player & p2) {
	std::cout << "Choose where to shoot, Player: ";
	int x, y;
	std::cin >> x >> y;
	if (x < 0 || y < 0 || x > M || y > N) {
		std::cout << "\nYour coordinates are suks, try again \n";
		shootResult(p1, p2);
	}
	else {
		if (p2.cell[x][y] != 0) {
			int hp = p2.cell[x][y];
			if (hp == 0) {
				std::cout << std::endl << "U Killed\n " << std::endl;
				p2.cell[x][y] = 6; //Killed
				std::cout << "U shoot again!\n " << std::endl;
				shootResult(p1, p2);
			}
			else {
				std::cout << std::endl << "U Hit\n" << std::endl;
				p2.cell[x][y] = 7; //Hit
				std::cout << "U shoot again!\n " << std::endl;
				shootResult(p1, p2);
			}
		}
		else {
			std::cout << std::endl << "U Missed\n " << std::endl;
			p2.cell[x][y] = 9; //missed cell
		}
	}
}



#endif 

