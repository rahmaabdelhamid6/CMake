cmake_minimum_required(VERSION 3.16)  
project(HELLOAPP)
#add_executable(hellobinary main.cpp src/calc.cpp) 

set(SRC_FILES 
    main.cpp 
    src/calc.cpp)  #B ASSIGN VARIALBE w feh set l enviroment variabels brdu w kol d mawgud f el documentation 
#set (ENV {<variable>} [<value>)
# el seprator elly bystkhdmo el set lw grbt atb3 el variabels bykn ( ; ) 
add_executable(hellobinary ${SRC_FILES}) 
#lw 3awez atb3 el SRC_FILES 3chan ata'ked nha sah 
# w el message d bykun leha mode w mawgud f el doc zy warning , send error, Status etc 
message(STATUS "Src Files has ${SRC_FILES}") #STATUS btdef -- f el tab3a w m3naha nha nagha 
# w hna b3rfo nu yinclude m3 el hellobinary bta3i el include folder ay haga gowah f kma yegi y compile el main.cpp hay3rf mkan ek calc.hpp lwahdo 
#zy kda iostream m hwa mch nfs el path d gowa el mingw f f el cmake bta3o mt3rflo d 
target_include_directories(hellobinary PUBLIC include/)  #PUBLIC d accesses permission hankhudha odam 
 # el CMake leha built in variabels kter w b3rfha mn el terminal 3n tariq 1- cmake --help , 
 #haydini options kter akhtar elly 3awez ashufu --> 2- cmake --help-variable-list
 #zy CMAKE_SOURCE_DIR  --> d bydini el path mn el awl ll akher  
 #cmake --help-variable-list | grep -i source .. -i d 3chan y ignore el case senstive 
 #cmake --help-variable variable name .. 3chan yshrhli el var d by3ml eh 
 message(${CMAKE_CURRENT_SOURCE_DIR})
 message(${CMAKE_SOURCE_DIR})

 if(EXISTS ${CMAKE_SOURCE_DIR}/main.cpp)
    message("file exists")
 else()
    message(FATAL_ERROR)
 endif()