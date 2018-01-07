// C program to implement stack using arrays
#include<stdio.h>
#include<stdlib.h>

// A stack data structure using array
struct stack
{
    int top;
    unsigned int capacity;
    int *array;
};

// Utility function to initialize stack data structure
struct stack* createStack(int capacity)
{
    struct stack *newStack =
      (struct stack*)malloc(sizeof(struct stack));
    newStack->top        = -1;
    newStack->capacity   = capacity;
    newStack->array = (int *)malloc(sizeof(capacity*sizeof(int)));

    return newStack;
}

// Utility function to push to stack
int pushToStack (int num, struct stack *newStack)
{
  if(newStack->top == 0) {
      printf("The stack is full\n");
      return newStack->top;
  }

  if(newStack->top == -1)
    newStack->top = newStack->capacity-1;
  else
    newStack->top--;

  newStack->array[newStack->top] = num;

  return newStack->top;
}

// Utility function to pop from stack
int popFromStack (struct stack* newStack)
{
  if(newStack->top == -1)
    return newStack->top;

  newStack->array[newStack->top] = 0;

  ++(newStack->top);
  if (newStack -> top == newStack->capacity)
    newStack->top = -1;

  return(newStack->array[newStack->top]);
}

// Utility function to print out the contents of stack
int printStack(struct stack* newStack)
{
  int top = newStack->top;

  if(top == -1) {
      printf("No items in stack to print\n");
      return top;
  }

  while ((top != -1) && (top < newStack->capacity)) {
    printf("| %d |", newStack->array[top], top);
    top++;
  }

  return top;
}

// Driver program
int main()
{
    struct stack *newStack = createStack(4);

    //Pushing elements to stack
    pushToStack(10, newStack);
    pushToStack(20, newStack);
    pushToStack(30, newStack);
    pushToStack(40, newStack);
    printf("After pushing\n");
    printStack(newStack);

    //Pop element from stack
    if(popFromStack(newStack) == -1) {
      printf("Stack is empty\n");
    }
    printf("\nAfter popping\n");
    printStack(newStack);

    return 0;
}
