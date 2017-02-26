# ppl-assignment-pr-s18
ppl-assignment-pr-s18 created by GitHub Classroom
# Made by Priyanka Singla (IIT2015504)
# To create library file (504_lib.a) execute these commands
g++ -c boy.cpp;
g++ -c couple.cpp
g++ -c generate_boy.cpp
g++ -c generate_gift.cpp
g++ -c generate_girl.cpp
g++ -c girl.cpp
g++ -c make_pair.cpp
ar rvs 504_lib.a boy.o couple.o generate_boy.o generate_gift.o generate_girl.o girl.o make_pair.o

# Steps to Execute 
## Generate Random inputs
g++ generate_boy.cpp
./a.out
g++ generate_girl.cpp
./a.out
g++ generate_gift.cpp
./a.out

## To run Question 1
g++ 1.cpp 504_lib.a
./a.out

## To run Question 2
g++ 2.cpp 504_lib.a
./a.out
Take Input

## To view All couples
Open couples.txt

## To view K Happiest Couples and K Compatible Couples
Open Happiness_compatibility_gift.txt

## To view Documentation in html format
doc/html/index.html

## To view Documentation in pdf format
PPL_documentation.pdf

