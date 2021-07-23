#include <stdio.h>
#define Max 100
int stackarray[Max], i;
int top = -1;
int push(int data)
{
  if (top >= Max - 1)
  {
    printf("\nStack is Already Full");
    return 0;
  }
  else
  {
    top = top + 1;
    stackarray[top] = data;
    return 1;
  }
}

int pop()
{
  int data;
  if (top == -1)
  {
    printf("\nStack is Empty");
    return 0;
  }
  else
  {
    data = stackarray[top];
    top = top - 1;
    return data;
  }
}

int peek()
{
  if (top == -1)
  {
    printf("\nStack is Empty");
    return 0;
  }
  else
  {
    return stackarray[top];
  }
}

int show()
{
  if (top == -1)
  {
    printf("\nStack is empty ");
  }
  else
  {
    printf("\nThe Stack elements are :\n ");
    for (i = 0; i <= top; i++)
    {
      printf("%d\t", stackarray[i]);
    }
  }
}

int Exit()
{
  if (top == -1)
  {
    return 0;
  }
  else
  {
    return -1;
  }
}

void Main()
{
  int option, data, f;
  do
  {
    printf("\nSelect the Operation to be performed from below : ");
    printf("\n1.Push  2.Pop  3.Peek  4.Show  5.Exit : \n");
    printf("\nEnter your Choice : ");
    scanf("%d", &option);
    switch (option)
    {
    case 1:
      printf("\nEnter the element to be inserted : ");
      scanf("%d", &data);
      f = push(data);
      if (f == 0)
      {
        printf("Operation Failed");
      }
      else
      {
        printf("\nElement %d inserted \n", data);
        break;
      }
    case 2:
      f = pop();
      if (f == 0)
      {
        printf("\nOperation Failed\n");
      }
      else
      {
        printf("\nElement %d deleted \n", f);
        break;
      }

    case 3:
      f = peek();
      if (f == 0)
      {
        printf("\nOperation Failed\n");
      }
      else
      {
        printf("\nThe element %d is at top position \n", f);
        break;
      }

    case 4:
      f = show();
      break;

    case 5:
      f = Exit();
      break;

    case 6:
      break;

    default:
      printf("\nInvalid Data\n");
      break;
    }
  } while (option != 6);
}
