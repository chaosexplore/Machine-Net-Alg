#include <iostream>
#include <vector>
#include <deque>
#include "ctimer.h"

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        deque<int> que{nums[0]};

        for (int i = 1; i < k - 1; ++i) {
            insertQue(que, nums, i, k);
        }

        for (int i = k-1; i < nums.size(); ++i) {
            ret.push_back(insertQue(que, nums, i, k));
        }

        return ret;
    }

    int insertQue(deque<int>& que, vector<int>& value, int endIdx, int k) {

        if (endIdx - k + 1 > que.front())
            que.pop_front();        // only need 1 step

        while (!que.empty() && value[endIdx] >= value[que.back()])
            que.pop_back();

        que.push_back(endIdx);

        return value[que.front()];
    }
};

int main()
{
    vector<int> in;
    int myint = 0;

    while(1) {
    	cin >> myint;
		if (myint == -99) break;
		in.emplace_back(myint);
    }     

	Solution so;
	
	generateVec(in, 100000, 100000);
	
	auto t1 = t_now();
    
	// TODO
	vector<int> out = so.maxSlidingWindow(in, 100);
	
	auto t2 = t_now();
	t_cal_echo(t1, t2);
	
	//checkVecOrder(in);

	//cout << binaryFindKth(in, 0, in.size()-1, 2) << endl;

    for (auto x : out)
	cout << x << "    ";
    
	
	//cout << in.size() << endl;
	//cout << ret << endl;
	
    cin.get();

    return 0;
}
