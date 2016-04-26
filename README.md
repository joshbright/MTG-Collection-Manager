# MTG Collection Manager
Compilation Instructions:

Compile and Run Just the c++ backend

1. Compile the sqlite3

a. Run gcc -c sqlite3.c

2. Compile the main program 

a. Run g++ mtgcmain.cpp sqlite3.o -o test

3. Run test



Java Portion is Currently Malfunctioning
1. Compile the sqlite3

a. Run gcc -c sqlite3.c

2. Compile the mtgcmain into object file

a. g++ -I "C:\Program Files\Java\jdk1.8.0_77\include" -I "C:\Program Files\Java\jdk1.8.0_77\include\win32" -c -o mtgcmain.o mtgcmain.cpp

3. Combine object files in shared object file

a. g++ -shared -o whateveryouwanttonamethefile.so mtgcmain.o sqlite3.o

4. Compile all java files in directory

a. javac *.java

5. Run It

a. java -classpath . Frame.test  

