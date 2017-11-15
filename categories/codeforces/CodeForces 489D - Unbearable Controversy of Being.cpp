#include <iostream>
#include <vector>

using namespace std;

int n, m, a, b, rhombi = 0;
int damm[3001];
bool isVisit[3001];
vector<int> road[3001];

inline void DFS(int i, int step) {
	
	int r;

	for (int j = 0; j < road[i].size(); ++j) {

		r = road[i][j];

		if (!isVisit[r]) {

			isVisit[r] = true;
			if (step < 2) { DFS(r, step + 1); }
			else { ++damm[r]; }
			isVisit[r] = false;
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);	

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {

		cin >> a >> b;
		road[a].push_back(b);
	}

	for (int i = 1; i <= n; ++i) {

		isVisit[i] = true;			
		DFS(i, 1);

		for (int i = 1; i <= n; ++i) {

			if (damm[i] >= 2) {

				rhombi += damm[i] * (damm[i] - 1) / 2;
			}

			damm[i] = 0;
		}
		
		isVisit[i] = false;
	}

	cout << rhombi << '\n';
	return 0;
}