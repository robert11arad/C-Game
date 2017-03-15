#include <iostream>
#include <vector>
#include <string>
#include <sqlite3.h> // includes sqlite3 library
#include <memory> // defines general utilities to manage dynamic memory
using namespace std;
#include "header.h" // includes headers of the game

// Function Declaration
int rooftop(); 
int shadow(); 
int save(string inp, string function);
int database(string operation, string object);
int load(string name);
int saves();
// object declaration
string saveName;
int gameScore = 0;
int savedGames = 0;

// Story Code
int out(string value){
    gameScore = gameScore + 100;
    if(value == "dead"){
        gameScore = gameScore - 100;
		// User dies
        cout << "You Died" << endl;
        save(saveName, "|_F1N1SHED_|");
    }
    else if(value == "transport"){
        // Gets transported 
        cout << "You got teleported to the clearings." << endl;
        return clearings();
        save(saveName, "|_F1N1SHED_|");
    }
    else if(value == "leaveR"){
        // Leaves cloudland 
        cout << "You leave cloudland to ... r" << endl;
        // return 0; add new section here
        save(saveName, "|_F1N1SHED_|");
    }
    else if(value == "leaveH"){
        gameScore = gameScore + 300;
        // Leaves cloudland 
        cout << "You leave cloudland to ... h" << endl;
        // return 1; add nre section here
        save(saveName, "|_F1N1SHED_|");
    }
    else if (value == "fight"){
        if(database("select", "golden_sword") == 1){
                cout << "You win the fight" << endl;
                gameScore = gameScore + 500;
                return out("transport");
            }
        else{
            return out("dead");
        }
    }
    return 0;
}

int house2(){
    save(saveName, "house2");
    gameScore = gameScore + 250;
    cout << "As you seat on a chair you notice text on a wall, you "
                "can’t read it. You ask the old man what was written on "
                "it, he says he doesn’t know."<< endl;

    string option; // Defines option value type
    getline(cin,option); // Gets user input

    if(option == "sleep"){
        cout << "As you fall asleep the old man attacks you and kills you." << endl;
        return out("dead");
    }
    else if(option == "attack"){
        cout << "You attack the old man, after killing him the wind stops, "
                "you go out and head towards the hole when you reach it you "
                "see a ladder and leave the cloudland." << endl;
        return out("leaveH");
    }    
    else if(option == "threaten"){
        cout << "You demand an answer, the old man tries to stab you but you "
                "are stronger and fight back, after killing him the wind stops, "
                "you go out and head towards the hole when you reach it you see "
                "a ladder and leave the cloudland." << endl;
        return out("leaveH");
    }
    else{
        cout << "Not valid" << endl;
        return house2();
    }
}

int house(){
    save(saveName, "house");
    gameScore = gameScore + 250;
    if(database("select", "precious_necklace") == 1){
        cout << "As you get closer to the hole the wind gets "
            "stronger and you can’t move back anymore. The wind starts "
            "pulling you towards the hole, you see a hut and take cover "
            "on it. As you enter the hut you find and old man, he says "
            "he’s been there for decades waiting for the windstorm end." << endl;
    }
    else{
        cout << "As you get closer to the hole the wind gets "
            "stronger and you can’t move back anymore. The wind starts "
            "pulling you towards the hole, you see a hut and take cover "
            "on it. As you enter the hut you find and old man, he says "
            "he’s been there for decades waiting for the windstorm end, "
            "you also notice a precious necklace." << endl;
    }
    string option; // Defines option value type
    getline(cin,option); // Gets user input

    if(option == "wait"){
        return house2();
    }
    else if(option == "attack"){
        cout << "Attack the old man- You attack the old man, after killing "
                "him the wind stops, you go out and head towards the hole "
                "when you reach it you see a ladder and leave the cloudland." << endl;
        return out("leaveH");
    }
    else if(option == "go out"){
        cout << "As you leave the hut you get pulled towards the "
                "hole and fall." << endl;
        return out("dead");
    }    
    else if(option == "get necklace"){
        gameScore = gameScore + 1000;
        database("update", "precious_necklace");
        save(saveName, "house");
        return house();
    }  
    else{
        cout << "Not valid" << endl;
        return house();
    }
}

