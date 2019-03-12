class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int k, int i, int j, vector<vector<int>>& visited) {
        if(k == word.size())
            return true;
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] !=  word[k])
            return false;
        if(visited[i][j] == 0) {
            visited[i][j] = 1;
            if(dfs(board, word, k + 1, i + 1, j, visited) ||  //下边走
               dfs(board, word, k + 1, i - 1, j, visited) ||  //上边走
               dfs(board, word, k + 1, i, j + 1, visited) ||  //右边走
               dfs(board, word, k + 1, i, j - 1, visited))    //左边走
                return true;
            visited[i][j] = 0;        //回溯
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty() || word.empty())
            return false;
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(dfs(board, word, 0, i, j, visited))
                    return true;
            }
        }
        return false;
    }
};
