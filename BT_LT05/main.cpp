#include "nlohmann/json.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

//Bai 1
#include "Phone.h"
//Bai 2
#include "Books.h"
//Bai 3
struct DateTime {
	int phut{};
	int gio{};
	int ngay{};
	int thang{};
	int nam{};
};

class AirlineTickets {
private:
	std::string tenChuyen;
	DateTime ngayBay;
	int giaVe{};
public:
	//Constructor
	AirlineTickets() {
	}
	//Setter
	void setTenChuyen(std::string ten) {
		tenChuyen = ten;
	}
	void setNgayBay(DateTime ngay) {
		ngayBay = ngay;
	}
	void setGiaVe(int gia) {
		giaVe = gia;
	}
	//Getter
	std::string getTenChuyen() {
		return tenChuyen;
	}
	DateTime getNgayBay() {
		return ngayBay;
	}
	int getGiaVe() {
		return giaVe;
	}
};

class Person {
private:
	std::string hoTen;
	std::string gioiTinh;
	int tuoi{};
public:
	//Constructor
	Person() {
	}
	Person(std::string ten, std::string gioi, int t) {
		hoTen = ten;
		gioiTinh = gioi;
		tuoi = t;
	}
	//Setter
	void setHoTen(std::string ten) {
		hoTen = ten;
	}
	void setGioiTinh(std::string gioi) {
		gioiTinh = gioi;
	}
	void setTuoi(int t) {
		tuoi = t;
	}
	//Getter
	std::string getHoTen() {
		return hoTen;
	}
	std::string getGioiTinh() {
		return gioiTinh;
	}
	int getTuoi() {
		return tuoi;
	}
};

class Passenger : public Person {
private:
	AirlineTickets* veMayBay{};
	int soLuongVe{};
public:
	//Constructor
	Passenger() : Person() {
	}
	Passenger(std::string ten, std::string gioi, int t, AirlineTickets* ve, int sove) : Person(ten, gioi, t) {
		veMayBay = ve;
		soLuongVe = sove;
	}
	//Setter
	void setVeMayBay(AirlineTickets* ve) {
		veMayBay = ve;
	}
	void setSoLuongVe(int sove) {
		soLuongVe = sove;
	}
	//Getter
	AirlineTickets* getVeMayBay() {
		return veMayBay;
	}
	int getSoLuongVe() {
		return soLuongVe;
	}
};

std::vector<Passenger*> docFile() {
	std::vector<Passenger*> danhSachKhachHang;
	
	std::ifstream readFile("input.json");
	nlohmann::json data = nlohmann::json::parse(readFile);

	int soLuongKhach = data["quantity"];
	for (const auto& customer : data["customers"]) {
		std::string hoTen = customer["name"];
		std::string gioiTinh = customer["sex"];
		int tuoi = customer["age"];
		int soVe = customer["numberoftickets"];
		std::string tenChuyen = customer["ticket"]["flightname"];
		int giaVe = customer["ticket"]["flightticketprice"];

		std::string thoiGianBay = customer["ticket"]["flightdate"];
		std::stringstream ss(thoiGianBay);
		char delim{};	
		DateTime dateTime;
		ss >> dateTime.gio >> delim >> dateTime.phut;
		ss >> dateTime.ngay >> delim >> dateTime.thang >> delim >> dateTime.nam;
		
		AirlineTickets* veBay = new AirlineTickets;
		veBay->setTenChuyen(tenChuyen);
		veBay->setNgayBay(dateTime);
		veBay->setGiaVe(giaVe);

		Passenger* khachMoi = new Passenger(hoTen, gioiTinh, tuoi, veBay, soVe);
		danhSachKhachHang.push_back(khachMoi);
	}

	readFile.close();
	return danhSachKhachHang;
}
void yeuCau(const std::vector<Passenger*>& danhSachKhach) {
	std::ofstream writeFile("output.txt");

	for (const auto& khach : danhSachKhach) {
		AirlineTickets* veBay = khach->getVeMayBay();
		DateTime thoiGian = veBay->getNgayBay();
		std::string thoiGianBay = std::to_string(thoiGian.gio) + ":" + std::to_string(thoiGian.phut) + " " + std::to_string(thoiGian.ngay) + "/" + std::to_string(thoiGian.thang) + "/" + std::to_string(thoiGian.nam);
		int tienVe = veBay->getGiaVe() * khach->getSoLuongVe();

		std::cout << "Ho ten: " << khach->getHoTen() << std::endl;
		std::cout << "Ten chuyen bay: " << veBay->getTenChuyen() << std::endl;
		std::cout << "Khoi hanh luc: " << thoiGianBay << std::endl;
		std::cout << "Tien ve bay: " << tienVe << std::endl;

		std::cout << std::endl;

		writeFile << "Ho ten: " << khach->getHoTen() << "\n";
		writeFile << "Ten chuyen bay: " << veBay->getTenChuyen() << "\n";
		writeFile << "Khoi hanh luc: " << thoiGianBay << "\n";
		writeFile << "Tien ve bay: " << tienVe << "\n";

		writeFile << "\n";	
	}

	writeFile.close();
}
int main() {
	std::vector<Passenger*> danhSachKhach = docFile();
	yeuCau(danhSachKhach);

	for (auto& khach : danhSachKhach) {
		delete khach->getVeMayBay();
		delete khach;
	}
	danhSachKhach.clear();

	return 0;
}