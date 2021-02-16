class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < dp.size(); i ++) {
            for (int j = 0; j < i ; j ++) {
                if (nums[j] < nums[i])
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        int res = 0;

        for (int i = 0; i < dp.size(); i ++) {
            res = max(res, dp[i]);
        }
        return res;
    }
};