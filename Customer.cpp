
#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;

Customer::Customer(string x, char y, int z) {
	lastName = x;
	initial = y;
	balance = z;
}
Customer::Customer(){}
Customer::Customer(const Customer& in) : lastName(in.lastName), initial(in.initial), balance(in.balance) 
{}

ostream& operator<<(ostream & os,  Customer & c)  {
	os << c.getName() << ", " << c.getInitial() << ". (" << c.getBalance() << ")";
	return os;
}
bool Customer::operator== ( Customer &b) {
return (this->getName() == b.getName() && this->getInitial() == b.getInitial());
}

 bool Customer::operator< (Customer &b){
 	if(this->getName() < b.getName()){return true;}
 	else if(this->getName() == b.getName() && this->getInitial() < b.getInitial()){return true;}
 	else{return false;}
 }
 bool Customer::operator<= (Customer &b){
 	 if(this->getName() == b.getName() && this->getInitial() == b.getInitial()){return true;}
 	else if(this->getName() < b.getName()){return true;}
 	else if(this->getName() == b.getName() && this->getInitial() < b.getInitial()){return true;}
 	else{return false;}
 }
 bool Customer::operator> (Customer &b){
 	if(this->getName() > b.getName()){return true;}
 	else if(this->getName() == b.getName() && this->getInitial() > b.getInitial()){return true;}
 	else{return false;}
 }
 bool Customer::operator>= (Customer &b){
 	if(this->getName() == b.getName() && this->getInitial() == b.getInitial()){return true;}
 	else if(this->getName() > b.getName()){return true;}
 	else if(this->getName() == b.getName() && this->getInitial() > b.getInitial()){return true;}
 	else{return false;}
 }
 bool Customer::operator!= (Customer &b){
 	return !(this->getName() == b.getName() && this->getInitial() == b.getInitial());
 }
Customer::~Customer(){}

string Customer::getName(){
	return lastName;
}

char Customer::getInitial(){
	return initial;
}

int Customer::getBalance(){
	return balance;
}

void Customer::setBalance(int x){
	balance = x;
}
