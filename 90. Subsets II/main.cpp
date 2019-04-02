class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& one_res, vector<int>& nums, int level) {
        res.push_back(one_res);

        if(one_res.size() == res.size()) {
            return;
        }

        for(int i = level; i < nums.size(); ++i) {
            if(i > level && nums[i] == nums[i - 1])
                continue;
            one_res.push_back(nums[i]);
            dfs(res, one_res, nums, i + 1);
            one_res.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> one_res;
        sort(nums.begin(), nums.end());
        dfs(res, one_res, nums, 0);
        return res;
    }
};
