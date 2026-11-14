
#define CayAVL.h
#include <iostream>
#include "thuvien.h"
using namespace std;
struct AVLNode {
    int stt;
    int height;
    AVLNode* left;
    AVLNode* right;
};
AVLNode* khoiTaoAVL()

    {
        return NULL;
    }

int height(AVLNode* p)
{
    if (p == NULL)
        return 0;
    else
        return p->height;
}
int maxAVL(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
void capNhatChieuCao(AVLNode* p)
{
    p->height = 1 + maxAVL(height(p->left), height(p->right));
}

int heSoCanBang(AVLNode* p)
{
    if (p == NULL)
        return 0;
    else
        return height(p->left) - height(p->right);
}

int bookCompare(Sach ds[], int a, int b)
{
    if (ds[a].tieuDe > ds[b].tieuDe)
        return 1;
    if (ds[a].tieuDe < ds[b].tieuDe)
        return -1;
    if (ds[a].maSach > ds[b].maSach)
        return 1;
    if (ds[a].maSach < ds[b].maSach)
        return -1;
    return 0;
}
AVLNode* rightRotate (AVLNode* y)
{
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    capNhatChieuCao(y);
    capNhatChieuCao(x);
    return x;
}
AVLNode* leftRotate (AVLNode* x)
{
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    capNhatChieuCao(x);
    capNhatChieuCao(y);
    return y;
}
AVLNode* themSach(AVLNode* node, Sach ds[], int stt)
{
    if (node == NULL)
    {
        AVLNode* p = new AVLNode;
        p->stt = stt;
        p->height = 1;
        p->left = NULL;
        p->right = NULL;
        return p;
    }
    int kq = bookCompare(ds,stt, node->stt);
    if (kq < 0)
        node->left = themSach(node->left, ds, stt);
    else if (kq > 0)
        node->right = themSach(node->right, ds, stt);
    else
        return node;
    capNhatChieuCao(node);
    int balance = heSoCanBang(node);
    // Truong hop LL
    if (balance > 1 && bookCompare(ds, stt, node->left->stt) < 0)
        return rightRotate(node);
    // Truong hop RR
    if (balance < -1 && bookCompare(ds, stt, node->right->stt) > 0)
        return leftRotate(node);
    // Truong hop LR
    if (balance > 1 && bookCompare(ds, stt, node->left->stt) > 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    // Truong hop RL
    if (balance < -1 && bookCompare(ds, stt, node->right->stt) < 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
AVLNode* timNhoNhat(AVLNode* node)
{
    AVLNode* p = node;
    while (p != NULL && p->left != NULL)
        p = p->left;
    return p;
}
AVLNode* xoaSach(AVLNode* node, Sach ds[], int index)
{
    if (node == NULL)
        return NULL;
    int kq = bookCompare(ds, index, node->stt);
    if (kq < 0)
        node->left = xoaSach(node->left, ds, index);
    else if (kq > 0)
        node->right = xoaSach(node->right, ds, index);
    else
    {
        if (node->left == NULL || node->right == NULL)
        {
            AVLNode* temp = node->left ? node->left : node->right;
            if (temp == NULL)
            {
                temp = node;
                node = NULL;
            }
            else
                *node = *temp;
            delete temp;
        }
        else
        {
            AVLNode* temp = timNhoNhat(node->right);
            node->stt = temp->stt;
            node->right = xoaSach(node->right, ds, temp->stt);
        }
    }
    capNhatChieuCao(node);
    int balance = heSoCanBang(node);
    // Truong hop LL
    if (balance > 1 && heSoCanBang(node->left) >= 0)
        return rightRotate(node);
    // Truong hop LR
    if (balance > 1 && heSoCanBang(node->left) < 0)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < 1 && heSoCanBang(node->right) <= 0)
        return leftRotate(node);
    if (balance < 1 && heSoCanBang(node->right) > 0)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
int timTheoTen(AVLNode* node, Sach ds[], string ten)
{
    while (node != NULL)
    {
        int i = node->stt;
        if (ten == ds[i].tieuDe)
            return i;
        else if (ten < ds[i].tieuDe)
            node = node->left;
        else
            node = node->right;
    }
    return -1;
}
void duyetLNR(AVLNode* node, Sach ds[])
{
    if (node != NULL)
    {
        duyetLNR(node->left, ds);
        cout << ds[node->stt].tieuDe << endl;
        duyetLNR(node->right, ds);
    }
}
void clear(AVLNode* node)
{
    if (node == NULL)
        return;
    clear(node->left);
    clear(node->right);
    delete node;
}





