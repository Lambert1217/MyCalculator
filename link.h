#ifndef LINK_H
#define LINK_H

/**
 * Create by ¡ı—«∆Ê on 2022/10/15
 */
#include <cstddef>

//class of node
template <typename Elem>
class Link
{
private:
    static Link<Elem>* freelist; //Head
public:
    Elem element; //value
    Link* next; //Pointer to next node
public:
    Link(const Elem& elemval,Link* nextval = nullptr){
        element = elemval; next = nextval;
    }
    Link(Link* nextval = nullptr){
        next = nextval;
    }
    //÷ÿ–¥new∫Õdelete
    void* operator new(size_t){
        if(freelist == nullptr) return ::new Link;
        Link<Elem>* temp = freelist;
        freelist = freelist->next;
        return temp;
    }
    void operator delete(void* ptr){
        ((Link<Elem>*)ptr)->next = freelist;
        freelist = (Link<Elem>*)ptr;
    }
};

//init freelist
template <class Elem>
Link<Elem>* Link<Elem>::freelist = nullptr;

#endif // LINK_H
