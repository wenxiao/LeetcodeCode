class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n==0)return 0;
        
        //��¼ѹ����Ķ���λ��
        int compress_ptr=1;
        for(int i=1;i<n;i++){
            if(A[i]==A[i-1])
                continue;
            A[compress_ptr++]=A[i];
        }
        return compress_ptr;
    }
};