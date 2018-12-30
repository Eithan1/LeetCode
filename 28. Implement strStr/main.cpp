#include <iostream>
#include <string>
#include <assert.h>
#include <cstring>
using namespace std;


class Solution {
public:
    //求模式串的next数组
    void getNext(char * p, int next[])
    {
        int nLen = (int)strlen(p);
        next[0] = -1;
        int k = -1;
        int j = 0;

        while (j < nLen - 1)
        {
            //此刻，k即next[j-1]，且p[k]表示前缀，p[j]表示后缀
            //注：k==-1表示未找到k前缀和k后缀相等，首次分析可先忽略
            if (k == -1 || p[j] == p[k])
            {
                ++j;
                ++k;
                next[j] = k;
            }
            else     //p[j]与p[k]失配，则继续递归计算前缀p[next[k]]
                k = next[k];
        }
    }

    //KMP算法
    int KMP(char * t, char * p)
    {
        //先求模式串的next数组
        int next[int(strlen(p))];
        //int* next = new int[strlen(p)];

        getNext(p, next);

        int i = 0;
        int j = 0;
        int ans = -1;

        while (i < strlen(t))
        {

            if (j == -1 || t[i] == p[j])
            {
                i++;
                j++;
            }
            else
                j = next[j];
            if (j == strlen(p)) {
                ans = i - strlen(p);
                break;
            }
        }
        return ans;
    }

    //KMP算法，从文本串中找出模式串第一次出现的位置
    //haystack为文本串，needle为模式串
    int strStr(string haystack, string needle) {
        //空串则直接返回0
        if(needle == "")
            return 0;

        //将string转化为char*
        char* t = new char[haystack.length() + 1];
        strcpy(t, haystack.c_str());
        char* p = new char[needle.length() + 1];
        strcpy(p, needle.c_str());
        return KMP(t, p);
    }
};

string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    //freopen("input.txt", "r", stdin);
    string line;
    while (getline(cin, line)) {
        string haystack = stringToString(line);
        getline(cin, line);
        string needle = stringToString(line);

        int ret = Solution().strStr(haystack, needle);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
