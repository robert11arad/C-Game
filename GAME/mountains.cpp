#include <iostream>
#include <string>
using namespace std;
#include "header.h"
string command;
int chest()
{
    getline (cin, command);
    if (command == "open chest")
    {
        cout <<"\nYou open the chest and find it empty whoever killed the giant monster must have already looted it long ago\n" << endl;
    }
    else if (command == "use key")
    {
        cout <<"\nYou put the key in the lock and turn it however the key doesn’t turn you try to open the chest and find that it was already unlocked and empty inside the skeleton outside must belong to the person who cleared out this cave\n"  << endl;
    }
}

int caveopening()
{
    getline (cin, command);
    if (command == "search skeleton")
    {
        cout <<"\nYou walk up to the skeleton and see a chest behind it you walk around the skeleton and kneel down to inspect the chest there is a keyhole on the front of it\n" << endl;
        return chest();
    }
}



int leftpath()
{
    getline (cin, command);
    if (command == "go forward")
    {
        cout <<"\nThe light steadily gets brighter as you reach the end of the path, you pass a few more skeletons along the way. The path opens into a large opening light is coming in through a hole in the ceiling and near the back of the opening lies a huge skeleton with a large sword wedged between its ribs\n" << endl;
        return caveopening();
    }
    else if (command == "get helmet")
    {
        cout <<"\nYou pick up the helmet and continue down the path the light steadily gets brighter as you reach the end of the path you pass a few more skeletons along the way.The path opens into a large opening light is coming in through a hole in the ceiling and near the back of the opening lies a huge skeleton with a large sword wedged between its ribs\n" << endl;
        return caveopening();
    }
}

int rightpath()
{
    getline (cin, command);
    if (command == "clear rocks")
    {
        cout <<"\nYou try to clear the rocks but they won't budge so you take the left path\n" <<endl;
       
    }
    else if (command == "go back")
    {
        cout <<"\nYou go back and take the left path\n" <<endl;
        
    }
    return leftpath();
}

int caveentrance()
{
    getline (cin, command);
    if (command == "go left")
    {
        cout <<"\nYou make your way down the left path, there is a dim light shining from further into the cave it lights the cave enough for you to make out a dozen or so skeletons littered over the ground and a very battered helmet near the cave wall\n" << endl;
        return leftpath();
    }
    else if (command == "go right")
    {
        cout <<"\nYou make your way down the right path, after walking for a bit you find the path is blocked by rocks\n" << endl;
        return rightpath();
    }
}

int map()
{
    cout << "\nYou look at the map and see that it’s a map of the cave, it shows the cave splits into two paths that join up again into a wide opening and there is an X marking the back of the wide opening\n" << endl;
    return caveentrance();
}

int mountain()
{
    cout << "\nYou reach a cliff about halfway up the mountain, you notice a pile of rocks off to the left and an opening to a cave in front of you\n" << endl;
    getline (cin, command);
    if (command == "search rocks")
    {
        cout << "\nYou walk over to the pile of rocks and find a skeleton buried underneath them with the remains of a map and a key\n" << endl;
        return map();
    }
    else if (command == "enter cave")
    {
       cout << "\nYou enter the cave, it’s very dark and damp inside, you can just about make out that the cave splits off to the left and right\n" << endl;
       return caveentrance();
    }
}
