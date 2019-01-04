#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;


class Solution {
public:
    void intRev(int* from, int* to ) { //vector是连续存储的内存空间
        int t;
        while(from < to) {
            t = *from;
            *from = *to;
            *to = t;
            from++;
            to--;
        }
    }

    void nextPermutation(vector<int>& nums) {
        //后找
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i + 1])
            --i;
        if(i < 0)  {     //已经是最大排列
            reverse(nums.begin(), nums.end());
            //intRev(&nums[0], &nums[nums.size() - 1]);
            return;
        }
        else {
            //小大
            int j = nums.size() - 1;
            while(nums[j] <= nums[i])
                --j;

            //交换
            swap(nums[j], nums[i]);

            //翻转
            reverse(nums.begin() + i + 1, nums.end());
            //intRev(&nums[i + 1], &nums[nums.size() - 1]);
        }
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

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);

        Solution().nextPermutation(nums);

        string out = integerVectorToString(nums);
        cout << out << endl;
    }
    return 0;
}
