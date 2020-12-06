class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret(2, -1);
        map<int, int> map_idx;
        for (int i = 0; i < nums.size(); i ++) {
            if (map_idx.count(target-nums[i]) > 0) {
                ret[0] = i;
                ret[1] = map_idx[target - nums[i]];
                return ret;
            }
            map_idx[nums[i]] = i;
        }
        return ret;
    }
};
