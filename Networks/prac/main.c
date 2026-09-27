#include <stdio.h>
#include <string.h>
#include <malloc.h>


double parseDouble(char *s) {
    int minus = 0;
    double number = 0;
    if (s[0] == '-')
        minus = 1;
    int n = strlen(s);
    int i = minus;
    for (; i < n; i++) {
        if (s[i] == '.')
            break;
        number *= 10;
        number += (int) (s[i] - '0');
    }
    double rem = 0;
    if (i != n) {
        i++;
        int size = 0;
        for (; i < n; i++) {
            size++;
            rem *= 10;
            rem += (int) (s[i] - '0');
        }
        for (int i = 0; i < size; i++) {
            rem /= 10;
        }
    }
    number += rem;
    if (minus == 1)
        return number * -1;
    return number;
}


void printArray(int *a, int N) {
    for (int i = 0; i < N; i++)
        printf("%d\t", a[i]);
    printf("\n");
}

void f(int *a, int *b, int *n) {
    int *p1 = a, *p2 = b;
    for (int i = 1; i <= *n; i++) {
        int t = *p1;
        *p1 = *p2;
        *p2 = t;
        p1++;
        p2++;
    }
    *n = *(p1 - 1);
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int b[] = {10, 11, 12, 13, 14, 15};
    int n = 3;
    f(a+1,b+2,&n);
    printArray(a,6);
    printArray(b,6);
    printf("%d\n",n);
    return 0;
}
