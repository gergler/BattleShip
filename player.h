#ifndef PLAYER_H
#define PLAYER_H

const int EmptyCell = 0, MissedCell = 6, DestroyedCell = 7;
const int N = 10, M = 10, Ships = 10;
const int refHP[Ships] = { 4,3,3,2,2,2,1,1,1,1 };

class Player {

public:

	int cell[10][10]; //ship id by coo
	int hp[Ships]; //health of a ship
	int ships; //ships still alive

	void initPlayer(Player& player) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				player.cell[i][j] = 0;
			}
		}
		player.ships = Ships;
	}

	int isAlive(const Player& p) {
		int ship = 0;
		for (int k = 0; k < 10; k++) {
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < N; j++) {
					if (p.cell[i][j] == refHP[k])
						ship++;
				}
			}
		}
		return ship;
	}

	bool isEmpty(const Player& player, int r0, int c0, int r1, int c1) {
		int r, c;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				r = i;
				c = j;
				if (r0 <= r < r1 && c0 <= c <= c1) {
					if (player.cell[r][c] == 0)
						return true;
					else 
						return false;
				}
			}
		}

	}
};


#endif