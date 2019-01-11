class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back(nums);
        while(next_permutation(nums.begin(), nums.end())) {  //返回值为bool，但内部已重新排序
            res.push_back(nums);
        }

        return res;
    }
};
