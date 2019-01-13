class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> m;
        vector<string> s = strs;
        int k = 0;
        for(int i = 0; i < s.size(); ++i) {
            sort(s[i].begin(), s[i].end());
            if (!m.count(s[i])) {
                m[s[i]] = k++;
                res.push_back(vector<string>{});
            }

            res[m[s[i]]].push_back(strs[i]);
        }
        return res;
    }
};
