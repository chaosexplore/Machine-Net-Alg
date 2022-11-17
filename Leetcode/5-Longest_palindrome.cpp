class Solution {
public:
    string longestPalindrome(string s) {
        int max_i = 0;
        int max = 0;

        auto fn = [&](int h, int t, int tmp)->void{
            while(h >=0 && t < s.size())
            {
                if (s[h] == s[t]) {
                    tmp += 2;
                    --h;
                    ++t;
                }
                else
                    break;
            }
            if (tmp > max) {
                max = tmp;
                max_i = h + 1;
            }
        };

        for (int k = 0; k < s.size(); ++k)
        {
            fn(k-1, k+1, 1);
            fn(k, k+1, 0);
        }

        return s.substr(max_i, max);
    }
};