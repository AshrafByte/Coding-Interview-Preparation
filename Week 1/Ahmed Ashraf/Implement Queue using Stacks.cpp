class MyQueue
{
public:
    stack <int> que,temp ;
    MyQueue()
    {
    }

    void fillFromTo (stack<int> &src , stack<int> &des)
    {
        while (!src.empty())
        {
            des.push(src.top());
            src.pop();
        }
    }

    void updateQueue(int x)
    {
        fillFromTo(que,temp);
        que.push(x);
        fillFromTo(temp,que);
    }


    void push(int x)
    {
        updateQueue(x);
    }

    int pop()
    {   
        if (que.empty())
            return -1;
        int top = que.top();
        que.pop();
        return top;
    }

    int peek()
    {
        return que.top();
    }

    bool empty()
    {
        return que.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

/*
    MyQueue myQueue = new MyQueue();
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.peek(); // return 1
    myQueue.pop(); // return 1, queue is [2]
    myQueue.empty(); // return false

*/
