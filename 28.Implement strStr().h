class Solution {
public:
    //using hash to check if two str is the same~
    //not always right, but~~~it can approach 2^64 if we use a mod approximate to 2^64
    //通过hash函数h=p^s x_0 + p^{s-1} x_1 + ... + p^0 x_s
    //判断两个字符串是否相等
    //时间复杂度为O(n+m)，n与m分别为两个字符串的长度
    int strStr(string haystack, string needle) {
        const long long llprime=1009;
        const long long llmod=274876858367LL;
        
        //llprime^needle.size() (mod in llmod)
        long long llprime_pow_needle=1;
        
        long long needle_hash_number=0;
        for(int i=0;i<needle.size();i++){
            llprime_pow_needle*=llprime;
            llprime_pow_needle%=llmod;
            
            needle_hash_number=(needle_hash_number*llprime+needle[i])%llmod;
        }
        
        long long current_hash_number=0;
        for(int i=0;i<haystack.size();i++){
            if(i<needle.size()){
                current_hash_number=(current_hash_number*llprime+haystack[i])%llmod;
            }
            else{
                if(current_hash_number==needle_hash_number)
                    return i-needle.size();
                current_hash_number=(current_hash_number*llprime+haystack[i] -haystack[i-needle.size()]*llprime_pow_needle)%llmod;
                //in case haystack[i-needle.size()>current_hash_number*llprime+haystack[i] and 
                //current_hash_number become nagetive
                current_hash_number=(current_hash_number+llmod)%llmod;
            }
        }
        if(current_hash_number==needle_hash_number)
            return haystack.size()-needle.size();
        return -1;
    }
};