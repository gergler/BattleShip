/*
метод Shoot по координатам
getType(coo) when we shoot 
Arena (драйвер нашей игры) - включение игры, инициализация -> поля -> chose strategy -> tactika for gamers 
	Gamer
	Field - агрегирование (?)
	Ships
G_Strategy - один класс, из которого можно наследовать стратегии

Разговор с игроком 

адапторы ооп - даёт только те методы, которые разрешены 
*/
#include <iostream>;
#include <cstdlib>;
#include <ctime>;

#include "player.h";
#include "shoot.h";
#include "field.h";
#include "ship.h";
#include "shoot.h";
#include "strategy.h";


	

void playgame () {
	srand((unsigned)time(nullptr)); 
	Player p1;
	Player p2;
	putShips(1, p1);
	putShips(2, p2);
	int turn = 1, x, y;
	while ((p1.isAlive(p1) != 0) && (p2.isAlive(p2) != 0)) {
		if (turn % 2 != 0) {
			std::cout << "\nBoard Player 1\n" << std::endl;
			printGameBoard(p1, true, p2, false);
			shootResult(p1, p2);
			printGameBoard(p1, true, p2, false);
		}
		else {
			std::cout << "\nBoard Player 2\n" << std::endl;
			printGameBoard(p1, false, p2, true);
			shootResult(p2, p1);
			printGameBoard(p1, false, p2, true);
		}
		turn++;
	}
	if (p1.isAlive(p1) != 0)
		std::cout << "Player 1 is WINNER!";
	else
		std::cout << "Player 2 is WINNER!";
}

int main() {
	std::cout << "BattleShip \n";
	char c = 'no';
	do {
		playgame();
		std::cout << "Repeat the game? (yes/no) ";
		std::cin >> c;
	} while (c == 'yes');
}



