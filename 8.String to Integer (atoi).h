class Solution {
    //这里主要注意对符号的处理
    //开始写的时候是允许数字前面包括多个正负号的，没想到这样处理反而被判错了。
    //前导空格的处理……也……
public:
    int atoi(string& s) {
        long long ret=0;
        int sign=1;
        int i=0;
        
        //清楚前导空格。。。。。。。。。。。。。。。。
        while(s[i]==' ')i++;
        
        //判断符号
        if(s[i]=='+'||s[i]=='-'){
            if(s[i]=='-')sign=-sign;
            i++;
        }
        
        //读入数字，随时判断是否溢出
        while(i<s.size()){
            if(s[i]>='0'&&s[i]<='9'){
                ret*=10;
                ret+=s[i]-'0';
                if(sign==-1&&-ret<INT_MIN)
                    return INT_MIN;
                if(sign==1&&ret>INT_MAX)
                    return INT_MAX;
                i++;
            }else{
                break;
            }
        }
        
        return sign*ret;
    }
};