//Defining the library to be able to use various functions in the program
#include <iostream>
#include <string>
#include <stdlib.h>
#include <algorithm> //used for randomization
#include <ctime>
#include <cstdlib>
#include "libsqlite.hpp" //importing the class file that has the database connection structure
using namespace std; //used to eliminate the stf:: infront of names for example cin, cout , endl
#include "header.h"



bool PLAYING; //Used to repeat story as long as player is playing
int STORY_PROGRESSION; //variable to track in which story you are
string CHARACTER_NAME; //variable where the name of the character is stored
string OPTION; //save the option the player chooses in this variable for later comparison 

int PRSGame(int PlayerScore,int FairiesScore) // The Rock Paper Scissors game function
{
	string PlayerAnswer; // variable where player answer is stored
	string FairiesAnswer; // variable where fairies answer is stored
	array<string,3> Option = { "paper","rock","scissors" }; // options for the player to choose
	while (PlayerScore < 3 && FairiesScore < 3) // repeat until player or fairies have a score of three wins
	{
		cout << endl;
		cin >> PlayerAnswer; // get answer from player
		srand(time(NULL));
		FairiesAnswer = Option[rand() % 3]; //select a random option for the faries from the Option array 
		cout << endl << " The fairy chose : " << FairiesAnswer << endl; //display what the fairies chose

		if (PlayerAnswer != FairiesAnswer)// if statement to anounce the player as the winner of the round from the following comparissons
		{
			if ((PlayerAnswer == "paper" && FairiesAnswer == "rock") || (PlayerAnswer == "scissors" && FairiesAnswer == "paper")
				|| (PlayerAnswer == "rock" && FairiesAnswer == "scissors"))
			{
				PlayerScore++; //increase the players score by 1
				cout << endl << "You won this round" << endl;
			}
            // if statement to anounce the fairies as the winner of the round from the following comparissons
			else if ((FairiesAnswer == "paper" && PlayerAnswer == "rock") || (FairiesAnswer == "scissors" && PlayerAnswer == "paper")
				|| (FairiesAnswer == "rock" && PlayerAnswer == "scissors"))
			{
				FairiesScore++; //Increase the fairies score by 1
				cout << endl << "Fairies won this round" << endl;
			}


		}
		else //if the comparissons above are not evalueated to true then no one wins because it was a tie
		{
			cout << endl << "No one wins" << endl;
		}


	}
    if (PlayerScore > FairiesScore) //Compare two scores to anounce winner
	{
		return true; //return true if the player has won
	}
    else
    {
        return false; //return false if the fairies won.
    }
    
}

void UpdateDatabase(string Process) //function used to update the database to keep track of the story progression
{
    try
		{
			sqlite::sqlite db("GameDatabase.sqlite3"); //Opens the Database

			auto curTemp = db.get_statement(); //declaring cur as an sql Statement
        
        if (Process == "CheckPoint") //if the parameter sent to the function is CheckPoint then the story progression gets saved
        {
            curTemp->set_sql("UPDATE SavedData SET PROGRESSION = '" +  to_string(STORY_PROGRESSION) +
		    "' WHERE ID = 1");
        }
        else if (Process == "NameUpdate") //if the parameter sent to the function was NameUpdate the name the player chose at the beginning gets saved to the 
            //Database
        {
            curTemp->set_sql("UPDATE SavedData SET NAME = '" + CHARACTER_NAME +
		    "' WHERE ID = 1");
            
        }
			
        
				
			curTemp->exec();//Executes the statement


			}
			catch (sqlite::exception e)      // catch all sql issues
			{
				std::cerr << e.what() << std::endl; //print Errors
			}
    
}

void FectData() //This function is used to load the data from the database on startup of the application.
{
    
    string sqliteFile = "GameDatabase.sqlite3"; //Set database name
	try
	{
		sqlite::sqlite db(sqliteFile);//connect to database

		auto cur = db.get_statement();            // create query
		cur->set_sql("select * from SavedData where ID = 1");
		cur->prepare();                            // run query


		while (cur->step())// loop over results
		    {
            
                CHARACTER_NAME = cur->get_text(1); //save the characters name in this variable for later use
                STORY_PROGRESSION =  cur->get_int(2); //save the story progression in this variable for later use
			
		    }

	    }
	catch (sqlite::exception e)      // catch all sql issues
	    {
		    std::cerr << e.what() << std::endl; // Display error
	    }
   
}

