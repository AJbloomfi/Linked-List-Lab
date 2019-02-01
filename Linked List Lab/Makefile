a.out: lab5.cpp linked_list.o single_node.o
	g++ -std=c++11 lab5.cpp linked_list.o single_node.o

linked_list.o: linked_list.cpp linked_list.h
	g++ -std=c++11 -c linked_list.cpp

single_node.o: single_node.cpp single_node.h
	g++ -std=c++11 -c single_node.cpp

clean:
	rm *.o *gch a.out
