#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

class HocSinh {
	int maHS = 0;
	std::string tenHS = "";
	int tuoiHS = 0;
	std::string quequanHS = "";
	float chieucaoHS = 0.0;
	float cannangHS = 0.0;
	std::string dsMon[8] = { "Toan", "Ly", "Hoa", "Van", "Anh", "Sinh", "Su", "Dia" };
	float diemHS[8] = { 0 }; // Toan, Ly, Hoa, Van, Anh, Sinh, Su, Dia.

	static int soluongHocSinh;

public:
	static void soHocSinh();

	HocSinh() {
		soluongHocSinh++;
	}
	HocSinh(int ma, std::string ten, int tuoi, std::string qq, float cc, float cn, float diem[]) {
		maHS = ma;
		tenHS = ten;
		tuoiHS = tuoi;
		quequanHS = qq;
		chieucaoHS = cc;
		cannangHS = cn;
		for (int i = 0; i < (sizeof(diemHS)/sizeof(diemHS[0])); i++) diemHS[i] = diem[i];
	}

	void hienThiGioiThieu() const {
		std::cout << "Toi la " << tenHS << "." << std::endl;
		std::cout << "Hien toi " << tuoiHS << " tuoi." << std::endl;
		std::cout << "Que quan o " << quequanHS << "." << std::endl;
	}
	void hienThiBangDiem() const {
		std::cout << "\n========== BANG DIEM MON HOC ==========" << std::endl;
		std::cout << "+-------+--------------------+--------+" << std::endl;
		std::cout << "|  STT  |      Ten mon       |  Diem  |" << std::endl;
		std::cout << "+-------+--------------------+--------+" << std::endl;
		for (int i = 0; i < (sizeof(diemHS) / sizeof(diemHS[0])); i++) {
			std::cout << "|   " << i + 1 << "   |" << "  " << std::left << std::setw(18) << dsMon[i] << "|  " << std::setw(6) << diemHS[i] << "|" << std::endl;
			std::cout << "+-------+--------------------+--------+" << std::endl;
		}
	}
	void hienThiHocLuc() const {
		float dtb = 0;
		for (int i = 0; i < (sizeof(diemHS) / sizeof(diemHS[0])); i++) dtb += diemHS[i];
		dtb /= (static_cast<float>(sizeof(diemHS)) / sizeof(diemHS[0])); // Tinh diem trung binh
		std::string hocluc = (dtb > 8) ? "Gioi" : (dtb >= 5) ? "Kha" : "Trung binh"; // Xet hoc luc theo dieu kien
		std::cout << "\nDiem tb mon la " << dtb <<  " => hoc luc cua " << tenHS << " la " << hocluc << std::endl;
	}

	//setter
	void setmaHS(int ma) {
		maHS = ma;
	}
	void settenHS(std::string ten) {
		tenHS = ten;
	}
	void settuoiHS(int tuoi) {
		tuoiHS = tuoi;
	}
	void setqueQuanHS(std::string qq) {
		quequanHS = qq;
	}
	void setchieuCaoHS(float cc) {
		chieucaoHS = cc;
	}
	void setcanNangHS(float cn) {
		cannangHS = cn;
	}
	void setdiemHS(float diem[]) {
		for (int i = 0; i < (sizeof(diemHS) / sizeof(diemHS[0])); i++) diemHS[i] = diem[i];
	}

	//getter
	int getmaHS() const {
		return maHS;
	}
	std::string gettenHS() {
		return tenHS;
	}
	const std::string* getDsMon() const {
		return dsMon;
	}
	float getchieuCaoHS() const {
		return chieucaoHS;
	}
	float getcanNangHS() const {
		return cannangHS;
	}
	std::string getqueQuanHS() {
		return quequanHS;
	}
	int gettuoiHS() const {
		return tuoiHS;
	}
	float getdiemTB() const {
		float dtb = 0;
		for (int i = 0; i < 8; i++) dtb += diemHS[i];
		return (dtb / 8);
	}

};

class LopHoc {
	std::string maLop;
	std::vector<HocSinh*> dsLop;
	HocSinh* lopTruong;

	static int soLopTrongTruong;
	

public:
	static void soLop();

	LopHoc() {
		maLop = "";
		lopTruong = nullptr;
		soLopTrongTruong++;
	}
	~LopHoc() {
		for (auto i : dsLop) delete i;
		delete lopTruong;
	}

