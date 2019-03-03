class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();  //行

        if(m == 0)
            return false;

        int n = matrix[0].size(); //列


        int low = 0;  //矩阵第一个元素下标
        int high = m * n - 1; //矩阵最后一个元素下标

        //二分查找
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(matrix[mid / n][mid % n] > target)
                high = mid-1;
            else if(matrix[mid / n][mid % n] < target)
                low = mid+1;
            else
                return true;
        }
        return false;
    }
};
