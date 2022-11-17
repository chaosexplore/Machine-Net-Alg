#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max_i = 0;
        int max = 1;

        vector<vector<int>> record(s.size());

        /*auto checkMax = [&](int h, int t)->void{
            if (t > max)
            {
                max = t;
                max_i = h;
            }
        };*/

        for (int k = 1; k < s.size(); ++k)
        {
            record[k].reserve(record[k-1].size()+2);
            record[k-1].push_back(0);
            record[k-1].push_back(1);

            for (vector<int>::reverse_iterator it = record[k-1].rbegin(); it != record[k-1].rend(); ++it)
            {
                int tmp = 0;

                /*if (s[k] == s[k-1])
                {
                    tmp = 2;
                    record[k].push_back(tmp);
                    checkMax(k, tmp);
                    cout << k << " : " << k-1 << " : "<< tmp << endl;                         
                }*/

                if (k-*it-1 >= 0 && s[k] == s[k-*it-1])
                {
                    tmp = *it + 2;
                    record[k].push_back(tmp);
                    
                    if (tmp > max)
                    {
                        max = tmp;
                        max_i = k;
                    }

                    //cout << k << " : " << k-*it-1 << " : "<< tmp << endl;   
                }
            }
        }

        cout << max_i << endl;
        cout << max << endl;

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