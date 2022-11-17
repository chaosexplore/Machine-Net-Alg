#include <iostream>
#include <vector>
#include "ctimer.h"

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maxHeap(nums.begin(), nums.begin() + k), ret;
		
		vector<int> index1(k);
		int hi = 0;
		for (auto x = index1.begin(); x != index1.end(); ++x)
			*x = hi++;
		vector<int> index2(index1);
		
			        
        buildHeap(maxHeap, k, index1, index2);

        for (int i = k; i < nums.size(); ++i) {
            ret.push_back(maxHeap[0]);
            
            maxHeap[index2[i%k]] = nums[i];
            if (down2upHeapify(maxHeap, k, index2[i%k], index1, index2) == 0)
				up2downHeapify(maxHeap, k, index2[i%k], index1, index2);
        }
		
		ret.push_back(maxHeap[0]);

        return ret;
    }

    void buildHeap(vector<int>& in, int heapSize, vector<int>& h1, vector<int>& h2)
    {
        for(int i = (heapSize - 1) / 2; i >= 0; --i)
            up2downHeapify(in, heapSize, i, h1, h2);
    }

    void up2downHeapify(vector<int>& in, int heapSize, int i, vector<int>& h1, vector<int>& h2)
    {
        while(1) {
            int maxPos = i;
            if (i*2 + 1 < heapSize && in[i*2 + 1] > in[i]) maxPos = i*2 + 1;
            if (i*2 + 2 < heapSize && in[i*2 + 2] > in[maxPos]) maxPos = i*2 + 2;
            if (maxPos == i) break;
            std::swap(in[i], in[maxPos]);
			
			//std::swap(h2[h1[i]], h2[h1[maxPos]]);
			std::swap(h1[i], h1[maxPos]);
			
			// or
			h2[h1[maxPos]] = maxPos;
			h2[h1[i]] = i;
			
            i = maxPos;
        }
    }
	
	int down2upHeapify(vector<int>& in, int heapSize, int i, vector<int>& h1, vector<int>& h2)
	{
		int count = 0, up = (i-1)/2;
		while(up >= 0 && in[up] < in[i]) {
			std::swap(in[up], in[i]);
			
			std::swap(h1[i], h1[up]);
			h2[h1[up]] = up;
			h2[h1[i]] = i;
			
			++count;
			
			i = up;
			up = (i-1)/2; // notice
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
	in.emplace_back(myint);
    }     

	Solution so;
	
	//generateVec(in, 1000000, 100000);
	
	auto t1 = t_now();
    
	// TODO
	vector<int> out = so.maxSlidingWindow(in, 5);
	
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
