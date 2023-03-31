/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
    long long minVal;
    stack<long long> min_stack;
public:
    MinStack() {}
    
    void push(int val) {
        if (min_stack.empty()) {
            minVal = val;
            min_stack.push(val);
        } else {
            min_stack.push(val - minVal);
            minVal = minVal >= val ? val : minVal;
        }
    }
    
    void pop() {
        if (min_stack.top() >= 0) {
            min_stack.pop();
            return;
        }
        long long tmp = min_stack.top();
        min_stack.pop();
        minVal = minVal - tmp;
        return;
    }
    
    int top() {
        if (min_stack.top() >= 0 && min_stack.size() != 1) {
            return min_stack.top() + minVal;
        } else if (min_stack.top() >= 0) {
            return minVal;
        }
        return minVal;
    }
    
    int getMin() {
        return minVal;
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
// @lc code=end

/**
 * @brief 
 * ["MinStack","push","push","top","getMin","pop","getMin","top"]\n[[],[1],[2],[],[],[],[],[]]\n
 * 
 * ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]\n[[],[2147483646],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]\n
 * [null,null,null,null,2147483647,null,2147483646,null,2147483646,null,null,2147483647,2147483647,null,-2147483648,-2147483648,null,2147483647]
 */