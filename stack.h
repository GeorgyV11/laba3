#ifndef LABA4_STACK_H
#define LABA4_STACK_H

typedef struct Stack{
    int data;
    struct Stack * link;
}Stack;

void add_element(Stack **, Stack**, int);
void print_Stack(Stack*);
void delete_Stack(Stack**, Stack**, int* );
int pop(Stack **stack);
void insertionSortStack(Stack **stack);

#endif //LABA4_STACK_H
