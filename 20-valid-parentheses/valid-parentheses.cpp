class Solution {
public:
    // bool validCloseParentheses(char )
    bool isValid(string s) {
        stack<char> counter;
        set<char> openers {'(','[','{'};
        map<char,char> closerNeeds { {')', '('}, {']', '['}, {'}', '{'} };
        
        for(char c : s){
            if(openers.find(c) != openers.end())
                counter.push(c);
            else {
                if(counter.size() == 0 || counter.top() != closerNeeds[c])
                    return false;
                counter.pop();
            }
        }
        return counter.size() == 0;
    }
};