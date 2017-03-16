There is no need to meet up. Dungeons is now in the joined up version of the game, all codes
went through changes to make it work. THE FILE USED FOR DUNGEONS IS "dungeons.cpp".

To compile your code together with the one alredy here do the following:

Add #include "header.h" at the top of your code and replace the main function of your code 
with a diferent name and add that name to the "header.h" file.
If you give the funtion the name "example()", add it to the "header.h" file as int example().

RUN THE COMMAND:
g++ --std=c++11 main.cpp cloudland.cpp clearings.cpp dungeons.cpp [ADD OTHER FILES HERE] -o [NAME OF TH GAME FILE] -l sqlite3

P.S. Clearings and cloudland, the ones in this folder, already work. The database is not being used though.
