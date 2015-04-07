class Solution {
    //题目感觉具有误导性
    //如果"ABCD",2的话，加密网格应该为：
    // A C
    // B D
    // 大小为5的网格为：
    // A     G
    // B   F H
    // C E   I
    // D     J
public:
    string convert(string s, int nRows) {
        if(nRows==1)
          return s;
          
        //可以将向下的与锯齿向上返回的看作两列
        int char_per_two_cols=nRows+nRows-2;
        //最大列数（不精确但是不影响最终结果）
        int max_cols=s.size()/char_per_two_cols*2+2;
        
        string ret;
        int pos;
        for(int r=0;r<nRows;r++){
            for(int c=0;c<max_cols;c++){
                //斜向上的列没列比向下的少两个元素，需要跳过
                if(c%2==1 && (r==0 || r==nRows-1))
                    continue;
                
                //如果属于向下的列
                if(c%2==0)
                    pos=r+c/2*char_per_two_cols;
                else
                //如果属于斜向上的列
                    pos=nRows+(nRows-r-2)+c/2*char_per_two_cols;
                    
                if(pos<s.size())
                    ret.push_back(s[pos]);
            }
        }
        return ret;
    }
};