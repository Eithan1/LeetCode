class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int dim = matrix.size();

        //将行倒序
        reverse(matrix.begin(), matrix.end());

        //求矩阵转置
        for(int i = 0; i < dim; ++i) {
            for(int j = 0; j < dim; ++j) {
                if(i < j) //保证只交换一次
                    swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