int clearings()
 {

    FectData(); //call to the function to retrive data from the database
    PLAYING = true; //PLAYING boolean is set to true to repeat the main function as long as the player is playing the game
    
    while (CHARACTER_NAME == "NONE") //If the characters name is empty then to keep looping this menu 
        {
        //display message 
            cout << "And what may your name be ?" << endl << endl;

            cout <<"My name is: " ;
            getline(cin,CHARACTER_NAME); //get players response
            UpdateDatabase("NameUpdate"); //call the the UpdateDatabase function with the parameter set to NameUpdate to save the name to the database


            
        }

    while(PLAYING) //Repeat story while the player is playing
    {

        switch(STORY_PROGRESSION) //Compare to see at which part of the story the player is
        {

            case 0:
                cout << endl << endl;

                cout << /*CHARACTER_NAME <<*/ " You just woke up in a dark place. You do not have any idea where you are. " << endl;
                cout << "You must find your way out alive. On your journey, you may run into obstacles you " << endl;
                cout << "have never imagined before. Choose a direction to proceed further." << endl << endl;


                getline(cin,OPTION); //Get player choice

                transform(OPTION.begin(),OPTION.end(),OPTION.begin(),::toupper); //Used to make everything the player typed in capital for easier comparisson
                if (OPTION == "GO RIGHT" || OPTION == "GO EAST")
                {
                    STORY_PROGRESSION = 1;
                    //UpdateDatabase("CheckPoint");//Call to this function to update the story progression into the database
                }
                else if (OPTION == "GO LEFT" || OPTION == "GO WEST")
                {
                    STORY_PROGRESSION = 2;
                    //UpdateDatabase("CheckPoint");//Call to this function to update the story progression into the database
                }
                else // default response when the option is not allowed
                {
                    cout << endl << endl;
                    cout << "You can not " << OPTION << endl;
                }


                break;

            case 1: // if the player has passed the first stage
                
                cout << endl;
                cout << "There is a shed in the middle of nowhere. It seems like someone could be " << endl;
                cout << "living there but it is dark and scary. What do you want to do?" <<endl;

                getline(cin,OPTION);

                transform(OPTION.begin(),OPTION.end(),OPTION.begin(),::toupper); //Used to make everything the player typed in capital for easier comparisson
                if (OPTION == "GO EAST_")
                {
                    cout << "There is a dungeon. You may not get alive from there. Think wisely what to do." << endl;
                    //return dungeon
                    STORY_PROGRESSION = 4;
                    //UpdateDatabase("CheckPoint");//Call to this function to update the story progression into the database
                }
                else if (OPTION == "GO WEST")
                {
                    cout << "There is a clearing leading to the high, cold mountains which are hiding unexpected secrets." << endl;
                    STORY_PROGRESSION = 2;
                    //UpdateDatabase("CheckPoint");//Call to this function to update the story progression into the database
                }
                else  // default response when the option is not allowed
                {
                    cout << endl << endl;
                    cout << "You can not " << OPTION << endl;
                }


                break;
                
                
            case 2:
                cout << endl;
                cout << "There is a massive tree nearby and nothing else in radius of 10 miles." << endl;
                cout << "If you chose to run to the right you will reach a swamp with ruins, and if you " << endl;
                cout << "chose to fly left you will appear in the cloudland." << endl;
                
                getline(cin,OPTION);

                transform(OPTION.begin(),OPTION.end(),OPTION.begin(),::toupper); //Used to make everything the player typed in capital for easier comparisson
                if (OPTION == "FLY TO WEST" || OPTION == "FLY WEST")
                {
                    cout << "You are now in the cloudland…." << endl;
                    return cloudland();
                    //CLOUDLAND STORY
                    STORY_PROGRESSION = 12;
                    //UpdateDatabase("CheckPoint");//Call to this function to update the story progression into the database
                    
                     
                }
                else if (OPTION == "RUN EAST_" || OPTION == "RUN TO EAST")
                {
                    cout << "That exhausted you but you reached successfully the swamp…" << endl; 
                    //SWAMP STORY
                    // return swamp
                    STORY_PROGRESSION = 21;
                    //UpdateDatabase("CheckPoint");//Call to this function to update the story progression into the database
                }
        
                
                break;
                
                ///////////////////////////////////////////
                //Other members stories to be added here//
                //////////////////////////////////////////
                
            case 19:
                cout << endl;
                cout << "There is huge tree with a house on it. In the house are living fairies." << endl;
                cout << "They have a pond in which you have to swim if you want the fairies to let you pass." << endl;
               
                
                getline(cin,OPTION);//get players choice

                transform(OPTION.begin(),OPTION.end(),OPTION.begin(),::toupper);//Used to make everything the player typed in capital for easier comparisson
                if (OPTION == "CLIMB TREE")
                {
                    cout << "You climbed the tree you need to enter the fairies house." << endl; 
                    getline(cin,OPTION);

                    transform(OPTION.begin(),OPTION.end(),OPTION.begin(),::toupper);//Used to make everything the player typed in capital for easier comparisson
                    if (OPTION == "ENTER HOUSE")
                    {
                        cout << "You are in the house but the fairies want to play a game with you before they let you pass." << endl << endl;
                        cout << "Fairies: You are in our territory. We control the paths to this land. We will only let you pass if you play a game with us." << endl;
                        cout << "We can play paper, rock and scissors. First to get to three wins" << endl << endl;
                        
                        getline(cin,OPTION); //get players option

                        transform(OPTION.begin(),OPTION.end(),OPTION.begin(),::toupper); //Used to make everything the player typed in capital for easier comparisson
                        if (OPTION == "PLAY")
                        {
                           bool Won = PRSGame(0,0); //call to the PRS game function to start the mini game
                           if (Won) // if the player won then to continue the progression
                           {
                               STORY_PROGRESSION = 32;
                               //UpdateDatabase("CheckPoint");//Call to this function to update the story progression into the database
                           }
                            else // if the player lost to repeat the progresssion 
                            {
                                cout << "You lost and so the fairies whiped your memory of them" << endl << endl;
                                STORY_PROGRESSION = 19;
                                //UpdateDatabase("CheckPoint");//Call to this function to update the story progression into the database
                                
                            }
                            
                        }
                        else
                        {
                            cout << endl << endl; 
                            cout << "You can not " << OPTION << endl;
                        }
                        
                        
                    }
                    
                }
                else //default response to an invalid choice by the player
                {
                    cout << endl << endl;
                    cout << "You can not " << OPTION << endl;
                }
        
                
                break;
                 
                ///////////////////////////////////////////
                //Other members stories to be added here//
               //////////////////////////////////////////
            
                
        }
    }

 return 0;
 }