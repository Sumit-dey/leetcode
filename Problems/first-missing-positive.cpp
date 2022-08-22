class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int ind = -1;
        for( int i = 0; i < nums.size(); i++ )
        {
            if( nums[i] == 1 )
            {
                ind = i;
                break;
            }
        }
        if( ind == -1 ) return 1;
        for( int i = 0; i < nums.size(); i++ )
        {
            if( nums[i] <= 0 or nums[i] > nums.size() ) nums[i] = 1;
        }

        for( int i = 0; i < nums.size(); i++ )
        {
            int v = abs(nums[i]);
            if( nums[v-1] > 0 )
            {
                nums[v-1] = - nums[v-1];
            }
        }
        int ans = nums.size() + 1;
        for( int i = 0; i < nums.size(); i++ )
        {
            if( nums[i] > 0 )
            {
                return i+1;
            }
        }

        return ans;

    }
};
