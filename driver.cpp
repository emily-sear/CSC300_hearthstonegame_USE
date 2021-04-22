
#include "URL.hpp"
#include "json.hpp"
#include "LinkedList.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using json = nlohmann::json;
using namespace std;

// all functions before implementation so they can be used before they are implemented

vector<Card*> insertionSortByHealth(vector<Card*> toBeSorted, int sizeOfList); //the & should allow us to pass the vector by reference rather than value

int main(int argc, char** argv)
{
    URL* u1 = new URL("https://api.hearthstonejson.com/v1/25770/enUS/cards.json");
    string jsonString = u1->getContents(); // this is a string of the URL above
    json parsedJson = json::parse(jsonString);
    LinkedList* theCards = new LinkedList();

    //Card* theCards[parsedJson.size()];


    if(parsedJson.is_array())
    {
        for(int i = 0; i < parsedJson.size(); i++)
        {
            json currValue = parsedJson[i];
            if(currValue.is_object()) // really don't need to ask but ya know
            {
                string name = currValue.value("name", "N/A"); // this gives us the individual cards
                string type = currValue.value("type", "N/A");
                int attack = currValue.value("attack", -1);
                int health = currValue.value("health", -1);
                int manaCost = currValue.value("cost", -1);
                theCards->addEnd(new Card(name, type, manaCost, attack, health));
                //theCards[i]->
            }
 
        } 
    }

   // theCards->display();
    theCards->insertionSortOnDefense();
    theCards->display();

    vector<Card*> theMinions;

   /** for(int j = 0; j < parsedJson.size() ; j++)
    {
        if(theCards[j]->getType().compare("MINION") == 0)
        {
            theMinions.push_back(theCards[j]);
        }
    } **/

    int sizeOfMinions = theMinions.size();

    theMinions = insertionSortByHealth(theMinions, sizeOfMinions);

    for(int k = 0; k < theMinions.size(); k++)
    {
        theMinions.at(k)->display();
    }

    

    return 0;
}

vector<Card*> insertionSortByHealth(vector<Card*> toBeSorted, int sizeOfList)
{
    Card* tempSwap;
    Card* tempSwap2;
    int theFollower;

    for(int currStart = 1; currStart < sizeOfList; currStart++)
    {
        theFollower = currStart;

        while(theFollower > 0 && toBeSorted.at(theFollower)->getHealth() < toBeSorted.at(theFollower - 1)->getHealth())
        {
       
            tempSwap = toBeSorted.at(theFollower);
            tempSwap2 = toBeSorted.at(theFollower - 1);
            toBeSorted.erase(toBeSorted.begin() + theFollower);
            toBeSorted.insert(toBeSorted.begin() + theFollower, tempSwap2);
            toBeSorted.erase(toBeSorted.begin() + theFollower - 1);
            toBeSorted.insert(toBeSorted.begin() + (theFollower - 1), tempSwap);
            theFollower--;
        }
        // cout << currStart << endl;
    }

    return toBeSorted;
}
