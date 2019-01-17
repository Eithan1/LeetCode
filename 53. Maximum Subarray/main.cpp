/*--------------DP---------------*/
class Solution1 {
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


/*--------------分治-----------------*/
class Solution2 {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        return maxSubArray(nums, 0, nums.size() - 1);
    }

    int maxSubArray(vector<int>& nums, int l, int r) {
        if(l > r)  //若l>r，则此次计算无意义，返回INT_MIN不影响最后的max函数结果
            return INT_MIN;
        if(l == r)
            return nums[l];
        int mid = (l + r) / 2;
        int left = maxSubArray(nums, l, mid - 1);
        int right = maxSubArray(nums, mid + 1, r);
        int t = nums[mid];
        int middle = nums[mid];
        for(int i = mid - 1; i >= l; --i) {
            t += nums[i];
            middle = max(middle, t);
        }
        t = middle;
        for(int i = mid + 1; i <= r; ++i) {
            t += nums[i];
            middle = max(middle, t);
        }
        return max(max(left, right), middle);
    }
};
