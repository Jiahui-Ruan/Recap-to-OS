#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int val;
    struct node *next;
};

struct node *head = NULL;
struct node *curt = NULL;

struct node* create_list(int val) {
    printf("Creating list with headnode as %d\n", val);
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    if (NULL == ptr) {
        printf("\n Node creation failed. \n");
        return NULL;
    }

    ptr->val = val;
    ptr->next = NULL;

    head = curt = ptr;
    return ptr;
}

struct node* add_to_list(int val, bool add_to_end) {
    if (NULL == head) {
        return (create_list(val));
    }

    struct node *ptr = (struct node*)malloc(sizeof(struct node));

    if (NULL == ptr) {
        printf("\n Node creation failed. \n");
        return NULL;
    }

    ptr->val = val;
    ptr->next = NULL;

    if (add_to_end)
    {
        curt->next = ptr;
        curt = ptr;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }

    return ptr;
}

void print_list(void) {
    struct node *ptr = head;
    while (ptr != NULL) {
        printf("[%d]->", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

bool search_in_list(int val) {
    struct node *ptr = head;
    while (ptr != NULL) {
        if (ptr->val == val) {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

struct node* delete_from_list(int val) {
    struct node *dummy = (struct node*)malloc(sizeof(struct node));
    dummy->val = -1;
    dummy->next = head;
    struct node* ptr = dummy;

    while (ptr != NULL && ptr->next != NULL) {
        if (ptr->next->val != val) {
            ptr = ptr->next;
        } else {
            ptr->next = ptr->next->next;
            break;
        }
    }
    return dummy->next;
}

int main() {


    create_list(0);
    add_to_list(1, true);
    add_to_list(2, true);
    add_to_list(3, true);
    add_to_list(4, true);
    add_to_list(5, true);
    print_list();
    printf("[search2 in list is %s]\n", search_in_list(2) ? "true" : "false");
    printf("[search6 in list is %s]\n", search_in_list(6) ? "true" : "false");
    delete_from_list(2);
    print_list();
    printf("[search2 in list is %s]\n", search_in_list(2) ? "true" : "false");
    return 0;
}