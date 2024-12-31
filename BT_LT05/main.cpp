#include <iostream>
#include <string>
//Bai 1
#include "Phone.h"

int main() {
	IPhone* newIphone = new IPhone("Apple", "16 Pro Max", 6.9, 1);
	newIphone->showPhoneSpecifications();
	GalaxyS* newGalaxyS = new GalaxyS("Samsung", "Galaxy S24 Ultra", 6.8, 2);
	newGalaxyS->showPhoneSpecifications();
	return 0;
}