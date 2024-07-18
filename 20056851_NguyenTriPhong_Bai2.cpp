#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int num;
} Queue;


void Init(Queue &q) {
    q.front = NULL;
    q.rear = NULL;
    q.num = 0;
}


bool IsEmpty(Queue q) {
    return (q.num == 0);
}


bool EnQueue(Queue &q, int newItem) {
    if (q.num == MAX) {
        return false;
    }

    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "cap phat bo nho khong thanh cong\n");
        return false;
    }
    newNode->data = newItem;
    newNode->next = NULL;

    if (q.num == 0) {
        q.front = q.rear = newNode;
    } else {
        q.rear->next = newNode;
        q.rear = newNode;
    }

    q.num++;
    return true;
}


bool DeQueue(Queue &q, int &itemOut) {
    if (IsEmpty(q)) {
        return false;
    }

    Node *temp = q.front;
    itemOut = temp->data;

    if (q.front == q.rear) {
        q.front = q.rear = NULL;
    } else {
        q.front = q.front->next;
    }

    free(temp);
    q.num--;
    return true;
}


bool Front(Queue q, int &itemOut) {
    if (IsEmpty(q)) {
        return false;
    }

    itemOut = q.front->data;
    return true;
}


bool Rear(Queue q, int &itemOut) {
    if (IsEmpty(q)) {
        return false;
    }

    itemOut = q.rear->data;
    return true;
}


void nhapQueue(Queue &q) {
    int newItem;
    printf("Nhap cac gia tri vao Queue (nhap <= 0 de ket thuc):\n");
    do {
        scanf("%d", &newItem);
        if (newItem > 0) {
            EnQueue(q, newItem);
        }
    } while (newItem > 0);
}


void layVaXuat5PhanTuDau(Queue &q) {
    int item;
    printf("5 gia tri dau tien cua Queue:\n");
    for (int i = 0; i < 5; ++i) {
        if (DeQueue(q, item)) {
            printf("%d ", item);
        } else {
            break;
        }
    }
    printf("\n");
}

int main() {
    Queue queue;
    Init(queue);


    nhapQueue(queue);


    layVaXuat5PhanTuDau(queue);


    int frontItem, rearItem;
    if (Front(queue, frontItem)) {
        printf("Gia tri dau cua Queue: %d\n", frontItem);
    } else {
        printf("Queue rong.\n");
    }

    if (Rear(queue, rearItem)) {
        printf("Gia tri cuoi cua Queue: %d\n", rearItem);
    } else {
        printf("Queue rong.\n");
    }

    return 0;
}

