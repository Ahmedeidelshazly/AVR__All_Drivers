
#include <stdio.h>

void factor_list(int n) {
    printf("Factors of %d are: ", n);
    for (int i = 2; i <= n; ++i) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    int number = 12;
    factor_list(number);
    return 0;
}