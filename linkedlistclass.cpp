#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
        void createNode(int data){
            this->data = data;
            this->next = NULL;
        }
};

class LinkedList{
    public:
        Node* head;
        Node* tail;
        void createList(){
            this->head = NULL;
            this->tail = NULL;
        }
        void addHead(Node *node){
            if (this->head == NULL){
                this->head = node;
                this->tail = node;
            }
            else{
                node->next = this->head;
                this->head = node;
            }
        }
        void insertAfterQ(Node *node, Node *q){
            if (q!=NULL){
                node->next = q->next;
                q->next = node;
                if (this->tail == q){
                    this->tail = node;
                }
            }
            else{
                addHead(node);
            }
        }
        Node *index(int i){
            Node *node = this->head;
            for (int j=0; j<i; j++){
                if (node!=NULL){
                    node = node->next;
                }
            }
            return node;
        }
        void remove(int i){
            Node *node = this->head;
            Node *q;
            for (int j=0; j<i; j++){
                if (j==(i-1)){
                    q = node;
                }
                if (node!=NULL){
                    node = node->next;
                }
            }
            q->next = node->next;
            delete node;
        }
        void print(){
            Node *node = this->head;
            while(node!=NULL){
                cout<<node->data<<" ";
                node = node->next;
            }
            cout<<endl;
        }
};



int main(){
    Node *node1 = new Node;
    node1->createNode(3);
    Node *node2 = new Node;
    node2->createNode(4);
    Node *node3 = new Node;
    node3->createNode(5);
    Node *node4 = new Node;
    node4->createNode(6);

    LinkedList list;
    list.createList();
    list.addHead(node1);
    list.print();
    list.insertAfterQ(node2, node1);
    list.print();
    list.insertAfterQ(node3,node2);
    list.print();
    list.remove(1);
    list.print();
}