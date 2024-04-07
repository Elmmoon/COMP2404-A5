/*Data structure that contains the participants of the escape. 
Implemented as a Linked-List with Class Template*/
#ifndef LIST_H
#define LIST_H

#include "defs.h"

template <class T>
class List
{
  class Node
  {
    public:
      T data;
      Node* next;
  };

  public:
    List();
    ~List();
    List& operator +=(T);
    void convertToArray(T*, int&) const;

  private:
    Node* head;
};

template <class T>
List<T>::List() : head(nullptr) {}

template <class T>
List<T>::~List()
{
  Node* currNode = head;
  Node* nextNode;

  while (currNode != nullptr) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

template <class T>
List<T>& List<T>::operator +=(T t){
  Node* newNode;
  Node* currNode;
  Node* prevNode;

  newNode = new Node;
  newNode->data = t;
  newNode->next = nullptr;

  currNode = head;
  prevNode = nullptr;

  while (currNode != nullptr) {
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == nullptr) {
    head = newNode;
  }
  else {
    prevNode->next = newNode;
  }
  return *this;
}

template <class T>
void List<T>::convertToArray(T* arr, int& size) const{
  Node* currNode = head;
  size = 0;

  while (currNode != nullptr) {
    arr[size++] = currNode->data;
    currNode = currNode->next;
  }
}

#endif
