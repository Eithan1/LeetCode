#include <map>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; ++i) {  //每个i对应检查第i行，第i列和第i个九宫格
            map<char, bool> row, col, grid;
            for(int j = 0; j < 9; ++j) { //每个j对应检查第i行，第i列和第i个九宫格的第j个数

                if(board[i][j] != '.') {   //检查第i行的第j个数(j=0...9)
                    if(row[board[i][j]] == true) //为true代表该数字已在该行出现过
                        return false;
                    else
                        row[board[i][j]] = true; //之前没出现过则标记为出现
                }

                if(board[j][i] != '.') {   //检查第i列的第j个数(j=0...9)
                    if(col[board[j][i]] == true) //为true代表该数字已在该列出现过
                        return false;
                    else
                        col[board[j][i]] = true; //之前没出现过则标记为出现
                }

                int m = i / 3 * 3 + j / 3; //第i个九宫格第j个数的行号可以表示为m
                int n = i % 3 * 3 + j % 3; //第i个九宫格第j个数的列号可以表示为n
                if(board[m][n] != '.') {   //检查第i个格子的第j个数(j=0...9)
                    if(grid[board[m][n]] == true) //为true代表该数字已经在该九宫格内出现过
                        return false;
                    else
                        grid[board[m][n]] = true; //之前没出现过则标记为出现
                }
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    if(Solution().isValidSudoku(board))
        cout << "true";
    else
        cout << "false";

    return 0;
}
