class Solution {
    //��Ŀ�о���������
    //���"ABCD",2�Ļ�����������Ӧ��Ϊ��
    // A C
    // B D
    // ��СΪ5������Ϊ��
    // A     G
    // B   F H
    // C E   I
    // D     J
public:
    string convert(string s, int nRows) {
        if(nRows==1)
          return s;
          
        //���Խ����µ��������Ϸ��صĿ�������
        int char_per_two_cols=nRows+nRows-2;
        //�������������ȷ���ǲ�Ӱ�����ս����
        int max_cols=s.size()/char_per_two_cols*2+2;
        
        string ret;
        int pos;
        for(int r=0;r<nRows;r++){
            for(int c=0;c<max_cols;c++){
                //б���ϵ���û�б����µ�������Ԫ�أ���Ҫ����
                if(c%2==1 && (r==0 || r==nRows-1))
                    continue;
                
                //����������µ���
                if(c%2==0)
                    pos=r+c/2*char_per_two_cols;
                else
                //�������б���ϵ���
                    pos=nRows+(nRows-r-2)+c/2*char_per_two_cols;
                    
                if(pos<s.size())
                    ret.push_back(s[pos]);
            }
        }
        return ret;
    }
};