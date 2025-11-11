/*
------------------------------------------------------------
Algorithm: Job Queue Simulation using Array
------------------------------------------------------------
1. Start
2. Initialize queue[] array, front = -1, rear = -1
3. For enqueue (Add Job):
      a) If queue full → display "Queue Overflow"
      b) Else if empty → set front = rear = 0 and insert job
      c) Else → increment rear and insert job
4. For dequeue (Delete Job):
      a) If queue empty → display "Queue Underflow"
      b) Else → remove job from front
      c) If front == rear → reset front and rear to -1
      d) Else increment front
5. For display:
      a) Traverse from front to rear and print all jobs
6. Stop
------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int job) {
    if (rear == MAX - 1)
        printf("Queue Overflow! Cannot add more jobs.\n");
    else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = job;
        printf("Job %d added to queue.\n", job);
    }
}

void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue Underflow! No jobs to delete.\n");
    else {
        printf("Job %d removed from queue.\n", queue[front]);
        front++;
        if (front > rear) front = rear = -1;
    }
}

void display() {
    if (front == -1)
        printf("Queue is empty.\n");
    else {
        printf("Current Job Queue:\n");
        for (int i = front; i <= rear; i++)
            printf("Job %d\n", queue[i]);
    }
}

int main() {
    int choice, job;
    do {
        printf("\n---- Job Queue Simulation ----\n");
        printf("1. Add Job\n2. Delete Job\n3. Display Jobs\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter job number to add: ");
                scanf("%d", &job);
                enqueue(job);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 4);
    return 0;
}

/*
--------------------- Sample Output ---------------------
---- Job Queue Simulation ----
1. Add Job
2. Delete Job
3. Display Jobs
4. Exit
Enter your choice: 1
Enter job number to add: 101
Job 101 added to queue.

Enter your choice: 1
Enter job number to add: 102
Job 102 added to queue.

Enter your choice: 3
Current Job Queue:
Job 101
Job 102

Enter your choice: 2
Job 101 removed from queue.

Enter your choice: 3
Current Job Queue:
Job 102

Enter your choice: 4
Exiting...
---------------------------------------------------------
*/
