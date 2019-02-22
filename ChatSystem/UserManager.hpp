#pragma once

#include<iostream>
#include<string>
#include<unordered_map>

class User
{
private:
    std::string nick_name;
    std::string school;
    std::string password;
public:
    User(const std::string &nick_name_, const std::string &school_,const std::string &password_):
        nick_name(nick_name_),
        school(school_),
        password(password_)
    {

    }
    ~User();
};


class UserManager
{
private:
    unsigned assign_id;
    std::unordered_map<unsigned int,User> users;
    std::unordered_map<unsigned int,struct sockaddr_in> online_users;
public:
    UserManager():assign_id(10000){}
    ~UserManager();
};
