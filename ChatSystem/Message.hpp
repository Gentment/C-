#pragma once
#include<iostream>
#include<string>
#include "ProtocolUtil.hpp"
#include<json.h>
class Message
{
public:
    std::string nick_name;
    std::string school;
    std::string text;
    unsigned int id;
public:
    Message(/* args */){}
    Message(std::string name_,std::string school_,std::string text_,unsigned int id_)
        :nick_name(name_),
         school(school_),
         text(text_),
         id(id_)
    {

    }
    void ToSendString(std::string &sendString)
    {
        Json::Value root;
        root["name"] = nick_name;
        root["school"] =  school;
        root["text"] = text;
        root["id"] = id;
        Utils::Seralize(root,sendString);
    }

    void ToRecvValue(std::string &recvString)
    {
        //反序列化
        Json::Value root;
        Utils::UnSeralize(recvString,root);
        nick_name = root["name"].asString;
        school = root["school"].asString;
        text = root["text"].asString;
        id = root["id"].asInt;
    }

    ~Message();
};