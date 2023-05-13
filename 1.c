#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 10

int count = 0;

typedef struct stack
{
  int items[MAXSTACK];
  int top;
} st;

void createEmptyStack(st *s)
{
  s->top = 0;
}

int isfull(st *s)
{
  if (s->top == MAXSTACK - 1)
    return 1;
  else
    return 0;
}

int isempty(st *s)
{
  if (s->top == 0)
    return 1;
  else
    return 0;
}

void push(st *s, int newitem)
{
  if (isfull(s))
  {
    printf("STACK FULL");
  }
  else
  {
    s->top;
    s->items[s->top++] = newitem;
  }
  count++;
}

void pop(st *s)
{
  if (isempty(s))
  {
    printf("\n STACK EMPTY \n");
  }
  else
  {
    s->top--;
    printf("Item popped= %d", s->items[s->top]);
  }
  count--;
  printf("\n");
}

void printStack(st *s)
{
  printf("Stack: ");
  for (int i = 0; i < count; i++)
  {
    printf("%d ", s->items[i]);
  }
  printf("\n");
}
int stackSize(st *s)
{
  return s->top;
}
void clearStack(st *s)
{
  s->top = 0;
}
int main()
{
  int choice, elemnt;

  st *s = (st *)malloc(sizeof(st));
  createEmptyStack(s);

  push(s, 10);
  push(s, 20);
  push(s, 30);
  push(s, 40);

  while (1)
  {
    printf("Choose what you want to do , please! \n");
    printf("\n\
          1.clear stack\n\
          2.Push elemnt\n\
          3.Pop elemnt\n\
          4.Stack size\n\
          5.Display stack\n\
          6.exit\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
      clearStack(s);
    }
    else if (choice == 2)
    {
      printf("Enter element you want to push\n");
      scanf("%d", &elemnt);
      push(s, elemnt);
      printStack(s);
    }
    else if (choice == 3)
    {
      pop(s);
      printf("\nAfter popping out\n");
      printStack(s);
    }
    else if (choice == 4)
    {
      printf("Stack size: %d\n", stackSize(s));
    }
    else if (choice == 5)
    {
      printStack(s);
    }

    else if (choice == 6)
    {
      break;
    }
    else
    {
      printf("Invalid choice!\n");
    }
  }
}