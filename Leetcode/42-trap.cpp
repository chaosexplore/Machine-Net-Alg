#include <iostream>
#include <vector>
#include "ctimer.h"

using namespace std;
class Solution {
public:
	int trap (vector<int> &height) {
		int sum = 0;
		trapSum (&height[0], 0, height.size() - 1, sum);
		
		return sum;
	}
	
	void getMax (int* vec, int left, int right, int& maxi, int& lmaxi, int& rmaxi) {
		//if (left > right) return -1;
		
        maxi = left; lmaxi = left; rmaxi = left;
		int max = -(1 << 30);
        int gap = (1 << 30), t = 0;
		
		for (int i = left; i <= right; ++i) {
            t = max - *(vec + i);
			if (t < 0) {
                lmaxi = maxi;
				max = *(vec + i);
				maxi = i;
                rmaxi = maxi;
				gap = (1 << 30);
			}
            else if (t < gap) {
                gap = t;
                rmaxi = i;
            }
		}
	}
	
	void trapSum (int* vec, int left, int right, int & sum) {
		if (right - left < 2) return;
		
		int max_index = 0, left_max_index = 0, right_max_index = 0;
        getMax (vec, left, right, max_index, left_max_index, right_max_index);
		
		
        sum += cal (vec, left_max_index, max_index, *(vec + left_max_index));
        trapSum (vec, left, left_max_index, sum);
    
        sum += cal (vec, max_index, right_max_index, *(vec + right_max_index));
        trapSum (vec, right_max_index, right, sum);
    
	}
	
	int cal (int *vec, int m, int n, int height) {
		int width = n - m - 1;
		//int height = *(vec + left) < *(vec + right) ? *(vec + left) : *(vec + right)
		if (width <= 0) return 0;
		
		int count = width * height;
		for (int i = m + 1; i < n; ++i) {
			count -= *(vec + i);
		}
		
		return count;
	}
};

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
    
	// TODO
	Solution s;
	int ret = s.trap(in);
	
	auto t2 = t_now();
	t_cal_echo(t1, t2);
	
	//checkVecOrder(in);

	//cout << binaryFindKth(in, 0, in.size()-1, 2) << endl;

    //for (auto x : in)
	//cout << x << "    ";
    
	
	//cout << in.size() << endl;
	cout << ret << endl;
	
    cin.get();

    return 0;
}
