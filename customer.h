#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <set>
#include "order.h"
using namespace std;

class Order;

class Customer {
	private:
		static set<string> listCustomer;
		string nameCustomer;
		set<Order*> listOrd;
	public:
		Customer(string name);
		~Customer();
		string getName();
		void addOrder(Order& name);
		const set<string>& getCustomer();
		void removeOrder(Order* name);
};


#endif