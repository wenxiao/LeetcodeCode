class Solution {
    //������Ҫע��Է��ŵĴ���
    //��ʼд��ʱ������������ǰ�������������ŵģ�û�뵽�������������д��ˡ�
    //ǰ���ո�Ĵ�����Ҳ����
public:
    int atoi(string& s) {
        long long ret=0;
        int sign=1;
        int i=0;
        
        //���ǰ���ո񡣡�����������������������������
        while(s[i]==' ')i++;
        
        //�жϷ���
        if(s[i]=='+'||s[i]=='-'){
            if(s[i]=='-')sign=-sign;
            i++;
        }
        
        //�������֣���ʱ�ж��Ƿ����
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