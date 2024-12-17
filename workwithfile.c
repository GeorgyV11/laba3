#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#define MAX_LINE_LENGTH 1024

void print_last_two_lines(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening");
        return;
    }
    char *lines[2] = {NULL, NULL};
    char buffer[MAX_LINE_LENGTH];
    int line_count = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        free(lines[0]);
        lines[0] = lines[1];
        lines[1] = strdup(buffer);
        line_count++;
    }
    if (line_count >= 2) {
        printf("%s", lines[0]);
        printf("%s\n", lines[1]);
    } else if (line_count == 1) {
        printf("%s\n", lines[1]);
    } else {
        printf("empty file\n");
    }
    free(lines[0]);
    free(lines[1]);
    fclose(file);
}


void append_stack_rows_to_file(const char *filename, Stack *stack) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    while (stack != NULL) {
        fprintf(file, "%d ", stack->data);
        stack = stack->link;
    }
    fprintf(file, "\n");
    fclose(file);
}