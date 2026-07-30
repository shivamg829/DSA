class MinStack {
private:
    stack<int>mainst;
    stack<int>minst;
public:
    MinStack() {
    }
    
    void push(int value) {
        mainst.push(value);
        if(minst.empty() || value<=minst.top()){
            minst.push(value);
        }
    }
    
    void pop() {
        int top = mainst.top();
        if(!minst.empty() && top==minst.top()){
            minst.pop();
        }
        mainst.pop();
        
    }
    
    int top() {
        if(!mainst.empty()){
            return mainst.top();
        }
        return 0;
    }
    
    int getMin() {
        if(!minst.empty()){
            return minst.top();
        }
        return 0;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */