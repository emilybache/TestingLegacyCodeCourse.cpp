#pragma once

#include <iostream>

#include "third_party_code.h"

int RestCall(std::string url, std::string action, int key) {

    return _third_party_code_::rest_call(url, action, key);
}

void initialiseServices()
{
    int key = 42;
    int result = RestCall("https://postgresdatabase.acme.com", "start", key);
    if ( result == 200 )
    {
        key = key + 100;
        result = RestCall("https://kafka.acme.com", "subscribe", key);
        if ( result == 200 )
        {
            result = RestCall("https://cache.acme.com", "load", key);
            if ( result != 200 )
            {
                std::cout << "Error starting cache\n";
            }
            result = RestCall("https://search.acme.com", "index", key);
            if ( result != 200 )
            {
                std::cout << "Error indexing search\n";
            }
        }
    }
}
