#include<stdio.h>

#include<stdlib.h>

#define SUCCESS 1
#define FAILURE 0
typedef struct node {
  int data;
  struct node * next;
}
node;
int insertbeg(node ** head, int item);
int insertend(node ** head, int item);
int insertmid(node ** head, int item);
int deletebeg(node ** head);
int deleteend(node ** head);
int deletemid(node ** head, int ele);
void display(node * head);
void main(void) {
  int b = 1;
  node * head = NULL;
  while (b) {
    int a, r, w;
    printf("LINKED LIST\n");
    printf("choose the operation to be performed\n");
    printf("1.INSERTION AT BEGINNIG\n");
    printf("2.INSERTION AT END\n");
    printf("3.INSERTION AT MID\n");
    printf("4.DELETION AT BEGINNING\n");
    printf("5.DELETION AT END\n");
    printf("6.DELETION AT MID\n");
    printf("7.DISPLAY THE LINKED LIST\n");
    scanf("%d", & a);
    switch (a) {
    case 1:
      printf("Enter the element to insert\n");
      scanf("%d", & w);
      r = insertbeg( & head, w);
      display(head);
      break;
    case 2:
      printf("Enter the element to insert\n");
      scanf("%d", & w);
      r = insertend( & head, w);
      display(head);
      break;

    case 3:
      printf("Enter the element to insert\n");
      scanf("%d", & w);
      r = insertmid( & head, w);
      display(head);
      break;

    case 4:
      r = deletebeg( & head);
      if (1 == r) {
        printf("The deleted operation is successfully performed: \n");
      }
      break;
    case 5:
      r = deleteend( & head);
      printf("The deleted elements is : %d\n", r);
      break;
    case 6:
      printf("Enter the data to be deleted from the list:\n");
      scanf("%d", & w);
      r = deletemid( & head, w);
      printf("The deleted elements is : %d\n", r);
      break;
    case 7:
      display(head);
      break;
    default:
      printf("Enter choice is invalid\n");
      break;
    }
    printf("DO YOU WANT TO CONTINUE: IF YES PRESS 1 IF NO PRESS 0\n");
    scanf("%d", & b);
  }
  return;
}
int insertbeg(node ** head, int item) {
  node * new;
  new = (node * ) malloc(sizeof(node));
  if (NULL == new) {
    printf("memory allocation failure\n");
    return 0;
  }
  new -> data = item;
  if (NULL == * head) {
    new -> next = NULL;
    * head = new;
  } else {
    new -> next = * head;
  }
  * head = new;
  return SUCCESS;
}
int insertend(node ** head, int item) {
  node * new;
  node * p;
  new = (node * ) malloc(sizeof(node));
  if (NULL == new) {
    printf("memory allocation failure\n");
    return 0;
  }
  new -> data = item;
  new -> next = NULL;
  if (NULL == * head) {
    new -> next = NULL;
    * head = new;
  } else {
    p = * head;
    while (NULL != p -> next) {
      p = p -> next;
    }
    p -> next = new;
  }
  return SUCCESS;
}
int insertmid(node ** head, int item) {
  node * new;
  node * p;
  node * q;
  new = (node * ) malloc(sizeof(node));
  if (NULL == new) {
    printf("memory allocation failure\n");
    return 0;
  }
  new -> data = item;
  if (NULL == * head) {
    new -> next = NULL;
    * head = new;
    return SUCCESS;
  }
  if (item < ( * head) -> data) {
    new -> next = * head;
    * head = new;
  }
  p = ( * head) -> next;
  q = * head;
  while (item > p -> data && NULL != p) {
    q = p;
    p = p -> next;
  }
  new -> next = p;
  q -> next = new;
  return SUCCESS;
}
int deletebeg(node ** head) {
  int item;
  node * p;
  if (NULL == * head) {
    printf("List is empty\n");
  }
  p = * head;
  item = p -> data;
  if (NULL == p -> next) {
    * head = NULL;
  } else {
    * head = p -> next;
  }
  free(p);
  p = NULL;
  return item;
}
int deleteend(node ** head) {
  int item;
  node * p, * q;
  if (NULL == * head) {
    printf("List is empty\n");
  }
  p = * head;
  if (NULL == p -> next) {
    * head = NULL;
  } else {
    q = p;
    while (NULL != p -> next) {
      q = p;
      p = p -> next;
    }
    q -> next = NULL;
  }
  item = p -> data;
  free(p);
  p = NULL;
  return item;
}
int deletemid(node ** head, int ele) {
  int item;
  node * p, * q;
  if (NULL == * head) {
    printf("List is empty\n");
  }
  p = * head;
  if (NULL == p -> next) {
    item = ( * head) -> data;
    * head = NULL;
    return item;
  } else {
    q = p;
    p = p -> next;
    while ((ele == (p -> data)) && (NULL != p)) {
      q = p;
      p = p -> next;
    }
    item = p -> data;
    q -> next = p -> next;
    return item;
  }
  free(p);
  p = NULL;
  return item;
}
void display(node * head) {
  node * p;
  p = head;
  if (NULL == p) {
    printf("List is empty\n");
  }
  else
  {
    printf("Elements in the list are:\n");
    while (NULL != p) {
      printf("%d\t", p -> data);
      p = p -> next;
    }
    return;
  }
}