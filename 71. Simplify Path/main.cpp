#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        int i = 0;
        while(i < path.size()) {
            while(path[i] == '/' && i < path.size()) //找到第一个非'/'的下标，标记为start
                ++i;
            int start = i;

            while(path[i] != '/' && i < path.size()) //找到下一个'/'之前的下标，标记为end，从而确定两个'/'之间的内容
                ++i;
            int end = i - 1;

            if(start > end)
                break;

            string s = path.substr(start, end - start + 1); //两个'/'之间的内容
            if(s == "..") {  //'..'则删除前面的目录
                if (!v.empty())
                    v.pop_back();
            }
            else if(s != ".")  //'.'则保持不动，不是'.'则加入目录
                v.push_back(s);
        }

        if(v.empty()) return "/"; //什么都没有则返回根目录；
        string res;
        for(int i = 0; i < v.size(); ++i) {    //依次将各个目录以'/'连接
            res += '/' + v[i];
        }
        return res;
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
    string line;
    while (getline(cin, line)) {
        string path = stringToString(line);

        string ret = Solution().simplifyPath(path);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
}
