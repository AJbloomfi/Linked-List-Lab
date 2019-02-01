#include "linked_list.h"

int main(){
    linked_list<int> list;
    
    list.InsertFront(1);
    list.InsertFront(2);
    list.InsertFront(3);
    
    list.PrintAll();
}
