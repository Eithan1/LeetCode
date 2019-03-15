class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())
            return false;

        int left = 0, right = nums.size() - 1;

        //查找旋转点，始终保持查找目标位于[left,right]
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return true;
            if(nums[left] < nums[mid]) {  //[left,mid]递增
                if(nums[left] <= target && target < nums[mid])
                    right = mid;
                else
                    left = mid + 1;
            }
            else if(nums[left] > nums[mid]) { //[mid,right]递增
                if(nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
                left++;   //跳过相等元素
        }
        return false;   //没找到
    }
};
