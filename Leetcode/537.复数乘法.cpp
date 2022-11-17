/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */

// @lc code=start
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int n11, n12, n21, n22;
        std::tie(n11, n12) = seperateNum(num1);
        std::tie(n21, n22) = seperateNum(num2);

        int ret1 = n11 * n21 - n12 * n22;
        int ret2 = n11 * n22 + n21 * n12;

        string ret = to_string(ret1) + '+' + to_string(ret2) + 'i';

        return ret;
    }

    tuple<int, int> seperateNum(string& str) {
        size_t p1 = str.find('+');
        
        //if (string::npos == p1) return {};

        int n1 = stoi(str.substr(0, p1));
        int n2 = stoi(str.substr(p1+1, str.size()-p1-1));

        return {n1, n2};
    }
};
// @lc code=end

