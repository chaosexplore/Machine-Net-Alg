class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        unordered_map<int,int>::iterator it;
        for(int i = 0; i < nums.size(); ++i) {
            it = hash.find(target - nums[i]);
            if(it != hash.end())
                return {i, it->second};
            hash[nums[i]] = i;
        }
        return {};
    }
};