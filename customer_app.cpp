
#include "Customer.h"
#include "BSTree.h"

#include <iostream>
#include <fstream>
using namespace std;


void printMenu();
void promptReadCustomer(string&, char&, int&);
void promptReadCustomerName(string&, char&);
void readCustomersFile(string fname, BSTree &);


int main() {
	BSTree bst;

	// Temporary variables for application main loop.
	string lname1;
	char finit1;
	int balance;
	string lname2;
	char finit2;
	vector<Customer> vc;
	string fname;

	// Application main loop.
	// Loop until "q" is hit.
	char input;
	bool done = false;
	while (!done) {
		printMenu();

		cout << "Select an option: ";
		cin >> input;
		switch(input) {
		case 'i':
			// Process insertion.
			promptReadCustomer(lname1,finit1,balance);
			bst.insert(lname1,finit1,balance);
			break;
		case 'd':
			// Process deletion.
			promptReadCustomerName(lname1,finit1);
			if (bst.remove(lname1,finit1)) {
				cout << "Customer deleted." << endl;
			} else {
				cout << "Customer not found." << endl;
			}
			break;
		case 's':
			// Process search.
			promptReadCustomerName(lname1,finit1);
			if (bst.search(lname1,finit1)) {
				cout << "Customer found." << endl;
			} else {
				cout << "Customer not found." << endl;
			}
			break;
		case 'p':
			// Process print all.
			bst.inOrderPrint();
			break;
		case 'r':
			// Process print range.
			cout << "Customer 1: ";
			promptReadCustomerName(lname1,finit1);
			cout << "Customer 2: ";
			promptReadCustomerName(lname2,finit2);
			vc = bst.rangeSearch(lname1,finit1,lname2,finit2);

			// Iterate over vc to print its contents.
			cout << "Customers in range:" << endl;
			for (int i=0; i < (int) vc.size(); i++) {
				cout << " " << vc[i] << endl;
			}

			break;
		case 'f':
			// Process read from file.
			cout << "Enter file name: ";
			cin >> fname;
			readCustomersFile(fname,bst);
			break;
		case 'q':
			// Stop application.
			done = true;
			break;
		}
	}



	return 0;
}


void printMenu() {
	// Present user with options.
	cout << endl;
	cout << "===============================================" << endl;
	cout << "Options" << endl;
	cout << " i: Insert new customer" << endl;
	cout << " d: Delete a customer" << endl;
	cout << " s: Search for a customer" << endl;
	cout << " p: Print all customers" << endl;
	cout << " r: Print a range of customers" << endl;
	cout << " f: Read customer data from file" << endl;
	cout << " q: Quit application" << endl;
	cout << "===============================================" << endl;
}


// Prompt the user for customer data.
void promptReadCustomer(string& lname, char& finit, int& balance) {
	cout << "Enter customer last name: " << endl;
	cin >> lname;

	cout << "Enter customer first initial: " << endl;
	cin >> finit;

	cout << "Enter customer balance: " << endl;
	cin >> balance;
}


// Prompt the user for customer data, but only the name, not balance.
void promptReadCustomerName(string& lname, char& finit) {
	cout << "Enter customer last name: " << endl;
	cin >> lname;

	cout << "Enter customer first initial: " << endl;
	cin >> finit;
}


void readCustomersFile(string fname, BSTree& bst) {
	// Read customer data from a file.
	// Create a file object and open the file
	ifstream inStream;
	inStream.open(fname.c_str());

	// Temporary variables for reading customers.
	string lname;
	char finit;
	int balance;

	// Only process file if opening it is successful
	if(!inStream.fail()){
		// Insert words in the vector
		while(!inStream.eof()){
			inStream >> lname >> finit >> balance; // Read customer.
			bst.insert(lname,finit,balance);
		}

		inStream.close(); 
	}else{
		cout << "file not found ...";
	}
}
