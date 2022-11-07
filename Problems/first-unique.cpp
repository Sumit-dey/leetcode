class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.length();
        if(n==1)
            return 0;
        vector<int> vc(26,0);
        for(int i=0;i<n;i++){
            int j=s[i]-97;
            vc[j]++;
        }
        for(int i=0;i<n;i++){
            int k=s[i]-97;
            if(vc[k]==1){
                return i;
            }
        }
        return -1;
    }
};
