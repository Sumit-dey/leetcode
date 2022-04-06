class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size()-1;
        while(l < h)
        {
            cout << l << " " << h << endl;
            int m = (l+h)/2;
            if( nums[m] == target ) return m;
            if( nums[m] > nums[l] and target < nums[m] and target >= nums[l] )
            {
                h = m-1;
            }
            else if( nums[m] < nums[l] and ( target >= nums[l] or target < nums[m] ) )
            {
                h = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        cout << l << endl;
        if( nums[l] == target ) return l;
        return -1;

    }
};
