#include <stdio.h>
#include <stdlib.h>

#define MAX 5 

typedef struct {
    int items[MAX];
    int front;
    int rear;
} LinearQueue;
void initQueue(LinearQueue* q) {
    q->front = -1;
    q->rear = -1;
}
int isEmpty(LinearQueue* q) {
    return q->front == -1;
}
int isFull(LinearQueue* q) {
    return q->rear == MAX - 1;
}
void enqueue(LinearQueue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}
int dequeue(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1; 
    }
    printf("Dequeued: %d\n", item);
    return item;
}
void display(LinearQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    LinearQueue q;
    initQueue(&q);
    
    int choice, value;

    while (1) {
        printf("1. Enqueue 2. Dequeue 3. Display 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