	void themHS() {
		HocSinh* hocSinhMoi = new HocSinh;
		std::cout << "Ma hoc sinh (4)   : "; int ma; std::cin >> ma; hocSinhMoi->setmaHS(ma); std::cin.ignore();
		std::cout << "Ten hoc sinh      : "; std::string ten; std::getline(std::cin, ten, '\n'); hocSinhMoi->settenHS(ten);
		std::cout << "Tuoi hoc sinh     : "; int tuoi; std::cin >> tuoi; hocSinhMoi->settuoiHS(tuoi); std::cin.ignore();
		std::cout << "Que quan          : "; std::string qq; std::getline(std::cin, qq); hocSinhMoi->setqueQuanHS(qq);
		std::cout << "Chieu cao hs (m)  : "; float cc; std::cin >> cc; hocSinhMoi->setchieuCaoHS(cc); std::cin.ignore();
		std::cout << "Can nang hs (kg)  : "; float cn; std::cin >> cn; hocSinhMoi->setcanNangHS(cn); std::cin.ignore();

		std::cout << "\nDiem cac mon cua hoc sinh " << hocSinhMoi->gettenHS() << ":" << std::endl;
		const std::string* dsMon = hocSinhMoi->getDsMon();
		float diemHS[8] = { 0 };
		for (int i = 0; i < 8; i++) {
			std::cout << std::setw(4) << std::setfill(' ') << std::left << dsMon[i] << std::right << ": "; std::cin >> diemHS[i];
		}
		std::cin.ignore();
		hocSinhMoi->setdiemHS(diemHS);

		dsLop.push_back(hocSinhMoi);
	}
	void xoaHS() {
		std::cout << "\n============== DANH SACH LOP ===============" << std::endl;
		std::cout << "+-------------+----------------------------+" << std::endl;
		std::cout << "| Ma hoc sinh |       Ten hoc sinh         |" << std::endl;
		std::cout << "+-------------+----------------------------+" << std::endl;
		for (int i = 0; i < dsLop.size(); i++) {
			std::cout << "|    " << dsLop[i]->getmaHS() << "     |" << " " << std::setfill(' ') << std::setw(27) << std::left << dsLop[i]->gettenHS() << std::right << "|" << std::endl;;
			std::cout << "+-------------+----------------------------+" << std::endl;
		}

		int maXoa;
		std::cout << "\nMa hoc sinh muon xoa: "; std::cin >> maXoa;
		//Xoa theo ma hoc sinh
		auto it = std::find_if(dsLop.begin(), dsLop.end(), [maXoa](HocSinh* hs) { return hs->getmaHS() == maXoa; }); // Tim ma can xoa trong danh sach
		if (it != dsLop.end()) {
			delete* it; // Giai phong vung nho
			dsLop.erase(it); // Xoa hoc sinh ra khoi dsLop
			std::cout << "Xoa thanh cong" << std::endl;
		}
		else {
			std::cout << "Xoa khong thanh cong" << std::endl;
		}

		if (!dsLop.empty()) {
			std::cout << "\n============== DANH SACH LOP ===============" << std::endl;
			std::cout << "+-------------+----------------------------+" << std::endl;
			std::cout << "| Ma hoc sinh |       Ten hoc sinh         |" << std::endl;
			std::cout << "+-------------+----------------------------+" << std::endl;
			for (int i = 0; i < dsLop.size(); i++) {
				std::cout << "|    " << dsLop[i]->getmaHS() << "     |" << " " << std::setfill(' ') << std::setw(27) << std::left << dsLop[i]->gettenHS() << std::right << "|" << std::endl;;
				std::cout << "+-------------+----------------------------+" << std::endl;
			}
		}
		else std::cout << "Hien khong con hoc sinh..." << std::endl;
	}
	void suaHS() {
		//Thong bao danh sach hien tai
		std::cout << "\n============== DANH SACH LOP ===============" << std::endl;
		std::cout << "+-------------+----------------------------+" << std::endl;
		std::cout << "| Ma hoc sinh |       Ten hoc sinh         |" << std::endl;
		std::cout << "+-------------+----------------------------+" << std::endl;
		for (int i = 0; i < dsLop.size(); i++) {
			std::cout << "|    " << dsLop[i]->getmaHS() << "     |" << " " << std::setfill(' ') << std::setw(27) << std::left << dsLop[i]->gettenHS() << std::right << "|" << std::endl;;
			std::cout << "+-------------+----------------------------+" << std::endl;
		}

		//Nhap ma de tim
		std::cout << "\nMa hoc sinh muon sua: "; int maSua; std::cin >> maSua;
		std::vector<HocSinh*>::iterator hocsinh = std::find_if(dsLop.begin(), dsLop.end(), [maSua](HocSinh* hs) { return hs->getmaHS() == maSua; }); // Tim ma can xoa trong danh sach
		if (hocsinh != dsLop.end()) {
			(*hocsinh)->hienThiGioiThieu();
			(*hocsinh)->hienThiBangDiem();
			
			//Bat dau nhap cap nhat
			std::cout << "\nNhap lai thong tin cua hoc sinh " << (*hocsinh)->gettenHS() << std::endl;
			std::cout << "Tuoi hoc sinh     : "; int tuoi; std::cin >> tuoi; (*hocsinh)->settuoiHS(tuoi); std::cin.ignore();
			std::cout << "Que quan          : "; std::string qq; std::getline(std::cin, qq); (*hocsinh)->setqueQuanHS(qq);
			std::cout << "Chieu cao hs (m)  : "; float cc; std::cin >> cc; (*hocsinh)->setchieuCaoHS(cc); std::cin.ignore();
			std::cout << "Can nang hs (kg)  : "; float cn; std::cin >> cn; (*hocsinh)->setchieuCaoHS(cn); std::cin.ignore();

			std::cout << "\nDiem cac mon cua hoc sinh " << (*hocsinh)->gettenHS() << ":" << std::endl;
			const std::string* dsMon = (*hocsinh)->getDsMon();
			float diemHS[8] = { 0 };
			for (int i = 0; i < 8; i++) {
				std::cout << std::setw(4) << std::setfill(' ') << std::left << dsMon[i] << std::right << ": ";
				std::cin >> diemHS[i];
			}
			std::cin.ignore();
			(*hocsinh)->setdiemHS(diemHS);

			// Hien thi lai thong tin da cap nhat
			std::cout << "\nThong tin da cap nhat" << std::endl;
			(*hocsinh)->hienThiGioiThieu();
			(*hocsinh)->hienThiBangDiem();
		}
		else {
			std::cout << "Khong ton tai trong danh sach" << std::endl;
		}
	}
	void thietLapLT() {
		if (lopTruong) {
			std::cout << "Lop truong la: " << lopTruong->getmaHS() << " - " << lopTruong->gettenHS() << std::endl;
			std::cout << "Co muon doi lop truong (Co - 1 hoac Khong - 0): "; int x; std::cin >> x;
			if (x) {
				lopTruong = nullptr;
				thietLapLT();
			}
		}

		else {
			std::cout << "\n============== DANH SACH LOP ===============" << std::endl;
			std::cout << "+-------------+----------------------------+" << std::endl;
			std::cout << "| Ma hoc sinh |       Ten hoc sinh         |" << std::endl;
			std::cout << "+-------------+----------------------------+" << std::endl;
			for (int i = 0; i < dsLop.size(); i++) {
				std::cout << "|    " << dsLop[i]->getmaHS() << "     |" << " " << std::setfill(' ') << std::setw(27) << std::left << dsLop[i]->gettenHS() << std::right << "|" << std::endl;;
				std::cout << "+-------------+----------------------------+" << std::endl;
			}

			std::cout << "Thiet lap lop truong cho lop " << maLop << " theo ma hoc sinh: "; int malt; std::cin >> malt;
			std::vector<HocSinh*>::iterator hocsinh = std::find_if(dsLop.begin(), dsLop.end(), [malt](HocSinh* hs) { return hs->getmaHS() == malt; }); // Tim ma can xoa trong danh sach
			if (hocsinh != dsLop.end()) {
				lopTruong = *hocsinh; // Dat lop truong voi mash da dc nhap
				std::cout << "Thiet lap lop truong thanh cong" << std::endl;
			}
			else {
				std::cout << "Khong ton tai trong danh sach" << std::endl;
			}
		}		
	}
	void hienThiHSLop() {
		std::cout << "================================ DANH SACH LOP " << maLop << " ================================" << std::endl;
		std::cout << "+------+-------------------------+------+----------+---------+-------------+-------+" << std::endl;
		std::cout << "| MaHS |          TenHS          | Tuoi | Chieucao | Cannang |   Quequan   |  DTB  |" << std::endl;
		std::cout << "+------+-------------------------+------+----------+---------+-------------+-------+" << std::endl;
		
		for (int i = 0; i < dsLop.size(); i++) {
			std::cout << "| " << std::setfill(' ') << std::setw(5) << std::left << dsLop[i]->getmaHS() << std::right << "| "
				<< std::setw(24) << std::left << dsLop[i]->gettenHS() << std::right << "| "
				<< std::setw(5) << std::left << dsLop[i]->gettuoiHS() << std::right << "| "
				<< std::setw(9) << std::left << dsLop[i]->getchieuCaoHS() << std::right << "| "
				<< std::setw(8) << std::left << dsLop[i]->getcanNangHS() << std::right << "| "
				<< std::setw(12) << std::left << dsLop[i]->getqueQuanHS() << std::right << "| "
				<< std::setw(6) << std::left  << std::setprecision(3) << dsLop[i]->getdiemTB() << std::right << "|" << std::endl;
			std::cout << "+------+-------------------------+------+----------+---------+-------------+-------+" << std::endl;
		}
	}

