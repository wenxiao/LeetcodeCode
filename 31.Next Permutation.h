class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //�ҵ�����num[i]<num[i+1]�����꣬�����������Ԫ�ص���С��һ�����以��λ�ã�����ʣ�µ�Ԫ�ذ��մ�С��������
        int i;
        
        for(i=nums.size()-2;i>=0;i--)
            if(nums[i]<nums[i+1])
                break;
        if(i<0){
            //����Ҳ���������꣬��
            sort(nums.begin(),nums.end());
        }else{
			int j;
			for(j=nums.size()-1;;j--)
				if(nums[i]<nums[j])
					break;
            swap(nums[i],nums[j]);
            sort(nums.begin()+i+1,nums.end());
        }
    }
};