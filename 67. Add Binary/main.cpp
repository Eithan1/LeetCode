#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int num_a = a.size();
        int num_b = b.size();

        vector<int> aa;
        vector<int> bb;
        vector<int> sum;

        //将string从低位开始存入vector
        for(int i = num_a - 1; i >= 0; --i) {
            aa.push_back(a[i] - '0');
        }
        for(int i = num_b - 1; i >= 0; --i) {
            bb.push_back(b[i] - '0');
        }

        int carry = 0;
        int get;

        for(int i = 0; i < max(num_a, num_b); ++i) {
            if(i > num_a - 1) {
                get = (bb[i] + carry) % 2;
                carry = (bb[i] + carry) / 2;
            }
            else if(i > num_b - 1) {
                get = (aa[i] + carry) % 2;
                carry = (aa[i] + carry) / 2;
            }
            else {
                get = (aa[i] + bb[i] + carry) % 2;
                carry = (aa[i] + bb[i] + carry) / 2;
            }
            sum.push_back(get);
        }

        if(carry > 0)
            sum.push_back(carry);

        //将vector逆序转化为string输出
        string res = "";
        for(int i = sum.size() - 1; i >= 0; --i) {
            res += to_string(sum[i]);
        }

        return res;
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
        string a = stringToString(line);
        getline(cin, line);
        string b = stringToString(line);

        string ret = Solution().addBinary(a, b);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
