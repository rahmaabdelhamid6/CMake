cmake_minimum_required(VERSION 3.16)

#d 3chan abtdi a generate library ll wifi.hpp wifi.cpp f el func  add_library () bdiha esm el libaray 
#w el files elly hat3ml beha el libaray w t3ml file.lib w hla'aeh b3d m a3ml make tahat build/lib/ b esm libwifi_lib.a
#w f nfs el wa'at ha3rf f cmake el parent nu y link ma3a el lib 3n tariq target_link_libraries()
# w b kda na mch hahtga adef adef wifi.cpp m3 el src files elly mawguda f el parent cmake 3chan hawa hay3fo lma y link el lib 
#bs hahtag adef el header file bs m3 el includes f el parent cmake 3chan mydnish warning 
add_library(wifi_lib
    Wifi.cpp
    Wifi.hpp)

#lab 5 built invariabels
message(STATUS "hello from lib")
message(STATUS "CMAKE SOURCE DIR ${CMAKE_SOURCE_DIR}") 
message(STATUS "CMAKE CURRENT SOURCE DIR ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "CMAKE CURRENT BINARY DIR ${CMAKE_CURRENT_BINARY_DIR}")
       