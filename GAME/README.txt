ADD YOU DATABASE FILES TO THIS FOLDER


To compile your code together with the one alredy here do the following:

Add #include "header.h" at the top of your code and replace the main function of your code with a diferent name and add that name to the "header.h" file.
If you give the funtion the name "example()", add it to the "header.h" file as int example().

RUN THE COMMAND:
g++ --std=c++11 main.cpp cloudland.cpp clearings.cpp [ADD OTHER FILES HERE] -o [NAME OF TH GAME FILE] -l sqlite3
