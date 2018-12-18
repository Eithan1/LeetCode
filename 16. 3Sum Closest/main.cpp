#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        /*-----------方法一--------------
        int sum;
        int mindis = abs(nums[0] + nums[1] + nums[2] - target);
        int sumClosest = nums[0] + nums[1] + nums[2];
        int num = nums.size();
        for(int i = 0; i < num - 2; ++i) {
            for(int j = i + 1; j < num - 1; ++j) {
                for(int k = j + 1; k < num; ++k) {
                    sum = nums[i] + nums[j] + nums[k];
                    if(abs(sum - target) < mindis) {
                        mindis = abs(sum - target);
                        sumClosest = sum;
                    }
                }
            }
        }
        return sumClosest;
        */

        //方法二
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int head = 0;
        int tail = len - 1;
        int temp_sum;
        int temp_diff;
        int min_diff = INT_MAX;
        int sumClosest;
        for (int i = 0; i < len; ++i) {
            head = i + 1;
            tail = len - 1;
            while(head < tail) {
                temp_sum = nums[i] + nums[head] + nums[tail];
                temp_diff = abs(temp_sum - target);
                if(temp_diff < min_diff) {
                    min_diff = temp_diff;
                    sumClosest = temp_sum;
                }
                if(temp_sum == target)
                    return temp_sum;
                else if(temp_sum < target) {
                    ++head;
                }
                else if(temp_sum > target) {
                    --tail;
                }
            }
        }
        return sumClosest;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int target = stringToInteger(line);

        int ret = Solution().threeSumClosest(nums, target);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
