
//https://leetcode.com/problems/implement-stack-using-queues/

class MyStack {
public:
    queue<int> q;
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        while (q.front() != x) {
            int t = q.front();
            q.pop();
            q.push(t);
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int last = q.back();
        while (q.front() != last) {
            int t = q.front();
            q.pop();
            q.push(t);
        }
        q.pop();
        return last;
    }

    /** Get the top element. */
    int top() {
        return q.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};
