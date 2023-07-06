#include <stdio.h>
#include <stdarg.h>

void sumint(int args, ...) {
    va_list ap;
    va_start(ap, args);
    int sum = 0;
    for (int i = 0; i < args; i++) {
        sum = sum + va_arg(ap, int);
        printf("%i\n", sum);
    }
    printf("sum: %i\n", sum);

}

int main() {
    sumint(5, 2, 4, 5, 3, 9); 
    return 0;
}