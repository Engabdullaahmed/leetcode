class MyCircularDeque {
private:
struct Node {
Node* next ;
int value ;
Node* prev;
Node(int num) : value(num),next(nullptr),prev(nullptr){}
};
Node* head;
Node* tail;

int size ;
int capacity  ;


public:

    MyCircularDeque(int k) {
        capacity = k ;
        size = 0;
        head = nullptr ;
        tail = nullptr ;
    }
    
    bool insertFront(int value) {
        if(size < capacity)
        {
        size++;
        if(head)
        {
            Node* cur = new Node(value);
        cur->next = head ;
        head->prev= cur ; 
        head = head ->prev ;
        }
        else {
            head = new Node(value);
            
            tail = head;
        }
        return true;
        }
        else {
            return false ;
        }
        
        
    }
    
    bool insertLast(int value) {
        if(size < capacity)
        {
        size++;
         if(tail)
        {

            Node* cur = new Node(value);

        cur->next = nullptr ;
        cur->prev = tail ;
        tail->next= cur ;
        tail = tail ->next ;
        }
        else {
             tail = new Node(value);
            head = tail ;
        }
        return true ;
        }
        return false ;
    }
    
 bool deleteFront() {
    if (!head) {
        return false;
    }

    Node* cur = head;

    if (head == tail) {
        head = nullptr;
        tail = nullptr;
    }
    else {
        head = head->next;
        head->prev = nullptr;
        
    }

    delete cur;
    size--;

    return true;
}
    
    bool deleteLast() {
       if(!tail)
       {
        return false ;
       }
       Node* cur = tail ;
       if(head == tail )
       {
        head = nullptr;
        tail = nullptr;
       }
       else {
        tail = tail->prev ;
        tail->next = nullptr;
        
       }
       delete cur;
    size--;

    return true;
    }
    
    int getFront() {
     
        return (head)?head->value:-1  ;
        
    }
    
    int getRear() {
         return (tail)?tail->value:-1  ;
    }
    
        bool isEmpty() {
            return size == 0;
        }

        bool isFull() {
            return size == capacity;
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