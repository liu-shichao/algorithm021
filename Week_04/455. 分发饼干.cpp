class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        for (int j = 0; i < g.size() && j < s.size(); ) {
            if (g[i] <= s[j]) {
                i ++;
            }
            j ++;
        }
        return i;
    }
};
