# ni yba'a 3ndi parent cmake w feh cmake taht b3d f ykun feh inheritance 
# f ezay na k cmake elly bara f lab_3cmake anadi 3la cmake file elly gowa lib folder ?
# tb eh elly ykhlini alga' l d lw shaghal f project mch lwahdi f kol had by3ml module zy wifi masln 
# wana hahtag
cmake_minimum_required(VERSION 3.16)  
#project(HELLOAPP ) 
project(HELLOAPP VERSION 3.2) 
set(SRC_FILES 
    main.cpp 
    src/calc.cpp)
message(STATUS "Src Files has ${SRC_FILES}")
#d m3naha ni b add subdirectory ll parent directory .. ${CMAKE_SOURCE_DIR} /lib-->shuf nt wa'aef fen w adkhul gowa el lib
#f ka'no byshel el line d w y3wd bdalo b file el cmake elly gowa el lib folder 

add_executable(hellobinary ${SRC_FILES}) 

add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
target_include_directories(hellobinary PUBLIC include/ lib/)
#target_include_directories(hellobinary PUBLIC include/ lib/ build/)

#3chan y link m3 el libarary elly cmake child hay3mlha 
target_link_libraries(hellobinary PUBLIC wifi_lib)

#lab 5 vbuilt in ariabels
#d el path bta3 awl cmake a run
message(STATUS "CMAKE SOURCE DIR ${CMAKE_SOURCE_DIR}") 
# d bta3 el cmake elly na wa'af feh y3i lw hato gowa cmake elly f lib haygeb el path lhad el lib
message(STATUS "CMAKE CURRENT SOURCE DIR ${CMAKE_CURRENT_SOURCE_DIR}")
#same as source 
message(STATUS "CMAKE BINARY DIR ${CMAKE_BINARY_DIR}")
message(STATUS "CMAKE CURRENT BINARY DIR ${CMAKE_CURRENT_BINARY_DIR}")
message(STATUS "CMAKE GENERATOR ${CMAKE_GENERATOR}")

#feh shwayet built in variabels na momkn a3mlhum set zy aw overwrite 3la el default value 
#f el aghlb el 2 lines el gayeen byba'o mawguden f awl ay cmake file  mohtrm 3chan yhdd hayshtghl 3la ea
set(CMAKE_CXX_STANDARD  14) #el line elly tahto mohm 3chan y apply el value .. 
set(CMAKE_CXX_STANDARD_REQUIRED True) #d matlub 3chan a3rf anfz el line elly ablo bhes myrunsh la bystkhdm c++14
#momkn aktb massege kda aw , MASSAGE kda hatshtghl f el halten w d f ay comman 3momn mch argument 3chan btfr'
message(STATUS "SHOW C++ STANDARD ${CMAKE_CXX_STANDARD}")
message(STATUS "SHOW C++ STANDARD REQUIRED ${CMAKE_CXX_STANDARD_REQUIRED} ")

#momkn assign variable kda 
#set(SRC_FILES 
    #main.cpp 
    #src/calc.cpp)
#aw kda set(SRC_FILES "main.cpp ;src/calc.cpp")


# momkn yba'a lya access 3la enciroment variabels 3chan a'der awsl l compiler mo3yen hwa 3amlo b cross tool
#aw ywsl l application mo3yen  
#ENV --> d key word ll cmake w b3dha bhut el variable elly na 3awzo 
set(p $ENV{PATH})
Message(STATUS "RAHMA : $ENV{PATH}")

#momkn wana b run el cmake adeh value mn khlal el terminal lw mch 3awez a3rfo f el code f ha3rfo wana shaghal  
message(STATUS "Argument Value is  ${Myvalue}") #1- ---> 2- wana brun aadeh value cmake .. -DMyvalue=10
#  w momkn brdu a set wana brun l built in variable 
message(STATUS "CMAKE_CXX_STANDARD is ${CMAKE_CXX_STANDARD}") #cmake .. -DCMAKE_CXX_STANDARD=17 ---> mch hyassign lw mt3rfa fo'

#----------------------------------------------------------------------------------------------------------------------------------------------
#lab 6 configure file 

set(PRODUCT_YEAR "2024")
target_include_directories(hellobinary  PUBLIC ${PROJECT_BINARY_DIR})  # w bhtag adef el header file ellu hygenerato d f target_include_directories aw adefo hna kda 

