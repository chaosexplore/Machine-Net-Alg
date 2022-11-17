#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max_i = 0;
        int max = 1;

        //int n = s.size();
        //unsigned short* ret = (unsigned short*)malloc(n*n*sizeof(unsigned short));
        unsigned short record[1024][1024];
        memset(record, 0, sizeof record);

        for (int k = 1; k < s.size(); ++k)
        {
            record[k-1][0] = 1;
            record[k-1][1] = 1;

            for (int i = 0; i <= 1000; ++i)
            {
                if (record[k-1][i] == 1) {
                    if (k-i-1 >= 0 && s[k] == s[k-i-1])
                    {
                        record[k][i+2] = 1;
                        if (i+2 > max)
                        {
                            max = i+2;
                            max_i = k;
                        }
                    }
                }
            }

        }

        return s.substr(max_i-max+1, max);
    }
};

int main()
{
	string s = "abababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababababa";
	Solution t;
	cout << t.longestPalindrome(s) << endl;
	return 0;
}