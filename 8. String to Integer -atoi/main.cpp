#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int len = str.size();
        int flag = 0;
        long long ans = 0;
        for(int i = 0; i < len; ++i) {
            if(flag == 0) {
                if(str[i] == '+')  flag = 1;
                else if(str[i] == '-')  flag = -1;
                else if(str[i] == ' ') continue;
                else if(str[i] >= '0' && str[i] <= '9') {
                    ans = str[i] - '0';
                    flag = 1;
                }
                else return 0;
            }
            else {
                if(str[i] >= '0' && str[i] <= '9') {
                    ans = ans * 10 + (str[i] - '0');
                    if(ans * flag < INT_MIN) return INT_MIN;
                    if(ans * flag > INT_MAX) return INT_MAX;
                }
                else if(ans != 0) break;
                else return 0;
            }
        }
        return ans * flag;
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
        string str = stringToString(line);

        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
