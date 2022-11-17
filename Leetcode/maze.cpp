/*
给一个矩阵，.代表可以通过，*代表不可以通过
左上角为起点，右下角为终点，每一步可以上下左右走一格
求出左上角走到右下角的最少步数

输入：
行数n，列数m
一个n×m的矩阵

如：
9 13
....*........
...*......*..
..*.....***..
..*..........
..*....***...
..**......*..
.*..***...*..
..........*..
..........*..
输出
30
*/

int calc (char** matrix, int col, int row) {
	bool step[m][n];
  
  queue<pair<int, int>>que;
  
  que.emplace(0,0);
  int step = 0;
  
  while (!que.empty) {
  	t = que.top();
    que.pop();
    
    ++step;
    if (t.x == col && t.y == row)	return step;
    
    if (x-1 >= 0 && matrix[x-1][y] == '.') { que.emplace(x-1, y); step[x-1][y] = true;}
    if (y-1 >= 0  && matrix[x][y-1] == '.') { que.emplace(x, y-1); step[x][y-1] = true;}
    if (y+1 <= row  && matrix[x][y+1] == '.') { que.emplace(x, y+1); step[x][y+1] = true;}
    if (x+1 <= col  && matrix[x+1][y] == '.') { que.emplace(x+1, y); step[x+1][y] = true;}
  }
}