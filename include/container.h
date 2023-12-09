#ifndef CONTAINER_H__
#define CONTAINER_H__

#ifndef CONTAINER_MALLOC
#include <stdlib.h>
#define CONTAINER_MALLOC malloc
#endif // CONTAINER_MALLOC

#ifndef CONTAINER_FREE
#include <stdlib.h>
#define CONTAINER_FREE free
#endif // CONTAINER_FREE

#ifndef CONTAINER_REALLOC
#include <stdlib.h>
#define CONTAINER_REALLOC realloc
#endif // CONTAINER_REALLOC

#ifndef CONTAINER_DEFINE
#include <stddef.h>
#define CONTAINER_DEFINE(dtype) \
    typedef struct { \
        dtype *array; \
        size_t size; \
        size_t capacity; \
    } container_##dtype##_t; \
    \
    container_##dtype##_t container_##dtype##_new(size_t size); \
    void container_##dtype##_delete(container_##dtype##_t container); \
    \
    dtype container_##dtype##_get_element(size_t index, \
            container_##dtype##_t container); \
    void container_##dtype##_set_element(size_t index, dtype value, \
            container_##dtype##_t container); \
    \
    void container_##dtype##_resize(size_t size, \
            container_##dtype##_t *container); \
    static size_t container_##dtype##_compute_required_capacity( \
            container_##dtype##_t container); \
    \
    container_##dtype##_t container_##dtype##_new(size_t size) \
    { \
        container_##dtype##_t container; \
        container.capacity = 0; \
        container.size = size; \
        \
        container.capacity = container_##dtype##_compute_required_capacity( \
                container); \
        container.array = CONTAINER_MALLOC(container.capacity * \
                sizeof(dtype)); \
        \
        return container; \
    } \
    \
    void container_##dtype##_delete(container_##dtype##_t container) \
    { \
        CONTAINER_FREE(container.array); \
    } \
    \
    dtype container_##dtype##_get_element(size_t index, \
            container_##dtype##_t container) \
    { \
        return container.array[index]; \
    } \
    void container_##dtype##_set_element(size_t index, dtype value, \
            container_##dtype##_t container) \
    { \
        container.array[index] = value; \
    } \
    \
    void container_##dtype##_resize(size_t size, \
            container_##dtype##_t *container) \
    { \
        container->size = size; \
        container->capacity = container_##dtype##_compute_required_capacity( \
                *container); \
        container->array = CONTAINER_REALLOC(container->array, \
                container->capacity * sizeof(dtype)); \
    } \
    \
    static size_t container_##dtype##_compute_required_capacity( \
            container_##dtype##_t container) \
    { \
        size_t upper_bound = 1; \
        \
        while (upper_bound <= container.size) { \
            upper_bound <<= 1; \
        } \
        \
        return upper_bound; \
    }
#endif // CONTAINER_DEFINE

#endif // CONTAINER_H__
