class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int> &num) {
        //��¼����������Ƶ��
        map<int,int> numct;
        //����ֵ
        vector<vector<int>>rets;
        
        for(int i=0;i<num.size();i++){
            numct[num[i]]++;
        }
        
        for(auto i=numct.begin();i!=numct.end();i++){
            //�޸Ķ�Ӧ���ֵ�ʣ�����Ƶ��
            //Ϊ0�˱�ʾ��Ӧ�����ֶ��Ѿ�������
            i->second--;
            for(auto j=i;j!=numct.end();j++){
                if(j->second==0)
                    continue;
                    
                j->second--;
                //Ϊ�˷�ֹһ�����ֱ���μ�������˲�����
                if(i->first<=-i->first-j->first && j->first<=-i->first-j->first){
                    auto it=numct.find(-j->first-i->first);
                    if(it!=numct.end() && it->second>0){
                        vector<int>ret{i->first,j->first,-i->first-j->first};
                        rets.push_back(ret);
                    }
                }
                //�ָ�ʹ��Ƶ��
                j->second++;
            }
            i->second++;
        }
        
        return rets;
    }
};