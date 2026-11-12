class MyCircularDeque {
    struct Node {
        int v;
        Node* p;
        Node* n;
        Node(int v) {
            this->v = v;
            p = n = nullptr;
        }
    };
    int sz, k; Node* front; Node* rear;
public:
    MyCircularDeque(int k) {
        sz = 0, this->k = k;
        front = rear = nullptr;
    }
    
    bool insertFront(int value) {
        if (sz == k) return 0;
        Node* x = new Node(value);
        if (sz == 0) front = rear = x;
        else {
            front->n = x;
            x->p = front;
            front = x;
        }
        sz++;
        return 1;
    }
    
    bool insertLast(int value) {
        if (sz == k) return 0;
        Node* x = new Node(value);
        if (sz == 0) front = rear = x;
        else {
            rear->p = x;
            x->n = rear;
            rear = x;
        }
        sz++;
        return 1;
    }
    
    bool deleteFront() {
        if (sz == 0) return 0;
        if (sz == 1) front = rear = nullptr;
        else {
            front = front->p;
            delete front->n;
            front->n = nullptr;
        }
        sz--;
        return 1;
    }
    
    bool deleteLast() {
        if (sz == 0) return 0;
        if (sz == 1) front = rear = nullptr;
        else {
            rear = rear->n;
            delete rear->p;
            rear->p = nullptr;
        }
        sz--;
        return 1;
    }
    
    int getFront() {
        if (sz == 0) return -1;
        return front->v;
    }
    
    int getRear() {
        if (sz == 0) return -1;
        return rear->v;
    }
    
    bool isEmpty() {
        return sz == 0;
    }
    
    bool isFull() {
        return sz == k;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */