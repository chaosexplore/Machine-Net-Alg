class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char,int> hash;
        unordered_map<char, int>::iterator it;
        int max = 0, sub = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            it = hash.find(s[i]);
            if (it != hash.end() && i - it->second <= sub)
            {
                sub = i - it->second;
            }
            else
            {
                ++sub;
                if (sub > max) max = sub;
            }
            
            hash[s[i]] = i;
        }

        return max;
    }
};