int shadow(){
    save(saveName, "shadow");
    gameScore = gameScore + 250;
    cout << "As you get closer to the shadow a horrifying noise gets louder, "
            "the shadow start moving." << endl;
	
    string option; // Defines option value type
	getline(cin, option); // Gets user input

    if (option == "fight"){
        return out("fight");
    }
    else if (option == "run"){
        return rooftop();
    }
    else{
        cout << "Not valid" << endl;
        return shadow();
    }
}

int rooftop(){
    save(saveName, "rooftop");
    gameScore = gameScore + 250;
    cout << "You reach the rooftop and see a ladder, the human "
                "shadow east and the thunderstorm west." << endl;
    
    string option; // Defines option value type
	getline(cin, option); // Gets user input

    if(option == "go east"){
        return shadow();
    }
    else if (option == "use ladder"){
        cout << "You leave cloudland." << endl;
        return out("leave");
    }
    else if (option == "go west"){
        cout << "As you head towards the thunderstorm you get pulled "
                "by a wormhole that takes you to a different place." << endl;
        return out("transport");
    }
    else{
        cout << "Not valid" << endl;
        return rooftop();
    }
}

int sun (){
    save(saveName, "sun");
    gameScore = gameScore + 250;
	// Identifies if a object is inside the objects vector
    if(database("select", "golden_sword") == 1){
        cout << "As you reach the sun ray you see a "
                "shadow east, a rooftop north and a "
                "thunderstorm west." << endl;
    }
    else{
       cout << "As you reach the sun ray you see a golden sword, "
                "a shadow east, a rooftop north and a "
                "thunderstorm west." << endl;
    }
    string option; // Defines option value type
	getline(cin, option); // Gets user input
    
    if (option == "go north"){
        return rooftop();
    }
    else if (option == "go east"){
        return shadow();
    }
    else if (option == "go west"){
        cout << "As you head towards the thunderstorm you get pulled by "
                "a wormhole that takes you to a different place." << endl;
        return out("transport");
    }
    else if (option == "get sword"){
        gameScore = gameScore + 1000;
        database("update", "golden_sword");
        save(saveName, "sun");
        return sun();
    }
    else{
        cout << "Not valid" << endl;
        return sun();
    }
}

int game (){
    save(saveName, "game");
    gameScore = gameScore + 250;
     // Identifies if a object is inside the objects vector
    if(database("select", "flying_boots") == 1) {
        cout << "You fall on a cloud, look around and see a sun ray north, "
	        "a hole in the clouds south and a human shadow east." << endl;
    }
    else{
       cout << "You fall on a cloud, look around and see the legendary "
                "Flying Boots, a sun ray north, a hole in the clouds "
                "south and a human shadow east." << endl;
    }    
    string option; // Defines option value type
	getline(cin, option); // Gets user input
    
    if (option == "go north"){
        return sun();
    }
    else if (option == "get boots"){
        gameScore = gameScore + 1000;
        database("update", "flying_boots");
        save(saveName, "game");
        return game();
    }
    else if (option == "go east"){
        return shadow();
    }
    else if (option == "go south"){
        return house();
    }
    else{
        cout << "Not valid" << endl;
        return game();
    } 
}

