/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
private:
    static constexpr short mag[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29,
     31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
public:
    int strStr(string haystack, string needle) {
        short p_size = needle.size();
        if (0 == p_size) return 0;
        if (haystack.size() < p_size) return -1;

        int target = 0, str_sum = 0;
        for (int i = 0; i < p_size; ++i) {
            target += mag[needle[i] -'a'];
            str_sum += mag[haystack[i] - 'a'];
        }
        
        for (int i = 0; i <= haystack.size() - p_size; ++i) {
            if (i > 0)
                str_sum = str_sum - mag[haystack[i-1] - 'a'] + mag[haystack[i + p_size - 1] - 'a'];
            
            if (target == str_sum) {
                int t = i, j;
                for (j = 0; j < p_size; ++j) {
                    if (haystack[t] == needle[j]) {
                      ++t;
                    }
                else
                    break;
                }

                if (j == p_size) return i;
            }
            
        }

        return -1;
    }
};
// @lc code=end

