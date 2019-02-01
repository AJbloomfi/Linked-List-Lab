#ifndef LIST_CPP
#define LIST_CPP
#include "linked_list.h"
#include <iostream>
#include <string>
using namespace std;

template <class NODETYPE>
linked_list<NODETYPE>::linked_list() {
        first = NULL;
        current = NULL;
        last = NULL;
}

template <class NODETYPE>
linked_list<NODETYPE>::~linked_list() {
        current = first;
        while (current != NULL) {
                first = first->next;
                delete current;
                current = first;
        }
        current = last = first = NULL;
}
template <class NODETYPE>
linked_list<NODETYPE>::linked_list(linked_list<NODETYPE> &originalList) {
        if(originalList.first == nullptr){
		first = nullptr;
		last = nullptr;
	}else{
		linked_list<NODETYPE> *orig, *lastptr = nullptr;
		orig = originalList.first;
		lastptr = new ListNode <NODETYPE>;
		if(lastptr!=nullptr){
			lastptr -> data = orig -> data;
			first = lastptr;
			orig = orig -> next;
		    while(orig!=nullptr){
			    current = lastptr;
			    lastptr =  ListNode<NODETYPE>(orig->data);
			    if(lastptr != nullptr){
				    current -> next = lastptr;
			    }
			orig = orig -> next;
		    }
		last = lastptr;
		}
		
	}

}


template <class NODETYPE>
bool linked_list<NODETYPE>::InsertInOrder(NODETYPE value)
{
    
    //Declare a new node
    //New the node
    ListNode<NODETYPE> *temp = nullptr;
    temp = new ListNode<NODETYPE>;
    temp -> data = value;
    
    //if the new node is not nullptr continue with the insert in order
    //else return false
    if(temp == nullptr){
        return false;
    }
    else{
    //if this is the first node you are inserting the linked list
        if(first == NULL){
        //call either insertFront or insertRear
            InsertFront(value);
        }
    //else if the new node data is less than first data
        else if(value >= last -> data){
        //call insertFront
            InsertRear(value);
        }
    //else if the new node data is greater than last data
        else if(first -> data >= value){
        //call insertRear
            InsertFront(value);
        }
    //else
        else{
        //set current to first
            current = first;
        //use a while loop to set current to the node before where you want to insert the new node
            while(current != nullptr && current -> next -> data < value){
        //connect the new node next to current next
                current = current -> next;
        //connect current next to the new node
            }
            temp -> next = current -> next;
            current -> next = temp;
        }
    //return true
        return true;
    }
}
template <class NODETYPE>
bool linked_list<NODETYPE>::InsertFront(NODETYPE value) {
    //New a new node with current
    ListNode<NODETYPE> *current = new ListNode<NODETYPE>;
    //if current equal nullptr return false
    if(current == nullptr){
        return false;
    }
    //else
    else{
        //set current data to value
        current -> data = value;
        //if this is the first node in the linked list
        if(first == NULL){
            //set first to current
            first = current;
            //set last to current
            last = current;
            //set current next to nullptr
            current -> next = nullptr;
        }
        //else
        else{
            //set current next to first
            current -> next = first;
            //set first to current
            first = current;
        }
        return true;
    }
    //return true;
    
}
template <class NODETYPE>
bool linked_list<NODETYPE>::InsertRear(NODETYPE value) {
    //New a new node with current
    ListNode<NODETYPE> *current = new ListNode<NODETYPE>;
    //if current equal nullptr return false
    if(current == nullptr){
        return false;
    }
    //else
    else{
        //set current data to value
        current -> data = value;
        //if this is the first node in the linked list
        if(first == NULL){
            //set first to current
            first = current;
            //set last to current
            last = current;
            //set current next to nullptr
            current -> next = nullptr;
        }
        //else
        else{
            //set last next to current
            last -> next = current;
            //set current next to nullptr
            current -> next = nullptr;
            //set last to current
            last = current;
        }
        return true;
    //return true;
    }
}

template <class NODETYPE>
bool linked_list<NODETYPE>::IsEmpty() const {
        return (first == NULL);
}

template <class NODETYPE>
bool linked_list<NODETYPE>::Search(NODETYPE value) {
        //if the list is empty return false
        if(this -> IsEmpty() == true){
            return false;
        }
        //else
        else{
            //set current to first
            current = first;
            //use a while loop to check not for nullptr and not for current data not equal to the value
            while(current != nullptr && current -> data != value){
                current = current -> next;
            //if current equals null not found
            
            }
            if(current == NULL ){
                //return false
                return false;
            }
            //else
            else{
                //return true
                return true;
            }  
            
        }
}


template <class NODETYPE>
void linked_list<NODETYPE>::PrintAll() {
    if(this -> IsEmpty() != true){
    //if not empty
        current = first;
        //set current to first
        while(current != nullptr){
        //use a while loop to check for not equal to nullptr
            cout << current -> data << endl;
            //print out data
            current = current -> next;
            //move current over
        }
    }

}

template <class NODETYPE>
bool linked_list<NODETYPE>::RemoveFront(NODETYPE & value) {
    ListNode<NODETYPE> *temp = new ListNode<NODETYPE>;
    if(first != nullptr){
        temp = first -> next;
        value = first -> data;
        delete first;
        first = temp;
        return true;
    }
    else{
        return false;
    }
}
template <class NODETYPE>
bool linked_list<NODETYPE>::RemoveRear(NODETYPE & value) {
    current = first;
    while(current -> next -> next != nullptr){
        current = current -> next;
    }
    last = current;
    value = current-> next -> data;
    delete current -> next;
    last -> next = nullptr;
    current -> next = nullptr;
    return true;
}
template <class NODETYPE>
bool linked_list<NODETYPE>::Remove(NODETYPE & value) {
    ListNode<NODETYPE> *temp = nullptr;
    temp = new ListNode<NODETYPE>;
    
    //if the value equals the first data and it is the last node in the linked last
    if(value == first -> data && value == last -> data){
    //set value to first data
        value = first -> data;
    //remove the node and set current last and first to nullptr
        delete first;
        current = nullptr;
        last = nullptr;
        first = nullptr;
        return true;
    }
    //else if the value equals the first data
    else if( value == first -> data){
    //set value to first data
        value = first -> data;
    //set current to first
        current = first;
    //move first to the next node
        first = first -> next;
    //delete current
        delete current;
        return true;
    }
    //else if the value equals the last data
    else if( value == last -> data){
    //set value to last data
        value = last -> data;
    //set current to first
        current = first;
    //use a while loop to set current to one before last
        while(current -> next != last){
            current = current -> next;
        }
         //delete last
            delete last;
    //set last to current
            last = current;
    //set current next to nullptr
            current -> next = nullptr;
        return true;
    }
    //else
    else{
    //set current to first
        current = first;
    //use a while loop to check for current does not equal null and current next data does not equal value
        while(current != nullptr && current -> next -> data != value){
    //if current equals null
            current = current -> next;
        }
        if(current == nullptr){
    //return false
                return false;
            }
    //else
            else{
                temp = current -> next;
                value = temp -> data;
                current -> next = temp -> next;
                delete temp;
                return true;
            }
    }
    //set temp pointer the node you will be deleting
    //set value to the temp data
    //set current next to temp next
    //delete temp
    //return true
}

#endif
