#pragma once
#include <string>

class Phone {
private:
	std::string manufacturer;
	std::string version;
	double sizeOfPhone;
	int guarantee;
public:
	Phone(std::string nsx, std::string pb, double sz, int bh);
	void call();
	void showPhoneSpecifications();
};

class IPhone : public Phone {
private:
public:
	IPhone(std::string nsx, std::string pb, double sz, int bh);
	void faceId();
	void AirDrop();
	void openAppStore();
};

class GalaxyS : public Phone {
private:
public:
	GalaxyS(std::string nsx, std::string pb, double sz, int bh);
	void openS_pen();
	void openGooglePlay();
};