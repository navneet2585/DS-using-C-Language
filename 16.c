/*
Write a menu-driven program to implement Circular-Queue(FIFO/LILO) using Linked-List 
    (a) Enqueue
    (a) Dequeue
    (a) Peek
    (a) display
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(front == NULL && rear == NULL){
        front = rear = newnode;
        rear->next = front;
    }
    else{
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue(){
    struct node *temp;
    temp = front;

    if(front == NULL && rear == NULL){
        printf("queue is empty\n");
    }
    else if(front == rear){
        front = rear = NULL;
        free(temp);
    }
    else{
        printf("%d elem is dequeue",front->data);
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void peek(){
    if(front == NULL && rear == NULL){
        printf("queue is empty\n");
    }
    else{
        printf("\n%d is front elem",front->data);
    }
}

void display(){
    struct node *ptr;
    ptr = front;

    if(front == NULL && rear == NULL){
        printf("queue is empty\n");
    }
    else{
        while(ptr->next != front){
            printf("%d-->",ptr->data);
            ptr = ptr->next;
        }
        printf("%d",ptr->data);
    }
}


int main(){
    int ch,data;

    printf("1. to enqueue\n");
    printf("2. to dequeue\n");
    printf("3. to peek\n");
    printf("4. to display\n");
    printf("5. to Exit\n");

    do{
        printf("\nEnter the choice : ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter num to be enqueue : ");
                scanf("%d",&data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exit");
                break;
            default:
                printf("invalid choice selected\n");
        }

    }while(ch != 5);


    return 0;
}
