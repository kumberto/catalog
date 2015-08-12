#include "category.h"
#include "Category.h"


using namespace std;

set<string> Category::listCategory;

Category::Category(string name) : name(name) {
	listCategory.insert(name);
}
Category::~Category(){
	listCategory.erase(name);
	// if (!catalog.empty()) {
		// set<Item*>::const_iterator it = catalog.begin();
		// for ( ; it != catalog.end(); it++ ) {
			// delete(*it);
		// }
	// }
}

string Category::getName() {
	return name;
}
void Category::addItem (Item* nameIt) {
	if ( nameIt->getNameCategory() == this ) {
		catalog.insert(nameIt);
	}
}
void Category::removeItem(Item* nameIt) {
		catalog.erase(nameIt);
}
const set<Item*>& Category::getCatalog() {
	return catalog;
}

set<string>& Category::getListCategory() {
	return listCategory;
}