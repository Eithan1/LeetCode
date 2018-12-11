#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int num = x;
        int num_rev = 0;
        while(num > 0) {
            num_rev = num_rev * 10 + num % 10;
            num /= 10;
        }
        return x == num_rev;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        bool ret = Solution().isPalindrome(x);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
