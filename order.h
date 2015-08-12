#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <set>
#include "item.h"
#include "customer.h"
using namespace std;

class Item;
class Customer;
class NotItemQuantity {};


class Order {
	private:
		static set<string> listOrder;
		string nameOrder;
		map<Item*,int> order;
		Customer* name;
	public:
		Order(Customer nameCust, Item nameIt, int quantity, string name);
		~Order();
		//void listOrder();
		string getName();
		const map<Item*,int>& getOrder();
		void addItemOrder(Item& name, int quantity);
		void removeItemOrder(Item& name, int quantity);
		static set<string> getListOrder();
		Item getItem(Item& name);
};

#endif