class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        //如果为空的话需要特殊处理。
        if(strs.size()==0)
            return prefix;
        for(int i=0;;i++){
            char c;
            for(int j=0;j<strs.size();j++){
                //如果越界了，则此前一个时刻的prefix是最长的prefix
                if(i>=strs[j].size())
                    return prefix;
                if(j==0)
                    c=strs[j][i];
                else if(c!=strs[j][i])
                    return prefix;
            }
            prefix.push_back(c);
        }
    }
};