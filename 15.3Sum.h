class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int> &num) {
        //记录出现数字与频度
        map<int,int> numct;
        //返回值
        vector<vector<int>>rets;
        
        for(int i=0;i<num.size();i++){
            numct[num[i]]++;
        }
        
        for(auto i=numct.begin();i!=numct.end();i++){
            //修改对应数字的剩余可用频度
            //为0了表示对应的数字都已经用完了
            i->second--;
            for(auto j=i;j!=numct.end();j++){
                if(j->second==0)
                    continue;
                    
                j->second--;
                //为了防止一组数字被多次技术，因此不妨令
                if(i->first<=-i->first-j->first && j->first<=-i->first-j->first){
                    auto it=numct.find(-j->first-i->first);
                    if(it!=numct.end() && it->second>0){
                        vector<int>ret{i->first,j->first,-i->first-j->first};
                        rets.push_back(ret);
                    }
                }
                //恢复使用频度
                j->second++;
            }
            i->second++;
        }
        
        return rets;
    }
};