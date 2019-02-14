#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {

        //行或列为0则返回0
        if(m == 0 || n == 0)
            return 0;

        //定义二维数组path记录到达网格某个点的不同路径数
        vector<vector<int>> path(m, vector<int>(n, 0));

        //将path的首行和首列初始化为1，因为只有一直往右或一直往下一种方法
        for(int i = 0; i < m; ++i) {
            path[i][0] = 1;
        }
        for(int i = 0; i < n; ++i) {
            path[0][i] = 1;
        }

        //其余点的路线数等于上面点的路线数加左边点的路线数
        for(int i = 1; i < m; ++i) {
            for(int j = 1; j < n; ++j) {
                path[i][j] = path[i - 1][j] + path[i][j - 1];
            }
        }

        //(m,n)处的路线数即为所求结果
        return path[m - 1][n - 1];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int m = stringToInteger(line);
        getline(cin, line);
        int n = stringToInteger(line);
        
        int ret = Solution().uniquePaths(m, n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
