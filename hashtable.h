#define hashtable.h
#define HASH_SIZE 101
#include "thuvien.h"
#include <string>
using namespace std;
struct hashNode {
	int stt;
	hashNode* next;
};
void khoiTaoHash(hashNode* bangBam[])
{
	for (int i = 0; i < HASH_SIZE; i++) {
		bangBam[i] = NULL;
	}
}
int hashFunction(string maSach) {
    unsigned long long tong = 0;

    for (int i = 0; i < maSach.length(); i++) {
        tong = (tong * 31 + (unsigned char)maSach[i])
            % HASH_SIZE;
    }

    return (int)tong;
}
int timHash(hashNode* bangBam[], Sach ds[], string maSach)
{
    int vt = hashFunction(maSach);
    hashNode* p = bangBam[vt];
    while (p != NULL)
    {
        int i = p->stt;
        if (if (ds[i].tonTai && ds[i].maSach == maSach))
            return i;
        p = p->next;
    }
    return -1;
}
bool themhash(hashNode* bangBam[], Sach ds[], int stt)
{
    if (timHash(bangBam, ds, ds[stt].maSach) != -1)
    {
        return false;
    }
    int vt = hashFunction(ds[stt].maSach);
    hashNode* p = new hashNode;
    p->stt = stt;
    p->next = bangBam[vt];
    bangBam[vt] = p;
    return true;

}
bool xoaHash(hashNode* bangBam[],Sach ds[],string maSach) {
    int vt = hashFunction(maSach);

    hashNode* p = bangBam[vt];
    hashNode* truoc = NULL;

    while (p != NULL) {
        int i = p->stt;

        if (ds[i].maSach == maSach) {

            if (truoc == NULL)
                bangBam[vt] = p->next;
            else
                truoc->next = p->next;

            delete p;

            return true;
        }

        truoc = p;
        p = p->next;
    }

    return false;
}
void hienThiHash(hashNode* bangBam[],Sach ds[]) {
    for (int i = 0; i < HASH_SIZE; i++) {

        cout << "\nVi tri " << i << ": ";

        hashNode* p = bangBam[i];

        while (p != NULL) {
            int j = p->stt;

            cout << ds[j].maSach<< " -> ";

            p = p->next;
        }

        cout << "NULL";
    }
}
void giaiPhongHash(hashNode* bangBam[]) {
    for (int i = 0; i < HASH_SIZE; i++) {

        hashNode* p = bangBam[i];

        while (p != NULL) {
            hashNode* temp = p;

            p = p->next;

            delete temp;
        }

        bangBam[i] = NULL;
    }
}
