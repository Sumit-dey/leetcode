class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> cnt;
        int ans=0;
        for(int i:nums1){
            for(int j:nums2)
                cnt[i+j]++;
        }

        for(int i:nums3){
            for(int j:nums4){
                if(cnt.count(-i-j)){
                    ans+= cnt[-i-j];
                }
            }
        }

        return ans;
    }
};
