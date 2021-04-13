#include "Card.hpp"
#include "URL.hpp"
#include "json.hpp"
#include <iostream>
#include <string>

using json = nlohmann::json;
using namespace std;

// all functions before implementation so they can be used before they are implemented


int main(int argc, char** argv)
{
    URL* u1 = new URL("https://api.hearthstonejson.com/v1/25770/enUS/cards.json");
    string jsonString = u1->getContents(); // this is a string of the URL above
    json parsedJson = json::parse(jsonString);

    Card* theCards[parsedJson.size()];


    if(parsedJson.is_array())
    {
        for(int i = 0; i < parsedJson.size(); i++)
        {
            json currValue = parsedJson[i];
            if(currValue.is_object()) // really don't need to ask but ya know
            {
                string name = currValue.value("name", "N/A"); // this gives us the individual cards
                int attack = currValue.value("attack", -1);
                int defense = currValue.value("health", -1);
                int manaCost = currValue.value("cost", -1);
                theCards[i] = new Card(name, manaCost, attack, defense);
                theCards[i]->display();
            }
 
        }
    } 

    return 0;
}