	//setter
	void setmaLop(std::string ma) {
		maLop = ma;
	}

	//getter
	std::string getmaLop() {
		return maLop;
	}
	std::vector<HocSinh*>& getdsLop() {
		return dsLop;
	}
	HocSinh* getlopTruong() {
		return lopTruong;
	}
};

int HocSinh::soluongHocSinh = 0;
int LopHoc::soLopTrongTruong = 0;
void LopHoc::soLop() {
	std::cout << "\nSo lop hoc trong truong la " << soLopTrongTruong << std::endl;
}
void HocSinh::soHocSinh() {
	std::cout << "\nSo hoc sinh co trong lop la: " << soluongHocSinh << std::endl;
};


// Cac ham trong main
static void menuChinh() {
	std::cout << "\t================== TRUONG THPT NGUYEN BINH KHIEM ===================" << std::endl;
	std::cout << "\t+------------------------------------------------------------------+" << std::endl;
	std::cout << "\t|          HO SO HOC SINH TRUONG THPT NGUYEN BINH KHIEM            |" << std::endl;
	std::cout << "\t+------------------------------------------------------------------+" << std::endl;
	std::cout << "\t|   0. Thoat chuong trinh                                          |" << std::endl;
	std::cout << "\t+------------------------------------------------------------------+" << std::endl;
	std::cout << "\t|   1. Them lop                                                    |" << std::endl;
	std::cout << "\t+------------------------------------------------------------------+" << std::endl;
	std::cout << "\t|   2. Danh sach lop hien tai                                      |" << std::endl;
	std::cout << "\t+------------------------------------------------------------------+" << std::endl;
	std::cout << "\t|   3. Them hoc sinh                                               |" << std::endl;
	std::cout << "\t+------------------------------------------------------------------+" << std::endl;
	std::cout << "\t|   4. Danh sach hoc sinh                                          |" << std::endl;
	std::cout << "\t+------------------------------------------------------------------+" << std::endl;
	std::cout << "\t|   5. Cap nhat thong tin hoc sinh                                 |" << std::endl;
	std::cout << "\t+------------------------------------------------------------------+" << std::endl;
	std::cout << "\t|   6. Cap nhat lop truong                                         |" << std::endl;
	std::cout << "\t+------------------------------------------------------------------+" << std::endl;
	std::cout << "\t|   7. Xoa lop                                                     |" << std::endl;
	std::cout << "\t+------------------------------------------------------------------+" << std::endl;
	std::cout << "\t|   8. Xoa hoc sinh                                                |" << std::endl;
	std::cout << "\t+------------------------------------------------------------------+" << std::endl;
	std::cout << "\t====================================================================" << std::endl;
}
static void luaChon1(std::vector<LopHoc*>& THPT) {
	LopHoc* newLop = new LopHoc;

	std::cout << "============== THEM LOP ==============\n" << std::endl;
	std::cout << "Nhap ten lop: "; std::string tenlop; std::getline(std::cin, tenlop); newLop->setmaLop(tenlop);
	std::cout << "Ten lop la: " << newLop->getmaLop() << std::endl;
	THPT.push_back(newLop);
	std::cout << "Da them thanh cong!" << std::endl;
}
static void luaChon2(std::vector<LopHoc*> THPT) {
	std::cout << "========== DANH SACH CAC LOP ==========" << std::endl;
	std::cout << "+--------------------+----------------+" << std::endl;
	std::cout << "|         Lop        |      Si so     |" << std::endl;
	std::cout << "+--------------------+----------------+" << std::endl;

	for (int i = 0; i < THPT.size(); i++) {
		std::cout << "| " << std::left << std::setfill(' ') << std::setw(19) << THPT[i]->getmaLop() << std::right << "|   " << std::setw(13) << std::left <<  THPT[i]->getdsLop().size() << std::right << "|" << std::endl;
		std::cout << "+--------------------+----------------+" << std::endl;
	}
}
static void luaChon3(std::vector<LopHoc*>& THPT) {
	if (THPT.size()) {
		luaChon2(THPT);
		std::cout << "\nChon lop: "; std::string malop; std::getline(std::cin, malop);
		std::vector<LopHoc*>::iterator lop = std::find_if(THPT.begin(), THPT.end(), [malop](LopHoc* l) { return l->getmaLop() == malop; }); // Tim ma can xoa trong danh sach
		if (lop != THPT.end()) {
			if ((*lop)->getdsLop().size()) (*lop)->hienThiHSLop();
			else std::cout << "Hien chua co hoc sinh..." << std::endl;
			std::cout << "Them hoc sinh #" << std::endl;
			(*lop)->themHS();
		}
		else {
			std::cout << "Lop khong ton tai..." << std::endl;
		}
	}
	else {
		std::cout << "Hien chua co lop!!!" << std::endl;
	}
}
static void luaChon4(std::vector<LopHoc*> THPT) {
	if (THPT.size()) {
		luaChon2(THPT);
		std::cout << "\nChon lop: "; std::string malop; std::getline(std::cin, malop);
		std::vector<LopHoc*>::iterator lop = std::find_if(THPT.begin(), THPT.end(), [malop](LopHoc* l) { return l->getmaLop() == malop; }); // Tim ma can xoa trong danh sach
		if (lop != THPT.end()) {
			if ((*lop)->getdsLop().size()) (*lop)->hienThiHSLop();
			else std::cout << "Hien chua co hoc sinh..." << std::endl;
		}
		else {
			std::cout << "Lop khong ton tai..." << std::endl;
		}
	}
	else {
		std::cout << "Hien chua co lop!!!" << std::endl;
	}
}
static void luaChon5(std::vector<LopHoc*>& THPT) {
	if (THPT.size()) {
		luaChon2(THPT);
		std::cout << "\nChon lop: "; std::string malop; std::getline(std::cin, malop);
		std::vector<LopHoc*>::iterator lop = std::find_if(THPT.begin(), THPT.end(), [malop](LopHoc* l) { return l->getmaLop() == malop; }); // Tim ma can xoa trong danh sach
		if (lop != THPT.end()) {
			if ((*lop)->getdsLop().size()) (*lop)->suaHS();
			else std::cout << "Hien chua co hoc sinh..." << std::endl;
		}
		else {
			std::cout << "Lop khong ton tai..." << std::endl;
		}
	}
	else {
		std::cout << "Hien chua co lop!!!" << std::endl;
	}
}
static void luaChon6(std::vector<LopHoc*>& THPT) {
	if (THPT.size()) {
		std::cout << "========== DANH SACH CAC LOP ==========" << std::endl;
		std::cout << "+------------+---------+--------------+" << std::endl;
		std::cout << "|     Lop    |  Si so  |  Lop truong  |" << std::endl;
		std::cout << "+------------+---------+--------------+" << std::endl;

		for (int i = 0; i < THPT.size(); i++) {
			std::cout << "| " << std::left << std::setfill(' ') << std::setw(11) << THPT[i]->getmaLop() << std::right << "|  "
				<< std::setw(7) << std::left << THPT[i]->getdsLop().size() << std::right << "| "
				<< std::setw(13) << std::left << ((THPT[i]->getlopTruong()) ? "Da co" : "Chua co") << std::right << "|" << std::endl;
			std::cout << "+------------+---------+--------------+" << std::endl;
		}

		std::cout << "\nChon lop: "; std::string malop; std::getline(std::cin, malop);
		std::vector<LopHoc*>::iterator lop = std::find_if(THPT.begin(), THPT.end(), [malop](LopHoc* l) { return l->getmaLop() == malop; }); // Tim ma can xoa trong danh sach
		if (lop != THPT.end()) {
			if ((*lop)->getdsLop().size()) (*lop)->thietLapLT();
			else std::cout << "Hien chua co hoc sinh..." << std::endl;
		}
		else {
			std::cout << "Lop khong ton tai..." << std::endl;
		}
	}
	else {
		std::cout << "Hien chua co lop!!!" << std::endl;
	}
	
}
static void luaChon7(std::vector<LopHoc*>& THPT) {
	if (!THPT.empty()) {
		luaChon2(THPT);
		std::cout << "\nChon lop: "; std::string malop; std::getline(std::cin, malop);
		std::vector<LopHoc*>::iterator lop = std::find_if(THPT.begin(), THPT.end(), [malop](LopHoc* l) { return l->getmaLop() == malop; }); // Tim ma can xoa trong danh sach
		if (lop != THPT.end()) {
			for (HocSinh* hs : (*lop)->getdsLop()) {
				delete hs;
			}
			(*lop)->getdsLop().clear();
			delete* lop;
			THPT.erase(lop);
			std::cout << "Da xoa lop thanh cong!\n" << std::endl;
			if (THPT.empty()) std::cout << "Hien khong con lop..." << std::endl;
			else luaChon2(THPT);
		}
		else {
			std::cout << "Lop khong ton tai..." << std::endl;
		}
	}
	else {
		std::cout << "Hien chua co lop!!!" << std::endl;
	}
}
static void luaChon8(std::vector<LopHoc*>& THPT) {
	if (THPT.size()) {
		luaChon2(THPT);
		std::cout << "\nChon lop: "; std::string malop; std::getline(std::cin, malop);
		std::vector<LopHoc*>::iterator lop = std::find_if(THPT.begin(), THPT.end(), [malop](LopHoc* l) { return l->getmaLop() == malop; }); // Tim ma can xoa trong danh sach
		if (lop != THPT.end()) {
			if ((*lop)->getdsLop().size()) {
				(*lop)->hienThiHSLop();
				std::cout << "Xoa hoc sinh #" << std::endl;
				(*lop)->xoaHS();
			}
			else std::cout << "Hien chua co hoc sinh..." << std::endl;
		}
		else {
			std::cout << "Lop khong ton tai..." << std::endl;
		}
	}
	else {
		std::cout << "Hien chua co lop!!!" << std::endl;
	}
}

