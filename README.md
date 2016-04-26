# MTG Collection Manager
Compilation Instructions:

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

