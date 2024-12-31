#include <iostream>
#include <string>
#include "Phone.h"

Phone::Phone(std::string nsx, std::string pb, double sz, int bh) {
	manufacturer = nsx;
	version = pb;
	sizeOfPhone = sz;
	guarantee = bh;
}
void Phone::call() {
}
void Phone::showPhoneSpecifications() {
	std::cout << "Nha san xuat : " << manufacturer << std::endl;
	std::cout << "Phien ban    : " << version << std::endl;
	std::cout << "Kich thuoc   : " << sizeOfPhone << " inch" << std::endl;
	std::cout << "Bao hanh     : " << guarantee << " nam" << std::endl;
	std::cout << std::endl;
}

IPhone::IPhone(std::string nsx, std::string pb, double sz, int bh) : Phone(nsx, pb, sz, bh) {
}
void IPhone::faceId() {
}
void IPhone::AirDrop() {
}
void IPhone::openAppStore() {
}

GalaxyS::GalaxyS(std::string nsx, std::string pb, double sz, int bh) : Phone(nsx, pb, sz, bh) {
}
void GalaxyS::openS_pen(){
}
void GalaxyS::openGooglePlay(){
}
