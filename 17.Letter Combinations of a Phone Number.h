class Solution {
    //在VS上不能通过编译，因为不能这样初始化mp，可以将其作为dfs函数的一个static变量初始化即可。
public:
    //对应每个数字对应的字母表
    map<char,vector<char>> mp={
        {'1',{}},
        {'2',{'a','b','c'}},
        {'3',{'d','e','f'}},
        {'4',{'g','h','i'}},
        {'5',{'j','k','l'}},
        {'6',{'m','n','o'}},
        {'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},
        {'9',{'w','x','y','z'}},
        {'0',{}}
    };
    
    //遍历每一种可能的情况
    void dfs(vector<string>& ret, const string& digits, string& current,int depth){
        if(depth==digits.size()){
            ret.push_back(current);
            return;
        }
        
        for(int i=0;i<mp[digits[depth]].size();i++){
            current[depth]=mp[digits[depth]][i];
            dfs(ret,digits,current,depth+1);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if(digits=="")
            return ret;
        
        string current=digits;
        dfs(ret,digits,current,0);
        return ret;
    }
};