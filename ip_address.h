#ifndef __IPADDRESS
#define __IPADDRESS

#include <cstddef>
#include <string>

class ip_address
{
public:
		ip_address();
    
        int operator = (const std::string &&str);
        void print_ip();
    //     ~ip_address();
    
private:
	std::byte A,B,C,D;		
};

//inline ip_address::ip_address():{A=0x00,B=0x00,C=0x00,D=0x00};

#endif
