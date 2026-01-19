#include <iostream>
#include <memory>
#include <map>
#include <list> 
#include <cstddef>
#include "UList.h" 
#include "pool_allocator.h" 

int main() {
     std::map<int, int> defaultmap;  
    for (int i = 0; i < 10; ++i) {
        if (i==1)defaultmap.insert({1,1});
        else defaultmap.insert({i,(i-1)*i});
    }

    std::cout << "------ Map default ------" << std::endl;
    for (auto iter = defaultmap.begin(); iter != defaultmap.end(); ++iter) 
    { 
        std::cout << iter->first << " ";
        std::cout << iter->second << std::endl;
    }

    std::map<int, int, std::less<int>,PoolAllocator<int,30>> Customap;
        for (int i = 0; i < 10; ++i) {
        if (i==1)Customap.insert({1,1});
        else Customap.insert({i,(i-1)*i});
    }

    std::cout << "------ Map allocator ------" << std::endl;
    for (auto iter = Customap.begin(); iter != Customap.end(); ++iter) 
    { 
       std::cout << iter->first << " ";
        std::cout << iter->second << std::endl;
    }

    UserList<int, std::allocator<Block<int>>> Defaultlist;
 //   UserList<int> Defaultlist;
    for (int i = 0; i < 10; ++i) 
    {
        Defaultlist.push_back(i);
    }

    std::cout << "------ User list default allocator ------" << std::endl;
    UserList<int, std::allocator<Block<int>>>::Iterator itdef;
    for (itdef = Defaultlist.begin(); itdef != Defaultlist.end(); ++itdef)
    {
        std::cout << *itdef << std::endl;
    }

    UserList<int, PoolAllocator<Block<int>,30>> Alloclist;
    for (int i = 0; i < 10; ++i) 
    {
        Alloclist.push_back(i);
    }

    std::cout << "------ User list custom allocator ------" << std::endl;
    UserList<int, PoolAllocator<Block<int>>>::Iterator it;
    for (it = Alloclist.begin(); it != Alloclist.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}