#include "linked_list.h"
void changeList(linked_list<char> &change);
int main(){
        linked_list<char> list;

        list.InsertInOrder('m');
        list.InsertInOrder('b');
        list.InsertInOrder('y');
        list.InsertInOrder('j');
        list.InsertInOrder('a');
        list.InsertInOrder('z');
        list.PrintAll();

        changeList(list);
        cout<<"After Change Method Called List should Contain l and q\n";    
        list.PrintAll();
}
void changeList(linked_list<char> &change){
        change.InsertInOrder('l');
        change.InsertInOrder('q');
}
