#include <iostream>
#include <cstdlib>
#include <vector>
#include "ctimer.h"

using namespace std;

inline void swap (int& a, int& b)
{
    int temp = a; 
    a = b; b = temp;
}

void qsort(vector<int>& arr, int begin, int end)
{
    if (begin >= end)
	    return;
	
	//swap(arr[begin], arr[rand()%(end - begin + 1) + 1]);

    int mid = arr[begin], left = begin, right = end+1, temp = 0;

    while(1) {
    	do { ++left; }  while(left <= end && arr[left] > mid);
		do { --right; } while(arr[right] < mid);

		if (left > right) break;

		swap(arr[left], arr[right]);
    }

    swap (arr[begin], arr[right]);

    qsort(arr, begin, right-1);
    qsort(arr, right+1, end);
}

void qsort2(vector<int>& nums, int begin, int end)
{
	if (end <= begin)
            return;

        int node = nums[end], temp = 0;
        int p = begin;
        int q = end;  // notice

        while(1) {
            while (nums[p] > node && p < q) ++p;
            while (nums[q] <= node && p < q) --q;

            if (p >= q)
                break;
			
			swap(nums[p], nums[q]);
        }

	swap(nums[p], nums[end]);
	
	qsort2(nums, begin, p-1);
	qsort2(nums, p+1, end);
}



int binaryFindKth(vector<int>& nums, int begin, int end, int k) {
	if (end <= begin)
		return nums[begin];

	int node = nums[end], temp = 0;
	int p = begin;
	int q = end;

	while(1) {
		while (nums[p] > node && p < q) ++p;
		while (nums[q] <= node && p < q) --q;

		if (p >= q)
			break;

		temp = nums[q]; nums[q] = nums[p]; nums[p] = temp;
	}

	temp = nums[p]; nums[p] = node; nums[end] = temp;

	if (p == k-1) return nums[p];
	else if (p < k-1) return binaryFindKth(nums, p+1, end, k);
	else return binaryFindKth(nums, begin, p-1, k);
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
    qsort(in, 0, in.size() - 1);
	auto t2 = t_now();
	t_cal_echo(t1, t2);
	checkVecOrder(in);
	
    //qsort2(in, 0, in.size() - 1);

	//cout << binaryFindKth(in, 0, in.size()-1, 2) << endl;

    //for (auto x : in)
	//cout << x << "    ";
    cout << in.size() << endl;

    cin.get();

    return 0;
}
