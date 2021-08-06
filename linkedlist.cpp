#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
};
struct LinkedList{
    Node *head;
    Node *tail;
};
Node *createNode(int data){
    Node *node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}
void createList(LinkedList &list){
    list.head = NULL;
    list.tail = NULL;
}

void addHead(LinkedList &list, Node *node){
    if (list.head == NULL){
        list.head = node;
        list.tail = node;
    }
    else{
        node->next = list.head;
        list.head = node;
    }
}

void addTail(LinkedList &list, Node *node){
    if (list.head == NULL){
        list.head = node;
        list.tail = node;
    }
    else{
        list.tail->next = node;
        list.tail = node;
    }
}


void insertAfterQ(LinkedList &list, Node *node, Node *q){
    if (q!=NULL){
        node->next = q->next;
        q->next = node;
        if (q == list.tail){
            list.tail = node;
        }
    }
    else{
        addHead(list, node);
    }
}

Node* index(LinkedList &list, int i){
    Node *node = list.head;
    for (int j =0; j<i; j++){
        if (node!=NULL){
        node = node->next;
        }
    }
    return node;
}

void remove(LinkedList &list, int i){
    Node *node = list.head;
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

void print(LinkedList &list){
    Node *node = list.head;
    while(node!=NULL){
        cout<<node->data<<" ";
        node = node->next;
    }
    cout<<endl;
}


int main(){
    Node *node1 = createNode(3);
    Node *node2 = createNode(4);
    Node *node3 = createNode(5);
    Node *node4 = createNode(6);
    Node *node5 = createNode(7);
    LinkedList list;
    createList(list);

    addHead(list, node1);
    print(list);
    addTail(list, node5);
    print(list);
    insertAfterQ(list, node2, node1);
    print(list);
    insertAfterQ(list, node3, node5);
    print(list);
    remove(list, 1);
    print(list);

}
