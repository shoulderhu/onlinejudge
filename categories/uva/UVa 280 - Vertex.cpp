#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int n, i, j, integer, vertex, counter;
bool accessible[101];
vector<int> edge[101];

void DFS(int v) {

	int size = edge[v].size(), end;

	for (int k = 0; k < size; ++k) {

		end = edge[v][k];

		if (accessible[end] == false) {

			accessible[end] = true;
			--counter;
			DFS(end);
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n && n != 0) {

		for (int k = 1; k <= n; ++k) {

			edge[k].clear();
		}

		while (cin >> i && i != 0) {

			while (cin >> j && j != 0) {

				edge[i].push_back(j);
			}
		}

		cin >> integer;

		for (int k = 0; k < integer; ++k) {

			cin >> vertex;
			counter = n;
			memset(accessible, false, sizeof(bool) * (n + 1));
			DFS(vertex);
			cout << counter;

			for (int l = 1; l <= n; ++l) {

				if (accessible[l] == false) {

					cout << ' ' << l;
				}
			}

			cout << '\n';
		}
	}

	return 0;
}