int main() {
	std::vector<LopHoc*> THPT;
	bool isRunning = true;

	while (isRunning) {
		system("cls");
		menuChinh(); int luachon;
		std::cout << "Lua chon cua ban: "; std::cin >> luachon; std::cin.ignore();
		switch (luachon) {
			case 0: {
				isRunning = false;
				std::cout << "Chuong trinh ket thuc..." << std::endl;
			}
				  break;
			case 1: {
				system("cls");
				luaChon1(THPT);
				system("pause");
			}
				  break;
			case 2: {
				system("cls");
				if (THPT.size()) luaChon2(THPT);
				else std::cout << "Hien chua co lop!!!" << std::endl;
				system("pause");
			}
				  break;
			case 3: {
				system("cls");
				luaChon3(THPT);
				system("pause");
			}
				  break;
			case 4: {
				system("cls");
				luaChon4(THPT);
				system("pause");
			}
				  break;
			case 5: {
				system("cls");
				luaChon5(THPT);
				system("pause");
			}
				  break;
			case 6: {
				system("cls");
				luaChon6(THPT);
				system("pause");
			}
				  break;
			case 7: {
				system("cls");
				luaChon7(THPT);
				system("pause");
			}
				  break;
			case 8: {
				system("cls");
				luaChon8(THPT);
				system("pause");
			}
				  break;
			default:
				std::cout << "Hay nhap gia tri dung!!!" << std::endl;
				system("pause");
				for (auto i : THPT) delete i;
				THPT.clear();
				break;
		}
	}
	return 0;
}