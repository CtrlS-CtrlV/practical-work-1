#include <stdio.h>
#include "utils.h"

void greet(const char *name)
{
    printf("Вітаю, %s! Ласкаво просимо до системного програмування.\n", name);
}

int sum_range(int from, int to)
{
    int sum = 0;
    for (int i = from; i <= to; i++) {
        sum += i;
    }
    return sum;
}
