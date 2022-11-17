/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 */

// @lc code=start
// 1*10 + 2*100 + 3*1000 + 4*10000 + n*10^n
class Solution {
public:
    int findNthDigit(int n) {
        if (n < 10) return n;

        long temp = -1;
        for (int i = 1; n >= temp; ++i) {
            temp += i*pow(10, i);
        }

        temp -= i*pow(10, i);
        --i;
    }
};
// @lc code=end

