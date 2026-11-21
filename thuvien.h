#define thuvien.h
#include <iostream>
#include <string>
using namespace std;

struct Sach {
	string maSach;
	string tieuDe;
	string tacGia;
	string theLoai;
	string nhaXuatBan;
	int namPhatHanh;
	int soLuong;
	int Priority;
	bool tonTai;
};
void nhapSach(Sach &s) {

    cout << "\n========== NHAP THONG TIN SACH ==========\n";

    cout << "Nhap ma sach: ";
    cin>> s.maSach;

    cout << "\nNhap ten sach: ";
    cin>> s.tieuDe;

    cout << "\nNhap tac gia: ";
    cin>> s.tacGia;

	cout<<"\nNhap the loai: ";
	cin>>s.theLoai;

    cout << "\nNhap nha xuat ban: ";
    cin>> s.nhaXuatBan;

    cout << "\nNhap nam phat hanh: ";
    cin >> s.namPhatHanh;

    cout << "\nNhap so luong: ";
    cin >> s.soLuong;

	cout<<"\nNhap Priority: ";
	cin>>s.Priority;
	s.tonTai=true;
    cout << "\nThem thong tin sach thanh cong!\n";
}
void hienThi( const Sach& s){
	cout<< "\nMa Sach: "<<s.maSach;
	cout<<"\nTen Sach: "<<s.tieuDe;
	cout<<"\nTac Gia: "<<s.TacGia;
	cout<<"\nNha Xuat Ban: "<<s.nhaXuatBan;
	cout<<"\nNam Phat Hanh: "<<s.namPhatHanh;
	cout<<"\nSo Luong: "<<s.soLuong;
}
	
