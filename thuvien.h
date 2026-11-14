#define thuvien.h
#include <iostream>
#include <string>
using namespace std;

struct Sach {
	string maSach;
	string tieuDe;
	string tacGia;
	string nhaXuatBan;
	int namPhatHanh;
	int soLuong;
	int conlai;
	int Priority;
	bool tonTai;

	Sach()
	{
		maSach = " ";
		nhaXuatBan = " ";
		tieuDe = " ";
		tacGia = " ";
		conlai = 0;
		namPhatHanh = 0;
		soLuong = 0;
		Priority = 0;
		tonTai = true;
	}
	Sach(string id, string nxb, string td, string tg, int cl, int year, int sl, int pr)
	{
		maSach = id;
		nhaXuatBan = nxb;
		tieuDe = td;
		tacGia = tg;
		conlai = cl;
		namPhatHanh = year;
		soLuong = sl;
		Priority = pr;
		tonTai = true;
	}
};