#include<stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
	char maSanpham[8];
	char tenSanpham[30];
	double donGia;
	char xuatXu[20];
	struct Node *next;
};
struct List
{
	Node *head;
	Node *tail;
};
void khoitao(List &l){
	l.head=NULL;
	l.tail=NULL;
}

Node *taoSanpham(char maSanpham[],char tenSanpham[],double donGia,char xuatXu[]){
	Node *p;
 	p = (Node *)malloc(sizeof(Node));
	if(p==NULL){
		printf("cap phat khong thanh cong");
		return NULL;
	}else{
	 strcpy(p->maSanpham, maSanpham);
        strcpy(p->tenSanpham, tenSanpham);
        p->donGia = donGia;
        strcpy(p->xuatXu, xuatXu);
        p->next = NULL;
		return p;
	}
}
void themdau(List &l,Node *p){
	if(l.head==NULL)
	{
		l.head=l.tail=p;
	}else
	{
		p->next=l.head;
		l.head=p;
	}
}
void nhapnode(List &l) {
    Node *node;
    khoitao(l);

    int x=1;
    int n;
        printf("Nhap so luong san pham: ");
        scanf("%d", &n);
    do {
 
        node = (Node *)malloc(sizeof(Node));
        if (node == NULL) {
            printf("Cap phat bo nho khong thanh cong!\n");
            return;
        }

        // Input data for the new node
        printf("Nhap ma san pham: ");
        scanf("%s", node->maSanpham);
        printf("Nhap ten san pham: ");
        scanf(" %[^\n]", node->tenSanpham);
        printf("Nhap don gia: ");
        scanf("%lf", &node->donGia);
        printf("Nhap xuat xu: ");
        scanf(" %[^\n]", node->xuatXu);

        node->next = NULL;


        themdau(l, node);
		x++;

    } while (x <= n);
}

void xuatDanhSach(List &l) {
    Node *current = l.head;

    printf("\nDanh sach san pham:\n");
    printf("\nMa hang	|Ten hang	|Don gia	|Xuat xu ");
    while (current != NULL) {
    printf("\n%s	|%s		|%.2lf		|%s", current->maSanpham,current->tenSanpham,current->donGia,current->xuatXu);
    printf("\n	------------------------------		\n");
	current = current->next; 
    }
}
double tinhGiaTriTrungBinh(List &l) {
    Node *current = l.head;
    double tongGia = 0.0;
    int count = 0;

    while (current != NULL) {
        tongGia += current->donGia;
        count++;
        current = current->next;
    }

    if (count > 0) {
        return tongGia / count;
    } else {
        return 0.0; 
    }
}
Node* timMatHangGiaCaoNhat(List &l) {
    if (l.head == NULL) {
        return NULL;
    }

    Node *current = l.head;
    Node *nodeGiaCaoNhat = l.head; 

    while (current != NULL) {
        if (current->donGia > nodeGiaCaoNhat->donGia) {
            nodeGiaCaoNhat = current; 
        }
        current = current->next;
    }

    return nodeGiaCaoNhat;
}
void xuatSpgiacaonhat(List &l){
	Node *nodeGiaCaoNhat = timMatHangGiaCaoNhat(l);
	if (nodeGiaCaoNhat != NULL) {
        printf("\nMat hang co gia cao nhat:\n");
        printf("Ma san pham: %s\n", nodeGiaCaoNhat->maSanpham);
        printf("Ten san pham: %s\n", nodeGiaCaoNhat->tenSanpham);
        printf("Don gia: %.2lf\n", nodeGiaCaoNhat->donGia);
        printf("Xuat xu: %s\n", nodeGiaCaoNhat->xuatXu);
    } else {
        printf("\nDanh sach san pham rong.\n");
    }
	}


int soSanhTen(Node *a, Node *b) {
    return strcmp(a->tenSanpham, b->tenSanpham);
}


void sapXepTheoTen(List &l) {
    Node *p, *q, *prev_p;

    if (l.head == NULL) return;

    p = l.head->next;
    l.head->next = NULL;

    while (p != NULL) {
        prev_p = NULL;
        q = l.head;

        while (q != NULL && soSanhTen(q, p) < 0) {
            prev_p = q;
            q = q->next;
        }

        if (prev_p == NULL) {
            l.head = p;
        } else {
            prev_p->next = p;
        }

        Node *next_p = p->next;
        p->next = q;
        p = next_p;
    }
}


List taoDanhSachL2(List &l1) {
    List l2;
    khoitao(l2);

    Node *current = l1.head;
    while (current != NULL) {
        if (strcmp(current->xuatXu, "Viet Nam") == 0) {
            Node *node = taoSanpham(current->maSanpham, current->tenSanpham, current->donGia, current->xuatXu);
            themdau(l2, node);
        }
        current = current->next;
    }

    sapXepTheoTen(l2);

    return l2;
}

int main()
{

	List l,l2;
    nhapnode(l);
    printf("Danh sach L ban dau:\n");
    xuatDanhSach(l);
    double giaTriTrungBinh = tinhGiaTriTrungBinh(l);
    printf("\n\nGia tri trung binh cua cac san pham: %.2lf\n\n", giaTriTrungBinh);
    xuatSpgiacaonhat(l);
    l2=taoDanhSachL2(l);
    xuatDanhSach(l2);
    
    



}
