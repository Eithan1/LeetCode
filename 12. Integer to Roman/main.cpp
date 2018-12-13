#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        /* 解法一：
        string result = "";
        char roman[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
        int value[] = {1000, 500, 100, 50, 10, 5, 1};

        for(int n = 0; n < 7; n += 2) {
            int x = num / value[n];
            if(x < 4) {
                for(int i = 1; i <= x; ++i)
                    result += roman[n];
            }
            else if(x == 4) {
                result = result + roman[n] + roman[n - 1];
            }
            else if(x > 4 && x < 9) {
                result += roman[n - 1];
                for(int i = 6; i <= x; ++i)
                    result += roman[n];
            }
            else if(x == 9)
                result = result + roman[n] + roman[n - 2];
            num %= value[n];
        }
        return result;  */


        /*解法二：
        string result = "";
        vector<int> val{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> str{"M", "CM", "D", "CD", "C", "XC",
                           "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i = 0; i < val.size(); ++i) {
            while(num >= val[i]) {
                num -= val[i];
                result += str[i];
            }
        }
        return result;  */


        //解法三：
        string result = "";
        vector<string> v1{"", "M", "MM", "MMM"};
        vector<string> v2{"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        vector<string> v3{"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> v4{"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return v1[num / 1000] + v2[(num % 1000) / 100] + v3[(num % 100) / 10] + v4[num % 10];
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int num = stringToInteger(line);

        string ret = Solution().intToRoman(num);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
