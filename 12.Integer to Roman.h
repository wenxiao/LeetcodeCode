class Solution {
public:
    //对每一位进行处理
    string GetString(int digit, char one, char five, char ten){
        string ret;
        if(digit==4||digit==9){
            digit++;
            ret+=one;
        }
        
        if(digit==10){
            ret+=ten;
            digit-=10;
        }
        else if(digit>=5){
            ret+=five;
            digit-=5;
        }
        
        while(digit){
            digit--;
            ret+=one;
        }
        
        return ret;
    }
    
    
    string intToRoman(int num) {
        string ret;
        ret+=GetString(num/1000,'M','?','?');
        num%=1000;ret+=GetString(num/100,'C','D','M');
        num%=100;ret+=GetString(num/10,'X','L','C');
        num%=10;ret+=GetString(num/1,'I','V','X');
        return ret;
    }
};