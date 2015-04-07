class Solution {
    //需要注意对负数和越界的处理，这里溢出的时候返回0而不是INT_MAX或者INT_MIN
public:
    int reverse(long long x) {
        //判断符号
        int sign=1;
        if(x<0) {
            x=-x;
            sign=-1;
        }
        
        //获得反序的数字。为了防止溢出使用long long
        long long ret=0;
        while(x){
            ret*=10;
            ret+=x%10;
            x/=10;
        }
        
        //判断是否溢出
        if(sign==1 && ret>INT_MAX)
            ret=0;
        if(sign==-1 && -ret<INT_MIN)
            ret=0;
            
        //写回符号
        if(sign==-1)
            return -ret;
        else
            return ret;
    }
};