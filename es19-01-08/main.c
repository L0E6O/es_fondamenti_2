#include <stdio.h>
#include <stdlib.h>

struct list{
   float value;
   struct list *next;
};

struct list** dupesTarget(struct list **ptr, float target, int n, int *i) {
   struct list **v = (struct list**) malloc(sizeof(int)*n);
   *i = 0;
   while (*ptr!=NULL) {
      if ((*ptr)->value == target) {
         struct list *newNode = (struct list*) malloc(sizeof(struct list));
         newNode->value = target;
         newNode->next = (*ptr)->next;
         (*ptr)->next = newNode;
         v[(*i)++] = *ptr;
         ptr = &(*ptr)->next->next;
      }else
         ptr = &(*ptr)->next;
   }
   return v;
}