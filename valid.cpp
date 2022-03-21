class Solution {
public:
    int getBracketIndex(char bracket)
    {
        string openBrackets = "({[";
        for(char c:openBrackets){
            if(c == bracket) return -1;
        }
        string closingBrackets = ")}]";
        for(int i = 0 ; i < closingBrackets.size() ; i++){
            char c = closingBrackets[i];
            if(c == bracket) return i;
        }
        return closingBrackets.size();
    }
    bool isValid(string s) {
        string openBrackets = "({[";
        stack < char > Stack;
        for(char c:s){
            int index = getBracketIndex(c);
            if(index < 0) Stack.push(c);
            else if(Stack.empty() || Stack.top() != openBrackets[index]) return false;
            else Stack.pop();
        }
        if(Stack.empty()) return true;
        return false;
    }
};
