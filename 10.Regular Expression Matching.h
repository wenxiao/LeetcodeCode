class Solution {
public:
    //判断两个字符是否相等
    inline char isMatch(const char c,const char p){
        return c==p || p=='.';
    }
    bool isMatch(const char *s, const char *p) {
        //空串匹配～边界处理
        if(*s==0 && *p==0)
            return true;
        if(*p==0)
            return false;
        
        //如果有*号的话就递归向后匹配
        if(*(p+1)=='*'){
            for(int i=0;;i++){
                if(isMatch(s+i,p+2))
                    return true;
                if(*(s+i)==0 || !isMatch(*(s+i),*p))
                    return false;
            }
        }
        
        //否则判断两个字符是否相等，相等的话继续匹配
        return isMatch(*s,*p) && *s!=0 && isMatch(s+1,p+1);
    }
};