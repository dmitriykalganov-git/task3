#include "ip_address.h"
#include <bitset>
#include <string>
#include <iostream>

ip_address::ip_address()
:A((std::byte)0x00),B((std::byte)0x00),C((std::byte)0x00),D((std::byte)0x00){};
//--------------------------------------------------------------------


//--------------------------------------------------------------------
int ip_address::operator=(const std::string &&str)
{
   size_t pos=0,length=0;
   std::string sub;
   int num=0;
   for (int i=0;i<4;++i)
   { 
         length = str.find(".",pos);
         sub = str.substr(pos, length-pos);
         pos = length+1;
         switch(i) {
         case 0: A = (std::byte)atoi(sub.c_str()); break;
         case 1: B = (std::byte)atoi(sub.c_str()); break;
         case 2: C = (std::byte)atoi(sub.c_str()); break;
         case 3: D = (std::byte)atoi(sub.c_str()); break;
         }
   }
   return 0;
};
//--------------------------------------------------------------------
void ip_address::print_ip()
{
   
 int num1 = std::to_integer<int>(A);
 int num2 = std::to_integer<int>(B);
 int num3 = std::to_integer<int>(C);
 int num4 = std::to_integer<int>(D);
 std::cout << num1 << "." << num2 << "." << num3 << "." << num4 <<std::endl;
}
//--------------------------------------------------------------------
