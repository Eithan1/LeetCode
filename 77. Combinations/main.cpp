class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& one_res, int n, int k, int level) {
        if(one_res.size() == k){
            res.push_back(one_res);
            return;
        }

        for(int i = level; i <= n; ++i) {
            one_res.push_back(i);
            dfs(res, one_res, n, k, i + 1);
            one_res.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> one_res;

        dfs(res, one_res, n, k, 1);

        return res;
    }
};
