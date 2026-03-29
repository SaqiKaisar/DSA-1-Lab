#include <iostream>

using namespace std;

 /// **************Linked List***************** ///

///Linked List --> Node : 1. Data 2. Pointer to next element
//Node

struct Node{
       int data;
       Node *next;
};

Node *head= nullptr;

/// Insert at the Beginning
/// head---> 2
///2-->3--> 4
/// insert at begin (1)
/// 1 ---> head
/// 1 ---> 2 --> 3--> 4
/// head --> 1
/// head -->1 --> 2--> 3--> 4
void insertBegin(int data){
 // case 1: empty list (head insert)
 // case 2: non empty list (change head and move to the next pointer)
  Node *new_node = new Node();
  new_node->data = data;
  new_node->next = head; /// Case 1: null

  head = new_node; /// case 1: head points to newly created node
}
///  temp -->1
/// temp = temp->next
/// 1-->2
/// temp-->2
/// head -->1 -->2-->3-->4-->nullptr
/// print the value
/// move pointer

///Insert End
/// case 1: list is empty: insert at head
/// case 2: list is non empty: move to last and insert at last
void insertEnd(int data){
  Node *new_node = new Node();
  new_node->data = data;
  new_node->next = nullptr; // both case satisfy

  ///Case 1
  if(head == nullptr){
      head = new_node;
      return;
  }

  ///Case 2
  Node *traveller = new Node();
  traveller = head;
  while(traveller->next!=nullptr){
     traveller = traveller->next;
  }
  ///4->null
  ///1-->2-->3-->null
  ///1-->2-->3 -->4 -->null
  traveller->next = new_node;
}
/// 1-->2-->3-->4 -->null
/// 5 after 3
/// target 3
/// data 5
/// 1-->2-->3-->5-->4
void insertAfterValue(int target, int data){
   /// case 1: list is empty
   if(head == nullptr){
     cout<<"List is empty"<<endl;
     return;
   }
   /// case 2: List is not empty
   Node *traveller = head;
   /// 1 --> 2---> 3 --> 5-->null 4-->>
   /// 1 --> 2--->4 --->null
   /// traveller-->3
   /// 5-->next= 3-->next
   /// 1-->2-->3-->4
    /// 5--->4
    /// 3-->next = new_node
    /// 3-->5-->4
   /// 1-->2 -->3 --->5-->4
   while(traveller!=nullptr && traveller->data != target){
       traveller = traveller->next;
   }
   if(traveller == nullptr){
     cout<<"List does not contain the target"<<endl;
     return;
   }
   Node *new_node= new Node();
   new_node->data = data;
   new_node->next = traveller->next;
   traveller->next = new_node;
}


/// SearchValue
bool searchValue(int value){
  Node *traveller = head;
  while(traveller!=nullptr){
      if(traveller->data == value)return true;
      traveller=traveller->next;
  }
  return false;
}



///Printing LinkedList
void printList(){
       Node *temp = head;
       while(temp!=nullptr){
          cout<<temp->data<<"->";
          temp = temp->next;
       }
       cout<<"Null"<<endl;
}

/// Delete Begining
void deleteBeginning(){
    ///Case 1: Empty List
    if(head == nullptr){
      cout<<"List is empty"<<endl;
      return;
    }
    ///Case 2: Non Empty List
    Node *current = head;
    head = current->next;
    delete current;
}


/// Delete Ending
/// case 1: list is empty
/// case 2: list is not empty
/// 1-->null
/// case 3: list has only one element

void deleteEnd(){
    ///Case 1
     if(head == nullptr){
        cout<<"List is empty !!!" <<endl;
        return;
     }

     ///Case 3
     if(head->next == nullptr){
        Node *current = head;
        head = current->next;
        delete current;
        return;
     }

     ///Case 2
     ///Traveler and Follower
     Node *traveler = head;
     Node *follower = head;
     traveler = traveler->next;
     ///1 --->2 ---> 3 ---> null
     /// 1(f) -->2(t)
     while(traveler->next!=nullptr){
         follower=traveler; /// 2(t, f)
         traveler = traveler->next;/// 2(f), 3(t)
     }
     /// 2(f)--> 3(t)
     /// 3(t)-->null
     follower->next = traveler->next;
     /// 2(f)-->null
     /// 1-->2-->null
     /// 3-->null
     delete traveler; /// 3(t) deleted
     /// just 1-->2-->null
}

/// Delete a value
void deleteValue(int value){
    ///Case 1: Empty List
    ///Case 2: At the head
    ///Case 3: Anywhere else
    ///Case 4: Element does not exist
    ///Case 5: Only one element in the list
    //Case 1
    if(head==nullptr){
         cout<<"List is Empty!!!"<<endl;
         return;
    }
    //Case 5
    if(head->next==nullptr){
         Node *current = head;
         if(current->data == value){
             head = current->next;
             delete current;
             return;
         }
         return;
    }
    //Case 2
    if(head->data==value){
         Node *current = head;
         head = current->next;
         delete current;
         return;
    }
    //Case 3 and 4
    Node *traveler = head;
    Node *follower = traveler;///equivalent to *follower = head;
    traveler = traveler->next;
    ///1 ->2-> 3-> 4-> 5
    // 2(t) 1(f)
    // 3(t) 2(f)
    while(traveler != nullptr && traveler->data != value){
         follower=traveler;
         traveler = traveler->next;
    }
    ///Case 4
    if(traveler==nullptr){
       cout<<"Value does not exist in the list"<<endl;
       return;
    }
    ///Case 3
    follower->next = traveler->next;
    delete traveler;
}
int main()
{
    insertBegin(10);
    printList();
    insertBegin(2);
    printList();
    insertBegin(1);
    printList();
    insertEnd(21);
    /// 10 --> 2 --> 1
    /// 1-->2-->10 -->21
    // 10
    // 2->10
    // 1->2->10
    // 1->2->10->21
    insertAfterValue(2, 3);
    printList();
    insertAfterValue(5, 4);
    insertAfterValue(3, 4);
    printList();
    cout<<searchValue(21)<<endl;
    cout<<searchValue(-1)<<endl;
    deleteBeginning();
    printList();
    deleteEnd();
    printList();
    deleteValue(4);
    printList();
    return 0;
}