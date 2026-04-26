#include <iostream>
using namespace std;

struct Node{
    int value;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* last = nullptr;

Node* createNewNode(int value){
    Node* newNode = new Node();
    newNode->value = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertBeginning(int value){
    Node* newNode = createNewNode(value);

    if(head==nullptr){
        head = newNode;
        last = newNode;
    }else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void insertEnd(int value){
    Node* newNode = createNewNode(value);

    if(last==nullptr){
        head = newNode;
        last = newNode;
    }else{
        newNode->prev = last;
        last->next = newNode;
        last = newNode;
    }
}

void insertAfter(int key, int value){
    if(head = nullptr){
        cout<<"This list is empty. Cannot insert anything after the given key."<<endl;
        return;
    }

    Node* cur = head;

    while(cur!=nullptr && cur->value!=key){
        cur = cur->next;
    }

    if(cur==nullptr){
        cout<<"The key is not available in the list."<<endl;
        return;
    }

    Node* newNode = createNewNode(value);

    newNode->next = cur->next;
    newNode->prev = cur;

    cur->next = newNode;
    if(cur!=last){
        newNode->next->prev = newNode;
    }else{
        last = newNode;
    }
}

void deleteBeginning(){
    if(head == nullptr){
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
    if(head!=nullptr){
        head->prev=nullptr;
    }
}

void deleteEnd(){
    if(last == nullptr){
        return;
    }

    Node* temp = last;
    last = last->prev;
    delete temp;
    if(last!=nullptr){
        last->next = nullptr;
    }
}

void deleteValue(int value){
    if(head == nullptr){
        return;
    }

    Node* cur = head;
    while(cur!=nullptr && cur->value!=value){
        cur=cur->next;
    }

    if(cur==nullptr){
        return;
    }

    if(cur==head){
        deleteBeginning();
    }else if(cur==last){
        deleteEnd();
    }else{
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }

    delete cur;
}

Node* search(int value){
    if(head == nullptr){
        return nullptr;
    }

    Node* cur = head;

    while(cur!=nullptr && cur->value!=value){
        cur = cur->next;
    }

    return cur;
}

void display(){
    Node* cur = head;

    while(cur!=nullptr){
        cout<<cur->value<<" ";
    }
}

