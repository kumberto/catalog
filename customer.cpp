#include "customer.h"

set<string> Customer::listCustomer;

Customer::Customer(string name ) : nameCustomer(name) {
	nameCustomer = name;
	listCustomer.insert(nameCustomer);
}
Customer::~Customer(){
	if ( !listOrd.empty() ) {
		set<Order*>::iterator it;
		for ( it = listOrd.begin(); it != listOrd.end(); it++ ) {
			delete(*it);
		}
	}
	listCustomer.erase(nameCustomer);
}

string Customer::getName() {
	return nameCustomer;
}

void Customer::addOrder(Order& name) {
	listOrd.insert(&name);
}

const set<string>& Customer::getCustomer(){
	return listCustomer;
}

void Customer::removeOrder(Order* name) {
	listOrd.erase(name);
}