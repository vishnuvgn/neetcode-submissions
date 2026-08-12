class LRUCache {
private:
    struct ListNode {
        int key;
        int value;
        ListNode* prev;
        ListNode* next;

        ListNode(int k, int v) 
            : key(k), value(v), prev(nullptr), next(nullptr) {}
    };
    std::unordered_map<int, ListNode*> pairings;
    ListNode* head;
    ListNode* tail;
    
    int limit;
    int length;

public:
    LRUCache(int capacity) {
       limit = capacity; 
       length = 0;
       head = nullptr;
       tail = nullptr;
    }
    
    int get(int key) {
        auto it = pairings.find(key);
        if (it != pairings.end()) {
            
            ListNode* ptr = it->second;
            
            if (ptr == head) return ptr->value;
            if (ptr == tail) { // implicitily will never equal head if in this branch
                tail = ptr->prev;
            }
            else {
                ptr->next->prev = ptr->prev;
            }
            ptr->prev->next = ptr->next;
            ptr->next = head;
            head->prev = ptr;
            ptr->prev = nullptr;
            head = ptr;

            return ptr->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        auto it = pairings.find(key);
        if (it == pairings.end()) {
            if (length == limit) {
                ListNode* ptr = tail;

                if (head != tail) {
                    tail->prev->next = nullptr;    
                }
                else {
                    head = nullptr;
                }

                tail = tail->prev;
                ptr->prev = nullptr;
                pairings.erase(ptr->key);
                delete ptr;
                --length;

            }
            ListNode* new_head = new ListNode(key, value);
            if (head != nullptr) {
                head->prev = new_head;
            }
            else {
                tail = new_head;   
            }
            new_head->next = head;
            head = new_head;
            pairings[key] = head;
            ++length;
        }
        else {
            get(key);
            head->value = value;
        }
    }
};
