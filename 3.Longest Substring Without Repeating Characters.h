class Solution {
    //时间，空间复杂度：O(n)
public:
    int lengthOfLongestSubstring(string s) {
        //记录每个字符上次出现的位置
        map<char,int> last_char_position;
        
        //当前无重复字符串的长度与最大长度
        int len=0,maxlen=0;
        
        for(int i=0;i<s.size();i++){
            len++;
            
            if(last_char_position.find(s[i])!=last_char_position.end())
                //如果这个字符以前出现过
                len=min(i-last_char_position[s[i]],len);
            
            maxlen=max(len,maxlen);
            last_char_position[s[i]]=i;
        }
        
        return maxlen;
    }
};