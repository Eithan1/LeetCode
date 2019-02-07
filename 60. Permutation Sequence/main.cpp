#include <iostream>
#include <string>
#include <vector>
//#include <algorithm>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        /*------方法一----------
        vector<int> num;
        string res = "";

        //形成第一个排列
        for(int i = 1; i <= n; ++i) {
            num.push_back(i);
        }

        //求第k个排列
        while(--k) {
            next_permutation(num.begin(), num.end());
        }

        //将结果转化为string
        for(int i = 0; i < num.size(); ++i) {
            res += to_string(num[i]);
        }

        return res;
         */

        /*------方法二----------*/
        string res;
        string num = "123456789";
        vector<int> f(n, 1);

        for (int i = 1; i < n; ++i)
            f[i] = f[i - 1] * i;

        --k;

        for (int i = n; i >= 1; --i) {
            int j = k / f[i - 1];
            k %= f[i - 1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }

        return res;
    }
};


int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        getline(cin, line);
        int k = stringToInteger(line);

        string ret = Solution().getPermutation(n, k);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
