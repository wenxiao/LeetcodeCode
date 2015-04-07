 class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &num, int target) {
        vector<vector<int>> rets;
        
        //先对原数组进行排序
        sort(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
            //如果前面i已经等于过这个值了，跳过
            if(i>0 && num[i]==num[i-1])continue;
            for(int j=i+1;j<num.size();j++){
                //如果前面j已经等于过这个值了，跳过
                if(j>i+1&&num[j]==num[j-1])continue;
                for(int k=j+1,x=num.size()-1;k<num.size();k++){
                    //如果前面k已经等于过这个值了，跳过
                    if(k>j+1&&num[k]==num[k-1])continue;
                    
                    //夹逼查找合适的x
                    while(target-num[i]-num[j]-num[k]<num[x] && x>k)
                        x--;
                    //如果对当前的k，已经没有k<x能满足i+j+k+x>=target，对于更大的k显然也没有
                    //因此可以跳出k这层循环
                    if(x==k)
                        break;
                    
                    if(target-num[i]-num[j]-num[k]==num[x])
                    {
                        vector<int> ret{num[i],num[j],num[k],num[x]};
                        sort(ret.begin(),ret.end());
                        rets.push_back(ret);
                    }
                }
            }
        }
        
        return rets;
    }
};