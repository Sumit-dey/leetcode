class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length=nums.size();
        int max=nums[0];
        int dp[length];
        dp[0]=nums[0];
        for(int i=1;i<length;i++){
            if(dp[i-1]>0)
                dp[i]=dp[i-1]+nums[i];

            else
                dp[i]=nums[i];

            if(dp[i]>max)
                max=dp[i];
        }

        return max;
    }
};
