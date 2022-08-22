class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        int a=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i]+nums[j]==target && i!=j && a==0){
                    v.push_back(i);
                    v.push_back(j);
                    a=1;

                }
            }
        }
        return v;
    }
};
