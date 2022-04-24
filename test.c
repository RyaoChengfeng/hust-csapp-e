#include <stdio.h>
#include <string.h>

char *f() {
    char tmp[20];
    strcpy(tmp, "hello");
    return tmp;
}

int main() {
    char *p;
    p = f();
    printf("%s\n", p);
    return 0;
}

