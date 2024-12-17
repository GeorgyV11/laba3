#ifndef LABA4_STACK_H
#define LABA4_STACK_H

typedef struct Stack{
    int data;
    struct Stack * link;
}Stack;

void add_element(Stack ** p, Stack ** top, int n);
void print_Stack(Stack * top);
void delete_Stack(Stack ** p, Stack ** top);
int pop(Stack **stack);
void insertionSortStack(Stack **stack);

#endif //LABA4_STACK_H
