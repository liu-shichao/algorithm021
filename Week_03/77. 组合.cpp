
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        if (n < k || k <= 0) return ret;
        vector<int> path;
        dfs(n, k, 1, path, ret);
        return ret;
    }
    void dfs(int n, int k, int begin, vector<int>& path, vector<vector<int>>& ret) {
        if (path.size() == k) {
            ret.push_back(path);
            return;
        }
        for (int i = begin; i <= n + 1 - (k - path.size()); i ++) {
            path.push_back(i);
            dfs(n, k, i + 1, path, ret);
            path.pop_back();
        }
    }
};
