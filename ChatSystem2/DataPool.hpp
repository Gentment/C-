#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<semaphore.h>

class DataPool{
	private:
		std::vector<std::string> pool;
		int cap;
		sem_t date_sem;
		sem_t blank_sem;
};

