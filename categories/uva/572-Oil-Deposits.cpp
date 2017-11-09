#include <iostream>

using namespace std;

int m, n, deposit;
char grid[100][100];

void DFS(int x, int y) {

    int xi, yi;
    grid[x][y] = '*';

    for (int i = -1; i <= 1; ++i) {

        for (int j = -1; j <= 1; ++j) {

            xi = x + i;
            yi = y + j;

            if (0 <= xi && xi < m &&
                0 <= yi && yi < n &&
                grid[xi][yi] == '@') {
								
                DFS(xi, yi);
            }			
        }
    }
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
		
    while (cin >> m >> n && m != 0) {

        for (int i = 0; i < m; ++i) {

            for (int j = 0; j < n; ++j) {

                cin >> grid[i][j];
            }
        }

        deposit = 0;

        for (int i = 0; i < m; ++i) {

            for (int j = 0; j < n; ++j) {

                if (grid[i][j] == '@') {

                    ++deposit;
                    DFS(i, j);
                }
            }
        }
    } 
  	
    cout << deposit << '\n';  
    return 0;
}
