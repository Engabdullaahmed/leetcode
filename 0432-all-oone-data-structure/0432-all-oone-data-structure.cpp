struct Node {
    Node* next;
    Node* prev;
    unordered_set<string> st;
    int cnt;

    Node(int c) {
        cnt = c;
        next = nullptr;
        prev = nullptr;
    }
};

class AllOne {
    unordered_map<string, Node*> mp;

private:
    Node* head;
    Node* tail;

public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);

        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {

        // New key
        if (mp.find(key) == mp.end()) {

            // Frequency 1 node doesn't exist
            if (head->next == tail || head->next->cnt != 1) {

                Node* temp = new Node(1);

                temp->prev = head;
                temp->next = head->next;

                head->next->prev = temp;
                head->next = temp;

                temp->st.insert(key);
                mp[key] = temp;
            }
            else {
                // Frequency 1 node exists
                head->next->st.insert(key);
                mp[key] = head->next;
            }
        }

        // Existing key
        else {

            Node* cur = mp[key];

            // Next node has frequency + 1
            if (cur->next != tail &&
                cur->next->cnt == cur->cnt + 1) {

                cur->next->st.insert(key);
                mp[key] = cur->next;
            }
            else {

                // Create new node
                Node* temp = new Node(cur->cnt + 1);

                temp->st.insert(key);

                temp->prev = cur;
                temp->next = cur->next;

                cur->next->prev = temp;
                cur->next = temp;

                mp[key] = temp;
            }

            // Remove key from old node
            cur->st.erase(key);

            // Delete old node if empty
            if (cur->st.empty()) {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
            }
        }
    }

    void dec(string key) {

        if (mp.find(key) == mp.end()) {
            return;
        }

        Node* cur = mp[key];

        // Frequency is 1
        if (cur->cnt == 1) {

            cur->st.erase(key);
            mp.erase(key);

            if (cur->st.empty()) {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
            }
        }

        else {

            // Previous node has frequency - 1
            if (cur->prev != head &&
                cur->prev->cnt == cur->cnt - 1) {

                cur->prev->st.insert(key);
                mp[key] = cur->prev;
            }
            else {

                // Create new node
                Node* temp = new Node(cur->cnt - 1);

                temp->st.insert(key);

                temp->prev = cur->prev;
                temp->next = cur;

                cur->prev->next = temp;
                cur->prev = temp;

                mp[key] = temp;
            }

            // Remove key from old node
            cur->st.erase(key);

            // Delete old node if empty
            if (cur->st.empty()) {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
                delete cur;
            }
        }
    }

    string getMaxKey() {

        if (tail->prev == head) {
            return "";
        }

        return *(tail->prev->st.begin());
    }

    string getMinKey() {

        if (head->next == tail) {
            return "";
        }

        return *(head->next->st.begin());
    }
};
