class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        //行或列为0则返回0
        if(m == 0 || n == 0)
            return 0;

        //定义二维数组path记录到达网格某个点的不同路径数（初始化为0）
        vector<vector<unsigned int>> path(m, vector<unsigned int>(n, 0));

        //将path的首行和首列初始化为1(一旦遇到障碍物，后面都无法到达)，因为只有一直往右或一直往下一种方法
        for(int i = 0; i < m; ++i) {
            if(obstacleGrid[i][0] == 0)
                path[i][0] = 1;
            else
                break;
        }
        for(int i = 0; i < n; ++i) {
            if(obstacleGrid[0][i] == 0)
                path[0][i] = 1;
            else
                break;
        }

        //其余点的路线数等于上面点的路线数加左边点的路线数(除了障碍物路线数为0)
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                if(obstacleGrid[i][j] == 1)
                    path[i][j] == 0;
                else
                    path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }

        //(m,n)处的路线数即为所求结果
        return path[m - 1][n - 1];
    }
};
