class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int num = strs.size();
        if(num == 0)
            return "";
        if(num == 1)
            return strs[0];
        int min_char = INT_MAX;
        string res = "";

        for(int i = 0; i < num; ++i) {
            if(strs[i] == "")
                return "";
            if(strs[i].size() < min_char)
                min_char = strs[i].size();
        }

        for(int i = 0; i < min_char; ++i) {
            for(int j = 1; j < num; ++j) {
                if(strs[j][i] != strs[0][i]) {
                    return res;
                }
            }
            res += strs[0][i];
        }
        return res;
    }
};
