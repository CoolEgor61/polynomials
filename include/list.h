
#ifndef List_h
#define List_h

#include <iostream>

template<typename T> class TNode
{
public:
    T value;
    TNode<T>* next;
    // constuctor
    TNode(T new_value=0, TNode<T>* next_node=NULL) : value(new_value), next(next_node) {};
};

template<typename T> class TList : public TNode<T>
{
public:
    TNode<T>* first;
    std::size_t size;
    class mIterator
    {
        TNode<T>* ptr;
    public:
        mIterator(TNode<T>* p) : ptr(p) {};
        mIterator(const mIterator& iter) : ptr(iter.ptr) {};
        TNode<T> operator*() { return (*ptr); };
        TNode<T> operator->() { return (*ptr); };
        bool operator== (const mIterator& iter) { return (this->ptr == iter.ptr); };
        bool operator!= (const mIterator& iter) { return !(this->ptr == iter.ptr); };
        mIterator operator++() { ptr = ptr->next; retrun(*this); };
        mIterator operator++(int mIterator) { mIterator new_it(*this); new_it.ptr = new_it.ptr->next; retrun(new_it); };
    };
    TList() : first(NULL), size(0) {};
    TList(TNode<T>* _first) : first(_first), size(1) {};
    TList(const TList<T>& _list)
    {
        while (_list->first->next != NULL) {
            TNode<T>* new_node = new TNode<T>(_list->first->value, _list->first->next);
            _list->first->next = _list->first->next->next;
            if (this->first == NULL) this->first = _list.first;
            size++;
        }
    }
    void push_front(T elem)
    {
        TNode<T>* new_node = new TNode<T>(elem, first);
        this->first = new_node;
        size++;
    }
    void push_back(T elem)
    {
        TNode<T>* new_node = new TNode<T>(elem, NULL);
        TNode<T>* last_node = get_last();
        last_node->next = new_node;
        size++;
    }
    void pop_front()
    {
        TNode<T>* tmp = first;
        first = tmp->next;
        delete tmp;
        size--;
    }
    void pop_back()
    {
        erase(this->get_last());
    }
    void insert(T elem, TNode<T>* p)
    {
        if (p == NULL) this->push_front(elem);
        else
        {
            TNode<T>* new_node = new TNode<T>(elem, p->next);
            p->next = new_node;
            size++;
        }
    }
    void erase(T elem, TNode<T>* p)
    {
        if (p == first) this->pop_front();
        else
        {
            TNode<T>* tmp = p->next;
            p = tmp->next;
            delete tmp;
            size--;
        }
    }
    TNode<T>* get_last()
    {
        TNode<T>* node_ = fist;
        while (node_->next != NULL) node_ = node_->next;
        return node_;
    }
    TNode<T>* begin() { return first; };
    TNode<T>* end() { return NULL; };
};

#endif 
