#include <iostream>
#include <memory>
#include <map>
#include <list> 
#include <cstddef>
#include "ip_address.h" 
#include "ip_base.h" 
#include "SimpleAllocator.h" 


int main() {
    std::map<int, int> defaultmap;  
    for (int i = 0; i < 10; ++i) {
        if (i==1)defaultmap.insert({1,1});
        else defaultmap.insert({i,(i-1)*i});
    }
    std::map<int, int, std::less<int>,SimpleAllocator<int>> Mymap;
        for (int i = 0; i < 10; ++i) {
        if (i==1)Mymap.insert({1,1});
        else Mymap.insert({i,(i-1)*i});
    }
    std::cout << "------Map default------" << std::endl;
    for (auto iter = defaultmap.begin(); iter != defaultmap.end(); ++iter) 
    { 
        std::cout << iter->first << " ";
        std::cout << iter->second << std::endl;
    }
    std::cout << "------Map allocator------" << std::endl;
    for (auto iter = Mymap.begin(); iter != Mymap.end(); ++iter) 
    { 
        std::cout << iter->first << " ";
        std::cout << iter->second << std::endl;
    }

    ip_address ip;
    ip = "192.168.7.7";
    ip.print_ip();
    ip_base<ip_address> base;
    base.push_back(ip);

    ip_base<int> myContainer;
    for (int i = 0; i < 10; ++i) {
        myContainer.push_back(i);
    }

    ip_base<int,SimpleAllocator<int>> myContainerAlloc(true);
        for (int i = 0; i < 10; ++i) {
        myContainerAlloc.push_back(i);
    }

std::cout << "------My container------" << std::endl;
    for (int i = 0; i < 10; ++i) {
        std::cout << myContainer.ReadItem(i) << "\n";
    }
   
std::cout << "------My container allocator------" << std::endl;    
for (int i = 0; i < 10; ++i) {
        std::cout << myContainerAlloc.ReadItem(i) << "\n";
    }
/*  std::list<int> myList;
    std::list<int>::iterator it1 = myList.begin();
    for (int i = 0; i < 10; ++i) {
        myList.insert(it1, i);
        };


   std::list<int,SimpleAllocator<int>> myContainer;
    std::list<int>::iterator it2 = myContainer.begin();
    for (int i = 0; i < 10; ++i) {
        myContainer.insert(it2, i);
        };
std::cout << "------My conteiner------" << std::endl;
    for (auto iter = myList.begin(); iter != myList.end(); ++iter) { std::cout << *iter << "\n"; }
std::cout << "------My conteiner allocator------" << std::endl;    
    for (auto iter = myContainer.begin(); iter != myContainer.end(); ++iter) { std::cout << *iter << "\n"; }
*/
   
    return 0;
}

