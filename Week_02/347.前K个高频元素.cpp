class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //map统计频数
        map<int, int> m;
        for (int num : nums) {
            m[num] ++;
        }
        //优先队列排序
        auto cmp =  [&](int a, int b){return m[a] > m[b];};
        priority_queue<int, vector<int>, decltype(cmp) > pq(cmp);
        for (auto itor = m.begin(); itor != m.end(); itor ++) {
            if (pq.size() < k) {
                pq.push(itor->first);
            } 
            else {
                if (m[itor->first] > m[pq.top()]) {
                    pq.pop();
                    pq.push(itor->first);
                }
            }
        }
        //返回结果
        vector<int> ret;
        while(!pq.empty()) {
            ret.push_back(pq.top());
            pq.pop();
        }
        return ret;
    }
};