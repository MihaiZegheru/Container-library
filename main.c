#include <stdio.h>
#include "include/container.h"

CONTAINER_DEFINE(int)

int main(void) {
    container_int_t container = container_int_new(10);
    printf("%lld", container.capacity);
    container_int_delete(container);
}
