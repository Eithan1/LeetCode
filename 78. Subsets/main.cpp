class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<vector<int>> new_res;
        vector<int> one_res;

        res.push_back(one_res);
        for(int i = 0; i < nums.size(); ++i) {
            new_res = res;
            for(int j = 0; j < res.size(); ++j) {
                new_res[j].push_back(nums[i]);
            }
            for(int k = 0; k < new_res.size(); ++k)
                res.push_back(new_res[k]);
        }
        return res;
    }
};
