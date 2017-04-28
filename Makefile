all: customer_app 

customer_app: customer_app.o BSTree.o Customer.o Node.o
	g++ -o customer_app customer_app.o BSTree.o Customer.o Node.o


customer_app.o: customer_app.cpp BSTree.h Customer.h Node.h
	g++ -c customer_app.cpp

BSTree.o: BSTree.cpp BSTree.h Customer.h Node.h
	g++ -c BSTree.cpp

Customer.o: Customer.cpp BSTree.h Customer.h Node.h
	g++ -c Customer.cpp

Node.o: Node.cpp BSTree.h Customer.h Node.h
	g++ -c Node.cpp

clean:
	rm -f *.o customer_app 