#bdeha defaultconfig.h.in w hya btgenerate defaultconfig.h lma bagi a3ml cmake Ttaht el path d lab_3cmake/build/defaultconfig.h
#bhes lw 3awez cmake hya el genrate file.h ykun feh b3d el defination el ra'esya aw el premitive configuration zy el product relase w el serial number product year w el product version 
#configure_file(defaultconfig.h.in defaultconfig.h)  # LAZEM D YKUN AKHER LINE b3d kol el set variable
#-----------------------------------------------------------------------------------------------------------------------
#lab 7 if conditioning 
# 1- if (variavle, string , constatnt , condition , multiple conditions , existence check (command), policy , TARGET, TEST , etc) w el ba'a f el documentaion
# OFF 0 NO FALSE N "NOTFOUND" "IGNORE" ---> False  .. from documentation
if(DEBUG)  #DEBUG d built in variable ha3mlo assign wana b cmake cmake -DDEBUG=1
   set(DEBUGINFO "Author Rahma Abdelhamid")
endif()

# if (NOT DEBUG) !
# if (var AND var2)
# if (var OR var2)
# if (myval MATCHES regularexpression )
#if (EXIST file)
#if (var LESS var2)
#if (var GREATER var2)
#if (var EQUAL var2)
#if (TARGET wifi_lib)  --> TARGET d l ay haga tal3a mn ay function mn dol --> add_executable 
#, add_ibrary , add_custom_target  ---> btb'a 3bara 3n target w lazem ttktb Capital case

if (TARGET wifi_lib)
    message(STATUS "wifi is availabe")
else()
    message(FATAL_ERROR "wifi isn't available")  # lw shelt el line d wa'atha haydrb error target_link_libraries(hellobinary PUBLIC wifi_lib) W D add_subdirectory(${CMAKE_SOURCE_DIR}/lib)
endif()
configure_file(defaultconfig.h.in defaultconfig.h)  # LAZEM D YKUN AKHER LINE b3d kol el set variable

#2- foreach (var IN LISTS , ITEMS)
#iTEMS ---> d bktb el items gowa el for 
#lkm el LISTS --> d lazet a set variable el awl b el list w beden a3wed beh f el foreach    
set (lst A B D E L H A M I D)
foreach(F IN ITEMS R A H M A)
    message(STATUS ${F})
endforeach()

foreach(var IN LISTS lst)
    message(STATUS ${var})
endforeach()
#---------------------------------------------------------------------------------------------------------------------
#lab 8
#3- while loop 
set (VAR 10)
while(VAR)
    message(STATUS ${VAR})
    math(EXPR VAR "${VAR} -  1")  # d function btakhud 1 arg command esmu EXPR w d mawgud zyo f el bash 
    #w b3den var y assign feh w b3do el equation elly 3awza ahsbha 
endwhile()

#4- functions  f el cmake hya basita mfihash ay return wala haga 
#mhtag a search 3la haga esmha el PARENT_SCOPE lhad m yshrha 
function(HappyNewYear arg1 ) # keyword function(function_name  arg1 arg2 arg3 )
    message("ARG1 ${arg1}")  #NAME OF VARIABLE --> haytb3 esm el var nfso elly hwa var bs lw ba3t constant haytb3o hwa 
    message("ARG1 ${${arg1}}") # show values of list  -> haytb3 elly gowa el var 
    message("ARG2 ${ARGN}") #extra argument  -> f halet lw el user b3t argument tani wahed aw kaza wahed 3adi
    message("ARG1 ${ARGC}") #count ---> 3dd el argument elly el user ba3tha 
endfunction() 

set(var 2024)
HappyNewYear(var jan feb)  #b3mlha cal b esmha w 3adi tba'a el function mt3rfa nha btakhud arg wahed wana ab3tlha etnen
HappyNewYear(33 jan) 

#5- CMake Cache 
# hwa ni leh f awl mara kunt bhtag aktb cmake -G "Unix Makefiles" .. w b3dha ba'aet bktb cmake .. ?
# d 3chan gowa folder el build by3ml file esmu CMakeCache.txt byshel feh b3d el variabels
# zy el generator , standard , etc momkn aftaho w abos feh 3adi w 3chan kda momkn lw ghirt haga w ast3mlt cmake ygeb error w ytslah lma a remove el files w arge a build b el -G 3chan byrg3 yktb el ma3lomat el gdida mn awl 

#option d bt3rf variable within el cmake f lw khadto w dawrt beh gowa el CMakeCache hla'aeh 3la ekd el set el 3adya mn ghir m adef (CACHE) masln f el var elly esmu SRC_FILES
#3ndi 2 ways 3chan a3rfo f el cache 1- option(variable_name "comment_elly haytktb fo'o" value ),
# 2- astkhdm el set --> set(variable_name value CACHE Data_Type "Comment")
#option(CVar "BOOL Var" TRUE)  
#set(Var2 TRUE CACHE BOOL "bool variable")
message("Cache is ${Var2}")


