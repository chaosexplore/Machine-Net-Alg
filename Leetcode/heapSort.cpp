#include <iostream>
#include <vector>
#include "ctimer.h"

using namespace std;

inline void swap (int& a, int& b)
{
    int temp = a; 
    a = b; b = temp;
}

void maxHeapify(vector<int>&a, int i, int heapSize)
{
	while(1){
		int maxPos = i;
		if (i*2+1 < heapSize && a[i] < a[i*2+1]) maxPos = i*2+1;
		if (i*2+2 < heapSize && a[maxPos] < a[i*2+2]) maxPos = i*2+2;  // notice
		if (maxPos == i) break;
		swap(a[i], a[maxPos]);
		i = maxPos;
	}
}

void buildHeap(vector<int>&a, int heapSize)
{
	for (int i = (heapSize - 1)/2; i >= 0; --i)
		maxHeapify(a, i, heapSize);
}

int getKthMax(vector<int>&a, int k)
{
	buildHeap(a, a.size());
	int n = a.size();
	for (int i = k-1; i > 0 ; --i) {
		swap(a[0], a[n-1]);
		maxHeapify(a, 0, --n);
	}
	
	return a[0];
}

int main()
{
    vector<int> in;
    int myint = 0;

    while(1) {
    	cin >> myint;
	if (myint == -99) break;
	in.emplace_back(myint);
    }     

	generateVec(in, 1000000, 100000);
	
	auto t1 = t_now();
    int ret = getKthMax(in, in.size());
	auto t2 = t_now();
	t_cal_echo(t1, t2);
	checkVecOrder(in);

	//cout << binaryFindKth(in, 0, in.size()-1, 2) << endl;

    //for (auto x : in)
	//cout << x << "    ";
    cout << in.size() << endl;
	//cout << ret << endl;
	
    cin.get();

    return 0;
}
