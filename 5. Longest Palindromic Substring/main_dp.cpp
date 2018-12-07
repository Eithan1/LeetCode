#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int len = s.size();
        if(len == 1) return s;
        int subStr_longest = 1;
        int start = 0;
        vector<vector<int> > dp(len, vector<int>(len));

        /*---------------边界条件--------------*/
        for(int i = 0; i < len; ++i) {
            dp[i][i] = 1;  //每个独立的字符都是回文串
            if(i < len - 1) {  //连续相同的两个字符也是回文串
                if (s[i] == s[i + 1]) {
                    dp[i][i + 1] = 1;
                    start = i;
                    subStr_longest = 2;
                }
            }
        }

        /*---------------状态转移--------------*/
        for(int l = 3; l <= len; ++l) {             //l:子串长度 长度递增，满足回文则更新，求得最长
            for(int i = 0; i + l - 1 < len; ++i) {  //i:子串起始位置
                int j = i + l - 1;                  //j:子串结束位置
                if(s[i] == s[j] && dp[i + 1][j - 1] ==1 ){
                    dp[i][j] = 1;
                    start = i;
                    subStr_longest = l;
                }
            }
        }
        return s.substr(start, subStr_longest);
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string s = stringToString(line);

        string ret = Solution().longestPalindrome(s);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
