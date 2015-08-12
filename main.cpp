#include <iostream>
#include "category.h"
#include "item.h"
#include "order.h"
#include "customer.h"

using namespace std;

int main() {
	int r;
	Category* cancelyar = new Category("cancelyar");
	cout << cancelyar->getName() << endl;
	Item* pencil = new Item(*cancelyar, "pencil", 50);
	cout << pencil->getNumber() << " " << pencil->getName() << endl;
	Customer* vasya = new Customer("vasya");
	cout << vasya->getName() << endl;
	cout << pencil->getNumber() << " " << pencil->getName() << endl;
	Order* d = new Order(*vasya,*pencil, 10, "d2");
	cout << d->getName() << endl;
	pencil->addOrder(d,10);
	cin >> r;
	delete d;
	delete pencil;
	delete vasya;
	delete cancelyar;
	return 0;
}