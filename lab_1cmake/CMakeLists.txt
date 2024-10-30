# hwa el tool elly btgenrate el makefile w mch btnzl m3 el gnu el project na bstbha 3chan hya external tool mbtnzlsh m3 el compiler  
#leha documentation  https://cmake.org  mawgud feha kol el hagat elly hahtgha , https://cmake.org/dowmload w b3d m bnzlha bhtag a3rf d version kam (cmake --version)
# el file bytktyb esmu kda CMakeLists.txt  
#el commands elly haktbha b el cmake btba'a very simple 3n elly bhtag aktbha f el makefile f b3ml el cmake w hwa y genrate el makefile 
cmake_minimum_required(VERSION 3.16)  #Lw el version a'al mn 3.16 edini error 
project(HELLOAPP) #Bdi projectname ll  cmake d 
add_executable(hellobinary main.cpp)  #bdiflo exectubale 3chan yshtghl (executablename sourcefile that depenf on it )
# kda d ex baset b 3 line 3chan y generate el make file .. cmake bytl3 files kter f 3chan a'der atl3 el files d ha3ml directory 
#1- mkdir build ,2- cd build , 3-cmake -G(for genrators) bhes masln nu ya'der ytl3li make file ytl3li build directory a'der aftaho 3la code block aw visula studio 
#4- cmake -G "Unix Makefiles" ..  #-G "Unix Makefiles": Use Unix Makefiles as the generator instead of MinGW Makefiles (since CMake recognizes this generator on Ubuntu)
#5- make --help  6-make //hatl3li el executable elly sameto hellobinary  7-./hellobinary hyrun el main.cpp
#8- lw 3awez amsah elly gowa el build bdkhul gowa .. 1-cd build , 2- del *