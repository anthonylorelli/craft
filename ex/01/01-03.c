#include <stdio.h>
#include <string.h>

typedef struct {
    void* next;
    void* prev;
    char* str;
} ListNode;

ListNode* list_find(char* str, ListNode* list) {
    if (!list) {
        return NULL;
    }

    if (strcmp(str, list->str) == 0) {
        return list;
    }

    return list_find(str, list->next);
}

ListNode* list_insert(char* str, ListNode* list) {
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->str = str;
    node->prev = NULL;
    node->next = list;
    if (list) {
        list->prev = node;
    }
    return node;
}

ListNode* list_delete(char* str, ListNode* list) {
    if (!list) {
        return NULL;
    }

    if (strcmp(str, list->str) == 0) {
        ListNode* next = list->next;
        free(list);
        return next;
    }

    ListNode* next = list_delete(str, list->next);
    list->next = next;
    if (next) {
        next->prev = list;
    }
    return list;
}

void list_print(ListNode* list) {
    if (!list) {
        printf("NULL\n");
        return;
    }
    printf("%s->", list->str);
    list_print(list->next);
}

int main() {
    printf("Hello world!\n");
    ListNode* head = list_insert("foo", NULL);
    head = list_insert("bar", head);
    head = list_insert("baz", head);
    list_print(head);
    head = list_delete("bar", head);
    list_print(head);
    return 0;
}
