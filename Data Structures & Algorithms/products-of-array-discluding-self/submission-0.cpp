class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1,n=nums.size(),cont_zero=0,poz;
        vector <int> output(n,0);
        for(int i=0;i<n - 1;i++)
        {
            if(nums[i] == 0)
            {
                cont_zero ++;
                poz = i;
            }
            else
                product *= nums[i];
        }
        if(cont_zero >= 2)
            return output;
        else
            if(cont_zero == 1)
            {
                output[poz] = product * nums[n-1];
                return output;
            }
        output[n-1] = product;
        for(int i=0;i<n-1;i++)
            output[i] = (product / nums[i]) * nums[n-1];
        return output;
    }
};
