class Solution {
    //��Ҫע��Ը�����Խ��Ĵ������������ʱ�򷵻�0������INT_MAX����INT_MIN
public:
    int reverse(long long x) {
        //�жϷ���
        int sign=1;
        if(x<0) {
            x=-x;
            sign=-1;
        }
        
        //��÷�������֡�Ϊ�˷�ֹ���ʹ��long long
        long long ret=0;
        while(x){
            ret*=10;
            ret+=x%10;
            x/=10;
        }
        
        //�ж��Ƿ����
        if(sign==1 && ret>INT_MAX)
            ret=0;
        if(sign==-1 && -ret<INT_MIN)
            ret=0;
            
        //д�ط���
        if(sign==-1)
            return -ret;
        else
            return ret;
    }
};