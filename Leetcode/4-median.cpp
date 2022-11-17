#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int m_left, m_right;

        m_left = (total+1) / 2;

        int i = 0, j = 0 ;
        bool flag = true;

        auto fn = [&]()->void {
            if(i >= nums1.size()) flag = false;
            else if (j >= nums2.size()) flag = true;
            else flag = nums1[i] < nums2[j];
        };

        for (int k = 1; k < m_left; ++k)
        {
            fn();
            if (flag) ++i;
            else ++j;
        }

        // reached the middle
        fn();
        m_left = flag ? nums1[i++] : nums2[j++];
        if (total % 2 == 0) {
            fn();
            m_right = flag ? nums1[i++] : nums2[j++];
        }
        else
            m_right = m_left;

        return (double)(m_left + m_right) / 2;
    }
};

int main()
{
	vector<int> nums1 = {1,3};
	vector<int> nums2 = {2};
	
	double ret = Solution::findMedianSortedArrays(nums1, nums2);
	
	cout << ret << endl;
	return 0;
}