// Main Function Controls Game Launch  
int cloudland(){
    return game();
}
/* This code is only used in the standalone version
int main(){
    cout << "Do you want to continue a saved game? ";    
    string ans;
    getline(cin, ans);
    
    if(ans == "yes"){
        saves();
        // Cheking availability of saved games
        if(savedGames > 0){
            cout << "Which one? ";
            string ans2;
            getline(cin, ans2);
            saveName = ans2;
            load(ans2);
            return 0;
        }
        else{
            cout << "No saved games." << endl;
            database("new", "flying_boots");
            database("new", "golden_sword");
            database("new", "precious_necklace");
            cout << "Give new game a name. ";
            string name;
            getline(cin, name);
            saveName = name;
            save(name, "NULL");
            return 0;
        }
    }
    else{
        database("new", "flying_boots");
        database("new", "golden_sword");
        database("new", "precious_necklace");
        cout << "Give new game a name. ";
        string name;
        getline(cin, name);
        saveName = name;
        save(name, "NULL");
        return 0;
    }
}*/
// Grants access to database.
int database(string operation, string object){ 
    int inInv = 1;
    int notIn = 0;
    sqlite3_stmt* s;
    sqlite3* db;
    const char* tail;
    
    if(operation == "select"){
        int rc = sqlite3_open("cloudland.db", &db);
        string sql = "SELECT state FROM inventory WHERE object = ?";
        rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
        rc = sqlite3_bind_text(s , 1, object.c_str(), object.length(), SQLITE_STATIC);
        rc = sqlite3_step(s);
        int state = sqlite3_column_int(s, 0);
        sqlite3_reset(s);
        sqlite3_close(db); 
        return state;
        }
    else if(operation == "new"){
        int rc = sqlite3_open("cloudland.db", &db);
        string sql = "UPDATE inventory SET state = ? WHERE object = ?";
        rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
        rc = sqlite3_bind_int(s , 1, notIn);
        rc = sqlite3_bind_text(s , 2, object.c_str(), object.length(), SQLITE_STATIC);
        rc = sqlite3_step(s);
        sqlite3_reset(s);
        sqlite3_close(db);
        return notIn;
    }
    else if(operation == "update"){
        int rc = sqlite3_open("cloudland.db", &db);
        string sql = "UPDATE inventory SET state = ? WHERE object = ?";
        rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
        rc = sqlite3_bind_int(s , 1, inInv);
        rc = sqlite3_bind_text(s , 2, object.c_str(), object.length(), SQLITE_STATIC);
        rc = sqlite3_step(s);
        sqlite3_reset(s);
        sqlite3_close(db);
        return inInv;
    }
}

int saves(){
    sqlite3_stmt* s;
    sqlite3* db;
    const char* tail;
    int rc = sqlite3_open("cloudland.db", &db);
    string sql = "SELECT count(*) FROM save";
    rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
    rc = sqlite3_step(s);
    int num = sqlite3_column_int(s, 0); 
    sqlite3_reset(s);
    sql = "SELECT name FROM save";
    rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
    while(num > 0){
            // prints unfinished games names
            rc = sqlite3_step(s);
            string func = (char*) sqlite3_column_text(s, 0);
            if(func != "|_F1N1SHED_|" & func != "no_name"){
                cout << func << endl;
                savedGames = savedGames + 1;
            }
            num = num -1;
        }
    sqlite3_reset(s);
    sqlite3_close(db);
    return 0;
}

int load(string name){
    // loads game
    sqlite3_stmt* s;
    sqlite3* db;
    const char* tail;
    int rc = sqlite3_open("cloudland.db", &db);
    string sql = "SELECT function FROM save WHERE name = ?";
    rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
    rc = sqlite3_bind_text(s , 1, name.c_str(), name.length(), SQLITE_STATIC);
    rc = sqlite3_step(s);
    string func = (char*) sqlite3_column_text(s, 0);
    sqlite3_reset(s);
    sql = "SELECT score FROM save WHERE name = ?";
    rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
    rc = sqlite3_bind_text(s , 1, name.c_str(), name.length(), SQLITE_STATIC);
    rc = sqlite3_step(s);
    gameScore = sqlite3_column_int(s, 0);
    sqlite3_reset(s);
    sqlite3_close(db);
    if(func == "house2"){
        return house2();
    }
    else if(func == "house"){
        return house();
    }
    else if(func == "shadow"){
        return shadow();
    }
    else if(func == "rooftop"){
        return rooftop();
    }
    else if(func == "sun"){
        return sun();
    }
    else if(func == "game"){
        return game();
    }
}

