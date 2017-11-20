#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;
typedef pair<long long, int> Pair;

int n, m, a;
struct to { int b, w; } To;
struct dis { 
	int parent;
	long long path;
} Dis[100001];
vector<to> edge[100001];

inline void Dijkstra() {

	Pair p;
	priority_queue<Pair, vector<Pair>, greater<Pair>> Queue;

	for (int i = 1; i <= n; ++i) {

		Dis[i].parent = i;
		Dis[i].path = LLONG_MAX;
	}

	Dis[1].path = 0;	
	Queue.push(Pair(0, 1));

	while (!Queue.empty()) {

		p = Queue.top();
		Queue.pop();

		if (Dis[p.second].path < p.first) {

			continue;
		}

		for (int i = 0; i < edge[p.second].size(); ++i) {

			To = edge[p.second][i];

			if (Dis[To.b].path > p.first + To.w) {

				Dis[To.b].parent = p.second;
				Dis[To.b].path = p.first + To.w;				
				Queue.push(Pair(Dis[To.b].path, To.b));
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	bool isPath = true;
	vector<int> path;

	cin >> n >> m;

	for (int i = 0; i < m; ++i) {

		cin >> a >> To.b >> To.w;
		edge[a].push_back(To);
		swap(a, To.b);
		edge[a].push_back(To);
	}

	Dijkstra();
	path.push_back(n);

	while (n != 1) {

		if (Dis[n].parent == n) {

			isPath = false;
			break;
		}

		n = Dis[n].parent;
		path.push_back(n);		
	}

	if(isPath) { 
	
		cout << 1;

		for (int i = path.size() - 2; i >= 0; --i) {

			cout << ' ' << path[i];
		}

		cout << '\n';
	}
	else { cout << "-1\n"; }
	
	return 0;
}