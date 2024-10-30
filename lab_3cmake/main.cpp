#include <iostream>
#include "calc.hpp"
#include "Wifi.hpp"
#include "defaultconfig.h"
int main ()
{
#ifdef DEBUGINFO 
    std::cout << DEBUGINFO<< std::endl;
#endif
    WIFI_Init();
    std::cout<< "software version is " << HELLOAPP_VERSION_MAJOR << "." << HELLOAPP_VERSION_MINOR << std::endl;
    std::cout <<"Produt Type is " << ProductType << std::endl;
    std::cout <<"Product Year is " << PRODUCT_YEAR << std::endl;
    std::cout << STD_CXX <<std::endl;
    return 0;
}