#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Node 
{
  int data;
  Node *next;
};

class Stack 
{
  public:
    Stack();
    ~Stack();
    void push(int d);
    int pop();
    bool isEmpty() {return (top == NULL);};
    friend ostream& operator<<(ostream& os, Stack &s);
  private:
    Node *top;
};

Stack::Stack() 
{
  top = NULL;
}

Stack::~Stack() 
{
  //PART 2
  while (!isEmpty()) 
  {
    cout << "Node deleted\n";
    pop();
  }
}

void Stack::push(int d) 
{
  Node *newtop = new Node;
  newtop->data = d;
  newtop->next = top;
  top = newtop;
}

int Stack::pop() {
  if (!isEmpty()) 
  {
    //PART 1
    int value = top->data; 
    Node *oldtop = top; 
    top = top->next; 
    delete oldtop; 
    return value; 
  } 
  else 
  {
    cout << "ERROR: Stack is empty!\n";
    exit(1);
  }
}

ostream& operator<<(ostream& os, Stack &s) 
{
  //PART 3
  if(s.isEmpty())
  {
    os<<"<empty stack>"<<endl;
  }
  else
  {
    os<<" Top -> ";
    Node *current = s.top;
    while(current != NULL)
    {
      os << current -> data<<" -> ";
      current = current->next;
    }
    os << "NULL";
  }
  return os; 
}

int main() 
{
  Stack *s = new Stack();
  cout<< *s << endl;
  s->push(5);
  cout<< *s << endl;
  s->push(3);
  cout<< *s << endl;
  while (!s->isEmpty()) 
  {
    cout << "Stack content popped: " << s->pop() << endl;
  }
  cout<< *s << endl;
  delete s;
  return 0;
}
