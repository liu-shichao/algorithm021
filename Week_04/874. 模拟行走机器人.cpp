class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<int> dirx = {0, 1, 0, -1};
        vector<int> diry = {1, 0, -1, 0};
        int curdir = 0;
        int curx = 0;
        int cury = 0;
        int ans = 0;
        set<pair<int, int>> obstacle_set;
        for (auto& obstacle : obstacles) {
            obstacle_set.insert(make_pair(obstacle[0], obstacle[1]));
        }
        for (auto& cmd : commands) {
            if (cmd == -1) {
                curdir = (curdir + 1) % 4;
            } else if (cmd == -2) {
                curdir = (curdir + 4 - 1) % 4;
            } else {
                for (int i = 0; i < cmd; i ++) {
                    int nx = curx + dirx[curdir];
                    int ny = cury + diry[curdir];
                    if (obstacle_set.count(make_pair(nx, ny)) == 0) {
                        curx = nx;
                        cury = ny;
                        ans = max(ans, curx * curx + cury * cury);
                    } else break;
                }
            }
        }
        return ans;
    }
};
