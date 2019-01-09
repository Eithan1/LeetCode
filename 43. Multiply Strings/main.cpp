#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        string result(len1 + len2, '0');

        if(len1 == 0 || len2 == 0)
            return "";

        for(int i = len1 - 1; i >= 0; --i) {
            int carry = 0;
            for(int j = len2 - 1; j >= 0; --j) {
                int mul_res = int(num1[i] - '0') * int(num2[j] - '0');
                int sum = int(result[i + j + 1] - '0') + carry + mul_res % 10;
                result[i + j + 1] = char(sum % 10 + '0');
                carry = mul_res / 10 + sum / 10;  //乘法和乘完的加法都有可能产生进位
            }
            result[i] += carry;
        }

        for (int i = 0; i < len1 + len2; ++i) {  //从结果中第一个不为0的开始返回
            if(result[i] != '0')
                return result.substr(i);
        }

        return "0";    //都为0则返回0
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
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);

        string ret = Solution().multiply(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
