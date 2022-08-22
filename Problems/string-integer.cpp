class Solution {
public:
    int myAtoi(string s) {
        int flag=1;
        int index=0;
        int ans=0;
        int n= s.size();

        while(index<n && s[index]==' '){
            index++;
        }

        if(index<n && s[index]=='+'){
            flag=1;
            index++;
        }
        else if(index<n && s[index]=='-'){
            flag=-1;
            index++;
        }

        while(index<n && isdigit(s[index])){
            int digit= s[index]-'0';

            if(ans> INT_MAX/10 || (ans==INT_MAX/10 && digit> INT_MAX%10)){
                return flag==1? INT_MAX:INT_MIN;
            }
            ans=10*ans +digit;
            index++;
        }

        return flag*ans;

    }
};
