// https://leetcode.com/problems/design-circular-queue/submissions/
// maintain head and tail for front and end of the vector, and each time head or tail reaches end , then start back at 0.
class MyCircularQueue {
public:
    MyCircularQueue(int k): size(0), maxSize(k), head(0), tail(-1), data(vector<int>(k, 0)) {}
    
    bool enQueue(int value) {
        if(size == maxSize) return false;
        if(++tail == maxSize) tail = 0;
        data[tail] = value;
        ++size;
        return true;
    }
    
    bool deQueue() {
        if(size == 0) return false;
        if(++head == maxSize) head = 0;
        --size;
        return true;
    }
    
    int Front() {
        return size == 0 ? -1 : data[head];
    }
    
    int Rear() {
        return size == 0 ? -1 : data[tail];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == maxSize;
    }
    
    int size;
    int maxSize;
    int head;
    int tail;
    vector<int> data;
};


void main() {

    int k = 3;
    MyCircularQueue* obj = new MyCircularQueue(k);
    bool p1 = obj->enQueue(1);
    bool p2 = obj->enQueue(2);
    bool p3 = obj->enQueue(3);
    bool p4 = obj->enQueue(4);
    int rear = obj->Rear();
    bool p5 = obj->isFull();
    bool p6 = obj->deQueue();
    bool p7 = obj->enQueue(4);
    rear = obj->Rear();
    
    system("PAUSE");
}
