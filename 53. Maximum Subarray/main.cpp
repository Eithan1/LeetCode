class Solution {
public:
    
    
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int maxVal = nums[0];
        int sumi = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            sumi = (sumi + nums[i] > nums[i]) ? sumi + nums[i] : nums[i];
            maxVal = sumi > maxVal ? sumi : maxVal;
        }
        return maxVal;
    }

};
