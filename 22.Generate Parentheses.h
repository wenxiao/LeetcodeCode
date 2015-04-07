class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        for(int i=1;i<=n;i++){
            //ö�ٵ�һ�����Ű�����������������
            vector<string> first_part;
            
            //���⴦����n=0��ʱ��������Ŀ��˼��ͬ������һ�����
            if(i-1==0)
                first_part=vector<string>{""};
            else
                first_part=generateParenthesis(i-1);
            
            //ʹ�����Ž����������������
            for(int i=0;i<first_part.size();i++)
                first_part[i]="("+first_part[i]+")";
                
            vector<string> other_parts=generateParenthesis(n-i);
            if(n-i==0){
                other_parts=vector<string>{""};
            }
            
            for(const string& s1:first_part)
            for(const string& s2:other_parts)
                ret.push_back(s1+s2);
        }
        return ret;
    }
};