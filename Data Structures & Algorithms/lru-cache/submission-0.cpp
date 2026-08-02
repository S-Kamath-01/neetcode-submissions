class Node{
public:
    int key,value;
    Node* prev;
    Node* next;
    Node(int k, int v){
        key = k;
        value = v;
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
private:
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;
    int capacity;

    void insert(Node* node){
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        
        node->next = right;
        right->prev = node;
    }

    void remove(Node* node){
        Node* p = node->next;
        Node* q = node->prev;
        q->next = p;
        p->prev = q;
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        left = new Node(0,0);
        right = new Node(0,0);
        left->next = right;
        right->prev = left;
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end()){
            return -1;
        }
        Node* node = cache[key];
        remove(node);
        insert(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(cache.find(key)!=cache.end()){
            Node* node = cache[key];
            node->value = value;
            remove(node);
            insert(node);
            return;
        }
        Node* node = new Node(key,value);
        cache[key] = node;
        insert(node);

        if(cache.size()>capacity){
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
