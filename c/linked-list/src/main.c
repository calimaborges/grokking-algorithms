#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 100

struct Node {
  int data;
  struct Node *next;
};

struct Node *linked_list_node_create(int data) {
  struct Node *node = malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void linked_list_append(struct Node *append_to, struct Node *new_node) {
  struct Node *temp = append_to->next;
  append_to->next = new_node;
  new_node->next = temp;
}

struct Node *linked_list_find_first(struct Node *head, int data) {
  for (struct Node *current = head; current != NULL; current = current->next) {
    if (current->data == data) {
      return current;
    }
  }
  return NULL;
}

void linked_list_print(struct Node *head) {
  for (struct Node *current = head; current != NULL; current = current->next) {
    printf("%d\n", current->data);
  }
}

void linked_list_remove(struct Node *head, struct Node *node_to_remove) {
  for (struct Node *current = head; current != NULL; current = current->next) {
    if (current->next == node_to_remove) {
      current->next = node_to_remove->next;
      free(node_to_remove);
    }
  }
}

// TODO: debug memory for this
// TODO: look for C memory profiler
void linked_list_destroy(struct Node *head) {
  if (head->next != NULL) {
    linked_list_destroy(head->next);
  }
  free(head);
}

int main(int argc, char *argv[]) {
  struct Node *head = NULL;
  struct Node *current = NULL;

  for (int i = 0; i < 100; ++i) {
    struct Node *new = linked_list_node_create(i);
    if (head == NULL) {
      head = new;
    }
    if (current == NULL) {
      current = new;
    } else {
      current->next = new;
      current = new;
    }
  }

  current = linked_list_find_first(head, 45);
  struct Node *new = linked_list_node_create(100);
  linked_list_append(current, new);
  linked_list_print(head);
  linked_list_remove(head, new);
  linked_list_print(head);
  linked_list_destroy(head);
}
