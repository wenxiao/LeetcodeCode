//Runtime: 45 ms
class Solution {
public:
    //原始int到原序列中位置的映射
    //注意会出现一个数字在序列中两次出现的情况，因此使用vector来记录每个数字出现在序列中的位置
    map<int,vector<int>> pos;
    vector<int> twoSum(vector<int> &numbers, int target) {
        
        //首先将每个数字在原序列中的位置记录下来，
        //随后对原序列进行排序，复杂度为O(nlogn)
        //排序后扫描一次即可知道是否有满足条件的解，复杂度为O(n)
        
        for(int i=0;i<numbers.size();i++)
            pos[numbers[i]].push_back(i+1);
        sort(numbers.begin(),numbers.end());
        
        int j=numbers.size()-1;
        for(int i=0;i<numbers.size();i++){
            while(numbers[i]+numbers[j]>target && j>0)j--;
            
            if(numbers[i]+numbers[j]==target){
                if(numbers[i]==numbers[j]){
                    return vector<int>{pos[numbers[i]][0],pos[numbers[i]][1]};
                }
                
                //需要判断保证先输出序号小的
                if(pos[numbers[i]]<pos[numbers[j]])
                    return vector<int>{pos[numbers[i]][0],pos[numbers[j]][0]};
                else
                    return vector<int>{pos[numbers[j]][0],pos[numbers[i]][0]};
            }
        }
    }
};