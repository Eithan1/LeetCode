#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {

        if(n == 1)
            return "1";

        string lastStr = countAndSay(n - 1);
        string resStr = "";

        int i = 0;
        char numToChar[10] = {'1', '2', '3', '4', '5',
                              '6', '7', '8', '9'};
        while(i < lastStr.size()) {
            for(int j = 0; j < 9; ++j) {
                if(lastStr[i] == numToChar[j]) {
                    int num = 1;
                    i++;
                    while(lastStr[i] == numToChar[j] && i < lastStr.size()) {
                        num++;
                        i++;
                    }
                    resStr += to_string(num) + numToChar[j];
                    j = 0;
                }
            }
        }
        return resStr;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        string ret = Solution().countAndSay(n);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
