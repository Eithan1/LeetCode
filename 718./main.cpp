#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int Max = 0;
        int lenA = A.size();
        int lenB = B.size();
        vector<vector<int>> DP(lenA + 1, vector<int>(lenB + 1, 0));

        //设置边界条件
        for(int i = 0; i <= lenA; i++)
        {
            DP[i][0] = 0;
        }
        for(int j = 0; j <= lenB; j++)
        {
            DP[0][j] = 0;
        }

        for(int i = 1; i <= lenA; i++)
        {
            for(int j = 1; j <= lenB; j++)
            {
                if(A[i - 1] == B[j - 1])
                {
                    DP[i][j] = DP[i- 1][j - 1] + 1;
                }
                else
                {
                    DP[i][j] = 0;
                }
                Max = Max > DP[i][j] ? Max : DP[i][j];
            }
        }

        return Max;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> A = stringToIntegerVector(line);
        getline(cin, line);
        vector<int> B = stringToIntegerVector(line);

        int ret = Solution().findLength(A, B);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
