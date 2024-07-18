#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *pLeft, *pRight;
} Node, *TREE;

int InsertNode(TREE &t, int x) {
    if (t == NULL) {
        t = (TREE)malloc(sizeof(Node));
        if (t == NULL)
            return -1; 
        t->data = x;
        t->pLeft = t->pRight = NULL;
        return 1; 
    } else {
        if (x < t->data)
            return InsertNode(t->pLeft, x);
        else if (x > t->data)
            return InsertNode(t->pRight, x);
        else
            return 0; 
    }
}


Node* searchNode(TREE t, int x) {
    if (t == NULL || t->data == x)
        return t;
    
    if (x < t->data)
        return searchNode(t->pLeft, x);
    else
        return searchNode(t->pRight, x);
}


Node* findMaxNode(TREE t) {
    if (t == NULL || t->pRight == NULL)
        return t;
    return findMaxNode(t->pRight);
}


Node* findMinNode(TREE t) {
    if (t == NULL || t->pLeft == NULL)
        return t;
    return findMinNode(t->pLeft);
}

Node* findMinRightNode(TREE t) {
    if (t == NULL)
        return NULL;
    return findMinNode(t->pRight);
}


Node* findMaxLeftNode(TREE t) {
    if (t == NULL)
        return NULL;
    return findMaxNode(t->pLeft);
}


void NLR(TREE t) {
    if (t != NULL) {
        printf("%d ", t->data);
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}


void LNR(TREE t) {
    if (t != NULL) {
        LNR(t->pLeft);
        printf("%d ", t->data);
        LNR(t->pRight);
    }
}


void printEvenNodes(TREE t) {
    if (t != NULL) {
        printEvenNodes(t->pLeft);
        if (t->data % 2 == 0)
            printf("%d ", t->data);
        printEvenNodes(t->pRight);
    }
}


int countNodes(TREE t) {
    if (t == NULL)
        return 0;
    return 1 + countNodes(t->pLeft) + countNodes(t->pRight);
}


int height(TREE t) {
    if (t == NULL)
        return -1; 
    int leftHeight = height(t->pLeft);
    int rightHeight = height(t->pRight);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}


int countLeafNodes(TREE t) {
    if (t == NULL)
        return 0;
    if (t->pLeft == NULL && t->pRight == NULL)
        return 1;
    return countLeafNodes(t->pLeft) + countLeafNodes(t->pRight);
}


int countSingleChildNodes(TREE t) {
    if (t == NULL)
        return 0;
    if ((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL))
        return 1 + countSingleChildNodes(t->pLeft) + countSingleChildNodes(t->pRight);
    else
        return countSingleChildNodes(t->pLeft) + countSingleChildNodes(t->pRight);
}


int countNodesWithRightChildOnly(TREE t) {
    if (t == NULL)
        return 0;
    if (t->pLeft == NULL && t->pRight != NULL)
        return 1 + countNodesWithRightChildOnly(t->pLeft) + countNodesWithRightChildOnly(t->pRight);
    else
        return countNodesWithRightChildOnly(t->pLeft) + countNodesWithRightChildOnly(t->pRight);
}


int countNodesWithLeftChildOnly(TREE t) {
    if (t == NULL)
        return 0;
    if (t->pLeft != NULL && t->pRight == NULL)
        return 1 + countNodesWithLeftChildOnly(t->pLeft) + countNodesWithLeftChildOnly(t->pRight);
    else
        return countNodesWithLeftChildOnly(t->pLeft) + countNodesWithLeftChildOnly(t->pRight);
}


int countNodesWithTwoChildren(TREE t) {
    if (t == NULL)
        return 0;
    if (t->pLeft != NULL && t->pRight != NULL)
        return 1 + countNodesWithTwoChildren(t->pLeft) + countNodesWithTwoChildren(t->pRight);
    else
        return countNodesWithTwoChildren(t->pLeft) + countNodesWithTwoChildren(t->pRight);
}


void printNodesAtLevel(TREE t, int level) {
    if (t == NULL)
        return;
    if (level == 0)
        printf("%d ", t->data);
    else {
        printNodesAtLevel(t->pLeft, level - 1);
        printNodesAtLevel(t->pRight, level - 1);
    }
}


void printNodesByLevel(TREE t) {
    int h = height(t);
    for (int i = 0; i <= h; ++i) {
        printf("Level %d: ", i);
        printNodesAtLevel(t, i);
        printf("\n");
    }
}


int pathLengthToNode(TREE t, int x) {
    if (t == NULL)
        return -1; 
    if (t->data == x)
        return 0;
    if (x < t->data) {
        int leftPathLength = pathLengthToNode(t->pLeft, x);
        if (leftPathLength >= 0)
            return 1 + leftPathLength;
    } else {
        int rightPathLength = pathLengthToNode(t->pRight, x);
        if (rightPathLength >= 0)
            return 1 + rightPathLength;
    }
    return -1; 
}


int main() {
    TREE root = NULL;
    InsertNode(root, 50);
    InsertNode(root, 30);
    InsertNode(root, 20);
    InsertNode(root, 40);
    InsertNode(root, 70);
    InsertNode(root, 60);
    InsertNode(root, 80);

    printf("Duyet cay theo NLR (Preorder traversal): ");
    NLR(root);
    printf("\n");

    printf("Duyet cay theo LNR (Inorder traversal): ");
    LNR(root);
    printf("\n");

    printf("Cac node co gia tri chan: ");
    printEvenNodes(root);
    printf("\n");

	printf("Cac node co gia tri lon nhat %d ",findMaxNode(root)->data);
   
    printf("\n");
    printf("Cac node co gia tri nho nhat %d ",findMinNode(root)->data);
        printf("\n");

	printf("Cac node co gia tri nho nhat ben phai %d ",findMinRightNode(root)->data);
   
    printf("\n");
    printf("Cac node co gia tri lon nhat ben trai %d ",findMaxLeftNode(root)->data);
    printf("So node cua cay: %d\n", countNodes(root));
    printf("Do cao cua cay: %d\n", height(root));
    printf("So node la (node bac 0): %d\n", countLeafNodes(root));

    printf("So node co 1 cay con (node bac 1): %d\n", countSingleChildNodes(root));

    printf("So node chi co 1 cay con phai: %d\n", countNodesWithRightChildOnly(root));

    printf("So node chi co 1 cay con trai: %d\n", countNodesWithLeftChildOnly(root));

    printf("So node co 2 cay con (node bac 2): %d\n", countNodesWithTwoChildren(root));

    printf("In cac node tren tung muc cua cay:\n");
    printNodesByLevel(root);

    int x = 60;
    printf("Do dai duong di tu goc den node %d: %d\n", x, pathLengthToNode(root, x));

    return 0;
}

