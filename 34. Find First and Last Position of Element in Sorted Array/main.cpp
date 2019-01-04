#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> res;
        int min = -1, max = -1;
        int len = nums.size();
        int left = 0, right = len - 1;

        //找第一个target
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target && (nums[mid - 1] != target || mid == 0)) {
                min = mid;
                break;
            }
            else if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] >= target)    //等于的话也继续向左查找，直到是第一个等于target的数，
                right = mid - 1;                            // 目的是找到第一次等于target的数
        }

        //找最后一个target
        left = 0, right = len - 1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target && (nums[mid + 1] != target || mid == len - 1)) {
                max = mid;
                break;
            }
            else if(nums[mid] <= target)    //等于的话也继续向右查找，直到是最后一个等于target的数，
                left = mid + 1;             //目的是找到最后一次等于target的数
            else if(nums[mid] > target)
                right = mid - 1;
        }

        res.push_back(min);
        res.push_back(max);
        return res;
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

int stringToInteger(string input) {
    return stoi(input);
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
        getline(cin, line);
        int target = stringToInteger(line);

        vector<int> ret = Solution().searchRange(nums, target);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}
