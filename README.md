# MTG Collection Manager

As of this moment in time the java portion of this code as not been implemented properly















Compilation Instructions:

Compile and Run Just the c++ backend

Compile the sqlite3

1. gcc -c sqlite3.c

Compile the main program 

2. g++ mtgcmain.cpp sqlite3.o -o test

3. Run test



Java Portion is Currently Malfunctioning
Compile the sqlite3

1. gcc -c sqlite3.c

Compile the mtgcmain into object file

2. g++ -I "C:\Program Files\Java\jdk1.8.0_77\include" -I "C:\Program Files\Java\jdk1.8.0_77\include\win32" -c -o mtgcmain.o mtgcmain.cpp

Combine object files in shared object file

3. g++ -shared -o whateveryouwanttonamethefile.so mtgcmain.o sqlite3.o

Compile all java files in directory

4. javac *.java

Run It

5. java -classpath . Frame.test  

