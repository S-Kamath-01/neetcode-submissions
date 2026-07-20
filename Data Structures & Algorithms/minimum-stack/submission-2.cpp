class MinStack {
public:
    //One stack optimal approach
    long long min;
    stack<long long> stk;
    MinStack(){}
    
    void push(int val) {
        if(stk.empty()){
            stk.push(0);
            min = val;
        }
        else{
            stk.push(val - min);
            if(val<min){
                min = val;
            }
        }
    }
    
    void pop() {
        if(stk.empty()) return;
        long long pop = stk.top();
        stk.pop();
        if(pop<0){
            min = min-pop;
        }     
    }
    
    int top() {
        long long top = stk.top();
        return(top>0)?(top+min):(int)min;
    }
    
    int getMin() {
        return (int)min;
    }
    //Time Complexity - O(1) for all operations
    //Space Complexity - O(n)
};
