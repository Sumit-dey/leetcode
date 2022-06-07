#include<bits/stdc++.h>
using namespace std;

string greedyCandyCrush(string s){
    for(int i=0;i<s.length();++i){

        if(i+2<s.length() && i+1<s.length() && s[i]==s[i+1] && s[i]==s[i+2]){  // found the series of atleast 3 similar elements
            int j = i;
            i+=2;

            char repeated = s[i];

            while(i<s.length() && s[i]==repeated){ // For more than 3 repeats of the same character
                ++i;
            }

            string left = string(s.begin(),s.begin()+j);
            string right = string(s.begin()+i,s.end());

            left.append(right);

            return greedyCandyCrush(left);
        }

    }
    return s;
}

int main() {

    string s = "aabbbacd";


    std::cout << greedyCandyCrush(s) << endl;
  }