int save(string inp, string function){
    sqlite3_stmt* s;
    sqlite3* db;
    const char* tail;
    int rc = sqlite3_open("cloudland.db", &db);
    string sql = "SELECT id FROM save WHERE name = ?";
    rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
    rc = sqlite3_bind_text(s , 1, inp.c_str(), inp.length(), SQLITE_STATIC);
    rc = sqlite3_step(s);
    int iD = sqlite3_column_int(s, 0);
    sqlite3_reset(s);
    sqlite3_close(db);
    
    // creates new save
    if (function == "NULL"){
        if(iD == 0){
            int rc = sqlite3_open("cloudland.db", &db);
            sql = "SELECT count(*) FROM save";
            rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
            rc = sqlite3_step(s);
            int newID = sqlite3_column_int(s, 0);
            sqlite3_reset(s);
            sqlite3_close(db);
            rc = sqlite3_open("cloudland.db", &db);
            sql = "INSERT INTO 'save' (id, name, score, function) VALUES(?, ?, 0, 'game')";
            rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
            rc = sqlite3_bind_int(s, 1, newID);
            rc = sqlite3_bind_text(s , 2, inp.c_str(), inp.length(), SQLITE_STATIC); 
            rc = sqlite3_step(s);
            sqlite3_reset(s);
            sqlite3_close(db);
            return game();
        }
        // alows alredy created save to be overwriten
        else{
            cout << "Save already exists. Do you want to overwrite it? ";
            string ans;
            getline(cin, ans);
            if(ans == "yes"){
                int rc = sqlite3_open("cloudland.db", &db);
                sql = "SELECT count(*) FROM save";
                rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
                rc = sqlite3_step(s);
                int newID = sqlite3_column_int(s, 0);
                sqlite3_reset(s);
                sql = "UPDATE save SET name = '|_F1N1SHED_|' WHERE name = ?";
                rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
                rc = sqlite3_bind_text(s , 1, inp.c_str(), inp.length(), SQLITE_STATIC);
                rc = sqlite3_step(s);
                sqlite3_reset(s);
                sqlite3_close(db);
                rc = sqlite3_open("cloudland.db", &db);
                sql = "INSERT INTO 'save' (id, name, score, function) VALUES(?, ?, 0, 'game')";
                rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
                rc = sqlite3_bind_int(s, 1, newID);
                rc = sqlite3_bind_text(s , 2, inp.c_str(), inp.length(), SQLITE_STATIC); 
                rc = sqlite3_step(s);
                sqlite3_reset(s);
                sqlite3_close(db);

                return game();
            }
            else{
                sqlite3_close(db);
                return 0;
            }
        }    
    }
    // defines finished game 
    else if(function == "|_F1N1SHED_|"){
        int rc = sqlite3_open("cloudland.db", &db);
        // Get current highscore
        sql = "SELECT count(*) FROM highscore";
        rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
        rc = sqlite3_step(s);
        sqlite3_reset(s);
        int num = sqlite3_column_int(s, 0); 
        int currHS = 0;
        sql = "SELECT score FROM highscore";
        rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
        while(num > 0){
            rc = sqlite3_step(s);
            int scr = sqlite3_column_int(s, 0);
            if(scr > currHS){
                currHS = scr;
            }
            num = num -1;
        }
        sqlite3_reset(s);
        // Prints new highscore message
        if(gameScore > currHS){
            cout << "New Highscore" << " " << gameScore << endl;
        }
        // Get current save ID
        sql = "SELECT id FROM save WHERE name = ?";
        rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
        rc = sqlite3_bind_text(s , 2, inp.c_str(), inp.length(), SQLITE_STATIC);
        rc = sqlite3_step(s);
        int hsID = sqlite3_column_int(s, 0);
        sqlite3_reset(s);
        // Set save name to |_F1N1SHED_| and its current score 
        sql = "UPDATE save SET name = '|_F1N1SHED_|', score = ? WHERE name = ?";
        rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
        rc = sqlite3_bind_int(s, 1, gameScore);
        rc = sqlite3_bind_text(s , 2, inp.c_str(), inp.length(), SQLITE_STATIC);
        rc = sqlite3_step(s);
        sqlite3_reset(s);
        // Places save info in highscore table
        sql = "INSERT INTO 'highscore' (id, name, score) VALUES(?, ?, ?);";
        rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
        rc = sqlite3_bind_int(s, 1, hsID);
        rc = sqlite3_bind_text(s , 2, inp.c_str(), inp.length(), SQLITE_STATIC); 
        rc = sqlite3_bind_int(s, 3, gameScore);
        rc = sqlite3_step(s);
        sqlite3_reset(s);
        sqlite3_close(db);
        return 0;
    }
    else{
        // saves game
        int rc = sqlite3_open("cloudland.db", &db);
        sql = "UPDATE save SET function = ?, score = ? WHERE name = ?";
        rc = sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &s, &tail);
        rc = sqlite3_bind_text(s , 1, function.c_str(), function.length(), SQLITE_STATIC);
        rc = sqlite3_bind_int(s, 2, gameScore);
        rc = sqlite3_bind_text(s , 3, inp.c_str(), inp.length(), SQLITE_STATIC);
        rc = sqlite3_step(s);
        sqlite3_reset(s);
        sqlite3_close(db);
        return 0;               
    }    
}
          
