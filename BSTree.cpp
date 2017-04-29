
#include "BSTree.h"
bool found;//Flag for breaking recursion

BSTree::BSTree() {
	root = NULL;
}

BSTree::~BSTree() {
 deleteAllNode(root);
}

void BSTree::copyTree(node *thisRoot, node *inRoot)
{
    if(inRoot == NULL)
    {
        thisRoot = NULL;
    }
    else
    {
        thisRoot = new node;
        thisRoot->thisCustomer = inRoot->thisCustomer;
        copyTree(thisRoot->left, inRoot->left);
        copyTree(thisRoot->right, inRoot->right);
    }
}

    // Creates and inserts a new customer (with the data shown in the parameters) in the tree, in a new tree node.

bool BSTree::insert(string x, char y, int z) {
	node* in = new node;
	node* parent = new node;
	in->thisCustomer = new Customer(x,y,z);
	in->left = NULL;
	in->right = NULL;
	parent = NULL;

	if(isEmpty()){ root = in;} //If this tree is empty then the 1st node is the root.
	else{
        node* currentNode;
        currentNode = root;
        while(currentNode)
        {
            parent = currentNode;
            if(*in->thisCustomer <= *currentNode->thisCustomer){currentNode = currentNode->left;}
            else{ currentNode = currentNode->right;}
        }

        if(*in->thisCustomer <= *parent->thisCustomer)
           {parent->left = in;}
        else
           {parent->right = in;}
    }
    return true;
}

    // Deletes the first node with a matching name and initial from the tree.
    // Returns true if the deletion was successful (that is, if the customer was found).
    // Note that two customers are equal if they have the same name and initial, regardless of the account balance.

bool BSTree::remove(string x, char y) {
   found = false;
    if(isEmpty()){ //Empty tree, so element can not be in it
         return false;
    }
    Customer* tempCustomer = new Customer(x,y,-1);
    node* current;
    node* parent;
    if(*root->thisCustomer == *tempCustomer){ //we are removing the root node.
        node* tempNode = root->right;
        while(tempNode->left != NULL){
            tempNode = tempNode->left;
        }
        *root->thisCustomer = *tempNode->thisCustomer;
        tempNode->thisCustomer = new Customer("DeletionFlagCustomer", 'd', -1); //Super hackish but works. Done this way for consistent deletion handling
        remove("DeletionFlagCustomer", 'd');//using the already built remove function because it handles linking already
        return true;}

    current = root;
    while(current  != NULL){ //One leaf at a time advance through the tree. Since it's a BSTree we know which direction to look.
        if(*current->thisCustomer == *tempCustomer){
            found = true;
            break;
        }
        else{
            parent = current;
            if(*tempCustomer > *current->thisCustomer){current = current->right;}
            else{ current = current->left;}
        }
    }
    if(found == false){return false;}//node not in tree
    if((current->left == NULL && current->right != NULL) || (current->left != NULL && current ->right == NULL))
    {
       if(current->left == NULL && current->right != NULL) //left node
       {
           if(parent->left == current)
           {
             parent->left = current->right;
             delete current;
           }
           else
           {
             parent->right = current->right;
             delete current;
           }
       }
       else // left node, no right node
       {
          if(parent->left == current)
           {
             parent->left = current->left;
             delete current;
           }
           else
           {
             parent->right = current->left;
             delete current;
           }
       }
     return true;
    }
        if( current->left == NULL && current->right == NULL) //leaf node
    {
        if(parent->left == current) {parent->left = NULL;}
        else {parent->right = NULL;}
        delete current;
        return true;
    }
    //2 children
    if (current->left != NULL && current->right != NULL)
    {
        node* tempNode;
        tempNode = current->right;
        if((tempNode->left == NULL) && (tempNode->right == NULL))
        {
            current = tempNode;
            delete tempNode;
            current->right = NULL;
        }
        else 
        {
            if((current->right)->left != NULL)
            {
            node* lcurrrent;
            node* lcurrrentparent;
            lcurrrentparent = current->right;
            lcurrrent = (current->right)->left;
            while(lcurrrent->left != NULL)
            {
               lcurrrentparent = lcurrrent;
               lcurrrent = lcurrrent->left;
            }
            current->thisCustomer = lcurrrent->thisCustomer;
            delete lcurrrent;
            lcurrrentparent->left = NULL;
            }
           else
           {
           node* tempNode;
           tempNode = current->right;
           current->thisCustomer = tempNode->thisCustomer;
           current->right = tempNode->right;
           delete tempNode;
           }
        }
         return true;
    }
    return false; //If we somehow got here something went wrong, should never reach this point.
}

vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a) {
    vector<Customer>* customerVector = new vector<Customer>();
    inOrderVectorAdd(root, x,y,z,a, customerVector);
    return *customerVector;
}

	// Returns a vector of Customers where the customer names (initial and last name)
	// are in the range specified in the parameters.  For example rangeSearch("Dobbs", 'A', "Fogg", D)
	// returns all customers whose names are between Dobbs A and Fogg D.
	
void BSTree::inOrderVectorAdd(node* p, string x, char y, string z, char a, vector<Customer>* customerVector){
    Customer* custA = new Customer(x,y,-1);
    Customer* custB = new Customer(z,a,-1);
        if(p != NULL) //Empty tree, no need to print
    {
        if(p->left) inOrderVectorAdd(p->left,x,y,z,a,customerVector);
        if(*p->thisCustomer >= *custA && *p->thisCustomer <= *custB){customerVector->push_back(*p->thisCustomer);}
        if(p->right) inOrderVectorAdd(p->right,x,y,z,a,customerVector);
    delete custA;
    delete custB;
    }
    else return;
}
void BSTree::inOrderPrint()     // Prints the contents of the tree in sorted order.
{
  inOrderP(root);
}

void BSTree::inOrderP(node* p)
{
    if(p != NULL) //Empty tree, no need to print
    {
        if(p->left) inOrderP(p->left);
        cout <<  *p->thisCustomer << endl;
        if(p->right) inOrderP(p->right);
    }
    else return;
}

void BSTree::deleteAllNode(node* p) 
{
    if(p != NULL) //Empty tree, no need to delete
    {
        if(p->left) deleteAllNode(p->left);
        delete p;
        if(p->right) deleteAllNode(p->right);
    }
    else return;
}

bool BSTree::search(string x, char y){
    if(isEmpty()){ //Empty tree, so element can not be in it
         return false;
    }
    found = false;
    Customer* tempCustomer = new Customer(x,y,-1);
    node* current;
    node* parent;
    current = root;
    while(current  != NULL){
        if(*current->thisCustomer == *tempCustomer)
        {
            found = true;
            break;
        }
        else
        {
            parent = current;
            if(*tempCustomer > *current->thisCustomer){current = current->right;}
            else{ current = current->left;}
        }
    }
    delete tempCustomer;
    return found;
}
bool BSTree::isEmpty(){
	return root == NULL;
}