#---------------------------------------------------------------------------------------------------------------------
#lab 9
# 6- compiler info 
# d haga shabh el defaultconfig.h bs feha kunt b3rf el variable b eidi 3chan y substitue beha 
#tayep lw mch 3awez ttl3li f el file w tba'a haga compile defination y3ni mt3rfa w atb3ha 3adi f el main.cpp 
#mezto ni mch mhatag a generate file header 3chan yakhud el definantion d 
target_compile_definitions(hellobinary PUBLIC "STD_CXX=20")
# d lw 3awzaa adi options ll compiler bta3i --> command compilername --target-help ..> gcc --target-help --> kol el hagat elly hattl3 d  target options 
#zy -march=CPU[ ] w hwa ni 3awza el mcu arch bta3i ykun i386,llom ,opteron masln , aw ahdd el freq bta3 el cpu 
target_compile_options(hellobinary PUBLIC -march=native)  # f na hna haddtlo nu yshtghl 3la el native compiler  elly hya machine arch 

#7-  install   d m3naha copy paste mn mkan l mkan
# b3d m b3ml cmake .. --> make --> cmake --install . -->f hwa y run file mawgud gowa el build folder esmu cmake_install.cmake
#
# d hla'eha kter gdn f codes bta3t el cmake w d elly hwa b3d m bigenerate ka'no by3ml copy 
#3chan ykun 3ndi kol el folder el re'sya gowa el build w a'der akhudhum copy l had tani ykml shoghl 3leh masln 
install(FILES "${PROJECT_BINARY_DIR}/hellobinary"
    DESTINATION "${PROJECT_BINARY_DIR}/executable"
     ) #eawez el file elly hellobinary.exe elly gowa el build wadeh f ff older esmu --> executable gowa el build brdu , el PROJECT_BINARY_DIR y3ni folder el build 

     install(FILES "${CMAKE_SOURCE_DIR}/lib/Wifi.hpp"
     "${CMAKE_SOURCE_DIR}/include/calc.hpp"
    DESTINATION "${PROJECT_BINARY_DIR}/include"
     )  # el path elly feh el cmake CMAKE_SOURCE_DIR adkhul gowa el lib w include  yb'ao f folder esmu include gowa PROJECT_BINARY_DIR elly hwa el build

#------------------------------------------------------------------------------------------------------------------------------------
#lab 10 
# 1- File --->bnstkhdmha 3chan ngeb haga mo3yana mn file aw n replace  ---> FILE ((READ,WRITE, STRINGS,APPEND,ETC ) FILE_NAME assigned variable)
FILE (READ "main.cpp" MAIN_TEXT)  #hna na kda ba'ra file mn el cmake bs hna kda k file bshaklo el 3adi
message("${MAIN_TEXT}")
message( "----------------------------")
FILE (STRINGS "main.cpp" MAIN_TEXT) #hna ba'rah bshakl string f 1 line w d yfedni f ni momkn a3ml 3leh regex expression
message("${MAIN_TEXT}")
message( "----------------------------")
FILE (STRINGS "main.cpp" MAIN_TEXT REGEX "^int.") # hna b3d m sglt el file f variable k string 3mlt 3leh regex exp b ni ay haga btbtdi b int w btnthi l nhayet el line 
message("${MAIN_TEXT}")  # w d momkn astkhdmha lw bdwer gowa file 3la klma mo3yna zy author aw passwaord masln aw service id 
# w momkn brdo mn el cmake yfth excel sheet aw file.txt w ytl3 el authorization key masln 
message( "----------------------------")
file (GLOB_RECURSE SRCS "*.cpp")  # ka'ani ba'lo a3ml recurse(motkarer) 3la (*) ay haga .cpp f el mkan elly na wa'af feh w hutaha f el variable elly esmu SRCS
message("${SRCS}")  # w d haryhni bdl m a3ml set elly fo' w agm3 el src files mch mhtag ashuf kol file mawgud fen 
message( "----------------------------")

#2- strings 
FILE (READ "main.cpp" MAIN_TEXT) #aret el main.cpp f el MAIN_TEXT
STRING(REGEX REPLACE "int" "void" OUT ${MAIN_TEXT}) # STRING d momkn t3ml replace -->
# khidi el REGEX w a3mlili replace ay int --> void w tl3li el output f OUT w el input bta3k MAIN_TEXT
message("${OUT}")
message( "----------------------------")

#3- Macro