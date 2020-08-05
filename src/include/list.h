/*
 * This is free and unencumbered software released into the public domain.
 *
 * Anyone is free to copy, modify, publish, use, compile, sell, or
 * distribute this software, either in source code form or as a compiled
 * binary, for any purpose, commercial or non-commercial, and by any
 * means.
 *
 * In jurisdictions that recognize copyright laws, the author or authors
 * of this software dedicate any and all copyright interest in the
 * software to the public domain. We make this dedication for the benefit
 * of the public at large and to the detriment of our heirs and
 * successors. We intend this dedication to be an overt act of
 * relinquishment in perpetuity of all present and future rights to this
 * software under copyright law.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 *
 * For more information, please refer to <https://unlicense.org>
 */

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

#include "node.h"

typedef struct Cell Cell;

typedef struct List {
    Tag tag;
    int length;
    Cell *head;
    Cell *tail;
} List;

struct Cell {
    Tag tag;
    void *data;
    Cell *next;
};

static inline Cell *list_head(const List *l) {
        return l ? l->head : NULL;
}

static inline Cell *list_tail(List *l) {
        return l ? l->tail : NULL;
}

static inline int list_length(const List *l) {
        return l ? l->length : 0;
}

#define next(lc)        ((lc)->next)
#define payload(lc)     ((lc)->data)
#define first(l)        payload(list_head(l))
#define last(l)         payload(list_tail(l))

#define foreach(c, l)        \
        for ((c) = list_head(l); (c) != NULL; (c) = lnext(c))

static List *new_list(void) {
    List *new_list;

    new_list = (List *) malloc(sizeof(*new_list));
    new_list->tag = T_List;
    new_list->length = 0;
    new_list->head = NULL;
    new_list->tail = NULL;

    return new_list;
}

static List *prepend(void *data, List *list) {
    Cell *head;

    if (!list)
        list = new_list();

    head = (Cell *) malloc(sizeof(*head));
    head->tag = T_Cell;
    head->next = list->head;
    head->data = data;

    if (!list->head)
        list->tail = head;

    list->head = head;
    list->length++;

    return list;
}

static List *append(List *list, void *data) {
    Cell *tail;

    if (!list)
        list = new_list();

    tail = (Cell *) malloc(sizeof(*tail));
    tail->tag = T_Cell;
    tail->next = NULL;
    tail->data = data;

    list->tail->next = tail;
    list->tail = tail;
    list->length++;

    if (!list->tail)
        list->head = tail;

    return list;
}


#endif
