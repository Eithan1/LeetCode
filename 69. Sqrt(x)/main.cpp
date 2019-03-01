#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
   int mySqrt(int x) {
        /*------牛顿迭代法--------
        if(x <= 1)    //x=0返回0，x=1返回1
            return x;

        double r = 1;
        double pre_r = 0;

        while(abs(r - pre_r) > 1e-6) {
            pre_r = r;
            r = (r + x / r) / 2;
        }
        //或（两种循环终止条件均可）
//        while(abs(pow(r, 2) - x) > 1e-6) {
//           //pre_r = r;
//            r = (r + x / r) / 2;
//        }

        return int(r);             */

        /*--------二分查找法---------*/
       if (x <= 1) {
           return x;
       }

       int l = 1, h = x;
       while (l <= h) {
           int mid = l + (h - l) / 2;
           int sqrt = x / mid;
           if (sqrt == mid) {
               return mid;
           } else if (sqrt < mid) {
               h = mid - 1;
           } else {
               l = mid + 1;
           }
       }
       return h;     //结束循环时h比l小1，故返回h
    }
};

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int x = stringToInteger(line);

        int ret = Solution().mySqrt(x);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
