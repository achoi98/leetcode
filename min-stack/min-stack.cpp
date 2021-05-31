class MinStack {
public:
    vector<int> aStack;
    int minIndex;
    
    /** initialize your data structure here. */
    MinStack() {
        minIndex = 0;
    }
    
    void push(int val) {
        aStack.push_back(val);
        if (val < aStack[minIndex]) minIndex = aStack.size() - 1;
    }
    
    void pop() {
        aStack.pop_back();
        if (minIndex >= aStack.size()) {
            minIndex = 0;
            for (int i = 0; i < aStack.size(); i++) {
                if (aStack[i] < aStack[minIndex]) minIndex = i;
            }
        }
    }
    
    int top() {
        return aStack[aStack.size() - 1];
    }
    
    int getMin() {
        return aStack[minIndex];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */