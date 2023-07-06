#include <stdio.h>

void increment_x_val(int x) {
    x = x + 1;
    printf("x is stored at %p\n", &x); // &x is address of x
}

void increment_x_ref(int * ref) { 
     *ref = *ref + 1;
     printf("x is stored at %p\n", ref); // &x is address of x
}

int main() {

    int x = 4; 

    printf("x value equals to %i\n", x);
    printf("x is stored at %p\n", &x); // &x is address of x

    // x is same -> pass by value, x copied into function stack

    increment_x_val(x);
    printf("x value equals to %i\n", x);

    // x changed -> reference of x is passed
    increment_x_ref(&x);
    printf("x value equals to %i\n", x);

    

    // pointer arithmetic

    puts("Pointer arithmetic test begins");

    int arr[] = {1,2,3};

    printf("1st order: %i drinks\n", arr[0]);
    printf("1st order: %i drinks\n", *arr); // array variable is a pointer to the first element

    printf("3rd order: %i drinks\n", arr[2]);
    printf("3rd order: %i drinks\n", *(arr + 2));

    return 0;

}