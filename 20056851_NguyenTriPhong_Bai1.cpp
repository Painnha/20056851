#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

void init(Stack &s) {
    s.top = NULL;
}

bool isEmpty(Stack s) {
    return (s.top == NULL);
}

bool Push(Stack &s, int newItem) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "cap phat bo nho khong thanh cong\n");
        return false;
    }
    newNode->data = newItem;
    newNode->next = s.top;
    s.top = newNode;
    return true;
}

bool Pop(Stack &s, int &outItem) {
    if (isEmpty(s)) {
        return false;
    }
    Node *temp = s.top;
    outItem = temp->data; // L?y giá tr? c?a ph?n t? b? xóa
    s.top = temp->next;
    free(temp);
    return true;
}

bool Top(Stack s, int &outItem) {
    if (isEmpty(s)) {
        return false;
    }
    outItem = s.top->data;
    return true;
}

void nhapStack(Stack &s) {
    int newItem;
    printf("nhap so nguyen >0 (<= 0 se dung): ");
    scanf("%d", &newItem);
    while (newItem > 0) {
        Push(s, newItem);
        scanf("%d", &newItem);
    }
}
void copyStack(Stack &stackGoc, Stack &stackCopy) {
    // Kh?i t?o stackCopy
    init(stackCopy);

    Stack tempStack;
    init(tempStack);


    Node *current = stackGoc.top;
    while (current != NULL) {
        Push(tempStack, current->data); 
        current = current->next;
    }


    int tempItem;
    while (Pop(tempStack, tempItem)) {
        Push(stackCopy, tempItem);
    }
}

void xuatStack(Stack s){
	Node *newNode= s.top;
	while(newNode!=NULL)
	{
		printf("[%d] ",newNode->data);
		newNode=newNode->next;
	}
}


int main() {

    Stack stack1, stack2;
    int item;

    init(stack1);
    nhapStack(stack1);
    printf("Stack 1: ");
    xuatStack(stack1);
    copyStack(stack1,stack2);
    printf("\nStack 2: ");
    xuatStack(stack2);
  

//    printf("\nstack da nhap:");
//    xuatStack(stack);

    // In ra các ph?n t? dã b? xóa t? stack
//    printf("Cac phan tu da xoa tu stack:\n");
//    while (Pop(stack, item)) {
//        printf("%d\n", item);
//    }

    return 0;
}

