
#ifndef BSTREE_H_
#define BSTREE_H_

#include "Customer.h"
#include<vector>
#include<string>
using namespace std;

class BSTree {
private:
	struct node{
		node* left;
		node* right;
		Customer* thisCustomer;
		node(){
		left = NULL;
		right = NULL;
		thisCustomer = NULL;
	}
	node(const node & inNode) : left(inNode.left), right(inNode.right), thisCustomer(inNode.thisCustomer) {}
};
	node* root;
public:
	BSTree();
	BSTree(const BSTree & rbt){    
		if(rbt.root == NULL)
        root = NULL;
    else
        copyTree(this->root, rbt.root);} // Copy constructor
	virtual ~BSTree();
	// Creates and inserts a new customer (with the data shown in the parameters) in the tree, in a new tree node.
	bool insert(string, char, int);
	// Deletes the first node with a matching name and initial from the tree.
	// Returns true if the deletion was successful (that is, if the customer was found).
	// Note that two customers are equal if they have the same name and initial, regardless of the account balance.
	bool remove(string, char);
	//  Searches the tree for the given value, returning true if the customer is found
	bool search(string, char);
	// Returns a vector of Customers where the customer names (initial and last name)
	// are in the range specified in the parameters.  For example rangeSearch("Dobbs", 'A', "Fogg", D)
	// returns all customers whose names are between Dobbs A and Fogg D.
	vector<Customer> rangeSearch(string, char, string , char);

	// Prints the contents of the tree in sorted order.
	void inOrderPrint();
	void inOrderP(node* p);
	bool inOrderSearch(node* p, node* c);
	bool isEmpty();
	void inOrderVectorAdd(node* p, string x, char y, string z, char a, vector<Customer>* customerVector);
	void deleteAllNode(node* p);
	void copyTree(node *thisRoot, node *inRoot);
};

#endif /* BSTREE_H_ */
