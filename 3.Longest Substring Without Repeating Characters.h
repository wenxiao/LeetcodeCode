class Solution {
    //ʱ�䣬�ռ临�Ӷȣ�O(n)
public:
    int lengthOfLongestSubstring(string s) {
        //��¼ÿ���ַ��ϴγ��ֵ�λ��
        map<char,int> last_char_position;
        
        //��ǰ���ظ��ַ����ĳ�������󳤶�
        int len=0,maxlen=0;
        
        for(int i=0;i<s.size();i++){
            len++;
            
            if(last_char_position.find(s[i])!=last_char_position.end())
                //�������ַ���ǰ���ֹ�
                len=min(i-last_char_position[s[i]],len);
            
            maxlen=max(len,maxlen);
            last_char_position[s[i]]=i;
        }
        
        return maxlen;
    }
};