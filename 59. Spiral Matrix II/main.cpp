class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

        vector<vector<int>> res(n, vector<int>(n, 0));

        //初始化一个(m,n)bool矩阵，标记原矩阵元素是否遍历过，初始值为false
        vector<vector<bool>> b(n, vector<bool>(n, false));

        //定义坐标变换向量，分别代表向右、下、左、上
        //（先往右，不行再往下，不行则往左，不行再往上，不行再往右。。。）
        //（改变方向后还不行则已遍历完，停止）
        vector<vector<int>> direc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int i = 0; //行
        int j = 0; //列
        int nextdirec = 0; //下一个方向
        int k = 1; //记录平方
        int flag = 1; //循环标记，看是否已经完成所有元素的遍历

        while(1) { //在矩阵大小范围内循环

            res[i][j] = k++;


            b[i][j] = true; //标记为访问过


            if (i + direc[nextdirec][0] < 0 || i + direc[nextdirec][0] >= n
                || j + direc[nextdirec][1] < 0 || j + direc[nextdirec][1] >= n
                || b[i + direc[nextdirec][0]][j + direc[nextdirec][1]]) { //如果沿原方向不满足条件（越界或下个元素已被访问）
                nextdirec = (nextdirec + 1) % 4; //按方向改变规律变换方向
            }

            if (i + direc[nextdirec][0] < 0 || i + direc[nextdirec][0] >= n
                || j + direc[nextdirec][1] < 0 || j + direc[nextdirec][1] >= n
                || b[i + direc[nextdirec][0]][j + direc[nextdirec][1]]) { //如果改变方向后仍不满足条件
                break; //已遍历所有元素，退出循环
            }

            i += direc[nextdirec][0];  //继续按原方向走或改变方向
            j += direc[nextdirec][1];
        }

        return res;
    }
};
