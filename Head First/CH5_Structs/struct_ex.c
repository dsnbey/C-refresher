#include <stdio.h>
#include <string.h>

// Define a struct named 'Person'
struct Person {
    char name[50];
    int age;
    float height;
};

// Function to print a person's details
void print_person(struct Person *p) {
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Height: %.2f\n", p->height);
}

// Function to change the fields of the person
void change_person(struct Person *p, char *name, int age, float height) {
    strncpy(p->name, name, sizeof(p->name)); // Be careful with buffer overflows
    p->name[sizeof(p->name) - 1] = '\0'; // Ensure null-termination
    p->age = age;
    p->height = height;
}

// Function to copy one person struct to another
void copy_person(struct Person *dest, const struct Person *src) {
    memcpy(dest, src, sizeof(struct Person));
}

int main() {
    // Create an instance of the struct
    struct Person john;
    change_person(&john, "John Doe", 25, 180.5);

    // Print person details using the function
    print_person(&john);

    // Change person's details
    change_person(&john, "John Smith", 30, 182.0);

    // Print person details again to check if they have changed
    print_person(&john);

    // Create another instance and copy the details of john to it
    struct Person john_clone;
    copy_person(&john_clone, &john);

    // Print clone's details to check if they match John's
    print_person(&john_clone);

    return 0;
}