#pragma once
#include<iostream>
#include<vector>
#include<semaphore.h>

class DataPool
{
private:
    std::vector<std::string> pool;
    int cap;
    sem_t date_sem;  //
    sem_t blank_sem;  //
    int product_step;
    int consume_step;
public:
    DataPool(){}
    DataPool(int cap_ = 512):cap(cap_),pool(cap_)
    {
        sem_init(&date_sem,0,0);
        sem_init(&blank_sem,0,cap);
        product_step = 0;
        consume_step = 0;
    }

    void PutMessage(const std::string &msg)
    {
        sem_wait(&blank_sem);
        pool[product_step] = msg;
        product_step++;
        product_step %= cap;
        sem_post(&date_sem);
    }

    void GetMessage(std::string &msg)
    {
        sem_wait(&date_sem);
        pool[consume_step] = msg;
        consume_step++;
        consume_step %= cap;
        sem_post(&blank_sem);
    }
    ~DataPool()
    {
        sem_destroy(&date_sem);
        sem_destroy(&blank_sem);
    }
};