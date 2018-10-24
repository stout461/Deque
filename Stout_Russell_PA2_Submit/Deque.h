#ifndef DEQUE_H
#define DEQUE_H

#include <exception>



template <class Type>
class Deque
{
private:
	node<Type> *head, *tail;
	int siz;
    
public:
    Deque(void);
    
    ~Deque(void);
    
    bool isEmpty(void);
    
    int size(void);
    
    Type first(void);
    
    Type last(void);
    
    void insertFirst(Type o);
    
    void insertLast(Type o);
    
    Type removeFirst(void);
    
    Type removeLast(void);
};

#endif
