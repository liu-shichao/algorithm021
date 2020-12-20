class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> path;
        vector<int> used(nums.size(), 0);
        dfs(nums, used, path, ret);
        return ret;
    }
    void dfs(vector<int>& nums, vector<int>& used, vector<int>& path, vector<vector<int>>& ret){
        if (path.size() == nums.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i ++) {
            if (used[i]) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = 1;
            dfs(nums, used, path, ret);
            path.pop_back();
            used[i] = 0;
        }
    }
};
