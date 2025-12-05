#ifndef __USERCONTANER
#define __USERCONTANER

#include <cstddef>
#include <string>
#include <vector>
#include "pool_allocator.h"

template <typename T>
struct Block
{
    T data;
    Block *next;
};

template <typename T, typename A = std::allocator<T>>
class UserList
{
public:
UserList(A allocator = A());
UserList(int B, A allocator = A());
~UserList();

void push_back(const T &data);
Block<int>* begin();
Block<int>* end();


    class Iterator
    {
    public:
        Iterator()    
        {
            ptr = nullptr;
        }

        void operator = (Block<int>* bl)
        {
            ptr = bl;         
        }
        
        void operator ++ ()
        {
            if (ptr != nullptr)
                ptr = ptr->next;
        }
        int operator * ()
        {
            return ptr->data;
            
        }
        bool operator != (Block<int>* bl)
        {
            if (ptr != bl) return true;
            else return false;
        }
        Block<int>* operator -> ()
        {
            return ptr;
        }
    
        bool IsEnd() const
        {
            return ptr == nullptr;
        }
    
     private:
        Block<int>* ptr;
    };
    friend class Iterator;

private:
    void Destroy(Block<int>* node);
    Block<int> *head;
    Block<int> *tail;
    Block<int> *begin_item;
    A alloc;
};
	


template <typename T, typename A>
UserList<T, A>::UserList(A allocator)
    : head(nullptr)
    , tail(nullptr)
    , alloc(allocator)
{

}


template <typename T, typename A>
UserList<T, A>::UserList(int B, A allocator)
    : head(nullptr)
    , tail(nullptr)
{
    PoolAllocator<Block<int>> alloc(B);
}

template <typename T, typename A>
UserList<T, A>::~UserList()
{
    auto ptr = head;
    while (ptr != nullptr)
    {
        auto next = ptr->next;
        Destroy(ptr);
        ptr = next;
    }
}

template <typename T, typename A>
void UserList<T, A>::Destroy(Block<int>* node)
{
    alloc.deallocate(node, 1);
}


template <typename T, typename A>
void UserList<T, A>::push_back(const T &data)
{
    Block<int>* block = alloc.allocate(1);
    block->data = data;
    block->next = nullptr;
    if (tail != nullptr)
        tail->next = block;
    tail = block;
    if (head == nullptr)
    {
        head = block;
        begin_item = block;
    }
};

template <typename T, typename A>
Block<int>* UserList<T, A>::begin()
{
    return begin_item;
}

template <typename T, typename A>
Block<int>* UserList<T, A>::end()
{
    return tail->next;
}

#endif
