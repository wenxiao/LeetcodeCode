class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        for(int i=1;i<=n;i++){
            //枚举第一个括号包括起来的括号数量
            vector<string> first_part;
            
            //特殊处理：当n=0的时候处理与题目意思不同，看做一种情况
            if(i-1==0)
                first_part=vector<string>{""};
            else
                first_part=generateParenthesis(i-1);
            
            //使用括号将所有情况包裹起来
            for(int i=0;i<first_part.size();i++)
                first_part[i]="("+first_part[i]+")";
                
            vector<string> other_parts=generateParenthesis(n-i);
            if(n-i==0){
                other_parts=vector<string>{""};
            }
            
            for(const string& s1:first_part)
            for(const string& s2:other_parts)
                ret.push_back(s1+s2);
        }
        return ret;
    }
};