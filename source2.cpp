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
//        if(!laSoNguyenTo(p->data)){ // N?u không ph?i là s? nguyên t?
//            if(prev == NULL){ // N?u là node d?u danh sách
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
//    // C?p nh?t l.tail n?u danh sách r?ng
//    if(l.head == NULL){
//        l.tail = NULL;
//    }
//}
#include <stdio.h>
#include <stdlib.h> // Ð? s? d?ng malloc và free

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
    p = (Node *)malloc(sizeof(Node)); // S? d?ng malloc d? c?p phát b? nh? d?ng
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

// Hàm s?p x?p m?ng các giá tr? tang d?n
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

// Hàm t?o danh sách m?i t? m?ng dã s?p x?p
void taoDanhSachMoi(List &l, int arr[], int n){
    khoitao(l);
    for(int i = 0; i < n; ++i){
        Node *p = taonode(arr[i]);
        themdau(l, p);
    }
}

// Hàm th?c hi?n vi?c s?p x?p danh sách liên k?t và in ra màn hình
void sapXepVaXuat(List &l){
    int count = 0;
    Node *p = l.head;

    // Ð?m s? lu?ng node trong danh sách
    while(p != NULL){
        count++;
        p = p->next;
    }

    // T?o m?ng và sao chép d? li?u t? danh sách vào m?ng
    int *arr = (int *)malloc(count * sizeof(int));
    p = l.head;
    for(int i = 0; i < count; ++i){
        arr[i] = p->data;
        p = p->next;
    }

    // S?p x?p m?ng các giá tr?
    sapXepMang(arr, count);

    // T?o danh sách m?i t? m?ng dã s?p x?p
    taoDanhSachMoi(l, arr, count);

    // Hi?n th? danh sách m?i dã s?p x?p
    printf("Danh sach moi voi thu tu tang dan:\n");
    xuatnode(l);

    // Gi?i phóng b? nh?
    free(arr);
}

int main(){
    List l;
    nhapnode(l);
    printf("Danh sach L ban dau:\n");
    xuatnode(l);

    // G?i hàm d? s?p x?p và xu?t danh sách m?i
    sapXepVaXuat(l);

    return 0;
}

