class Solution {
public:
    bool isValid(string s) {
       // Optimal Solution- using stacks
       stack<char> stk;
       unordered_map<char,char> closeToOpen = {
        {')','('},
        {']','['},
        {'}','{'}
       }; 
       for(char c: s){
        if(closeToOpen.count(c)){
            if(!stk.empty() && stk.top()== closeToOpen[c]){
                stk.pop();
            }else{
                return false;
            }
        }else{
            stk.push(c);
        }
       }
       return stk.empty();
    }
    //Time Complexity - O(n)
    //Space complexity - O(n)
};
