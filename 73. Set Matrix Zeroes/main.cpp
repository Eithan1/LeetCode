class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();    //m行
        int n = matrix[0].size(); //n列

        set<int> row;   //存储要置的行
        set<int> col;   //存储要删除的列
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        //将行置0
        set<int>::iterator iter;
        for(iter = row.begin(); iter != row.end(); ++iter) {
            for(int j = 0; j < n; ++j) {
                matrix[*iter][j] = 0;
            }
        }

        //将列置0
        for(iter = col.begin(); iter != col.end(); ++iter) {
            for(int j = 0; j < m; ++j) {
                matrix[j][*iter] = 0;
            }
        }

    }
};
