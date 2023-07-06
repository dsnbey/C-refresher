#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island {
    char *name;
    char *opens;
    char *closes;
    struct island *next;
} island;

island* create(char *name) {
    island *i = malloc(sizeof(island));
    i->name = strdup(name); // copies string
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

void display (island *start) {
    island *i = start;

    for (; i != NULL; i = i->next) {
        printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
    }
}

void release(island *start) {
    island *i = start;
    island *next = NULL;
    for (; i != NULL; i = next) {
        next = i->next;
        free(i->name);
        free(i);

    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    island *start = NULL;
    island *i = NULL;
    island *next = NULL;
    char name[80];

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", argv[1]);
        return 1;
    }

    while (fgets(name, 80, file) != NULL) {
        // Remove newline character from the end of the name
        name[strcspn(name, "\n")] = '\0';

        next = create(name);
        if (start == NULL) {
            start = next;
        }
        if (i != NULL) {
            i->next = next;
        }
        i = next;
    }

    fclose(file);

    display(start);
    release(start);

    return 0;
}