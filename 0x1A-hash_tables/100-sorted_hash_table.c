#include "hash_tables.h"

typedef struct shash_node {
    char *key;
    char *value;
    struct shash_node *prev;
    struct shash_node *next;
} shash_node_t;

typedef struct shash_table {
    unsigned long int size;
    shash_node_t **array;
    shash_node_t *shead;
    shash_node_t *stail;
} shash_table_t;

shash_table_t *shash_table_create(unsigned long int size) {
    shash_table_t *ht = malloc(sizeof(shash_table_t));
    if (ht == NULL) {
        return NULL;
    }
    ht->size = size;
    ht->array = calloc(size, sizeof(shash_node_t *));
    if (ht->array == NULL) {
        free(ht);
        return NULL;
    }
    ht->shead = NULL;
    ht->stail = NULL;
    return ht;
}

int shash_table_set(shash_table_t *ht, const char *key, const char *value) {
    unsigned long int index;
    shash_node_t *node;

    if (ht == NULL || key == NULL || value == NULL) {
        return 0;
    }

    index = hash_djb2((unsigned char *)key) % ht->size;
    node = ht->array[index];

    while (node != NULL && strcmp(node->key, key) != 0) {
        node = node->next;
    }

    if (node == NULL) {
        node = malloc(sizeof(shash_node_t));
        if (node == NULL) {
            return 0;
        }
        node->key = strdup(key);
        if (node->key == NULL) {
            free(node);
            return 0;
        }
        node->prev = NULL;
        node->next = NULL;
        if (ht->array[index] == NULL) {
            ht->array[index] = node;
        } else {
            node->next = ht->array[index];
            node->next->prev = node;
            ht->array[index] = node;
        }

        if (ht->shead == NULL) {
            ht->shead = node;
            ht->stail = node;
        } else {
            shash_node_t *curr = ht->shead;
            while (curr != NULL && strcmp(node->key, curr->key) >= 0) {
                curr = curr->next;
            }
            if (curr == NULL) {
                node->prev = ht->stail;
                ht->stail->next = node;
                ht->stail = node;
            } else if (curr == ht->shead) {
                node->next = ht->shead;
                ht->shead->prev = node;
                ht->shead = node;
            } else {
                node->prev = curr->prev;
                node->next = curr;
                curr->prev->next = node;
                curr->prev = node;
            }
        }
    } else {
        free(node->value);
    }

    node->value = strdup(value);
    if (node->value == NULL) {
        return 0;
    }

    return 1;
}

char *shash_table_get(const shash_table_t *ht, const char *key) {
    unsigned long int index;
    shash_node_t *node;

    if (ht == NULL || key == NULL) {
        return NULL;
    }

    index = hash_djb2((unsigned char *)key) % ht->size;
    node = ht->array[index];

    while (node != NULL && strcmp(node->key, key) != 0) {
        node = node->next;
    }

    if (node == NULL) {
        return NULL;
    } else {
        return node->value;
    }
}

void shash_table_print(const shash_table_t *ht) {
    shash_node_t *node;

    if (ht == NULL) {
        return;
    }

    for (node = ht->shead; node != NULL; node = node->next) {
        printf("%s:%s\n", node->key, node->value);
    }
}

void shash_table_print_rev(const shash_table_t *ht) {
    shash_node_t *node;

    if (ht == NULL) {
        return;
    }

    for (node = ht->stail; node != NULL; node = node->prev
