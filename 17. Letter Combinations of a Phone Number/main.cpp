class Solution{
private:
    vector<string> res;
    vector<string> phone = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    void dfs(string& digits,int idx,string tmp){
        if(idx == digits.size()){
            res.push_back(tmp);
            return;
        }
        for(int i = 0;i < phone[digits[idx] - '0'].size();++i){
            dfs(digits,idx + 1,tmp + phone[digits[idx] - '0'][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res;
        dfs(digits,0,"");
        return res;
    }
};
