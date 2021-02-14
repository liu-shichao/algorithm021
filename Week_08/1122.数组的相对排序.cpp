class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> arr(1001, 0);
        vector<int> ans;
        for (auto& a : arr1) {
            arr[a] ++;
        }
        for (auto& a : arr2) {
            while(arr[a] > 0) {
                ans.push_back(a);
                arr[a] --;
            }
        }
        for (int i = 0; i <= 1000; i ++) {
            while(arr[i] > 0) {
                ans.push_back(i);
                arr[i] --;
            }
        }
        return ans;
    }
};
