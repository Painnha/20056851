#include<stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
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
Node *taonode(int x){
	Node *p;
 	p = (Node *)malloc(sizeof(Node));
	if(p==NULL){
		printf("cap phat khong thanh cong");
		return NULL;
	}else{
		p->data=x;
		p->next=NULL;
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
void nhapnode(List &l){
	int x;
	Node *p;
	khoitao(l);
	printf("nhap x:");

	while(true)
	{
		scanf("%d",&x);
		if(x==0)
		break;
		p=taonode(x);
		themdau(l,p);
	
	}
}
void xuatnode(List &l){
	Node *p;
	p=l.head;
	
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
}
float average(List l)
{
	Node *p;
	p=l.head;
	int sum=0;
	int quatity=0;
	while(p!=NULL)
	{
		sum=sum+p->data;
		quatity=quatity+1;
		p=p->next;
	}
	float average=(float) sum/quatity;
	return average;
}
float min(List l){
    if(l.head == NULL){
        printf("Danh sach rong.");
        return 0;
    }

    Node *p = l.head;
    int min_value = p->data; 

    while(p != NULL){
        if(p->data < min_value){
            min_value = p->data;
        }
        p = p->next;
    }

    return (float)min_value;
}
int timMax(List l){
    if(l.head == NULL){
        printf("Danh sach rong\n");
        return -1; // Tru?ng h?p danh sách r?ng
    }

    Node *p = l.head;
    int max = p->data; // Gi? s? node d?u tiên là max

    while(p != NULL){
        if(p->data > max){
            max = p->data; // C?p nh?t max n?u tìm th?y giá tr? l?n hon
        }
        p = p->next;
    }

    return max;
}
void daoNguoc(List l, List &l2){
    Node *p = l.head;
    while(p != NULL){
        Node *newNode = taonode(p->data); 
        themdau(l2, newNode);
        p = p->next;
    }
}
bool kiemTraDoiXung(List l1, List l2){
    Node *p1 = l1.head;
    Node *p2 = l2.head;

    while(p1 != NULL && p2 != NULL){
        if(p1->data != p2->data){
            return false; 
        }
        p1 = p1->next;
        p2 = p2->next;
    }

  
    if(p1 == NULL && p2 == NULL){
        return true;
    } else {
        return false;
    }
}
void xoaNode(List &l, int value){
    Node *current = l.head;
    Node *prev = NULL;
    Node *toDelete = NULL;

    while(current != NULL){
        if(current->data == value){
            toDelete = current;

            // N?u node c?n xóa là node d?u danh sách
            if(current == l.head){
                l.head = current->next;
            }
            // N?u node c?n xóa là node cu?i danh sách
            if(current == l.tail){
                l.tail = prev;
            }

            // C?p nh?t liên k?t gi?a các node
            if(prev != NULL){
                prev->next = current->next;
            }

            // Ti?n hành xóa node và gi?i phóng b? nh?
            current = current->next;
            free(toDelete);
        } else {
            prev = current;
            current = current->next;
        }
    }
}
void chiaChanLe(List l, List &chan, List &le){
    Node *p = l.head;

    // Kh?i t?o danh sách chan và le
    khoitao(chan);
    khoitao(le);

    while(p != NULL){
        if(p->data % 2 == 0){ // N?u s? là ch?n
            Node *newNode = taonode(p->data);
            themdau(chan, newNode); // Thêm vào danh sách chan
        } else { // N?u s? là l?
            Node *newNode = taonode(p->data);
            themdau(le, newNode); // Thêm vào danh sách le
        }
        p = p->next;
    }
}
void themSauNode(List &l, int value, int newValue){
    Node *p = l.head;

    while(p != NULL){
        if(p->data == value){
            Node *newNode = taonode(newValue);
            newNode->next = p->next;
            p->next = newNode;
            // N?u thêm vào node cu?i danh sách
            if(p == l.tail){
                l.tail = newNode;
            }
            return; // K?t thúc sau khi thêm node m?i
        }
        p = p->next;
    }

    // N?u không tìm th?y giá tr? value trong danh sách
    printf("Khong tim thay node co gia tri %d trong danh sach.\n", value);
}
void themTruocNode(List &l, int value, int newValue){
    Node *p = l.head;
    Node *prev = NULL;

    while(p != NULL){
        if(p->data == value){
            Node *newNode = taonode(newValue);
            
            // N?u node c?n thêm là node d?u danh sách
            if(prev == NULL){
                newNode->next = l.head;
                l.head = newNode;
            } else {
                newNode->next = prev->next;
                prev->next = newNode;
            }
            
            return; // K?t thúc sau khi thêm node m?i
        }
        prev = p;
        p = p->next;
    }

    // N?u không tìm th?y giá tr? value trong danh sách
    printf("Khong tim thay node co gia tri %d trong danh sach.\n", value);
}
int main()
{
	//dao nguoc
//List l1, l2;
//    nhapnode(l1);
//    khoitao(l2); 
//    daoNguoc(l1, l2); 
//    printf("Danh sach L1:\n");
//    xuatnode(l1);
//    printf("\nDanh sach L2 (dao nguoc):\n");
//    xuatnode(l2);
//    if(kiemTraDoiXung(l1, l2)){
//        printf("\nDanh sach doi xung.\n");
//    } else {
//        printf("\nDanh sach khong doi xung.\n");
//    }
List l;
    nhapnode(l);
    printf("Danh sach L ban dau:\n");
    xuatnode(l);
    
//xoa node
//    int value;
//    printf("\nNhap gia tri can xoa: ");
//    scanf("%d", &value);
//    xoaNode(l, value);
//    printf("\nDanh sach L sau khi xoa cac node co gia tri %d:\n", value);
//    xuatnode(l);
 
//tinh trung binh
//	float ave=average(l);
//	printf("%2f",ave);


// list chan le
// List l, chan, le;
//    nhapnode(l);
//    chiaChanLe(l, chan, le);
//
//    printf("Danh sach L ban dau:\n");
//    xuatnode(l);
//
//    printf("Danh sach L chua cac so chan:\n");
//    xuatnode(chan);
//
//    printf("Danh sach L chua cac so le:\n");
//    xuatnode(le);


// them node
// int value, newValue; 
//    printf("Nhap gia tri node can tim: ");
//    scanf("%d", &value);
//    printf("Nhap gia tri node moi can them: ");
//    scanf("%d", &newValue);
//
//    themSauNode(l, value, newValue);
//
//    printf("Danh sach L sau khi them node %d sau node co gia tri %d:\n", newValue, value);
//    xuatnode(l);


}
