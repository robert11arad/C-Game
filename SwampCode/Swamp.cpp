#include "Swamp.h"

Swamp::Swamp()
{
    //ctor
}

Swamp::~Swamp()
{
    //dtor
}
void Swamp::Enter()
{
    int choice;

    cout<< "As you enter the muddy swamp you notice that it is very large, it seems going around a mountain of some sorts and it"<<endl;
cout<<"stretches further to the North and to the West, more than you wouldâ€™ve hoped it to. About 100 meters further from the entrance "<<endl;
cout<<"there is a Temple in ruins, it seems very old, like no one has entered it for thousands of years, youâ€™re not sure if you should "<<endl;
cout<<"go in there, maybe youâ€™re disturbing a sacred place. About  50 meters to the right of the Temple there is a bush of thorny, green "<<endl;
cout<<"vines that have grown on them some beautiful pink flowers, theyâ€™re like nothing youâ€™ve ever seen before, you feel like you have "<<endl;
cout<<"to hold at least one in your hands. You have 2 options : "<< endl<<endl;
    cout<< "1: Investigate ruined Temple" << endl;
    cout<< "2: Go further in the Swamp" <<  endl;
    cout<< "Enter choice: ";

    cin>>choice;

    if(choice ==1)
    {
        cout<<"Making the first steps inside the temple, you feel a chill go down your spine, you can hear pebbles falling down from"<<endl;
cout<<"the giant roof made of stone, you smell the old dust thatâ€™s been gathering there for a very long time. The walls have a lot of"<<endl;
cout<<"cracks in them and the light passes through barely so you can see where youâ€™re stepping, the only thing you know so far is that"<<endl;
cout<<"youâ€™re in a great hall that seems made for giants, and the only thing you can see clearly is the light coming from the door you"<<endl;
cout<<"left behind you slowly fading away. You got to a giant opening where in the middle is a giant statue and a lot of fallen pillars,"<<endl;
cout<<"youâ€™re wondering how is it that the whole thing didnâ€™t collapse already with so few pillars sustaining the giant roof. As you"<<endl;
cout<<"look around the statue you observe some kind of lines and circles on the ground, the lines are connecting the circles to the"<<endl;
cout<<"statue, and inside the circles are some kind of golden plates."<<endl;

        cout<< " You have to choose between 3 directions to be your next destination"<< endl;
        cout << " Enter 1 to see the statue, 2 to investigate the drawings or 3 to investigate the golden plates" << endl;
        cout << "Choice :" << endl;
        int choice1;

        cin >> choice1;

        if ( choice1 == 1)
        {
            cout<<"As you approach the statue you start to feel a warmth, like the sun is shining upon your skin, which seems a little"<<endl;
cout<<"strange since youâ€™re wearing clothes and it feels like the sun is warming you everywhere, and I mean everywhere, apart from the"<<endl;
cout<<"fact that you are in a dark room, inside a temple, made of stone and there is no sunlightâ€¦ Even though you feel like youâ€™re going"<<endl;
cout<<"crazy you make it to the statue and put your hand on itâ€™s pedestal, as your hand touches the pedestal you feel bombarded with"<<endl;
cout<<"sunlight,  and the grass tickling your bare feet, you find yourself naked in that strange place, with your hand on the bark of a"<<endl;
cout<<"tree. You close your eyes and take your hand off of the tree, as you open them you notice that you are back in the temple, but"<<endl;
cout<<"now there is a giant ball of fire right above the statueâ€™s head that lights the whole room. You take some steps back and look at"<<endl;
cout<<"the statue, which seems to be praising the sun, standing tall on two feet, with itâ€™s both arms raised at a 45 degree angle of"<<endl;
cout<<"itâ€™s head, with a giant ball of fire between itâ€™s arms, right above itâ€™s head. Something seems wrong with the fireball, it looks"<<endl;
cout<<"like is going to explode."<<endl<<endl;
cout<<"Game Over!"<<endl;

        }

        else if(choice1 ==2)
        {
        cout<<"You get down next to one of the lines and extend your arm to touch it, you're lost in thought as you gaze your sight upon"<<endl;
cout<<"the golden line, the way it glows makes it seem like it's alive, like the fluctuations of it's glow is it's breathing, but"<<endl;
cout<<"you lose all this train of thoughts the moment you lay your hand on the line because it feels like you've just touched the sun,"<<endl;
cout<<"and no, i do not mean it as some profound and divine experience, i mean it as in you've just burned your fingers in such a manner"<<endl;
cout<<"that you can see the bones surounded by your black, burnt flesh. You quickly withdraw your hand and get up, you're very"<<endl;
cout<<"scared, you just burnt your fingers and it hurts like hell, what is wrong with whoever made this temple you wonder,"<<endl;
cout<<"why the obsesion with fire and gold? why couldn't they just put their valuables in a nice chest in a dark cave like a"<<endl;
cout<<"normal person? Why all these puzzles, what do the developers of the game think you are, a 4 years old with too much time in your"<<endl;
cout<<"hands?... And worse of all the burnt on your hand is from magic so it is killing you..."<<endl<<endl;
cout<<"Game Over"<<endl;

        }

        else if ( choice1 == 3)
        {
        cout<<"There are 3 golden plates around the statue, each of them inside their own yellow circle, one of them is behind the"<<endl;
cout<<"statue, slightly to the right, the other 2 are in front of the statue, the one closer to the statue between the two, is right in"<<endl;
cout<<"front of it about 5 cm to the left, and the other one is slightly further away from the statue and much more to the left. They"<<endl;
cout<<"seem to make some kind of pattern, the one behind being connected to the statue directly and the one right in front of it too,"<<endl;
cout<<"only the one that's further away is connected to the next golden plate instead of the statue directly. As you inspect the"<<endl;
cout<<"closest golden plate to you, you see something engraved right in the middle of it, something is written there: íŸ±í´°Ì„íŸ°í²°ÌíŸ°í½°ÌƒíŸ°í° íŸ±í´°Ì•íŸ°í´°Ì‹íŸ°í»°Ì€"<<endl;
cout<<"íŸ°í³°Ì„ íŸ±í¶°Ì‰íŸ°í½°Ì‚íŸ±í¶°Ì‹íŸ°í¿® You go to check the other plates as well to see if there's anything written on them as well, and the moment you"<<endl;
cout<<"clean the dust away from the next plate you see there is something written on it too: íŸ±í°°Ì“íŸ°í¹°ÌŒíŸ°í° íŸ±í´°Ì•íŸ°í´°Ì‹íŸ°í»°Ì€ íŸ°í³°Ì„ íŸ±í¶°Ì‰íŸ°í½°Ì‚íŸ±í¶°Ì‹íŸ°í¿¬ last you check"<<endl;
cout<<"the plate behind the statue, and on this one it's engarved: íŸ±í·°Ì‹íŸ°í¹°Ì€íŸ±í³°Ì‰. What could it mean you wonder, it has to mean something..."<<endl;
cout<<"Something feels strange, you strat to feel deezy, all of a sudden you colapse on the cold, and hard floor..."<<endl<<endl;
cout<<"Game Over!"<<endl;

        }




    }
    else if(choice == 2)
    {
    int leave;
        cout<<"There seems to be something further in the swamp, just by the mountain, it looks like a strange tree. Because of your curiosity"<<endl;
cout<<"you feel the need to aproach it, see what it might be, so you move slowly towards it. As you get closer it looks more and more like"<<endl;
cout<<"a strange animal, it seems to have fur, and horns, and it is sleeping next to a huge swaord. You are next to it, you see it clearly now,"<<endl;
cout<<"it is a huge, green goat, it seems to be holding the huge sword. Good thing it's asleep or else who knows, maybe it would've killed you."<<endl;
cout<<"You strike it swftly right between it's eyes, and you can feel as it stops breathing... You just killed it, I honestly think you should"<<endl;
cout<<"be ashamed of yourself for killing a defenseless animal like that. Well whatever, your life, your sin. As you check the corpse of the"<<endl;
cout<<"animal you've just killed you notice it is wearing a key around it's neck, on a necklance, so you quickly grab it."<<endl;
cout<<"There's nothing left for you to do in this swamp, you'd better leave it."<<endl<<endl;
cout<<"Options:"<<endl;
cout<<"1.Leave Swamp"<<endl;
cin >> leave ;




    }







}
