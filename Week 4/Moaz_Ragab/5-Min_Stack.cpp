class MinStack {
public:
    vector<vector<int>> st;

    MinStack() {

    }

    void push(int val) {
        int mn = getMin();
        if (st.empty() || mn > val) {
            mn = val;
        }
        st.push_back({val, mn});
    }

    void pop() {
        st.pop_back();
    }

    int top() {
        if(st.empty())
            return -1;
        return st.back()[0];
    }

    int getMin() {
        if(st.empty())
            return -1;
        return st.back()[1] ;
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