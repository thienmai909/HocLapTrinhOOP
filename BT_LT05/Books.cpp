#include "Books.h"

#include <string>
#include <vector>

Books::Books(std::string tennxb, int nampb) {
	tenNXB = tennxb;
	namPH = nampb;
}

SachHocTap::SachHocTap(std::string tennxb, int nampb, std::string tenmh) : Books(tennxb, nampb) {
	tenMH = tenmh;
}

SachGiaoKhoa::SachGiaoKhoa(std::string tennxb, int nampb, std::string tenmh, std::vector<std::string> danhstsd) : SachHocTap(tennxb, nampb, tenmh) {
	danhSTSD = danhstsd;
}

SachBaiTap::SachBaiTap(std::string tennxb, int nampb, std::string tenmh, std::string mucd) : SachHocTap(tennxb, nampb, tenmh) {
	mucD = mucd;
}

Truyen::Truyen(std::string tennxb, int nampb, int gioihdt, std::string tentg, std::string tennd) : Books(tennxb, nampb) {
	tenTG = tentg;
	gioiHDT = gioiHDT;
	tenND = tennd;
}

TieuThuyet::TieuThuyet(std::string tennxb, int nampb, int gioihdt, std::string tentg, std::string tennd, int soc) : Truyen(tennxb, nampb, gioihdt, tentg, tennd) {
	soC = soc;
}

TieuThuyetNgonTinh::TieuThuyetNgonTinh(std::string tennxb, int nampb, int gioihdt, std::string tentg, std::string tennd, int soc) : TieuThuyet(tennxb, nampb, gioihdt, tentg, tennd, soc) {
}

TieuThuyetTrinhTham::TieuThuyetTrinhTham(std::string tennxb, int nampb, int gioihdt, std::string tentg, std::string tennd, int soc) : TieuThuyet(tennxb, nampb, gioihdt, tentg, tennd, soc) {
}

TruyenTranh::TruyenTranh(std::string tennxb, int nampb, int gioihdt, std::string tentg, std::string tennd, std::vector<std::string> dstct) : Truyen(tennxb, nampb, gioihdt, tentg, tennd) {
	dsTCT = dstct;
}
