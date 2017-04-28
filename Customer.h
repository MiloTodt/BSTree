#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>
using namespace std;

class Customer {
public:
	Customer(string,char,int);
	Customer();
	~Customer();
	Customer(const Customer& in);
	string getName();
	char getInitial();
	int getBalance();
	void setBalance(int x);
	bool operator== ( Customer &b);
	bool operator<  (Customer &b);
	bool operator<= (Customer &b);
	bool operator>  (Customer &b);
	bool operator>= (Customer &b);
	bool operator!= (Customer &b);
private:
	friend ostream& operator<<(ostream & os,  Customer & c);
	string lastName;
	char initial;
	int balance;

};

#endif /* CUSTOMER_H_ */
