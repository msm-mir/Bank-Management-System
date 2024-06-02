#ifndef LIST_H
#define LIST_H

template<typename T>
class Node{
private:
    T data;
    Node<T> *nextNode;
    Node<T> *previousNode;
public:
    Node(T data);
    void setData(T data);
    void setNextNode(Node<T> *nextNode);
    void setPreviousNode(Node<T> *previousNode);
    T getData();
    Node<T>* getNextNode();
    Node<T>* getPreviousNode();
};

template<typename T>
class List {
private:
    Node<T> *headNode;
    Node<T> *tailNode;
    int size;
public:
    List();
    Node<T>* getHeadNode();
    Node<T>* getTailNode();
    void pushBack(T data);
    bool popBack();
    int getSize();
    ~List();
};

#endif // LIST_H
