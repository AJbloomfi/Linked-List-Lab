#include "linked_list.h"

int main(){
    linked_list<int> list;
    
    list.InsertRear(1);
    list.InsertRear(2);
    list.InsertRear(3);
    
    list.PrintAll();
}
