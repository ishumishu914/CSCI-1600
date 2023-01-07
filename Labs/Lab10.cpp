#include <iostream>
#include <string>

using namespace std;

// Create a struct containing a string (element_name) and an bool (priority) as well as a node pointer (Node* next)
struct Node
{
    string element_name;
    Node *next;
};

// Queue class
class Queue 
{
    // --- public members ---
    public:
        Queue(); // constructor (with no parameters) - Creates an empty queue
        ~Queue(); // deconstructor - Deletes the queue
        bool isEmpty() // Checks if the queue is empty
        {
            return (front == NULL);
        };
        void Enqueue(string element);  // Adds a new Node to the Queue. The new Node should be added to the back of the queue.
        string Dequeue(); // Deletes a Node from the Queue. The Node deleted should be from the front of the queue (and it should return the element_name of the deleted Node)
        void PriorityEnqueue(string element); // Adds a new Node to the front of the Queue
        string toString(); // Returns a string containing the contents of the queue from the back Node to the front Node. For example:
    //           [Yoda] -> [R2D2] -> [Solo]
    
    // --- private members ---
    private:
        Node *front; // a pointer to the front of the Queue
        Node *back; // a pointer to the back of the Queue
};

Queue:: Queue() // constructor
{
    // Initialize
    Node *front = NULL;
    Node *back = NULL;
}

Queue:: ~Queue() // deconstructor
{
    //Delete all nodes in the list
    Node *temp = front->next;
    delete front;
    while (temp->next != NULL) 
    {
        front = temp;
        temp = temp->next;
        delete front;
    }
    delete temp;
    cout << "Queue deleted!" << endl;
}

void Queue::Enqueue(string element) // function to add a new Node to the back of Queue
{
    //If the queue is empty
    if (isEmpty()) 
    {
        front = new Node;
        front->element_name = element;
        front->next = NULL;
    } 
    else 
    {
        //If queue is not empty
        Node *current = front;
        while (current->next != NULL) // finds the end of the queue 
        {
            current = current->next;
        }
        current->next = new Node;
        current->next->element_name = element;
        current->next->next = NULL;
    }
}

void Queue::PriorityEnqueue(string element) // function to add a new Node to the front of Queue
{
    //If the queue is empty
    if (isEmpty()) 
    {
        front = new Node;
        front->element_name = element;
        front->next = NULL;
    } 
    else 
    {
        //If queue is not empty
        Node *newfront = new Node;
        newfront->element_name = element;
        newfront->next = front;
        front = newfront;
    }
}

string Queue::Dequeue() // delete node
{
    //If the queue is empty
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    string element = front->element_name;
    if (front == back)
    {
        front = back = NULL;
    }
    else
    {
        front = front->next;
    }
    return element;
}

string Queue::toString() // print contents of queue
{
    if (isEmpty()) //if queue is empty 
    {
        cout << "Queue is empty"<< endl;
    }
    //otherwise...
    string result = " ";
    Node *current = front;
    while (current != NULL) 
    {
        result = "[" + current-> element_name + "]" +" -> " + result;
        current = current->next;
    }
    result += "Front of queue reached";
    return result;
}

int main() 
{
    // create dynamic Queue variable q
    Queue* q = new Queue();

    q->Enqueue("Solo");
    q->Enqueue("R2D2");
    q->Enqueue("Yoda");
    q->PriorityEnqueue("BB8");

    cout << q->toString() << endl;

    q->Dequeue();

    cout << q->toString() << endl;

    delete q;

    return 0;
}
