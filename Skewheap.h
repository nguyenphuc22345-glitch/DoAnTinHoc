#define Skewheap_h
#include <iostream>
#include "thuvien.h"
using namespace std;
struct SkewNode {
	int stt;
	SkewNode* left;
	SkewNode* right;
};
SkewNode* khoiTaoSkewheap()
{
	return NULL;
}
bool uuTienHeap(Sach ds[], int a, int b)
{
	if (ds[a].Priority != ds[b].Priority)
		return ds[a].Priority > ds[b].Priority;

	return a < b;
}
SkewNode* merge(SkewNode* a, SkewNode* b, Sach ds[])
{
	if (a == NULL)
		return b;

	if (b == NULL)
		return a;
	if (!uuTienHeap(ds, a->stt, b->stt)) {
		SkewNode* temp = a;
		a = b;
		b = temp;
	}
	a->right = merge(a->right, b, ds);
	SkewNode* temp = a->left;
	a->left = a->right;
	a->right = temp;

	return a;

}
SkewNode* themSkewheap(SkewNode* h, Sach ds[], int stt)
{
	SkewNode* p = new SkewNode;

	p->stt = stt;
	p->left = NULL;
	p->right = NULL;

	return merge(h, p, ds);
}
int xemUuTienHeap(SkewNode* root) {
	if (root == NULL)
		return -1;

	return root->stt;
}
int xoaUuTienSach(SkewNode* h, Sach ds[])
{
	if (h == NULL)
		return -1;
	int stt = h->stt;
	SkewNode* leftTree = h->left;
	SkewNode* rightTree = h->right;
	delete h;
	h = merge(leftTree, rightTree, ds);
	return stt;
}
void duyetSkewHeap(SkewNode* root,Sach ds[]
) {
	if (root == NULL)
		return;

	int i = root->stt;
	if (ds[i].tonTai) hienThi(ds[i]);
	duyetSkewHeap(root->left, ds);
	duyetSkewHeap(root->right, ds);
}

void clearSH(SkewNode* h)
{
	if (h == NULL)
		return;

	clear(h->left);
	clear(h->right);

	delete h;
}

SkewNode* taoLaiSkewHeap(Sach ds[],int n) {
	SkewNode* root = khoiTaoSkewheap();

	for (int i = 0; i < n; i++) {
		root = themSkewheap(root, ds, i);
	}
	return root;
}

