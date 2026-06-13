#include <stdio.h>

int main() {
    int i = 2;
    do {
        printf("%d\n", i);
        i += 2;
    } while (i <= 100);

    return 0;
}
