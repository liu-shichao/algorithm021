class UnionFind {
public:
    int find(int x) {
        int root = x;
        while (father[root] != -1) {
            root = father[root];
        }
        while (x != root) {
            int origin_father = father[x];
            father[x] = root;
            x = origin_father;
        }
        return root;
    }
    bool is_conected(int x, int y) {
        return find(x) == find(y);
    }
    void merge(int x, int y) {
        int root_x = find(x);
        int root_y = find(y);
        if (root_x != root_y) {
            father[root_x] = root_y;
            num_of_sets -- ;
        }
    }
    void add(int x) {
        if (father.count(x) == 0) {
            father[x] = -1;
            num_of_sets ++;
        }
    }
    int get_num_of_sets() {
        return num_of_sets;
    }
private:
    unordered_map<int, int> father;
    int num_of_sets = 0;
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind uf;
        for (int i = 0; i < isConnected.size(); i ++) {
            uf.add(i);
            for (int j = 0; j < i; j ++) {
                if (isConnected[i][j]) {
                    uf.merge(i, j);
                }
            }
        }
        return uf.get_num_of_sets();
    }
};