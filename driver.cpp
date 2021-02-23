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

    string temp = "";
    if(jsonString[0] = '[')
    {
        int count = 1;
        for(int i = 1; i < jsonString.length(); i++)
        {   
            if(jsonString.at(i) == '[')
            {
                count++;
            }
            else if(jsonString.at(i) == ']')
            {
                count--;
                if(count == 0)
                {
                    return temp;
                }
            }

            temp = temp + jsonString[i];
        }
    }
    return "Something went wrong";

}





