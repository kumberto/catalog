#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <set>
#include <map>
#include "category.h"
#include "order.h"

using namespace std;
class Order;
class Category;
class NotNumberItem{};

class Item {
	private:
		static set<string> listItem;
		Category* nameCategory;
		string nameItem;
		int numberItem;
		set<Order*> orderList;
	public:
		Item(Category name, string nameIt, int number);
		~Item();
		string getName() const;
		int getNumber() const;
		Category* getNameCategory() const;
		void setNumberItem(int num);
		void removeItem(int number);
		void removeOrder(Order* name);
		void addOrder(Order* name, int number);
		const set<Order*>& getOrderList();
		static set<string>& getListItem();
};

#endif