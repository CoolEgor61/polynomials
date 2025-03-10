
#ifndef List_h
#define List_h

#include <iostream>

template<typename T> class TNode
{
public:
    T value;
    TNode<T>* next;
    // constuctor
    TNode(const T& new_value=0, TNode<T>* next_node=NULL) : value(new_value), next(next_node) {};
    TNode& operator=(const TNode& m)
    {
        if (this != &m)
        {
            value = m.value;
            next = m.next;
        }
        return *this;
    }
};

template<typename T> class TList
{
protected:
public:
    TNode<T>* first;
    std::size_t size;
    TNode<T>* get_first() noexcept { return first; };
    class mIterator
    {
    public:
        TNode<T>* ptr;
        TNode<T>* get_ptr() noexcept { return ptr; };
        mIterator(TNode<T>* p) : ptr(p) {};
        mIterator(const mIterator& iter) : ptr(iter.ptr) {};
        TNode<T>* operator*() { return (this->ptr); };
        TNode<T>* operator->() { return (this->ptr); };
        bool operator== (const TList<T>::mIterator& iter) { return (this->ptr == iter.ptr); };
        bool operator!= (const TList<T>::mIterator& iter) { return !(this->ptr == iter.ptr); };
        mIterator& operator++() { this->ptr = ptr->next; return(*this); };
        mIterator operator++(int) { mIterator new_it(*this); new_it.ptr = new_it.ptr->next; return(new_it); };
    };
    TList() : first(NULL), size(0) {};
    TList(TNode<T>* _first) : first(_first), size(1) {};
    TList(const TList<T>& _list) : first(NULL), size(_list.size)
    {
        if (_list.first == NULL) return;
        else {
            TNode<T>* pNew = this->first = new TNode<T>(*_list.first);
            for (; pNew->next != NULL; pNew = pNew->next)
                pNew->next = new TNode<T>(*pNew->next);
        }
    }
    TList(TList<T>&& _list) noexcept
    {
        this->first = NULL;
        std::swap(*this, _list);
    }
    ~TList()
    {
        TNode<T>* p;
        while (this->first != NULL)
        {
            p = this->first;
            this->first = first->next;
            delete p;
        }
    }
    TList<T>& operator=(const TList<T>& _list)
    {
        if (this != &_list)
        {
            TList<T> tmp(_list);
            std::swap(*this, tmp);
        }
        return *this;
    }
    void push_front(T elem)
    {
        TNode<T>* new_node = new TNode<T>(elem, this->first);
        if (new_node == 0) throw std::logic_error("Mem alloc error");
        else {
            this->first = new_node;
            size++;
        }
    }
    void push_back(T elem)
    {
        TNode<T>* new_node = new TNode<T>(elem, NULL);
        TNode<T>* last_node = this->get_last();
        if (last_node != NULL) last_node->next = new_node;
        else first = new_node;
        size++;
    }
    void pop_front()
    {
        if (this->first == NULL) throw std::logic_error("List is already empty");
        else {
            TNode<T>* tmp = first;
            first = tmp->next;
            delete tmp;
            size--;
        }
    }
    void pop_back()
    {
        TNode<T>* node_ = this->first;
        while (node_->next ->next != NULL) node_ = node_->next;
        delete node_->next;
        node_->next = NULL;
        size--;
    }
    void insert(T elem, TNode<T>* p) // inserts after p
    {
        if (p == NULL) this->push_front(elem);
        else
        {
            TNode<T>* new_node = new TNode<T>(elem, p->next);
            if (new_node == 0) throw std::logic_error("Mem alloc error");
            else {
                p->next = new_node;
                size++;
            }
        }
    }
    void erase(TNode<T>* p) // erases after p
    {
        if (p == NULL) this->pop_front();
        else
        {
            TNode<T>* tmp = p->next;
            if (tmp != NULL)
            {
                p->next = tmp->next;
                delete tmp;
                size--;
            }
            else p->next = NULL;
        }
    }
    TNode<T>* get_last()
    {
        TNode<T>* node_ = first;
        if (first == NULL) return node_;
        else while (node_->next != NULL) node_ = node_->next;
        return node_;
    }
    mIterator begin() noexcept { return first; };
    mIterator end() noexcept { return NULL; };
};

#endif 
