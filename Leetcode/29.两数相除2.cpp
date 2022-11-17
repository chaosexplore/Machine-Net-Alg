/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include <stdio.h>
#include <stdlib.h>
#define INT_MAX 2147483647 
#define INT_MIN -2147483648
// @lc code=start
class Solution {
public:
    int divide_sub(int divident, int divisor) {
        int t1 = divident, t2 = divisor, ret = 0, num = 1;

        if (t1 > t2) return 0;

        ret = 1;
        t1 = t1 - t2;

        while (t1 - t2 < t2) {
            t2 = t2 + t2;
            t1 = t1 - t2;
            num = num + num;
            ret += num;
        }

        int ret_sub = divide_sub(t1, divisor);
        if (ret == INT_MAX && ret_sub > 0)
            ret = -1;
        else
            ret += ret_sub;
        
        return ret;
    }

    int divide(int dividend, int divisor) {
        if (0 == divisor) return INT_MAX;
        if (INT_MIN == dividend && -1 == divisor) return INT_MAX;
        
        int ret = 0;
        bool bNeg = dividend >> 31 ^ divisor >> 31;

        if (bNeg) {
            if (divisor > 0)
                divisor = -divisor;
            else
                dividend = -dividend;
        }

        ret = divide_sub(dividend, divisor);
        
        if (-1 == ret)  return INT_MIN;
        if (bNeg)   ret = -ret;

        return ret;
    }
};
// @lc code=end

