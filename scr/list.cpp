#include "list.h"

template<typename T>
Node<T>::Node(T data) {
    this->data = data;
    this->nextNode = nullptr;
    this->previousNode = nullptr;
}
template<typename T>
void Node<T>::setData(T data) {
    this->data = data;
}
template<typename T>
void Node<T>::setNextNode(Node<T> * nextNode) {
    this->nextNode = nextNode;
}
template<typename T>
void Node<T>::setPreviousNode(Node<T> * previousNode) {
    this->previousNode = previousNode;
}
template<typename T>
T Node<T>::getData() {
    return this->data;
}
template<typename T>
Node<T> * Node<T>::getNextNode() {
    return this->nextNode;
}
template<typename T>
Node<T> * Node<T>::getPreviousNode() {
    return this->previousNode;
}

template<typename T>
List<T>::List() {
    this->size = 0;
    this->headNode = nullptr;
    this->tailNode = nullptr;
}
template<typename T>
Node<T>* List<T>::getHeadNode() {
    return this->headNode;
}
template<typename T>
Node<T>* List<T>::getTailNode() {
    return this->tailNode;
}
template<typename T>
void List<T>::pushBack(T data) {
    Node<T> *tmp = new Node<T>(data);
    tmp->setNextNode(nullptr);
    tmp->setPreviousNode(this->tailNode);

    if (headNode == nullptr) {
        headNode = tmp;
    }

    this->tailNode = tmp;
    this->size++;

    if (tmp->getPreviousNode() != nullptr) {
        (tmp->getPreviousNode())->setNextNode(this->tailNode);
    }
}
template<typename T>
bool List<T>::popBack() {
    if (size == 0) {
        return false;
    }

    Node<T> *tmp = this->tailNode;

    if (tmp->getPreviousNode() != nullptr) {
        this->tailNode = tmp->getPreviousNode();
        (tmp->getPreviousNode())->setNextNode(nullptr);
    }
    else {
        this->headNode = nullptr;
        this->tailNode = nullptr;
    }

    size--;
    delete tmp;

    return true;
}
template<typename T>
int List<T>::getSize() {
    return size;
}
template<typename T>
List<T>::~List() {
    Node<T> *tmp = this->headNode;

    while (tmp != nullptr) {
        Node<T> *tp = tmp;
        tmp = tmp->getNextNode();
        delete tp;
    }

    this->size = 0;
    this->headNode = nullptr;
    this->tailNode = nullptr;
}
