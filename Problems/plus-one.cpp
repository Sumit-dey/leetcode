class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        if(digits[digits.size()-1]<9){
            digits[digits.size()-1]=digits[digits.size()-1]+1;
            return digits;
        }
        else{
            int carry=1;
            ans.push_back(0);
            for(int i=digits.size()-2;i>=0;i--){
                ans.push_back((digits[i]+carry)%10);
                carry=(digits[i]+carry)/10;
            }
            if(carry==1)ans.push_back(1);

            reverse(ans.begin(),ans.end());
             return ans;
        }
    }
};
