#pragma once
#include<iostream>
#include<string>
#include<json.h>
class Message
{
private:
    std::string nick_name;
    std::string school;
    std::string text;
    std::string id;
public:
    Message(/* args */){}

    void ToSendString(std::string &sendString)
    {
        Json::Value root;

    }

    void ToRecvValue(std::string &recvString)
    {
        
    }

    ~Message();
};