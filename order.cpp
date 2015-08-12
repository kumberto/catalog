#include "order.h"

set<string> Order::listOrder;

Order::Order(Customer nameCust, Item nameIt, int quantity, string name) : name(&nameCust), nameOrder(name){
	addItemOrder(nameIt,quantity);
	listOrder.insert(nameOrder);
}

Order::~Order() {
	listOrder.erase(nameOrder);
	
	for ( map<Item*,int>::const_iterator it = order.begin(); it != order.end(); it++ ) {
		it->first->removeOrder(this);
	}
	name->removeOrder(this);
}

string Order::getName() {
	return nameOrder;
}
// void Order::listOrder() {
	// string ok = "o";
	// int quantity;
	// while( ok == "x" ) {
		// cout << "Введите название товара и количество!" << endl;
		// cout << "Для окончания составления заказа нажмите 'ч'" << enld;
		// cin >> ok >> quantity;
		// if ( listItem.count(ok) < 0 ) {
			// throw NotItem();
		// }
		// if ( ok.getNumber() < quantity ) {
			// throw NotItemQuantity;
		// }
		
		// order[ok] = quantity;
		// ok.removeItem(quantity);
	// }
// }
const map<Item*, int>& Order::getOrder() {
	return order;
}

void Order::addItemOrder(Item& name, int quantity) {
	if ( name.getNumber() < quantity ) {
		throw NotItemQuantity();
	}
	name.removeItem(quantity);
	order[&name] += quantity;
}
void Order::removeItemOrder(Item& name, int quantity) {
	map<Item*, int>:: const_iterator ifind = order.find(&name);
	if ( ifind != order.end() ) {
		if( ifind->second <= quantity ) {
			order.erase(&name);
		} else {
			order[&name] -= quantity;
		}
	}
	
	
}

set<string> Order::getListOrder() {
	return listOrder;
}
