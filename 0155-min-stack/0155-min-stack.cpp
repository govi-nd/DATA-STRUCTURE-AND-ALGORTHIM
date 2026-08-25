class MinStack {
public:
    vector<pair<int,int>> a;

    MinStack() {
        
    }
    
    void push(int value) {
        if (a.empty()) {
            a.push_back({value, value});
        }
        else {
            int mini = min(value, a.back().second);
            a.push_back({value, mini});
        }
    }
    
    void pop() {
        a.pop_back();
    }
    
    int top() {
        return a.back().first;
    }
    
    int getMin() {
        return a.back().second;
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