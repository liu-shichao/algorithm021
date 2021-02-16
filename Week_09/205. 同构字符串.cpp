class Solution {
public:
    bool isIsomorphic(string s, string t) {
        return (isIsomorphicHelper(s, t) && isIsomorphicHelper(t, s));
    }
    bool isIsomorphicHelper(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, char> m;
        for (int i = 0; i < s.size(); i ++) {
            if (m.count(s[i]) != 0) {
                if (m[s[i]] != t[i]) return false;
            } else {
                m[s[i]] = t[i];
            }
        }
        return true;
    }
};