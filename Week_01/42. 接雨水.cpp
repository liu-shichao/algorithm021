
//双指针法
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int left_max = 0, right_max = 0;
        int ans = 0;
        while (left <= right) {
            if (left_max < right_max) {
                ans += max(0, left_max - height[left]);
                left_max = max(left_max, height[left]);
                left ++;
            }
            else {
                ans += max(0, right_max - height[right]);
                right_max = max(right_max, height[right]);
                right --;
            }
        }
        return ans;
    }
};

//使用栈
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < height.size(); i ++) {
            while (st.size() > 0 && height[st.top()] < height[i]) {
                int cur = st.top();
                st.pop();
                if (st.size() == 0) break;
                int l = st.top();
                int r = i;
                int h = min(height[l], height[r]) - height[cur];
                ans += h * (r - l - 1);
            }
            st.push(i);
        }
        return ans;
    }
};
