#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, p, groupMax;
vector<int> manager;
vector<int> superior[2001];

void DFS(int m, int group) {

	groupMax = max(group, groupMax);

	for (int i = 0; i < superior[m].size(); ++i) {
				
		DFS(superior[m][i], group + 1);		
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
		
	cin >> n;

	for (int i = 1; i <= n; ++i) {

		cin >> p;

		if (p == -1) {

			manager.push_back(i);
		}
		else {

			superior[p].push_back(i);
		}
	}

	groupMax = 1;

	for (int i = 0; i < manager.size(); ++i) {
				
		DFS(manager[i], 1);
	}

	cout << groupMax << endl;
	return 0;
}