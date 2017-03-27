#include<iostream>
#include<string>
#include<cstring>
#include<sqlite3.h>
#include<cstdio>
#include<windows.h>
#include<iomanip>
#include<conio.h>

using namespace std;
int plates=0, statue=0, boss=0, temple=0, templetotal=0, mystdoor=0, health=100;
string name="import";
void RuinedTemple();


static int callback(void *NotUsed, int argc, char **argv, char **azColName)
	{
		int i;
		for (i = 0; i<argc; i++) {
			printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		}
		printf("\n");
		return 0;
	}

	void displayGameDatabase()
	{
		sqlite3 *db;
		char *zErrMsg = 0;
		int  rc;
		char *sql;

		/* Open database */
		rc = sqlite3_open("database.db", &db);
		if (rc) {
			fprintf(stderr, "-Can't open database: %s\n", sqlite3_errmsg(db));
		}
		else {
			fprintf(stdout, "-Database ---> database.db ACTIVE\n\n");
		}

		/* Create SQL statement */
		sql = "SELECT * from Inventory;";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "-INFO: %s\n\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else {
			fprintf(stdout, "-Database: Working - Everything saved..\n");
		}
		sqlite3_close(db);
	}

    void CreateGameDatabase()
	{
	 sqlite3 *db;
	char *zErrMsg = 0;
	int  rc;
	char *sql;

	/* Open database */
	rc = sqlite3_open("database.db", &db);
	if (rc) {
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	}
	else {
		fprintf(stdout, "Database Opened Successfully\n");
	}

	/* Create SQL statement */
	sql = "CREATE TABLE Enemy("
		"ID INT PRIMARY        KEY      NOT NULL," \
		"NAME            TEXT     NOT NULL," \
		"COLOUR          TEXT     NOT NULL);" \
		

	/* Execute SQL statement */
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if (rc != SQLITE_OK) {
		fprintf(stderr, "INFO: %s\nIGNORE Existing Table - just for checking.\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else {
		fprintf(stdout, "Table created successfully.\n");
	}
	sqlite3_close(db);

	}

	void addNeckToDB()
	{
		sqlite3 *db;
		char *zErrMsg = 0;
		int  rc;
		char *sql;

		/* Open database */
		rc = sqlite3_open("database.db", &db);
		if (rc) {
			fprintf(stderr, "-Can't open database: %s\n", sqlite3_errmsg(db));
		}
		else {
			fprintf(stdout, "-Opened database successfully\n");
		}

		/* Create SQL statement */
		sql = "INSERT INTO Inventory (ID, NAME, COLOUR, QUANTITY) " \
			"VALUES (1, 'Necklace', 'Blue', 1);";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "-INFO: %s\n\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else {
			fprintf(stdout, "-Necklace added successfully.\n");
			cout << rc;

		}
		sqlite3_close(db);
	}

void resetDB()
	{
		sqlite3 *db;
		char *zErrMsg = 0;
		int  rc;
		char *sql;

		/* Open database */
		rc = sqlite3_open("database.db", &db);
		if (rc) {
			fprintf(stderr, "-Can't open database: %s\n", sqlite3_errmsg(db));
		}
		else {
			fprintf(stdout, "-DATABASE: OPENED - OK --- RESETING ALL VALUES\n");
		}

		/* Create SQL statement */
		sql = "DELETE FROM Inventory;";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "-INFO: %s\nIGNORE Existing Table - just for checking.\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else {
			fprintf(stdout, "-Database has been reseted successfully.\n");
		}
		sqlite3_close(db);
	}


void addFurToDB()
	{
		sqlite3 *db;
		char *zErrMsg = 0;
		int  rc;
		char *sql;

		/* Open database */
		rc = sqlite3_open("database.db", &db);
		if (rc) {
			fprintf(stderr, "-Can't open database: %s\n", sqlite3_errmsg(db));
		}
		else {
			fprintf(stdout, "-Opened database successfully\n");
		}

		/* Create SQL statement */
		sql = "INSERT INTO Inventory (ID, NAME, COLOUR, QUANTITY) " \
			"VALUES (2, 'Fur', 'Grey', 1);";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "-INFO: %s\n\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else {
			fprintf(stdout, "-Fur added successfully.\n");
			cout << rc;

		}
		sqlite3_close(db);
	}
