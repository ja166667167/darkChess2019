@echo on
g++ -c main.cpp
g++ -c U32.cpp
g++ -c player.cpp
g++ -c move.cpp
g++ -c treeNode.cpp
g++ -c board.cpp
g++ -c ABV1.cpp

g++ main.o U32.o player.o move.o treeNode.o board.o ABV1.o -o main.exe

pause