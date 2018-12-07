#include <string>
#include <iostream>
#include <assert.h>
#include <vector>
using namespace std;

class Solution{
public:
    string longestPalindrome(string s)
    {
        string manaStr = "$#";
        for (int i=0;i<s.size();i++) //首先构造出新的字符串
        {
            manaStr += s[i];
            manaStr += '#';
        }
        vector<int> rd(manaStr.size(), 0);//用一个辅助数组来记录最大的回文串长度，注意这里记录的是新串的长度，原串的长度要减去1
        int pos = 0, mx = 0;
        int start = 0, maxLen = 0;
        for (int i = 1; i < manaStr.size(); i++)
        {
            rd[i] = i < mx ? min(rd[2 * pos - i], mx - i) : 1;
            while (i+rd[i]<manaStr.size() && i-rd[i]>0 && manaStr[i + rd[i]] == manaStr[i - rd[i]])//这里要注意数组越界的判断
                rd[i]++;
            if (i + rd[i] > mx) //如果新计算的最右侧端点大于mx,则更新pos和mx
            {
                pos = i;
                mx = i + rd[i];
            }
            if (rd[i] - 1 > maxLen)
            {
                start = (i - rd[i]) / 2;
                maxLen = rd[i] - 1;
            }
        }
        return s.substr(start, maxLen);
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
