class Solution {
public:
    int romanToInt(string s) {
        int ret=0;
        
        if(s.find("IV")!=string::npos){
            ret-=2;
        }
        if(s.find("IX")!=string::npos){
            ret-=2;
        }
        if(s.find("XL")!=string::npos){
            ret-=20;
        }
        if(s.find("XC")!=string::npos){
            ret-=20;
        }
        if(s.find("CD")!=string::npos){
            ret-=200;
        }
        if(s.find("CM")!=string::npos){
            ret-=200;
        }
        
        for(int i=0;i<s.size();i++){
            switch(s[i]){
                case 'I':ret++;break;
                case 'V':ret+=5;break;
                case 'X':ret+=10;break;
                case 'L':ret+=50;break;
                case 'C':ret+=100;break;
                case 'D':ret+=500;break;
                case 'M':ret+=1000;break;
            }
        }
        return ret;
    }
};