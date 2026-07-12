class LRUCache {
    // map to keep track of key value pair
    // how to track LRU?
    // we can use a map to map key to LL node
    // the tail of the LL should always contain the LRU element
    // when putting, update LRU by moving LL to most recently used
    // when over capacity, drop the LRU element from the map and LL

    // change this to a struct?
    struct Node {
        int val;
        Node* prev;
        Node* next;
    };

private:    
    map<int, int> store;
    map<int, Node*> book;
    Node* head;
    Node* tail;
    int max;
    int currCapacity;

    void use(int key) {
        // update book
        if (!book.contains(key)) {
            Node* node = new Node(key, nullptr, nullptr);
            // new node, update head
            node->next = head;
            head->prev = node;

            head = node;
            book[key] = head;
        }
        else {
            // check book for node
            Node* node = book[key];
            node->val = key;

            Node* prevNode = node->prev;
            Node* nextNode = node->next;
            
            if (!prevNode) {
                // is head, do nothing
            } 
            else if (!nextNode) {
                // is tail update tail
                tail = prevNode;
                prevNode->next = nextNode;

                // move to head
                node->next = head;
                node->prev = nullptr;
                head->prev = node;
                head = node;
            }
            else {
                prevNode->next = nextNode;
                nextNode->prev = prevNode;

                // move to head
                node->next = head;
                node->prev = nullptr;
                head->prev = node;
                head = node;
            }
        }

        // check if over capacity
        // remove tail
        if (currCapacity > max) {
            currCapacity--;
            Node* oldTail = tail;
            Node* prevTail = oldTail->prev;
            prevTail->next = nullptr;
            tail = prevTail;

            store.erase(oldTail->val);
            book.erase(oldTail->val);
        }
    }

public:
    LRUCache(int capacity) {
        max = capacity;
        currCapacity = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int key) {
        if (store.contains(key)) {
            use(key);
            return store[key];
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (!head) {
            head = new Node{key, nullptr, nullptr};
            tail = head;

            book[key] = head;
            store[key] = value;
            currCapacity++;
            return;
        }

        if (!store.contains(key)) {
            currCapacity++;
        }
        // update store
        store[key] = value;
     

        use(key);
    }
};
