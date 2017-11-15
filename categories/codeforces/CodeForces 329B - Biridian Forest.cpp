#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c, node = 0, moves, battle = 0;
int dir[4][2] = { { 0, -1 },{ -1, 0 },{ 0, 1 },{ 1, 0 } };
char forest[1000][1000];
struct pos { int x, y; }E, P, p;
struct breeder { int X, step; }b;
vector<struct breeder> B;

inline void BFS(struct pos &E) {

	int size, step = 0;
	char f;
	queue<struct pos> Queue;
	Queue.push(E);

	while (!Queue.empty()) {

		if (node == 0) { break; }
		size = Queue.size();
		++step;
		
		for (int i = 0; i < size; ++i) {

			P = Queue.front();
			Queue.pop();

			for (int j = 0; j < 4; ++j) {

				p.x = P.x + dir[j][0];
				p.y = P.y + dir[j][1];
				f = forest[p.x][p.y];

				if (0 <= p.x && p.x < r &&
					0 <= p.y && p.y < c &&					
					f != 'T') {

					if (f == 'S') {

						moves = step;
						--node;
					}
					else if (f != '0') {

						b.X = f - '0';
						b.step = step;		
						B.push_back(b);
						--node;
					}

					forest[p.x][p.y] = 'T';
					Queue.push(p);
				}
			}			
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; ++i) {

		for (int j = 0; j < c; ++j) {

			cin >> forest[i][j];			
			
			switch (forest[i][j]) {

			case '0':
			case 'T':
				continue;
			case 'E':
				E.x = i;
				E.y = j;
				forest[i][j] = 'T';
				break;
			default:
				++node;
				break;
			}			
		}
	}

	BFS(E);

	for (int i = 0; i < B.size(); ++i) {

		if (moves >= B[i].step) {

			battle += B[i].X;
		}
	}

	cout << battle << '\n';
	return 0;
}