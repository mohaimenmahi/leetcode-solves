/*
We will use 2 stacks.

While iterating through the string s:
# if the current index is unlocked, take it in unlocked stack
# else if the current index is '(', take it in the openBrackets stack
# else check:
    ## if there are available openBracket on left, for balancing, pop one from the openBrackets
    ## else if no openBrackets, use the latest unlocked (top element) to balacne by poping this
    ## else we can not make it valid, so return true

if we have some elements left on openBrackets and unlocked stack, we will check if we
can balance them. for balancing them, the index of the existing open brackets needs to be 
lower then the alternative unlocked, otherwise we can not balance.
for example: in x(x(x, the last 2 (x can be balanced, also the second last (x, but still there is 
a remaining x on the first index, so we can not balance the remaining

if we have like this (xxx, the last x can be balanced by the first index (, so the remainig xx can be replaced
as () so we can balance it. 

for more, see below code:
*/

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();

        if(n % 2) return false;

        stack<int> openBrackets, unlocked;

        for(int i = 0; i < n; i++) {
            if(locked[i] == '0') unlocked.push(i);
            else if(s[i] == '(') openBrackets.push(i);
            else {
                if(!openBrackets.empty()) {
                    openBrackets.pop(); // balancing the current index ')' with last appeared locked '('
                } else if(!unlocked.empty()) {
                    unlocked.pop(); // balancing with the last appeared unlocked
                } else return false; // for the current ')', we neither have locked openBrackets or unlocked brackets
            }
        }

        // Match the remaining unused elements
        while(!openBrackets.empty() && !unlocked.empty() && openBrackets.top() < unlocked.top()) {
            openBrackets.pop();
            unlocked.pop();
        }

        return openBrackets.empty();
    }
};