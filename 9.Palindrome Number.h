class Solution {
public:
    bool isPalindrome(int x) {
        //ͨ��������ȡ�����ж�һ�������Ƿ�Ϊ���Ĵ���
        //���������������ɷǻ��Ĵ������Ҳ���˺ܶ��жϡ�
        if(x<0)
            return false;
        int tx=x,t=0;
        while(tx){
            t=t*10+tx%10;
            tx/=10;
        }
        if(t==x)
            return true;
        return false;
    }
};