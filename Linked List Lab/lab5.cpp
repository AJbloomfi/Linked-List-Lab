#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <ios>
#include <iomanip>
using namespace std;

#include "linked_list.h"

class test
{	public:
        friend ostream &operator<<(ostream &output, test example);
        friend bool operator < (test left, test right);
        friend bool operator >= (test left, test right);
        friend bool operator != (test left, test right);
        friend bool operator == (test left, test right);
        test(string n, float g);
        test(){;};
        void set_info(string, float);
        void get_info(string &, float  &);
        string get_name(){return name;}

        private:
        string name;
        double gpa;
};

void print_insert(test name,bool inserted);
void print_removed(test name,bool removed);
void print_search(bool found, test name);

int main (void)
{
        bool found =false;


        linked_list <test>  list;
        test temp  ("Polack", 3.25);
        test temp2 ("Anewalt", 3.5);
        test temp3 ("Zacharski", 4.0);
        test temp4 ("Self", 3.75);
        test temp5 ("Finlayson", 3.8);
        test temp6 ("Marshall", 3.5);
        list.InsertInOrder(temp);
        list.InsertInOrder(temp2);
        list.InsertInOrder(temp3);
        list.InsertInOrder(temp4);
        list.InsertInOrder(temp5);
        list.InsertInOrder(temp6);


        cout<<"\nPRINTING\n";
        list.PrintAll();

        temp.set_info("Anewalt",0);
        found = list.Remove(temp);
        print_removed(temp,found);
        temp.set_info("Zacharski",0);
        found = list.Remove(temp);
        print_removed(temp,found);
        temp.set_info("Polack",0);
        found = list.Remove(temp);
        print_removed(temp,found);

        list.PrintAll();

        return 0;

}

ostream &operator<<(ostream &output, test example)
{
        output<<setw(15)<<example.name<<"\t"<<fixed<<setprecision(2)<<showpoint<<example.gpa;
        return output;
}
bool operator== (test left, test right)
{
        if (left.name==right.name)
                return true;
        else 
                return false;
}
bool operator< (test left, test right)
{
        if (left.name<right.name)
                return true;
        else
                return false;
}
bool operator>= (test left, test right)
{
        if (left.name>=right.name)
                return true;
        else
                return false;
}
bool operator!= (test left, test right)
{
        if (left.name!=right.name)
                return true;
        else
                return false;
}


test::test(string  pass_name,float num)
{
        gpa = num;
        name=pass_name;
}
void test::set_info(string pass_name, float num)
{
        gpa = num;
        name=pass_name;
}
void test::get_info(string &pass_name, float &num)
{
        pass_name=name;
        num=gpa;
}

void print_insert(test name,bool inserted)
{
        if (inserted)
                cout<<"The following information "<<name<<" was INSERTED into the list\n";
}
void print_removed(test name,bool removed)
{
        if (removed)
                cout<<"The following information "<<name<<" was REMOVED from the list\n";
}
void print_search(bool found, test name)
{
        if (found)
                cout<<"\tThe following information "<<name<<" was FOUND in the list\n";
        else
                cout<<name.get_name()<<" was NOT FOUND in the list\n";
}
