class Solution {
public:
    bool isValid(string s) {
        //用于记录尚未匹配的左括号
        string stacks;
        for(char c:s){
            //发现左括号则压入栈中
            //发现右括号则判断当前栈顶元素是否与之匹配
            if(c=='(' || c=='{' || c=='[')
                stacks.push_back(c);
            else{ 
                if(c==')' && stacks.back()!='(')
                    return false;
                if(c=='}'&&stacks.back()!='{')
                    return false;
                if(c==']'&&stacks.back()!='[')
                    return false;
                stacks.pop_back();
            }
        }
        
        //栈为空表示括号全部匹配正常，否则表示还有括号没有成功匹配
        if(stacks.empty())
            return true;
        else
            return false;
    }
};