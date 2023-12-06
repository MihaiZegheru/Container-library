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
#define CONTAINER_DEFINE(data_type) \
    typedef struct { \
        data_type *array; \
        size_t size; \
        size_t capacity; \
    } container_t;\
    \
    container_t container_new(size_t size); \
    void container_delete(container_t container); \
    \
    data_type container_get_element(size_t index, container_t container); \
    void container_set_element(size_t index, data_type value, container_t container); \
    \
    void container_resize(size_t size, container_t *container); \
    static size_t container_compute_required_capacity(container_t container); \
    \
    container_t container_new(size_t size) \
    { \
        container_t container; \
        container.capacity = 0; \
        container.size = size; \
        \
        container.capacity = container_compute_required_capacity(container); \
        container.array = CONTAINER_MALLOC(container.capacity * sizeof(data_type)); \
        \
        return container; \
    } \
    \
    void container_delete(container_t container) \
    { \
        CONTAINER_FREE(container.array); \
    } \
    \
    data_type container_get_element(size_t index, container_t container) \
    { \
        return container.array[index]; \
    } \
    void container_set_element(size_t index, data_type value, container_t container) \
    { \
        container.array[index] = value; \
    } \
    \
    void container_resize(size_t size, container_t *container) \
    { \
        container->size = size; \
        container->capacity = container_compute_required_capacity(*container); \
        container->array = CONTAINER_REALLOC(container->array, container->capacity * sizeof(data_type)); \
    } \
    \
    static size_t container_compute_required_capacity(container_t container) \
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
