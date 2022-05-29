class Solution {
     vector<string> ans;

     void generatep(vector<string> ans,string s,int a,int b, int n){
        if(a==n && b==n){
            ans.push_back(s);
            return;
    }

        if(a<n)generatep(ans,s+'(',a+1,b,n);
        if(b<n)generatep(ans,s+')',a,b+1,n);
    }
public:
    vector<string> generateParenthesis(int n) {
        generatep(ans,"",0,0,n);
        return ans;
    }
};
