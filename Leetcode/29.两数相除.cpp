/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */
#include <stdio.h>
#define INT_MAX 2147483647 
#define INT_MIN -2147483648
// @lc code=start

    int divide(int dividend, int divisor) {
        if (0 == divisor) return INT_MAX;
        if (INT_MIN == dividend && -1 == divisor) return INT_MAX;
        
        int ret = 0, sum = 0;
        bool bNeg = dividend >> 31 ^ divisor >> 31;
        bool bMin = false;

        if (bNeg) divisor = -divisor;

        if (dividend >= 0) {
            while (1) {
                if (dividend - sum < divisor || INT_MAX - sum < divisor)
                    break;

                sum += divisor;
                ++ret;
            }
        }
        else {
            while (1) {
                if (dividend - sum > divisor || INT_MIN - sum > divisor)
                    break;

                sum += divisor;
                if (INT_MAX != ret) ++ret;
                else bMin = true;
            }
        }

        if (bNeg)   ret = -ret;
        if (bMin) ret -= 1;

        return ret;
    }

    int main() {
        int ret = divide(INT_MIN, 1);
        printf("%d\n", ret);
        return 0;
    }
// @lc code=end

