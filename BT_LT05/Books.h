#pragma once
#include <string>
#include <vector>

class Books {
private:
	std::string tenNXB;
	int namPH{};
public:
	Books(std::string tennxb, int nampb);
};

class SachHocTap : public Books {
private:
	std::string tenMH;
public:
	SachHocTap(std::string tennxb, int nampb, std::string tenmh);
};

class SachGiaoKhoa : public SachHocTap {
private:
	std::vector<std::string> danhSTSD;
public:
	SachGiaoKhoa(std::string tennxb, int nampb, std::string tenmh, std::vector<std::string> danhstsd);
};

class SachBaiTap : public SachHocTap {
private:
	std::string mucD;
public:
	SachBaiTap(std::string tennxb, int nampb, std::string tenmh, std::string mucd);
};

class Truyen : public Books {
private:
	int gioiHDT{};
	std::string tenTG;
	std::string tenND;
public:
	Truyen(std::string tennxb, int nampb, int gioihdt, std::string tentg, std::string tennd);
};

class TieuThuyet : public Truyen {
private:
	int soC{};
public:
	TieuThuyet(std::string tennxb, int nampb, int gioihdt, std::string tentg, std::string tennd, int soc);
};

class TieuThuyetNgonTinh : public TieuThuyet {
private:
public:
	TieuThuyetNgonTinh(std::string tennxb, int nampb, int gioihdt, std::string tentg, std::string tennd, int soc);
};

class TieuThuyetTrinhTham : public TieuThuyet {
private:
public:
	TieuThuyetTrinhTham(std::string tennxb, int nampb, int gioihdt, std::string tentg, std::string tennd, int soc);
};

class TruyenTranh : public Truyen {
private:
	std::vector<std::string> dsTCT;
public:
	TruyenTranh(std::string tennxb, int nampb, int gioihdt, std::string tentg, std::string tennd, std::vector<std::string> dstct);
};
