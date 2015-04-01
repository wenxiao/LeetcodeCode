//Runtime: 45 ms
class Solution {
public:
    //ԭʼint��ԭ������λ�õ�ӳ��
    //ע������һ�����������������γ��ֵ���������ʹ��vector����¼ÿ�����ֳ����������е�λ��
    map<int,vector<int>> pos;
    vector<int> twoSum(vector<int> &numbers, int target) {
        
        //���Ƚ�ÿ��������ԭ�����е�λ�ü�¼������
        //����ԭ���н������򣬸��Ӷ�ΪO(nlogn)
        //�����ɨ��һ�μ���֪���Ƿ������������Ľ⣬���Ӷ�ΪO(n)
        
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
                
                //��Ҫ�жϱ�֤��������С��
                if(pos[numbers[i]]<pos[numbers[j]])
                    return vector<int>{pos[numbers[i]][0],pos[numbers[j]][0]};
                else
                    return vector<int>{pos[numbers[j]][0],pos[numbers[i]][0]};
            }
        }
    }
};