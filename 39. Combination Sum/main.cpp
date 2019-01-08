class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.size() == 0)
            return res;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        BackTracking(res, cur, candidates, target, 0);
        return res;
    }

    void BackTracking(vector<vector<int>>& res, vector<int> cur, vector<int> candidates, int target, int index) {
        if(target == 0) {
            res.push_back(cur);
            return;
        }
        else if(target < 0)
            return;
        else if(target < candidates[index])  //如果需要的数比当前最小的还要小，则没有必要尝试
            return;

        for(int i = index; i < candidates.size(); ++i) {
            target -= candidates[i]; //尝试将candidates[i]放入
            cur.push_back(candidates[i]);
            BackTracking(res, cur, candidates, target, i); //数字可重复所以是i，而不是i+1
            cur.pop_back(); //将candidates[i] pop出来，继续尝试下一个
            target += candidates[i];
        }
    }
};
