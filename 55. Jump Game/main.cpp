#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {

        int len = nums.size();
        int maxreach = 0;  //最远可以到达的位置(索引)

        for(int i = 0; i < len; ++i) {
            if(i > maxreach) //到达不了该位置的元素，后面没有意义，直接返回false
                return false;
            maxreach = max(maxreach, i + nums[i]); //随着遍历更新维护最远可以到达位置
        }

        if(maxreach >= len - 1)
            return true;
        else
            return false;

    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        bool ret = Solution().canJump(nums);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
