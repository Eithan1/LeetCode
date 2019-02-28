class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();    //行数
        int n = grid[0].size();  //列数
        int sum_temp = 0;

        if(m == 0 || n == 0)
            return 0;

        vector<vector<int>> minPath(m, vector<int>(n, 0));  //储存到达每个点的最短路值

        //初始化第一列
        for(int i = 0; i < m; ++i) {
            sum_temp = sum_temp + grid[i][0];
            minPath[i][0] = sum_temp;
        }

        //初始化第一行
        sum_temp = 0;
        for(int j = 0; j < n; ++j) {
            sum_temp = sum_temp + grid[0][j];
            minPath[0][j] = sum_temp;
        }


        //求剩余元素
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                minPath[i][j] = min(minPath[i - 1][j], minPath[i][j - 1]) + grid[i][j];
            }
        }

        return minPath[m - 1][n - 1];
    }
};
