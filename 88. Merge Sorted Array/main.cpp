class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0)
            nums1 = nums2;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(nums2[i] < nums1[j]) {
                    nums1.insert(nums1.begin() + j, nums2[i]);
                    break;
                }
                else if(j == m - 1)
                    nums1.insert(nums1.begin() + j + 1, nums2[i]);
            }
            m++;
        }
        nums1.erase(nums1.begin() + m, nums1.end());
    }
};
