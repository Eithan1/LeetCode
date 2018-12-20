class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> res;
        vector<int> res_tmp;
        int head = 0;
        int tail = 0;
        int sum = 0;
        for(int i = 0; i < len - 1; ++i) {
            if (i > 0 && (nums[i] == nums[i - 1])) //第一个数判重
                continue;
            for (int j = i + 1; j < len; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) //第二个数判重
                    continue;
                else {
                    head = j + 1;
                    tail = len - 1;
                    while (head < tail) {
                        if (head != j + 1 && nums[head] == nums[head - 1]) //第三个数判重
                            ++head;
                        else if (tail != len - 1 && nums[tail] == nums[tail + 1]) //第四个数判重
                            --tail;
                        else {
                            sum = nums[i] + nums[j] + nums[head] + nums[tail];
                            if (sum == target) {
                                res_tmp.push_back(nums[i]);
                                res_tmp.push_back(nums[j]);
                                res_tmp.push_back(nums[head]);
                                res_tmp.push_back(nums[tail]);
                                res.push_back(res_tmp);
                                res_tmp.clear();
                                ++head;
                                --tail;
                            } else if (sum < target) {
                                ++head;
                            } else if (sum > target) {
                                --tail;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
