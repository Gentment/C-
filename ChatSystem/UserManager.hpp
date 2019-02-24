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
    pthread_mutex_t lock;
    void Lock()
    {
        pthread_mutex_lock(&lock);
    }

    void UnLock()
    {
        pthread_mutex_unlock(&lock);
    }
public:
    UserManager():assign_id(10000)
    {
        pthread_mutex_init(&lock,NULL);
    }

    unsigned int Insert(const std::string &n_,const std::string &s_,const std::string &p_)
    {
        Lock();
        unsigned int id = assign_id++;
        User u(n_,s_,p_);
        if(users.find(id)== users.end())
        {
            users.insert({id,u});
            UnLock();
            return id;
        }
        UnLock();
        return -1;
    }

    //校验密码
    unsigned int Check(const int &id,const std::string &passwd)
    {
        Lock();
        auto it = users.find(id);
        if(it != users.end())
        {
            User &u = it->second;
        }
    }

    void AddOnlineUser(unsigned int id,struct sockaddr_in &peer)
    {
        Lock();
        auto it = online_users.find(id);
        if(it == online_users.end())
        {
            online_users.insert({id,peer});
        }
        UnLock();
    }

    std::unordered_map<unsigned int ,struct sockaddr_in> OnlineUser()
    {
        Lock();
        auto online = online_users;
        UnLock();
        return online;
    }
    ~UserManager()
    {
        pthread_mutex_destroy(&lock);
    }
};
