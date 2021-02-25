#include "Card.hpp"
#include "URL.hpp"
#include <iostream>
#include <string>

using namespace std;

// all functions before implementation so they can be used before they are implemented
string processJsonArray(string jsonString, int start);
string processJsonObject(string jsonString, int start);

int main(int argc, char** argv)
{
    //URL* u1 = new URL("https://api.hearthstonejson.com/v1/25770/enUS/cards.json");
    //cout << u1->getContents() << endl;

    string testJson = "[{fname:val1, lname: val2, sums:[1,2,3]},{fname:val3, lname:val4}]";

    processJsonObject(testJson, 0);
    //cout << whatsReturned << endl; 

    return 0;
}

string processJsonArray(string jsonString, int start)
{   

    string temp = "";
    int count = 1;

    for(int i = start + 1; i < jsonString.length(); i++)
    {   
        if(jsonString.at(i) == '[')
        {
            string answer = processJsonArray(jsonString, i);
            temp += answer;
            i += answer.length() + 1;
            count++;
        }
        else if(jsonString.at(i) == ']')
        {
            count--;
            if(count == 0)
            {
                cout << temp << endl;
                return temp;
            }
        }
        else if(jsonString[i] == '{')
        {
            temp += '{';
            string answer = processJsonObject(jsonString, i);
            temp += answer;
            i += answer.length() + 1;
        }
        if( i < jsonString.length())
        {
            temp = temp + jsonString[i];
        }
    }

    //return "Something went wrong";

}

string processJsonObject(string jsonString, int start)
{
    if(jsonString[start] == '[')
    {
        return processJsonArray(jsonString, start);
    }
    else if(jsonString[start] == '{')
    {
        //must be a JSON Object 

        string temp = "";
        int countCurlyBraces = 1;
        for(int i = start + 1; i < jsonString.length(); i++)
        {   
            
            if(jsonString[i] == '{')
            {   temp += '{';
                string answer = processJsonObject(jsonString, i);
                temp += answer;

                //you force i to jump ahead 
                i += answer.length()+1;
                countCurlyBraces++;
            }
            else if(jsonString.at(i) == '}')
            {
                countCurlyBraces--;
                if(countCurlyBraces == 0)
                {
                    cout << temp << endl;
                    return temp; 
                    
                }
            }
            else if(jsonString.at(i) == '[')
            {
                temp += '[';
                string answer = processJsonArray(jsonString, i);
                temp += answer;
                i += answer.length();
            }

            if(i < jsonString.length())
            {
                temp = temp + jsonString[i];
            }
        }
    
    }
}