void addHoofToDb():
    {
		sqlite3 *db;
		char *zErrMsg = 0;
		int  rc;
		char *sql;

		/* Open database */
		rc = sqlite3_open("database.db", &db);
		if (rc) {
			fprintf(stderr, "-Can't open database: %s\n", sqlite3_errmsg(db));
		}
		else {
			fprintf(stdout, "-Opened database successfully\n");
		}

		/* Create SQL statement */
		sql = "INSERT INTO Inventory (ID, NAME, COLOUR, QUANTITY) " \
			"VALUES (3, 'Hoof', 'Yellow', 1);";

		/* Execute SQL statement */
		rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
		if (rc != SQLITE_OK) {
			fprintf(stderr, "-INFO: %s\n\n", zErrMsg);
			sqlite3_free(zErrMsg);
		}
		else {
			fprintf(stdout, "-Fur added successfully.\n");
			cout << rc;

		}
		sqlite3_close(db);
	}


int trychoice(int maxchoices, string options)
{
    int choice;
    cout<<options<<endl;
    cout<<"\nEnter selection:"; cin>>choice;

    while(choice>=maxchoices+1 || choice<=0)
    {
        cout<<"That's not an option!";
        choice=trychoice(maxchoices, options);
    }
    return choice;
}
void Swamp()
{   int choice;
    if(temple==0)
    {
        cout<<"As you enter the muddy swamp you notice that it is very large, it seems going around a mountain of some sorts and it stretches further to the North, more than you would’ve hoped it to. About 100 meters further from the entrance there is a Temple in ruins, it seems very old, like no one has entered it for thousands of years, you’re not sure if you should go in there, maybe you’re disturbing a sacred place. About  50 meters to the right of the Temple there is a bush of thorny, green vines that have grown on them some beautiful pink flowers, they’re like nothing you’ve ever seen before, you feel like you have to hold at least one in your hands."<<endl;
        string options="Options:\n1.Investigate ruined temple.\n2.Go further north through the muddy swamp.\n3.Leave Swamp.";
        choice=trychoice(3,options);
    }
    else if(temple==1)
    {
        temple=0;

        if(templetotal==1)
        {
            cout<<"You finally decided to leave the teample. Honestly, I think it is for the best, that place was really unsettling.\nYou leave the same way to came in, thorugh the front door, as you enter the long hallway that you entered through you start seeing the light at the end, you move step by step towards it until you're finally outside, in the muddy swamp, at least you can breath some fresh air and feel the sun. It's way better to be outside exploring, than inside of that dusty old temple, what could even be in there? some stupid caveman drawings on the walls?"<<endl;
        }
        else if(templetotal>=2)
        {
            cout<<"You've returned to the muddy swamp."<<endl;
        }

        string options="Options:\n1.Investigate ruined temple again.\n2.Go further north through the muddy swamp.\n3.Leave Swamp.\n";
        choice=trychoice(3,options);
    }

    if(choice==2)
    {
        cout<<"Coming soon..."<<endl;
    }
    else if(choice==3)
    {
        cout<<"Someone else's part of the game."<<endl;
    }
    else if(choice==1)
    {
        RuinedTemple();
    }
}
void RuinedTemple()
{
    if(temple==0)
    {   templetotal+=1;
        if(templetotal==1)
        {
            cout<<"I honestly can't understand why you insist so much on going in this cursed place, but if you are so eager to die, fine, i'm not gonna interfere anymore."<<endl;
        }
        else if(templetotal>=2)
        {
            cout<<"You've enetered the ruined temple."<<endl;
        }
        else if(templetotal==0)
        {
            cout<<"Making the first steps inside the temple, you feel a chill go down your spine, you can hear pebbles falling down from the giant roof made of stone, you smell the old dust that’s been gathering there for a very long time. The walls have a lot of cracks in them and the light barely passes through, in such a way for you to see where you’re stepping, the only thing you know so far is that the further you venture into this place, greater is the urge to go back into the light, shinning from the door you left behind. You got to a big opening where, in the middle, there is a giant statue and a lot of fallen pillars,  you’re wondering how is it that the whole thing didn’t collapse already with so few pillars sustaining the enormous roof. As you look around, you observe some kind of lines and circles on the ground surounding a statue, the lines are connecting the circles to the statue, and inside the circles are some kind of golden plates."<<endl;
        }

        temple=1;
    }

    if(statue==0 && plates==0)
    {
        string options="Options:\n1.Investigate the statue.\n2.Check the strange drawings on the floor that connect the statue with the golden plates.\n3.Investigate the golden plates, hopefully they are indeed made of gold and you can get some money.\n4.Keep roaming around, maybe there’s something you’re not seeing, or maybe there isn’t, but you can’t be sure, can you?\n5.Leave Temple\n";
        int choice=trychoice(5,options);

        if(choice==1)
        {
            statue=1;
            cout<<"As you approach the statue you start to feel a warmth, like the sun is shining upon your skin, which seems a little strange since you’re wearing clothes and it feels like the sun is warming you everywhere, and I mean everywhere, apart from the fact that you are in a dark room, inside a temple, made of stone and there is no sunlight… Even though you feel like you’re going crazy you make it to the statue and put your hand on it’s pedestal, as your hand touches the pedestal you feel bombarded with sunlight,  and the grass tickling your bare feet, you find yourself naked in that strange place, with your hand on the bark of a tree. You close your eyes and take your hand off of the tree, as you open them you notice that you are back in the temple, but now there is a giant ball of fire right above the statue’s head that lights the whole room. You take some steps back and look at the statue, which seems to be praising the sun, standing tall on two feet, with it’s both arms raised at a 45 degree angle of it’s head, with a giant ball of fire between it’s arms, right above it’s head."<<endl;
            RuinedTemple();
        }
        else if(choice==2)
        {
            cout<<"You get down and put your face against the floor, looking how the line, that you have your face on, stretches like a road, connecting the plate behind you to the statue that's right in front of you. Besides the strange pattern the drawings have, there's nothing special to them, it looks like some yellow paint with a lot of layers of dust on top."<<endl;
            RuinedTemple();
        }
        else if(choice==3)
        {
            cout<<"There are 3 golden plates around the statue, each of them inside their own yellow circle, one of them is behind the statue, slightly to the right, the other 2 are in front of the statue, the one closer to the statue between the two, is right in front of it about 5 cm to the left, and the other one is slightly further away from the statue and much more to the left. They seem to make some kind of pattern, the one behind being connected to the statue directly and the one right in front of it too, only the one that's further away is connected to the next golden plate instead of the statue directly. As you inspect the closest golden plate to you, you see something engraved right in the middle of it, something is written there: ??????? ?????? ?? ????????. You go to check the other plates as well to see if there's anything written on them as well, and the moment you clean the dust away from the next plate you see there is something written on it too: ????? ?????? ?? ????????, last you check the plate behind the statue, and on this one it's engraved: ???????. What could it mean you wonder, maybe it means something..."<<endl;
            RuinedTemple();
        }
        else if(choice==4)
        {
            cout<<"'Who cares about strange statues or golden plates, there has to be something better in this place' you thought to yourself as you wondered, step by step, into the darkness. Strangely, you barely went 5 steps into that soul-consuming darkness and already hit a wall, with your face, hard! As you're falling on your ass you notice a strange light flashing around you, like a firefly with super-speed, like 'Flashy Gonzales' carrying a torch, like a laser beam fired at you by a Hurricanetrooper, you get the idea. As you open your eyes and look in front of you, there's a giant door with 5 slots in it, one after another, arranged horizontally, and all around you there are some stone cubes with letters engraved on them, they seem to fit perfectly into the sockets on the door. Ah! and there's light now, no idea where it is coming from but who cares, you can see. Maybe your head is a light bulb and your butt is the switch..."<<endl;
            RuinedTemple();
        }
        else if(choice==5)
        {
            Swamp();
        }
    }

    else if(statue==1 && plates==0)
    {
        string options="Options:\n1.Touch statue again.\n2.Check the strange drawings on the floor that connect the statue with the golden plates.\n3.Investigate the golden plates, hopefully they are indeed made of gold and you can get some money.\n4.Keep roaming around, maybe there’s something you’re not seeing, or maybe there isn’t, but you can’t be sure, can you?\n5.Leave Temple";
        int choice=trychoice(5,options);

        if(choice==1)
        {
            cout<<"This time when you approach the pedestal you don’t feel that warming light all over your body, just a little coming from the giant ball of fire above, but nevertheless, you put your hand on it and find yourself back to that field."<<endl;
            RuinedTemple();
        }
        else if(choice==2)
        {
            cout<<"You get down and put your face against the floor, looking how the line, that you have your face on, stretches like a road, connecting the plate behind you to the statue that's right in front of you. Besides the strange pattern the drawings have, there's nothing special to them, it looks like some yellow paint with a lot of layers of dust on top."<<endl;
            RuinedTemple();
        }
        else if(choice==3)
        {
            cout<<"There are 3 golden plates around the statue, each of them inside their own yellow circle, one of them is behind the statue, slightly to the right, the other 2 are in front of the statue, the one closer to the statue between the two, is right in front of it about 5 cm to the left, and the other one is slightly further away from the statue and much more to the left. They seem to make some kind of pattern, the one behind being connected to the statue directly and the one right in front of it too, only the one that's further away is connected to the next golden plate instead of the statue directly. As you inspect the closest golden plate to you, you see something engraved right in the middle of it, something is written there: ??????? ?????? ?? ????????. You go to check the other plates as well to see if there's anything written on them as well, and the moment you clean the dust away from the next plate you see there is something written on it too: ????? ?????? ?? ????????, last you check the plate behind the statue, and on this one it's engraved: ???????. What could it mean you wonder, maybe it means something..."<<endl;
            RuinedTemple();
        }
        else if(choice==4)
        {
            cout<<"'Who cares about strange statues or golden plates, there has to be something better in this place' you thought to yourself as you wondered, step by step, into the darkness. Strangely, you barely went 5 steps into that soul-consuming darkness and already hit a wall, with your face, hard! As you're falling on your ass you notice a strange light flashing around you, like a firefly with super-speed, like 'Flashy Gonzales' carrying a torch, like a laser beam fired at you by a Hurricanetrooper, you get the idea. As you open your eyes and look in front of you, there's a giant door with 5 slots in it, one after another, arranged horizontally, and all around you there are some stone cubes with letters engraved on them, they seem to fit perfectly into the sockets on the door. Ah! and there's light now, no idea where it is coming from but who cares, you can see. Maybe your head is a light bulb and your butt is the switch..."<<endl;
            RuinedTemple();
        }
        else if(choice==5)
        {
            Swamp();
        }
    }

    else if(statue==0 && plates==1)
    {
        string options="Options:\n1.Investigate Statue.\n2.Check the strange drawings on the floor that connect the statue with the golden plates.\n3.Keep roaming around, maybe there’s something you’re not seeing, or maybe there isn’t, but you can’t be sure, can you?\n4.Leave Temple";
        int choice=trychoice(4,options);

        if(choice==1)
        {
            cout<<"As you approach the statue you start to feel a warmth, like the sun is shining upon your skin, which seems a little strange since you’re wearing clothes and it feels like the sun is warming you everywhere, and I mean everywhere, apart from the fact that you are in a dark room, inside a temple, made of stone and there is no sunlight… Even though you feel like you’re going crazy you make it to the statue and put your hand on it’s pedestal, as your hand touches the pedestal you feel bombarded with sunlight,  and the grass tickling your bare feet, you find yourself naked in that strange place, with your hand on the bark of a tree. You close your eyes and take your hand off of the tree, as you open them you notice that you are back in the temple, but now there is a giant ball of fire right above the statue’s head that lights the whole room. You take some steps back and look at the statue, which seems to be praising the sun, standing tall on two feet, with it’s both arms raised at a 45 degree angle of it’s head, with a giant ball of fire between it’s arms, right above it’s head."<<endl;
            RuinedTemple();
        }
        else if(choice==2)
        {
            cout<<"You get down next to one of the lines and extend your arm to touch it, you're lost in thought as you gaze your sight upon the golden line, the way it glows makes it seem like it's alive, like the fluctuations of it's glow is it's breathing, but you lose all this train of thoughts the moment you lay your hand on the line because it feels like you've just touched the sun, and no, i do not mean it as some profound and divine experience, i mean it as in you've just burned your fingers in such a manner that you can see the bones surounded by your black, burnt flesh. You quickly withdraw your hand and get up, you're bat shit scared you just lost three of your fingers and it hurts like hell, what the hell is wrong with whoever made this temple you wonder, why the obsesion with fire and gold? why couldn't they just put their valuables in a nice chest in a dark cave like a normal person? Why all these puzzles, what do the developers of the game think you are, a 4 years old with too much time in your hands?"<<endl;
            RuinedTemple();
        }
        else if(choice==3)
        {
            cout<<"'Who cares about strange statues or golden plates, there has to be somethiong better in this place' you thought to yourself as you wondered, step by step, into the darkness. Strangely, you barely went 5 steps into that soul-consuming darkness and already hit a wall, with your face, hard! As you're falling on your ass you notice a strange light flashing around you, like a firefly with super-speed, like 'Flashy Gonzales' carrying a torch, like a laser beam fired at you by a Hurricanetrooper, you get the idea. As you open your eyes and look in front of you, there's a giant door with 5 slots in it, one after another, arranged horizontally, and all around you there are some stone cubes with letters engraved on them, they seem to fit perfectly into the sockets on the door. Ah! and there's light now, no idea where it is coming from but who cares, you can see. Maybe your head is a light bulb and your butt is the switch..."<<endl;
            RuinedTemple();
        }
        else if(choice==4)
        {
            Swamp();
        }
    }

    else if(statue==1 && plates==1)
    {
        string options="Options:\n1.Touch statue again.\n2.Check the strange drawings on the floor that connect the statue with the golden plates.\n3.Keep roaming around, maybe there’s something you’re not seeing, or maybe there isn’t, but you can’t be sure, can you?\n4.Leave Temple";
        int choice=trychoice(4,options);

        if(choice==1)
        {
            cout<<"This time when you approach the pedestal you don’t feel that warming light all over your body, just a little coming from the giant ball of fire above, but nevertheless, you put your hand on it and find yourself back to that field."<<endl;
            RuinedTemple();
        }
        else if(choice==2)
        {
            cout<<"You get down next to one of the lines and extend your arm to touch it, you're lost in thought as you gaze your sight upon the golden line, the way it glows makes it seem like it's alive, like the fluctuations of it's glow is it's breathing, but you lose all this train of thoughts the moment you lay your hand on the line because it feels like you've just touched the sun, and no, i do not mean it as some profound and divine experience, i mean it as in you've just burned your fingers in such a manner that you can see the bones surrounded by your black, burnt flesh. You quickly withdraw your hand and get up, you're bat shit scared you just lost three of your fingers and it hurts like hell, what the hell is wrong with whoever made this temple you wonder, why the obsession with fire and gold? why couldn't they just put their valuables in a nice chest in a dark cave like a normal person? Why all these puzzles, what do the developers of the game think you are, a 4 years old with too much time in your hands?"<<endl;
            RuinedTemple();
        }
        else if(choice==3)
        {
            cout<<"'Who cares about strange statues or golden plates, there has to be something better in this place' you thought to yourself as you wondered, step by step, into the darkness. Strangely, you barely went 5 steps into that soul-consuming darkness and already hit a wall, with your face, hard! As you're falling on your ass you notice a strange light flashing around you, like a firefly with super-speed, like 'Flashy Gonzales' carrying a torch, like a laser beam fired at you by a Hurricanetrooper, you get the idea. As you open your eyes and look in front of you, there's a giant door with 5 slots in it, one after another, arranged horizontally, and all around you there are some stone cubes with letters engraved on them, they seem to fit perfectly into the sockets on the door. Ah! and there's light now, no idea where it is coming from but who cares, you can see. Maybe your head is a light bulb and your butt is the switch..."<<endl;
            RuinedTemple();
        }
        else if(choice==4)
        {
            Swamp();
        }
    }
}
int main()
{
    Swamp();
    return 0;
}
