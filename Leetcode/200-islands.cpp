/*
*输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

*/
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <stdlib.h>  
#include "ctimer.h"

using namespace std;


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		bool * visited = (bool*)calloc(m*n, sizeof(bool));
		int ret = 0;

		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if (grid[i][j] == '0' || visited[i*n+j])	continue;
				
				++ret;

				// mark all connected node
				queue<pair<int, int>> que;
				que.emplace(i, j);
				while (!que.empty()) {
					auto t = que.front();
					que.pop();
					int x = t.first, y = t.second;
					visited[x*n+y] = true;
					if (x-1 >= 0 && grid[x-1][y] == '1' && !visited[(x-1)*n+y])		{ que.emplace(x-1,y); visited[(x-1)*n+y] = true; }
					if (x+1 < m && grid[x+1][y] == '1' && !visited[(x+1)*n+y])		{ que.emplace(x+1,y); visited[(x+1)*n+y] = true; }
					if (y-1 >= 0 && grid[x][y-1] == '1' && !visited[x*n+y-1])		{ que.emplace(x,y-1); visited[x*n+y-1] = true; }
					if (y+1 < n && grid[x][y+1] == '1' && !visited[x*n+y+1])		{ que.emplace(x,y+1); visited[x*n+y+1] = true; }
				}
			}
		}

		free(visited);
		return ret;
    }
};

class Solution2 {
public:
    int numIslands(vector<vector<char>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		bool * visited = (bool*)calloc(m*n, sizeof(bool));
		int ret = 0;

		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < n; ++j) {
				if (grid[i][j] == '0' || visited[i*n+j])	continue;
				
				++ret;

				// mark all connected node
                dfs(grid, i, j, m, n, visited);
			}
		}

		free(visited);
		return ret;
    }

    void dfs(vector<vector<char>>& grid, int x, int y, int m, int n, bool* visited) {
        if (visited[x*n+y]) return;

        visited[x*n+y] = true;

        if (x-1 >= 0 && grid[x-1][y] == '1' && !visited[(x-1)*n+y])		dfs(grid, x-1, y, m, n, visited);
        if (x+1 < m && grid[x+1][y] == '1' && !visited[(x+1)*n+y])		dfs(grid, x+1, y, m, n, visited);
        if (y-1 >= 0 && grid[x][y-1] == '1' && !visited[x*n+y-1])		dfs(grid, x, y-1, m, n, visited);
        if (y+1 < n && grid[x][y+1] == '1' && !visited[x*n+y+1])		dfs(grid, x, y+1, m, n, visited);
    }
};

int main()
{
    vector<vector<char>> in	{
	{'1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','0','1','0','1','1'},{'0','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','0'},
	{'1','0','1','1','1','0','0','1','1','0','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
	{'1','0','0','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','0','1','1','1','1','1','1','0','1','1','1','0','1','1','1','0','1','1','1'},
	{'0','1','1','1','1','1','1','1','1','1','1','1','0','1','1','0','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','1','1'},
	{'1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
	{'0','1','1','1','1','1','1','1','0','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
	{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','0','1','1','1','1','1','1','1','0','1','1','1','1','1','1'},
	{'1','0','1','1','1','1','1','0','1','1','1','0','1','1','1','1','0','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','1','1','0'},
	{'1','1','1','1','1','1','1','1','1','1','1','1','1','0','1','1','1','1','0','0'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
	{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},{'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}};


	auto t1 = t_now();
    
	// TODO
	Solution s;
	int ret = s.numIslands(in);
	
	auto t2 = t_now();
	t_cal_echo(t1, t2);
	cout << ret << endl;
	
	t1 = t_now();
	Solution2 s2;
	ret = s2.numIslands(in);
	
	t2 = t_now();
	t_cal_echo(t1, t2);
	
	cout << ret << endl;
	
    cin.get();

    return 0;
}
