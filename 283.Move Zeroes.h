class Solution {
public:
	//������ָ�룬һ����ʾ��ǰɨ�赽��λ�ã�һ����ʾ��һ����0Ԫ����Ҫ�����λ�á�
	//ע��ɨ�����Ժ��ʣ�����������䡣
    void moveZeroes(vector<int>& nums) {
        int l=0,r=0;
        while(r<nums.size()){
            if(nums[r])
                nums[l++]=nums[r];
            r++;
        }
        while(l<nums.size())nums[l++]=0;
    }
};