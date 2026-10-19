#include <stdio.h>
#include "utils.h"

int main(void)
{
    printf("=== Проект з кількома файлами ===\n");
    greet("Студент");
    printf("Сума 1..10 = %d\n", sum_range(1, 10));
    return 0;
}
