#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        /*  解法一：暴力解法
        int tmp_Area = 0;
        int max_Area = 0;
        int len = height.size();
        for(int i = 0; i < len - 1; ++i) {
            for(int j = i + 1; j < len; ++j) {
                if(j < len - 2 && height[j] < height[j + 1])
                    ++j;
                tmp_Area = (j - i) * (height[i] < height[j] ? height[i] : height[j]);
                if(max_Area < tmp_Area)
                    max_Area = tmp_Area;
            }
        }
        return max_Area;  */

        /* 方法二：两边向中间搜索 */
        int tmp_Area = 0;
        int max_Area = 0;
        int len = height.size();
        int head = 0;
        int tail = len - 1;
        while(head != tail) {
            tmp_Area = (tail - head) *
                       (height[head] < height[tail] ? height[head] : height[tail]);
            if (height[head] < height[tail])
                ++head;
            else
                --tail;
            if (max_Area < tmp_Area)
                max_Area = tmp_Area;
        }
        return max_Area;
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

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> height = stringToIntegerVector(line);

        int ret = Solution().maxArea(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
