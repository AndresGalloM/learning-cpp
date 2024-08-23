#include <iostream>

class ListNode {
  public:
    int data;
    ListNode *next;

    ListNode(int data) : data(data), next(NULL) {}
};

class Queue {

  ListNode *front;
  ListNode *rear;
  int length;

  public:
    Queue() : front(NULL), rear(NULL), length(0) {}

    bool isEmpty() {
      return length == 0;
    }

    void enqueue(int data) {
      ListNode *temp = new ListNode(data);

      isEmpty() ? front = temp : rear->next = temp;

      rear = temp;
      length ++;
    }

    void print() {
      ListNode *temp = front;

      while (temp != NULL) {
        std::cout << temp->data << " -> ";
        temp = temp->next;
      }

      std::cout << "NULL" << std::endl;
    }
};

int main() {
  Queue queue;
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);

  queue.print();

  return 0;
}