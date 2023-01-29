#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct node* treePointer;
typedef struct element {
    char word[11];
    int count;
} element;
typedef struct node {
    element data;
    treePointer leftChild, rightChild;
} node;



treePointer modifiedSearch(treePointer tree, char input[]) {
    while (tree) {
        if (strcmp(input, tree->data.word) == 0) { 
            tree->data.count++;
            return NULL;
            //binary search tree가 empty가 아니며 탐색하는 word가 이미 있으면 그것의 count를 1 증가시킨 후 NULL 반환
        }
        else if (strcmp(input, tree->data.word) == -1) {
            if (!(tree->leftChild)) {
                return tree;
            }
            tree = tree->leftChild;
        }
        else if (strcmp(input, tree->data.word) == 1) {
            if (!(tree->rightChild)) {
                return tree;
            }
            tree = tree->rightChild;
        }
        //binary search tree가 empty가 아니며 탐색하는 word가 아직 없으면 탐색 과정에서 가장 마지막에 도달했던(존재하는) 노드의 포인터를 반환
    }
    //binary search tree가 empty이면 NULL 반환
    return NULL;
}

void insert(treePointer* node, char input[]) {
    treePointer ptr, temp = modifiedSearch(*node, input);
    //만약 word가 binary search tree에 이미 있다면 호출된 modifiedSearch가 그것의 count를 1 증가시키고 돌아온다.
    //이 경우 if문의 조건은 교재 코드에서처럼 FALSE가 되게 하여 insert는 추가 작업 없이 종료되도록 한다.
    if (temp || !(*node)) {
        ptr = (treePointer)malloc(sizeof(*ptr));
        strcpy_s(ptr->data.word, sizeof(ptr->data.word), input);
        ptr->leftChild = ptr->rightChild = NULL;
        ptr->data.count = 1;
        //만약 word가 binary search tree에 아직 없는 처음 입력된 것이라면, binary search tree에 key = word and count = 1 인 노드를 삽입한다.
        if (*node) {
            if (strcmp(input, temp->data.word) == -1) {
                temp->leftChild = ptr;
            }
            else {
                temp->rightChild = ptr;
            }
        }
        else {
            *node = ptr;
        }
    }
}

void inorder(treePointer ptr) {
    /*중위 트리 순회*/
    if (ptr) {
        inorder(ptr->leftChild);
        printf(ptr->data.word);
        printf(":");
        printf("%d", ptr->data.count);
        printf("\t");
        inorder(ptr->rightChild);
    }
}
int main() {
    treePointer wordTree = NULL;
    while(1) {
        char word[11];
        printf("next word ? ");
        scanf("%s", word);
        if (strcmp(word,"END")==0) {
            break;
        }
        insert(&wordTree,word);
        inorder(wordTree);
        printf("\n");
    } 
}
