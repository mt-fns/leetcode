class MyCircularQueue {
private:
    struct ListNode {
        int val_;
        ListNode* prev;
        ListNode* next;
        ListNode(int val) : val_(val), prev(nullptr), next(nullptr) {}; 
    };


    int queueSize;
    int currSize;
    ListNode* head;
    ListNode* tail;

public:

    MyCircularQueue(int k) {
        queueSize = k;
        currSize = 0;
        head = new ListNode(0);
        tail = new ListNode(0);

        head->next = tail;
        tail->prev = head;
    }
    
    bool enQueue(int value) {
        if (currSize >= queueSize) {
            return false;
        }

        ListNode* curr = head;

        while (curr->next != tail) {
            curr = curr->next;
        }
        
        ListNode* newNode = new ListNode(value);

        newNode->prev = curr;
        curr->next = newNode;

        newNode->next = tail;
        tail->prev = newNode; 

        currSize++;

        return true;
    }
    
    bool deQueue() {
        ListNode* toDelete = head->next;
        if (toDelete == tail) {
            return false;
        }

        ListNode* nextNode = toDelete->next;

        head->next = nextNode;
        if (nextNode) {
            nextNode->prev = head;
        }

        currSize--;
        return true;
    }
    
    int Front() {
        if (currSize == 0) {
            return -1;
        }

        return head->next->val_;
    }
    
    int Rear() {
        if (currSize == 0) {
            return -1;
        }

        return tail->prev->val_;
    }
    
    bool isEmpty() {
        return (currSize == 0);
    }
    
    bool isFull() {
        return (currSize == queueSize);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */