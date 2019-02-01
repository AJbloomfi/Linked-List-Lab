#include <string>
#include <ostream>
#include <iostream>
using namespace std;
#include "linked_list.h"

class stuff{
        public:
                bool operator<(stuff right);
                bool operator<=(stuff right);
                bool operator>=(stuff right);
                bool operator>(stuff right);
                bool operator==(stuff right);
                bool operator!=(stuff right);
                int number;
                string name;
};
ostream & operator<<(ostream &output,const stuff &temp);

int main(){
        linked_list<stuff> list;
        stuff one = {1, "Fluffy"}; 
        list.InsertRear(one);
        one.number=2;
        one.name="Noddle";
        list.InsertRear(one);
        one.number=3;
        one.name="Cinnamon";
        list.InsertRear(one);
        one.number=4;
        one.name="Rosie";
        list.InsertRear(one);

        one.name="TEMP";
        one.number=3;
        if(list.Remove(one)){
                cout<<"If removed correctly you should see CINNAMON and 3.\n";
                cout<<one<<endl;
                cout<<"If you see TEMP then you did not pass ->data back by reference\n";
        }
}

bool stuff::operator<(stuff right){
        if(number < right.number)
                return true;
        else
                return false;
}
bool stuff::operator<=(stuff right){
        if(number <= right.number)
                return true;
        else
                return false;
}
bool stuff::operator>(stuff right){
        if(number > right.number)
                return true;
        else
                return false;
}
bool stuff::operator>=(stuff right){
        if(number >= right.number)
                return true;
        else
                return false;
}
bool stuff::operator!=(stuff right){
        if(number != right.number)
                return true;
        else
                return false;
}
bool stuff::operator==(stuff right){
        if(number == right.number)
                return true;
        else
                return false;
}
ostream & operator<<(ostream &output, const stuff &temp){
        output<<temp.number<<" "<<temp.name;
        return output;
}
