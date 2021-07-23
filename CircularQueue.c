#include <stdio.h>
#define Max 100
int queuearray[Max], i;
int front = -1;
int rear = -1;
int count = 0;

int enqueue(int data)
{
    if (rear>=Max-1)
    {
        printf("\nQueue is Full");
        rear==-1;
        return 0;
    }
    else if (front == -1)
    {
        rear = rear + 1;
        front = front + 1;
        queuearray[rear] = data;
        count = count + 1;
        return 1;
    }
    else
    {
        rear = rear + 1;
        queuearray[rear] = data;
        count + count + 1;
        return 1;
    }
}


int dequeue()
{
    int data;
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return 0;
    }
    else
    {
        data = queuearray[front];
        front = front + 1;
        if (front >= rear)
        {
            front = rear = -1;
        }
        count = count - 1;
        return data;
    }
}

int Front()
{
    if (front == -1)
    {
        printf("\nThe Queue is Empty");
        return 0;
    }
    else
    {
        return queuearray[front];
    }
}

int Rear()
{
    if (rear == -1)
    {
        printf("\nThe Queue is Empty");
        return 0;
    }
    else
    {
        return queuearray[rear];
    }
}

int display()
{
    if (front == -1)
    {
        printf("\nOperation Failed");
        printf("\nThe Queue is Empty");
        return 0;
    }
    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d\t", queuearray[i]);
            printf("\n");
        }
    }
}

int size()
{
    if(rear==-1)
    {
        printf("\nQueue is Empty");
    }
    else
    {
        printf("\nThe size of Circular Queue is %d\n",rear);
    }
}

int main()
{
    int option, data, op;
    do
    {
        printf("\nSelect the operation to perform on Circular Queue :");
        printf("\n1.Enqueue 2.Dequeue 3.Front 4.Rear 5.Display 6.Size 7.Exit\n");
        printf("\nEnter your option : ");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
            printf("\nEnter the element to insert : ");
                scanf("%d", &data);
            op = enqueue(data);
            if (op == 0)
            {
                printf("\nOperation Failed\n");
                break;
            }
            else
            {
                printf("\nElement %d successfully inserted\n", data);
                break;
            }
        case 2:
            op = dequeue();
            if (op == 0)
            {
                printf("\nOpration Failed\n");
                break;
            }
            else
            {
                printf("\nElement %d Successfully deleted\n", op);
                break;
            }
        case 3:
            op = Front();
            if (op == 0)
            {
                printf("\nOperation failed\n");
                break;
            }
            else
            {
                printf("\nElement %d is at Front\n", op);
                break;
            }

        case 4:
            op = Rear();
            if (op == 0)
            {
                printf("\nOperation failed\n");
                break;
            }
            else
            {
                printf("\nElement %d is at Rear\n", op);
                break;
            }    
        case 5:
            op = display();
            break;
        
        case 6:
            op = size();
            break;
        
        default:
            printf("\nSuccessfull Exit!!");
            break;
        }
    } while (option != 7);
}
