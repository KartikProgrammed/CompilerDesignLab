#include <stdio.h>

int main() {
    int a, b, c;

    // Testing write and read
    read("%d %d", &a, &b);
    c = a + b;
    write("The result is: %d\n", c);

    // Arithmetic expression example
    int x = 5;
    int y = 10;
    int result = x * y + (x - y);

    return 0;
}
