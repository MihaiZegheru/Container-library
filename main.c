#include <stdio.h>
#include "include/container.h"

CONTAINER_DEFINE(int)

int main(void) {
    container_t container = container_new(10);
    printf("%lld", container.capacity);
}
