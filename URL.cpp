#include <cstring>
#include <iostream>
#include <curl/curl.h> 
#include "URL.hpp"

using namespace std;

string contents = "";

URL::URL(string stringURL)
{
    this->stringURL=stringURL;
}

size_t handle_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
    int numbytes = size*nmemb;

    char lastchar = *((char *) ptr + numbytes - 1);
    *((char *) ptr + numbytes - 1) = '\0';

    contents.append((char *)ptr); 
    contents.append(1,lastchar); 

    *((char *) ptr + numbytes - 1) = lastchar; 
    return size*nmemb;
}


string URL::getContents()
{
    contents = "";
    CURL* curl = curl_easy_init();

    if(curl)
    {
        curl_easy_setopt(curl,CURLOPT_URL, this->stringURL.c_str()); 
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION, handle_data); 

        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        if(res == 0)
        {
            return contents;
        }
        else
        {
            return "Error: " + res;
        }
    }
    return "";
}

