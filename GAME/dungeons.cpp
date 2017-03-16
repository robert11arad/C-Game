#include <iostream>
#include <string>
using namespace std;
#include "header.h"
string command;

int dungeonnine()
{
    cout << "\na glowing key appears in the air\n" << endl;
}

int dungeoneight()
{
     getline (cin,command);
    if (command == "swing at the ork")
    {
        cout << "\nthe Ork is dead!!\n" << endl;
    }    
    else if (command == "raise sheild at ork")
    {
        cout << "\nthe Ork is dead!!\n" << endl;
    }     
    else if (command == "beat ork")
    {
        cout << "\nthe Ork is dead!!\n" << endl;
    }
    return dungeonnine();
}
int dungeonseven()

{
     getline (cin,command);
    if (command == "swing at the ork")
    {
        cout << "\nthe Ork is dead!!\n" << endl;
    }    
    else if (command == "raise sheild at ork")
    {
        cout << "\nthe Ork is dead!!\n" << endl;
    }    
    else if (command == "beat ork")
    {
        cout << "\nthe Ork is dead!!\n" << endl;
    }
    return dungeonnine();
}
    
int dungeonsix()
{
   getline (cin,command);
    if (command == "attack the ork")
    {
        cout << "\nyou fight the Ork\n" << endl;
        return dungeonseven();
    }    
    else if (command == "talk to the ork")
    {
        cout << "\nthe Ork laughs at you and grabs his glowing axe\n" << endl;
        return dungeoneight();
    } 
}

int dungeonfive()
{
    getline (cin,command);
    if (command == "swing at the skeleton")
    {
        cout << "\nthe skeleton crumbles to ash\n" << endl;
    }    
    else if (command == "raise sheild at sketeton")
    {
        cout << "\nthe skeleton crumbles to ash\n" << endl;
    }     
    else if (command == "beat skeleton")
    {
        cout << "\nthe skeleton crumbles to ash\n" << endl;
    }
    cout << "You fall in a hole." << endl;
    return cloudland();
}

int dungeonfour()
{
    getline (cin,command);
    if (command == "open chest")
    {
        cout << "\nThe chest is empty\n" << endl;
    }
    else if (command == "go east")
    {
        cout << "\nyou enter the room and see a lots of jewles and tresure in the corner there is a chair with massive Ork staring at you\n" << endl;
    }
    return dungeonsix();
}

int dungeonthree()
{

    getline (cin,command);
    if (command == "swing at the skeleton")
    {
        cout << "\nthe skeleton crumbles to ash\n" << endl;
    }    
    else if (command == "raise sheild at sketeton")
    {
        cout << "\nthe skeleton crumbles to ash\n" << endl;
    }     
    else if (command == "beat skeleton")
    {
        cout << "\nthe skeleton crumbles to ash\n" << endl;
    }
    else if (command == "go east")
    {
        cout << "\nyou walk into the room and it is empty\n" << endl;
    }
    else if (command == "go south")
    {
        cout << "\nyou walk into the room and there is a skeleton re-animates in the corner and charges at you\n" << endl;
    }
    return dungeonfive();
    
}

int dungeontwo()
{
    getline (cin,command);
    if (command == "swing at the skeleton")
    {
        cout << "\nthe skeleton crumbles to ash\n" << endl;
    }    
    else if (command == "raise sheild at sketeton")
    {
        cout << "\nthe skeleton crumbles to ash\n" << endl;
    }     
    else if (command == "beat skeleton")
    {
        cout << "\nthe skeleton crumbles to ash\n" << endl;
    }
    else if (command == "go east")
    {
        cout << "\nyou walk into the room and there is a chest in the right corner and another hallway to the east\n" << endl;
    }
    return dungeonfour();
        
}

int dungeon()
{
    cout << "\nYou drop in to a dungeon with a east and south hall\n" << endl;
    getline (cin, command);
    if (command == "go east")
    {
        cout << "\nyou go east and there is a skeleton re-animates in the corner and charges at you, there is a hallway to the east\n" << endl;
        return dungeontwo();
    }
    else if (command == "go south")
    {
        cout << "\nyou go south and there is a skeleton re-animates in the corner and charges at you, there is a hallway to the east and south\n" << endl;
        return dungeonthree();
    }   
}

int shed()
{
    getline (cin, command);
    if (command == "open shed")
    {
        cout << "\nThe shed contains a sword on the wall with a tri force logo and a plush yoshi on the ground\n" << endl;
        getline (cin, command);
        if (command == "get sword")
        {
            cout << "\nYou pick up the sword\n" << endl;
            return shed();
        }   
        else if (command == "get yoshi")
        {
            cout << "\nYou pick up the yoshi then a trapdoor opens on the floor and you fall into a dark hole\n" << endl;
            return dungeon();    
        }
    
    }
    
}

int dungeonStory()
{
	//player health
	float maxHealth;
	float currentHealth;
	
	//monsters
	float monsterMaxHealth;
	float enemyCurrentHealth;

	cout << "\nYou wake in a hole in the middle of no where\n" << endl;
	getline (cin, command);
    if (command == "climb out of hole")
	{
		cout << "\nYou are in a clearing with lots of trees around you, there is a gravel path to the east and west of you\n" << endl;
        return clearings();
    }
    getline (cin, command);    
    if (command == "go east")
   {
        cout << "\nYou enter another clearing with heavy grass and notice a abondoned shed with sign on it Gardeners dream\n" << endl;
        return shed();
    }
}