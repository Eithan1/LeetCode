class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2)
            return nums.size();

        int len = 1;
        int count = 1;
        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] == nums[i - 1]) {
                if(count < 2) {
                    nums[len++] = nums[i];
                    count++;
                }
            }
            else {
                count = 1;
                nums[len++] = nums[i];
            }
        }
        return len;
    }
};
