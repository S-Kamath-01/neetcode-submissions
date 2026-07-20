class MinStack {
public:
    //Brute Force Approach
    stack<int> stk;
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
    }
    
    void pop() {
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        stack<int> temp;
        int mini = stk.top();
        while(stk.size()){
            mini = min(mini,stk.top());
            temp.push(stk.top());
            stk.pop();
        }
        while(temp.size()){
            stk.push(temp.top());
            temp.pop();
        }
        return mini;
        // Time Complexity - O(n) for getMin() and O(1) for other operations
        // Space Complexity - O(n) for getMin() and O(1) for other operations
    }
};
