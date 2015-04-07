class Solution {
public:
    bool isPalindrome(int x) {
        //通过将数字取反来判断一个数字是否为回文串。
        //负数……都被当成非回文串，因此也简化了很多判断。
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