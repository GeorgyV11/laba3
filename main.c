#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "workwithfile.h"




int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("111>\n");
        return 1;
    }
    if (strcmp(argv[1], "--file") != 0) {
        printf("222 %s\n", argv[1]);
        return 1;
    }
    print_last_two_lines(argv[2]);
    Stack * stack = NULL, *p;
    int number;
    while(1) {
        if(scanf("%d",&number) == 1){
            add_element(&p,&stack,number);
        }
        if(getchar() == '\n') break;
    }
    print_Stack(stack);
    append_stack_rows_to_file("../data.txt",stack);
    insertionSortStack(&stack);
    append_stack_rows_to_file("../data.txt",stack);
    return 0;
}
