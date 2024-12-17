#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void add_element(Stack**p, Stack** top, int n){
    *p = (Stack*)malloc(sizeof(Stack));
    (*p)->data = n;
    (*p)->link = *top;
    *top = *p;
}

void print_Stack(Stack* top){
    Stack* tmp = top;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->link;
    }
    printf("\n");
}

void delete_Stack(Stack** p, Stack** top){
    while(top != NULL){
        *p = *top;
        (*top) = (*p)->link;
        free((*p));
    }
}

int pop(Stack **stack) {
    if ((*stack) == NULL) {
        printf("Стек пуст!\n");
        return -1; // Возвращаем -1 как ошибку
    }
    Stack *temp = *stack;
    int value = temp->data;
    *stack = temp->link;
    free(temp);
    return value;
}

void insertionSortStack(Stack **stack) {
    Stack *sortedStack = NULL;
    while ((*stack) != NULL) {
        int value = pop(stack);
        Stack *current = sortedStack;
        Stack *prev = NULL;
        while (current != NULL && current->data < value) {
            prev = current;
            current = current->link;
        }
        Stack *newElem = (Stack *)malloc(sizeof(Stack));
        if (newElem == NULL) {
            printf("Memory allocation error\n");
            return;
        }
        newElem->data = value;
        newElem->link = current;
        if (prev == NULL) {
            sortedStack = newElem;
        } else {
            prev->link = newElem;
        }
    }
    *stack = sortedStack;
}

