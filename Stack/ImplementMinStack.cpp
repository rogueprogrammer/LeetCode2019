//https://leetcode.com/problems/min-stack/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    int m;
    
    MinStack() {
        m = INT_MAX;    
    }
    
    void push(int x) {
        m = min(x, m);
        s.push(x);
    }
    
    void pop() {
        int t = top();
        s.pop();
        if(t == m){ //find a new min
            stack<int> s1; 
            m = INT_MAX;
            while(!s.empty()){
                t = s.top();
                s.pop();
                s1.push(t);
                m = min(m, t);
            }
            while(!s1.empty()){
                t = s1.top();
                s1.pop();
                s.push(t);
            }
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return m;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
