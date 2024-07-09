//bool laSoNguyenTo(int n){
//    if(n <= 1){
//        return false;
//    }
//    for(int i = 2; i*i <= n; ++i){
//        if(n % i == 0){
//            return false;
//        }
//    }
//    return true;
//}
//
//void locSoNguyenTo(List &l){
//    Node *p = l.head;
//    Node *prev = NULL;
//
//    while(p != NULL){
//        if(!laSoNguyenTo(p->data)){ // N?u kh�ng ph?i l� s? nguy�n t?
//            if(prev == NULL){ // N?u l� node d?u danh s�ch
//                l.head = p->next;
//                free(p);
//                p = l.head;
//            } else {
//                prev->next = p->next;
//                free(p);
//                p = prev->next;
//            }
//        } else {
//            prev = p;
//            p = p->next;
//        }
//    }
//
//    // C?p nh?t l.tail n?u danh s�ch r?ng
//    if(l.head == NULL){
//        l.tail = NULL;
//    }
//}
#include <stdio.h>
#include <stdlib.h> // �? s? d?ng malloc v� free

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
    p = (Node *)malloc(sizeof(Node)); // S? d?ng malloc d? c?p ph�t b? nh? d?ng
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
    printf("Nhap cac so nguyen (nhap 0 de ket thuc):\n");

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
    printf("\n");
}

// H�m s?p x?p m?ng c�c gi� tr? tang d?n
void sapXepMang(int arr[], int n){
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// H�m t?o danh s�ch m?i t? m?ng d� s?p x?p
void taoDanhSachMoi(List &l, int arr[], int n){
    khoitao(l);
    for(int i = 0; i < n; ++i){
        Node *p = taonode(arr[i]);
        themdau(l, p);
    }
}

// H�m th?c hi?n vi?c s?p x?p danh s�ch li�n k?t v� in ra m�n h�nh
void sapXepVaXuat(List &l){
    int count = 0;
    Node *p = l.head;

    // �?m s? lu?ng node trong danh s�ch
    while(p != NULL){
        count++;
        p = p->next;
    }

    // T?o m?ng v� sao ch�p d? li?u t? danh s�ch v�o m?ng
    int *arr = (int *)malloc(count * sizeof(int));
    p = l.head;
    for(int i = 0; i < count; ++i){
        arr[i] = p->data;
        p = p->next;
    }

    // S?p x?p m?ng c�c gi� tr?
    sapXepMang(arr, count);

    // T?o danh s�ch m?i t? m?ng d� s?p x?p
    taoDanhSachMoi(l, arr, count);

    // Hi?n th? danh s�ch m?i d� s?p x?p
    printf("Danh sach moi voi thu tu tang dan:\n");
    xuatnode(l);

    // Gi?i ph�ng b? nh?
    free(arr);
}

int main(){
    List l;
    nhapnode(l);
    printf("Danh sach L ban dau:\n");
    xuatnode(l);

    // G?i h�m d? s?p x?p v� xu?t danh s�ch m?i
    sapXepVaXuat(l);

    return 0;
}

