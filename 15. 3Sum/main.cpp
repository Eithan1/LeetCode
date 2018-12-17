class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> res;
        vector<int> res_tmp;
        int head = 0;
        int tail = 0;
        for(int i = 0; i < len; ++i) {
            if(nums[i] > 0)
                break;
            else if(i > 0 && (nums[i] == nums[i - 1]))
                continue;
            else {
                head = i + 1;
                tail = len - 1;
                while(head < tail) {
                    if(head != i + 1 && nums[head] == nums[head - 1])
                        ++head;
                    else if(tail != len - 1 && nums[tail] == nums[tail + 1])
                        --tail;
                    else if(nums[head] + nums[tail] == -nums[i]) {
                        res_tmp.push_back(nums[i]);
                        res_tmp.push_back(nums[head]);
                        res_tmp.push_back(nums[tail]);
                        res.push_back(res_tmp);
                        res_tmp.clear();
                        ++head;
                        --tail;
                    }
                    else if(nums[head] + nums[tail] < -nums[i])
                    {
                        ++head;
                    }
                    else if(nums[head] + nums[tail] > -nums[i])
                    {
                        --tail;
                    }
                }
            }
        }
        return res;
    }
};
