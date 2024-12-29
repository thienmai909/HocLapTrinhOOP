#include <iostream>
#include <vector>

class MaTran {
private:
	int hang;
	int cot;
	std::vector<std::vector<int>> dulieu;
public:
	MaTran(int h, int c) {
		hang = h;
		cot = c;
	}
	
	std::vector<std::vector<int>> nhan(MaTran* matran) {
		int hangKQ = hang;
		int cotKQ = matran->getCot();
		std::vector<std::vector<int>> ketqua(hangKQ, std::vector<int> (cotKQ, 0));
		if (cot != matran->getHang()) {
			for (auto i : ketqua) i.clear();
			ketqua.clear();
			return ketqua;
		}

		for (int i = 0; i < hangKQ; i++)
			for (int j = 0; j < cotKQ; j++)
				for (int k = 0; k < cot; k++)
					ketqua[i][j] += dulieu[i][k] * matran->getDuLieuO(k, j);

		return ketqua;
	}

	void setDulieu(std::vector<std::vector<int>> d) {
		dulieu = d;
	}
	std::vector<std::vector<int>> getDuLieu() {
		return dulieu;
	}
	int getDuLieuO(int i, int j) {
		return dulieu[i][j];
	}
	int getHang() {
		return hang;
	}
	int getCot() {
		return cot;
	}
};

void nhapMaTran(MaTran *matran) {
	int hang = matran->getHang();
	int cot = matran->getCot();
	std::vector<std::vector<int>> dulieu;
	std::cout << "\tNhap du lieu cho ma tran: \n";
	for (int i = 0; i < hang; i++) {
		std::vector<int> tmp(cot);
		std::cout << "Hang " << i + 1 << ": ";
		for (int j = 0; j < cot; j++) std::cin >> tmp[j];
		dulieu.push_back(tmp);
	}
	matran->setDulieu(dulieu);
}
void xuatMaTran(MaTran* matran) {
	int hang = matran->getHang();
	int cot = matran->getCot();
	std::vector<std::vector<int>> dulieu = matran->getDuLieu();
	std::cout << "\nXuat du lieu cho ma tran: \n";
	for (int i = 0; i < hang; i++) {
		for (int j = 0; j < cot; j++) {
			std::cout << dulieu[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	MaTran* matranA = new MaTran(2, 3);
	MaTran* matranB = new MaTran(3, 2);
	nhapMaTran(matranA);
	nhapMaTran(matranB);

	std::vector<std::vector<int>> ketqua = matranA->nhan(matranB);
	if (!ketqua.empty()) {
		std::cout << "Ket qua ma tran: " << std::endl;
		for (auto i : ketqua) {
			for (auto j : i)
				std::cout << j << " ";
			std::cout << std::endl;
		}
	}
	else {
		std::cout << "Khong the nhan ma tran" << std::endl;
	}

	return 0;
}