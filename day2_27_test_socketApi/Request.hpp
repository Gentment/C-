#pragma once
#include<string>
class Request
{
private:
    std::string method;
    std::string content_length;
    std::string text;
    std::string blank;
public:
    Request(/* args */):blank("\n"){}

    ~Request();
};

