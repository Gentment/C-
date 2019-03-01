#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include"Request.hpp"
#include"json/json.h"

class Util
{
private:
    /* data */
public:
    static void Serializ(Json::Value &root,std::string &string)
    {
        Json::FastWriter write;
        string = write.write(root);
    }
    
    static void UnSerializ(std::string &string,Json::Value &root)
    {
        Json::Reader read;
        read.parse(string,root,false);
    }

    static std::string IntToString(int x){
        std::stringstream ss;
        ss<<x;
        return ss.str();
    }

    static int StringToInt(std::string &str){
        std::stringstream ss(str);
        int s;
        ss>>s;
        return s;
    }
};