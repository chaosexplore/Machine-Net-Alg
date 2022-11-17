/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        int ret = 0;
        int *state = new int[n];

        retire(0, n, ret);

        delete[] state;

        return ret;
    }

    void retire(int idx, int n, int& count) {
        if (n == idx) {
            ++count;
            return;
        }

        if ()
            retire (idx+1, n, count);
    }
};
// @lc code=end

