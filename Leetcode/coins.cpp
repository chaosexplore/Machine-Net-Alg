#include <iostream>
#include <vector>
#include "ctimer.h"

using namespace std;

void coinSolution(vector<int>& coin, )
{
	
}


int main()
{
    vector<int> in;
    int myint = 0, total = 0;

    while(1) {
    	cin >> myint;
		if (myint == -99) break;
		in.push_back(myint);
    }     

	cin >> total; 
	
	auto t1 = t_now();
    
	// TODO
	
	auto t2 = t_now();
	t_cal_echo(t1, t2);
	
    cin.get();

    return 0;
}
