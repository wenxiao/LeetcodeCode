class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string prefix;
        //���Ϊ�յĻ���Ҫ���⴦��
        if(strs.size()==0)
            return prefix;
        for(int i=0;;i++){
            char c;
            for(int j=0;j<strs.size();j++){
                //���Խ���ˣ����ǰһ��ʱ�̵�prefix�����prefix
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