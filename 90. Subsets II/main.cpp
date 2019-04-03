
class Solution {
public:
    void dfs(vector<vector<int>>& res, vector<int>& one_res, vector<int>& nums, int level) {
        if(one_res.size() == nums.size()) { //退出条件
            res.push_back(one_res);         //记录answer
            return;
        }
        else {
            res.push_back(one_res);         //此题较为特殊，当个数小的时候仍要记录answer
            for(int i = level; i < nums.size(); ++i) {
                if(i > level && nums[i] == nums[i - 1])  //判断有重复元素则跳过
                    continue;
                one_res.push_back(nums[i]);     //元素入栈
                dfs(res, one_res, nums, i + 1); //深搜
                one_res.pop_back();             //元素出栈（此处还原所有条件）
            }
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
