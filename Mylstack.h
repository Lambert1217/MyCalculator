#ifndef MYLSTACK_H
#define MYLSTACK_H

/**
 * Create by ������ on 2022/10/15
 */

#include "link.h"
#include <assert.h>

//Linked stack
template <class Elem>
class MyLStack
{
private:
    Link<Elem> *top; //Pointer to first element
    int size; //size of the stack
public:
    MyLStack(){top = nullptr; size = 0;}
    ~MyLStack(){clear();} //����
    void clear(){
        //����delete���н��
        while(top != nullptr){
            Link<Elem> *temp = top;
            top = top->next;
            delete temp;
        }
        size = 0; //size ����
    }
    //ѹջ
    void push(Elem& item){
        top = new Link<Elem>(item,top);
        size++;
    }
    //��ջ
    Elem pop(){
        assert(top != nullptr);
        Link<Elem> *temp = top;
        top = top->next;
        size--;
        Elem item = temp->element;
        delete temp;
        return item;
    }
    //����ջͷ����element
    Elem topValue() const{
        assert(top != nullptr);
        return top->element;
    }
    //����ջ�Ĵ�С
    int length() const{
        return size;
    }
};

#endif // MYLSTACK_H






