#include "item.h"

#include "Item.h"

using namespace std;

set<string> Item::listItem;

Item::Item(Category name, string nameIt, int number) : nameCategory(&name), nameItem(nameIt), numberItem(number) {
	nameCategory->addItem(this);
	listItem.insert(nameIt);
}
Item::~Item() {
	listItem.erase(nameItem);
	
	if ( !orderList.empty() ) {
		set<Order*>::const_iterator it ;
		for ( it = orderList.begin(); it != orderList.end(); it++ ) {
			delete(*it);
		}
	}
	//nameCategory->removeItem(this);
}

string Item::getName() const {
	return nameItem;
}
int Item::getNumber() const {
	return numberItem;
}

Category* Item::getNameCategory() const {
	return nameCategory;
}

void Item::setNumberItem(int num) {
	numberItem += num;
}

void Item::removeItem(int number) {
	if (number > numberItem) {
		throw NotNumberItem();
	}
	numberItem -= number;
}
void Item::removeOrder(Order* name) {
	orderList.erase(name);
}

void Item::addOrder(Order* name, int number) {
	removeItem(number);
	orderList.insert(name);
}

const set<Order*>& Item::getOrderList() {
	return orderList;
}

set<string>& Item::getListItem() {
	return listItem;
}