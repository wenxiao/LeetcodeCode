class Solution {
public:
    bool isValid(string s) {
        //���ڼ�¼��δƥ���������
        string stacks;
        for(char c:s){
            //������������ѹ��ջ��
            //�������������жϵ�ǰջ��Ԫ���Ƿ���֮ƥ��
            if(c=='(' || c=='{' || c=='[')
                stacks.push_back(c);
            else{ 
                if(c==')' && stacks.back()!='(')
                    return false;
                if(c=='}'&&stacks.back()!='{')
                    return false;
                if(c==']'&&stacks.back()!='[')
                    return false;
                stacks.pop_back();
            }
        }
        
        //ջΪ�ձ�ʾ����ȫ��ƥ�������������ʾ��������û�гɹ�ƥ��
        if(stacks.empty())
            return true;
        else
            return false;
    }
};