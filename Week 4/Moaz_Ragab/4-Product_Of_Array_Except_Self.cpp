
//used division
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
    int prod=1;
                int zeroes=0;
        if(nums[0]!=0)
       prod=nums[0];
        else zeroes++;

        for(int i=1;i<n;i++)
        {
            if(nums[i]!=0)
           prod*=nums[i];
            else{
              
                zeroes++;
            }

        }
        vector<int>ans(n,0);
        if(zeroes>1)
        {
            return ans;
        }
        else if(zeroes==1)
        {
          for(int i=0;i<n;i++)
          {
            if(nums[i]==0)
            {
                ans[i]=prod;
                return ans;
            }
          }
        }
        else
        {
            for(int i=0;i<n;i++)
            ans[i]=prod/nums[i];
        }
        return ans;
    }
};
//without using division
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size(), 1);

        int left = 1;
        for (int i = 0; i < nums.size(); i++) {
            output[i] *= left;
            left *= nums[i];
        }

        int right = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            output[i] *= right;
            right *= nums[i];
        }

        return output;        
    }
};