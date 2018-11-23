#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

class Solution {
public:
    int count = 0;

    int countSubstrings(string s) {
        int left;
        int right;
        for(int i = 0; i <= s.size(); i++)
        {
            ExtendtoBothSide(s, i, i);
            ExtendtoBothSide(s, i, i+1);
        }
        return count;
    }

    void ExtendtoBothSide(string s, int left, int right) {

        //从中间向两边遍历
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
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

        int ret = Solution().countSubstrings(s);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
