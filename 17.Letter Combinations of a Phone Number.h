class Solution {
    //��VS�ϲ���ͨ�����룬��Ϊ����������ʼ��mp�����Խ�����Ϊdfs������һ��static������ʼ�����ɡ�
public:
    //��Ӧÿ�����ֶ�Ӧ����ĸ��
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
    
    //����ÿһ�ֿ��ܵ����
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