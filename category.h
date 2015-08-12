#ifndef CATEGORY_H
#define CATEGORY_H

#include <string>
#include <set>

#include "item.h"

using namespace std;

class Item;

class Category {
	private:
		static set<string> listCategory;
		string name;
		set<Item*> catalog;
	public:
		Category(string name);
		~Category();
		string getName();
		void addItem (Item* name);
		void removeItem(Item* name);
		const set<Item*>& getCatalog();
		static set<string>& getListCategory();
};


#endif //category.h