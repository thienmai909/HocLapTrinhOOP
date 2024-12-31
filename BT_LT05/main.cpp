#include <iostream>
#include <string>

class Phone {
private:
	std::string manufacturer;
	std::string version;
	double sizeOfPhone;
	int guarantee;
public:
	Phone(std::string nsx, std::string pb, double sz, int bh) {
		manufacturer = nsx;
		version = pb;
		sizeOfPhone = sz;
		guarantee = bh;
	}
	void call() {
	}
	void showPhoneSpecifications() {
		std::cout << "Nha san xuat : " << manufacturer << std::endl;
		std::cout << "Phien ban    : " << version << std::endl;
		std::cout << "Kich thuoc   : " << sizeOfPhone << " inch" << std::endl;
		std::cout << "Bao hanh     : " << guarantee << " nam" << std::endl;
		std::cout << std::endl;
	}
};

class IPhone : public Phone {
private:
public:
	IPhone(std::string nsx, std::string pb, double sz, int bh) : Phone(nsx, pb, sz, bh) {

	}
	void faceId() {

	}
	void AirDrop() {

	}
	void openAppStore() {

	}
};

class GalaxyS : public Phone {
private:
public:
	GalaxyS(std::string nsx, std::string pb, double sz, int bh) : Phone(nsx, pb, sz, bh) {
	}
	void openS_pen() {

	}
	void openGooglePlay() {

	}
};

int main() {
	IPhone* iphone = new IPhone("Apple", "16 Pro Max", 6.9, 1);
	iphone->showPhoneSpecifications();
	GalaxyS* galaxys = new GalaxyS("Samsung", "Galaxy S24 Ultra", 6.8, 2);
	galaxys->showPhoneSpecifications();

	delete iphone;
	delete galaxys;
	return 0;
}