//Mustafa Mannan U60366528


#include "deque.hpp"
#include <stdexcept>  // For handling errors

LinkedList::LinkedList() {
    head = new Node("");
    tail = new Node("");
    head->next = tail;
    tail->prev = head;
}

LinkedList::~LinkedList() {
    while (!isEmpty())
        removeFront();
    delete head;
    delete tail;
}

bool LinkedList::isEmpty() const {
    return (head->next == tail);
}

const std::string& LinkedList::front() const {
    if (isEmpty()) {
        throw std::runtime_error("Cannot access front element of an empty list");
    }
    return head->next->data;
}

const std::string& LinkedList::back() const {
    if (isEmpty()) {
        throw std::runtime_error("Cannot access back element of an empty list");
    }
    return tail->prev->data;
}

void LinkedList::add(Node* v, const std::string& e) {
    Node* u = new Node(e, v->prev, v);
    v->prev->next = u;
    v->prev = u;
}

void LinkedList::addFront(const std::string& e) {
    add(head->next, e);
}

void LinkedList::addBack(const std::string& e) {
    add(tail, e);
}

void LinkedList::remove(Node* v) {
    if (isEmpty()) {
        throw std::runtime_error("Cannot remove element from an empty list");
    }
    Node* u = v->prev;
    Node* w = v->next;
    u->next = w;
    w->prev = u;
    delete v;
}

void LinkedList::removeFront() {
    remove(head->next);
}

std::string LinkedList::removeBack() {
    if (isEmpty()) {
        throw std::runtime_error("Cannot remove from an empty list");
    }
    Node* nodeToRemove = tail->prev;
    std::string data = nodeToRemove->data;
    remove(nodeToRemove);
    return data;
}


bool Deque::empty() const {
    return D.isEmpty();
}

std::string Deque::getFront() {
    if (empty()) {
        throw std::runtime_error("Deque is empty");
    }
    return D.front();
}

std::string LinkedList::getBack() {
    if (isEmpty()) {
        throw std::runtime_error("List is empty");
    }
    return tail->prev->data; 
}

void Deque::insertFront(const std::string& e) {
    D.addFront(e);
}

void Deque::insertBack(const std::string& e) {
    D.addBack(e);
}

void Deque::removeFront() {
    if (empty()) {
        throw std::runtime_error("Cannot remove from an empty deque");
    }
    D.removeFront();
}

void Deque::removeBack() {
    if (empty()) {
        throw std::runtime_error("Cannot remove from an empty deque");
    }
    D.removeBack();
}
