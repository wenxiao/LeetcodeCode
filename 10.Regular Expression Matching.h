class Solution {
public:
    //�ж������ַ��Ƿ����
    inline char isMatch(const char c,const char p){
        return c==p || p=='.';
    }
    bool isMatch(const char *s, const char *p) {
        //�մ�ƥ�䡫�߽紦��
        if(*s==0 && *p==0)
            return true;
        if(*p==0)
            return false;
        
        //�����*�ŵĻ��͵ݹ����ƥ��
        if(*(p+1)=='*'){
            for(int i=0;;i++){
                if(isMatch(s+i,p+2))
                    return true;
                if(*(s+i)==0 || !isMatch(*(s+i),*p))
                    return false;
            }
        }
        
        //�����ж������ַ��Ƿ���ȣ���ȵĻ�����ƥ��
        return isMatch(*s,*p) && *s!=0 && isMatch(s+1,p+1);
    }
};