#include <vector>
struct Node
{
    int val;
    Node * next;
};

class LinkedList {
private:
    Node *lista;
    int cap;
public:
    LinkedList() {
        this->cap = 0;
        this->lista = NULL;
    }

    int get(int index) {
        if(this->lista == NULL)
            return -1;
        Node * nod = this->lista;
        while(index > 0)
        {
            if(nod->next == NULL)
                return -1;
            nod = nod->next;
            index --;
        }
        return nod->val;
    }

    void insertHead(int val) {
        Node * nod = (Node *)malloc(sizeof(Node));
        nod->val = val;
        nod->next = this->lista;
        this->lista = nod;
        this->cap ++;
    }
    
    void insertTail(int val) {
        if(this->lista == NULL)
        {
            insertHead(val);
            return ;
        }
        Node * nod = this->lista;
        while(nod->next != NULL)
            nod= nod->next;
        nod->next = (Node *)malloc(sizeof(Node));
        nod->next->next = NULL;
        nod->next->val = val;
        this->cap ++;
    }

    bool remove(int index) {
        Node *prev = NULL,*cur = this->lista;
        if(cur == NULL)
            return false;
        while(index-- > 0)
        {
            if(cur->next ==NULL)
                return false;
            prev = cur;
            cur = cur->next;
        }
        if(prev == NULL)
        {
            this->cap -- ;
            this->lista = cur->next;
            free(cur);
            return true;
        }
        prev -> next = cur->next;
        free(cur);
        this->cap --;
        return true;
    }

    vector<int> getValues() {
        std::vector<int> v;
        Node *nod = this->lista;
        if(nod == NULL)
            return v;
        while(nod != NULL)
        {
            v.push_back(nod->val);
            nod = nod->next;
        }
        return v;
    }
};
