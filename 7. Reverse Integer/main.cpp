#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int numRev = 0;
        while (x != 0) {
            int rmd = x % 10;
            x /= 10;
            if(numRev > INT_MAX / 10 || numRev == INT_MAX / 10 && rmd > 7)
                return 0;
            if(numRev < INT_MIN / 10 || numRev == INT_MIN / 10 && rmd < -8)
                return 0;
            numRev = numRev * 10 + rmd;
        }
        return numRev;
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        int ret = Solution().reverse(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
