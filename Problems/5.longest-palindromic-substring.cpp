// Given a string s, return the longest palindromic substring in s.

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();

        int start=0;
        int end=0;

        for(int i=0;i<n;i++){
            int left=i;
            int right=i;

            while(left>=0 && right<n){
                if(s[left]==s[right]){
                    if(right-left+1> end-start+1){
                        start=left;
                        end=right;
                    }
                    left--;
                    right++;
                }
                else break;
            }

            left=i;
            right=i+1;

            while(left>=0 && right<n){
                if(s[left]==s[right]){
                    if(right-left+1> end-start+1){
                        start=left;
                        end=right;
                    }
                    left--;
                    right++;
                }
                else break;
            }
        }
        return s.substr(start,end-start+1);
    }
};
