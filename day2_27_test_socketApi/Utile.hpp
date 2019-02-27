#pragma once
#include<iostream>
#include<string>
#include"json.h"

class Utile
{
private:
    /* data */
public:
    static void Serializ(Json::Value &root,std::string &string)
    {
        Json::FastWriter write;
        write.write(root);
    }
    
    static void Serializ(std::string &string,Json::Value &root)
    {
        Json::Reader read;
        read.parse(string,root,true);
    }

    
};