#ifndef MYLSTACK_H
#define MYLSTACK_H

/**
 * Create by 刘亚奇 on 2022/10/15
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
    ~MyLStack(){clear();} //析构
    void clear(){
        //遍历delete所有结点
        while(top != nullptr){
            Link<Elem> *temp = top;
            top = top->next;
            delete temp;
        }
        size = 0; //size 归零
    }
    //压栈
    void push(Elem& item){
        top = new Link<Elem>(item,top);
        size++;
    }
    //弹栈
    Elem pop(){
        assert(top != nullptr);
        Link<Elem> *temp = top;
        top = top->next;
        size--;
        Elem item = temp->element;
        delete temp;
        return item;
    }
    //返回栈头结点的element
    Elem topValue() const{
        assert(top != nullptr);
        return top->element;
    }
    //返回栈的大小
    int length() const{
        return size;
    }
};

#endif // MYLSTACK_H






