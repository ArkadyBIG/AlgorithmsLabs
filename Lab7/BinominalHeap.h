//
// Created by Acer on 02.04.2021.
//

#ifndef LAB7_BINOMINALTREE__BINOMINALHEAP_H
#define LAB7_BINOMINALTREE__BINOMINALHEAP_H

#include <map>

const int INF = 10e6;

template <typename T>
class BinominalHeap;

template <typename T>
class Node{
public:
    Node* parent = 0;
    Node* sibling = 0;
    Node* child = 0;
    T     value;
    int   degree{};
public:
    explicit Node(T newValue){
        value = newValue;
    }

    void print(int countTabs) const{
        for (int i = 0; i < countTabs; i++)
            std::cout << '\t';
        std::cout << value << ":" << degree;
        if (child != nullptr) {
            std::cout << std::endl;
            child->print(countTabs + 1);
        }
        if (sibling != nullptr){
            std::cout << std::endl;
            sibling->print(countTabs);
        }
        std::cout << std::endl;
    }
    void link (Node* other){
        this->parent = other;
        this->sibling = other->child;
        other->child = this;
        other->degree++;
    }

    friend std::ostream& operator<< (std::ostream &out, const Node &node){
        out << node.value;
        return out;
    }
    friend BinominalHeap<T>;
};

template <typename T>
class BinominalHeap {
public:
    Node<T>* head;

public:
             BinominalHeap(){
        head = nullptr;
    }
    explicit BinominalHeap(T newValue){
        head = new Node<T>(newValue);
    }
            ~BinominalHeap() = default;

    void print      () const{
        head->print(0);
    }
    void merge      (BinominalHeap<T> *first, BinominalHeap<T> *second) {

        if (first->head == nullptr){
            head = second->head;
            return;
        }
        if (second->head == nullptr){
            head = first->head;
            return;
        }
        Node<T> *firstTemp = first->head,
               *secondTemp = second->head;

        if (firstTemp->degree <= secondTemp->degree) {
            head       = firstTemp;
            firstTemp  = firstTemp->sibling;
        } else {
            head       = secondTemp;
            secondTemp = secondTemp->sibling;
        }

        Node<T> *temp = head;

        while (firstTemp != nullptr && secondTemp != nullptr){
            if (firstTemp->degree < secondTemp->degree) {
                temp->sibling = firstTemp;
                temp          = temp->sibling;
                firstTemp     = firstTemp->sibling;
            } else {
                temp->sibling = secondTemp;
                temp          = temp->sibling;
                secondTemp    = secondTemp->sibling;
            }
        }

        while (firstTemp != nullptr){
            temp->sibling = firstTemp;
            temp          = temp->sibling;
            firstTemp     = firstTemp->sibling;
        }

        while (secondTemp != nullptr){
            temp->sibling = secondTemp;
            temp          = temp->sibling;
            secondTemp    = secondTemp->sibling;
        }
    }
    void unionHeaps (BinominalHeap<T> *first, BinominalHeap<T> *second){
        merge(first, second);

        if (head == nullptr)
            return;

        Node<T> *prevX = nullptr,
                *X     = head,
                *nextX = X->sibling;

        while (nextX != nullptr){

            if (X->degree != nextX->degree || (nextX->sibling != nullptr && nextX->sibling->degree == X->degree)){
                prevX = X;
                X     = nextX;

            } else if (X->value <= nextX->value){

                X->sibling = nextX->sibling;
                nextX->link(X);

            } else {
                if (prevX == nullptr)
                    head = nextX;
                else
                    prevX->sibling = nextX;

                X->link(nextX);
                X = nextX;
            }
            nextX = X->sibling;
        }
    }
    void insert     (T value){
        auto tree = new BinominalHeap<T>(value);
        unionHeaps(this, tree);
        delete tree;
    }
    void extractMin (){
        if (head == nullptr)
            return;

        Node<T>* min = minNode();
        Node<T>* prevMin = prevMinNode();

        if (prevMin != nullptr){
            prevMin->sibling = min->sibling;
        } else {
            head = min->sibling;
        }

        if (min->child == nullptr)
            return;

        // nullptr all min's child's parent and reverse
        Node<T> *first = nullptr,
               *second = min->child,
                *third = second->sibling;
        while (second != nullptr){
            second->parent = nullptr;
            second->sibling = first;

            first = second;
            second = third;
            third = third == nullptr ? nullptr : third->sibling;
        }

        BinominalHeap<T> tree;
        tree.head = first;
        unionHeaps(this, &tree);
        delete min;
    }
    void decreaseKey(Node<T>* node, T newValue){
        if (newValue > node->value){
            std::cout << "New value is more than old one\n";
            return;
        }
        node->value = newValue;

        Node<T> *temp = node,
              *parent = node->parent;

        while (parent != nullptr && parent->value > temp->value){
            T tempValue = parent->value;
            parent->value = temp->value;
            temp->value = tempValue;

            temp = parent;
            parent = parent->parent;
        }
    }
    void erase      (Node<T>* node){
        decreaseKey(node, -INF);
        extractMin();
    }


    [[nodiscard]] Node<T>* minNode() const{
        Node<T>* minimal = head;
        Node<T>* temp    = head->sibling;

        while (temp != nullptr){
            if (temp->value < minimal->value)
                minimal = temp;
            temp = temp->sibling;
        }

        return minimal;
    }
    [[nodiscard]] Node<T>* prevMinNode() const{
        Node<T>* tempPrev = head;
        Node<T>* prev     = nullptr;
        Node<T>* minimal  = head;
        Node<T>* temp     = head->sibling;

        while (temp != nullptr){
            if (temp->value < minimal->value) {
                prev    = tempPrev;
                minimal = temp;
            }

            tempPrev = tempPrev != nullptr ? tempPrev->sibling : head;
            temp = temp->sibling;
        }

        return prev;
    }

};


#endif //LAB7_BINOMINALTREE__BINOMINALHEAP_H
