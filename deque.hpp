//Mustafa Mannan U60366528

#ifndef DEQUE_H
#define DEQUE_H

#include <string>

class Node {
public:
    std::string data;
    Node* prev;
    Node* next;
    Node(const std::string& val, Node* p = nullptr, Node* n = nullptr) : data(val), prev(p), next(n) {}
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    bool isEmpty() const;
    const std::string& front() const;
    const std::string& back() const;
    void addFront(const std::string& e);
    void addBack(const std::string& e);
    void removeFront();
    std::string removeBack();
    std::string getFront();
    std::string getBack();

    
private:
    Node* head;  
    Node* tail;  
    void add(Node* v, const std::string& e);
    void remove(Node* v);
};

class Deque {
public:
    bool empty() const;
    std::string getFront();
    std::string getBack();

    void insertFront(const std::string& e);
    void insertBack(const std::string& e);
    void removeFront();
    void removeBack();
    int getSize() const{
        return size;
    }
private:
    LinkedList D;
    int size;
};

#endif
