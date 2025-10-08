#ifndef __IPBASE
#define __IPBASE

#include <cstddef>
#include <string>
#include <vector>
#include "SimpleAllocator.h"
#include "ip_address.h"

template<typename T, class _Ax = SimpleAllocator<T> >
class ip_base
{
public:
    
     ip_base()
     {
      bl = false;
//        SimpleAllocator<int> alloc;
//        int* arr = alloc.allocate(10);
     };

      ip_base(bool b) {bl = b;}

      void push_back(const T &value)
      {
  //       if (!std::is_same_v<_Ax, SimpleAllocator<T>>) 
        if (bl == true) 
        {
          baseal.push_back(value);
        }
        else 
          base.push_back(value);
      };

     std::vector<int>::iterator begin()
     {
      if (bl == false) return base.begin();
      else return baseal.begin();
     };

     std::vector<int>::iterator end()
     {
      if (bl == false) return base.end();
      else return baseal.end();
     };
     int ReadItem (int i)
     {
      if (bl == false) return base[i];
      else return baseal[i];
     };
private:
  std::vector<T> base;		
	std::vector<T,_Ax> baseal;	
  bool bl;	
};

#endif
