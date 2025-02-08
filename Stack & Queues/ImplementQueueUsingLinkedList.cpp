//GFG : https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implement-queue-using-linked-list

//Time Complexity : O(1)
//Space Complexity : O(1)

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

//And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; 

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
        // Your Code
        if(rear == nullptr){
            rear = new QueueNode(x);
            front = rear;
        }
        else{
            rear->next = new QueueNode(x);
            rear = rear->next;
        }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
        // Your Code
        if(front == nullptr){
            return -1;
        }
        else if(front == rear){
            int val = front->data;
            delete front;
            front = rear = nullptr;
            return val;
        }
        else{
            int val = front->data;
            QueueNode*save = front;
            front = front->next;
            delete save;
            return val;
        }
}
