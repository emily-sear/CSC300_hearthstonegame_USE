#include "Card.hpp"
#include "URL.hpp"
#include <iostream>
#include <string>

using namespace std;

// all functions before implementation so they can be used before they are implemented
string contentsOfJsonString(string jsonString);

int main(int argc, char** argv)
{
    //URL* u1 = new URL("https://api.hearthstonejson.com/v1/25770/enUS/cards.json");
    //cout << u1->getContents() << endl;

    string testJson = "[{fname:val1, lname: val2, sums:[1,2,3]},{fname:val3, lname:val4}]";

    string whatsReturned = contentsOfJsonString(testJson);
    cout << whatsReturned << endl; 

    return 0;
}

string contentsOfJsonString(string jsonString)
{   
    int firstInstance = -1;
    int lastInstance = -1;
    int count = 0;

    for(int i = 0; i < jsonString.length(); i++)
    {   
        if(jsonString.at(i) == '[')
        {
            count++;
            if(firstInstance == -1)
            {
                firstInstance = i;
            }
        }
        else if(jsonString.at(i) == ']')
        {
            count--;
        }

        lastInstance++;

        if(count == 0 && i != 0)
        {
            jsonString.erase(firstInstance , 1);
            jsonString.erase(lastInstance - 1 ,1);
            return jsonString;
        }
 
    }
    return "Did not find any JSON strings";
}





