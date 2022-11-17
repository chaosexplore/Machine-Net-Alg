#include <iostream>
#include <vector>
#include <algorithm>  
#include "ctimer.h"

using namespace std;

int firstMissingPositive(vector<int>& nums) {

	int n = nums.size(), tmp, i;

	for (i = 0; i < n; ++i)
		while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
			tmp = nums[i];
			nums[i] = nums[nums[i] - 1];
			//nums[nums[i] - 1] = tmp;		notice
			nums[tmp - 1] = tmp;
		}
	
	i = 0;
	for (; i < n; ++i)
		if (i+1 != nums[i])   break;

	return i + 1;
}

int firstMissingPositive2(vector<int>& nums) {

	int n = nums.size(), i;

	for (i = 0; i < n; ++i)
		while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
			std::swap(nums[nums[i] - 1], nums[i]);
		}
	
	i = 0;
	for (; i < n; ++i)
		if (i+1 != nums[i])   break;

	return i + 1;
}

int main()
{
    vector<int> in;
    int myint = 0;

    while(1) {
    	cin >> myint;
		if (myint == -99) break;
		in.push_back(myint);
    }     

	//generateVec(in, 1000000, 100000);
	
	auto t1 = t_now();
    
	myint = firstMissingPositive(in);
	
	auto t2 = t_now();
	t_cal_echo(t1, t2);
	
	//checkVecOrder(in);

	//cout << binaryFindKth(in, 0, in.size()-1, 2) << endl;

    //for (auto x : in)
	//cout << x << "    ";
    
	
	cout << myint << endl;
	//cout << ret << endl;
	
    cin.get();

    return 0;
}
