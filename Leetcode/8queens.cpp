#include <iostream>
#include <array>
#include "ctimer.h"

using namespace std;

#define N 8

static int count = 0;

bool isOK(array<int, N>& col,int row)
{
	for(int i = 1, j = row - 1 ; j >= 0; --j, ++i) {
			if (col[j] == col[row])
				return false;
			if (col[row] - i == col[j] || col[row] + i == col[j])
				return false;
	}
	
	return true;
}

void print(array<int, N>& col)
{
	++count;
	cout << endl;
	
	for (int i = 0; i < N; ++i) {
		cout << endl;
		for (int j = 0; j < N; ++j) {
			if (col[i] != j) cout << " * ";
			else cout << " Q ";
		}
		
		cout << endl;
	}
	
	cout << endl;
}


void func(array<int, N>& col, int row = 0)
{
	if (N == row) { print(col); return; }
	
	for (int i = 0; i < N; ++i) {
		col[row] = i;
		if (isOK(col, row))
			func(col, row+1);
	}
}

int main()
{
    array<int, N> col;
    
	for (int i = 0 ; i < N; ++i)
		col[i] = -1;
	
	auto t1 = t_now();
    
	// TODO
	func(col);
	
	auto t2 = t_now();
	t_cal_echo(t1, t2);
	

	cout << count << endl;

    return 0;
}
