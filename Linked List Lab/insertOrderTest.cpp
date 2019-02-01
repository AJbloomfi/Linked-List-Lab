#include "linked_list.h"

int main(){
    linked_list<char> list;
    
    list.InsertInOrder('m');
    list.InsertInOrder('b');
    list.InsertInOrder('y');
    list.InsertInOrder('j');
    list.InsertInOrder('a');
    list.InsertInOrder('z');

    
    list.PrintAll();
}

