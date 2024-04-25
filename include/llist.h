/**
 * @file    llist.h
 * @brief   generic linked list implementation
 * @author  geronimo
 *
 *          This generic linked list implementation mimics the
 *          list.h behaviour from the linux kernel.
 *
 */

#ifndef LLIST_H
#define LLIST_H

#include "lib/errno.h"
#include "lib/stdbool.h"

extern int errno;
unsigned int const MAX_LLIST_ITEMS = 100;

struct llist_node {
  struct llist_node *prev;
  struct llist_node *next;
};

#define llist_obj(ptr, obj_type)                                               \
  ({(void *)(ptr - (sizeof(obj_type) - sizeof(llist_node)))})

bool lst_add(struct llist_node *head, struct llist_node *node) {

  struct llist_node *temp = head;
  unsigned int iteration_guard;

  // Check for NULL-pointer
  if (!head || !node || !head->next) {
    errno = EFAULT;
    return false;
  }

  while (temp->next != head) {
    if (iteration_guard > MAX_LLIST_ITEMS) {
      errno = EFAULT;
      return false;
    }
    iteration_guard++;
    temp = temp->next;
  }

  temp->next = node;
  node->prev = temp;
  node->next = head;

  return true;
}

#endif
