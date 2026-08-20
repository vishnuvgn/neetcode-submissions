class LRUCache {
private:

    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };


    unordered_map<int, Node*> cache;
    int max_size;
    Node* head;
    Node* tail;

public:
    LRUCache(int capacity) : max_size(capacity), head(nullptr), tail(nullptr) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;

        Node* curr = it->second;
        if (head == curr) return curr->value;

        curr->prev->next = curr->next;
        
        if (curr->next) {
            curr->next->prev = curr->prev;
        }
        else {
            tail = curr->prev;
        }

        curr->prev = nullptr;
        curr->next = head;
        head->prev = curr;
        head = curr;
        return curr->value;
    }
    
    void put(int key, int value) {

        // for existing
        auto it = cache.find(key);
        if (it != cache.end()) {
            Node* curr = it->second;
            curr->value = value;
            get(key);
            return;
        }

        if (cache.empty()) {
            Node* curr = new Node(key, value);
            head = curr;
            tail = curr;
            cache[key] = curr;
        }

        else if (static_cast<int>(cache.size()) < max_size) {
            Node* curr = new Node(key, value);
            curr->next = head;
            head->prev = curr;
            head = curr;
            cache[key] = curr;
        }

        else {
            Node* curr = new Node(key, value);
            curr->next = head;
            head->prev = curr;
            head = curr;
            cache[key] = curr;
        
            Node* old_tail = tail;
            old_tail->prev->next = nullptr;
            tail = old_tail->prev;
            old_tail->prev = nullptr;
            cache.erase(old_tail->key);
            delete old_tail;
        }

        // for new
        // if empty: create node, set head and tail to it, add it to map
        // if not empty & not full: create node, set it to head, and add it to the map
        // if full: evict tail and remove from map, create node, add it to head

    }
};
