#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* next;
    struct node* prev;
} node_t;

node_t* HEAD = NULL;
node_t* BACK = NULL;

/*node_t* make_node(int value, node_t* next, node_t* prev) {
    node_t* new = (node_t*) malloc(sizeof(node_t));
    new->value = value;
    new->next = next;
    new->prev = prev;
}*/

void add_back(node_t** list, int value) {
    if (*list == NULL) {
        node_t* new = (node_t*) malloc(sizeof(node_t));
        new->value = value;
        new->next = NULL;
        new->prev = NULL;
        HEAD = new;
        *list = HEAD;
    } else {
        node_t* node = HEAD;
        while (node->next != NULL) {
            node = node->next;
        }
        node_t* new = (node_t*) malloc(sizeof(node_t));
        new->value = value;
        new->next = NULL;
        new->prev = node;
        node->next = new;
        BACK = new;
    }
}

void print_list(node_t* list, int backwards) {
    if (backwards == 1) {
        for (node_t* node = BACK; node != NULL; node = node->prev) {
            printf("%d ", node->value);
        }
    } else {
        for (node_t* node = HEAD; node != NULL; node = node->next) {
            printf("%d ", node->value);
        }
    }
    printf("\n");
}

void remove_node(node_t** list, int value) {
    if (*list == NULL) {
        //do nothing
    } else if (HEAD->value == value) {
        node_t* nextnode = HEAD->next;
        free(HEAD);
        HEAD = nextnode;
        HEAD->prev = NULL;
    } else if (BACK->value == value) {
        node_t* prevnode = BACK->prev;
        free(BACK);
        BACK = prevnode;
        BACK->next = NULL;
    } else {
        node_t* node = HEAD;
        while (node->next->value != value) {
            node = node->next;
        } //found node before tobedeleted
        node_t* nextnode = node->next->next;
        free(node->next);
        node->next = nextnode;
        nextnode->prev = node;
        
    }
}

int main() {
    node_t* list = NULL;        // initially the tree is NULL

    // add_back(&list, 42);
    // add_back(&list, 13);
    // add_back(&list, 50);
    // add_back(&list, 15);
    // add_back(&list, 2);   

    // remove_node(&list, 2);   

    // remove_node(&list, 42);         

    print_list(list, 1);                // 50, 2
}