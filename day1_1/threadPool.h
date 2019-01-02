#ifndef __THREAD_POOL_H__
#define __THREAD_POOL_H__

#include<iostream>
#include<queue>
#include<pthread.h>

typedef void (*handler_t)(int);

class Task{

	private:
		int sock;
		handler_t handler;
	public:
		Task(int sock_,handler_t h_):sock(sock_),handler(h_){}

		void Run()
		{
			handler(sock);
			close(sock);
		}

		~Task(){}

};


class ThreadPool{

		private:
			int nums;
			int id_nums;
			std::queue<Task> task_queue;
			pthread_mutex_t lock;
			pthread_cond_t cond;
		public:
			ThreadPool(int nums_):nums(nums_),id_nums(0)
			{
				pthread_mutex_init(&lock,NULL);
				pthread_cond_init(&cond,NULL);
			}

			void LockQueue()
			{
				pthread_mutex_lock(&lock);
			}

			void UnLockQueue()
			{
				pthread_mutex_unlock(&lock);
			}

			void ThreadIdle()
			{
				id_nums++;
				pthread_cond_wait(&cond,&lock);
				id_nums--;
			}

			void WakeUpOneThread()
			{
				pthread_cond_signal(&cond);
			}

			bool IsQueueEmpty()
			{
				return task_queue.size()>0?false:true;
			}

			Task PopTask()
			{
				Task t = task_queue.front();
				task_queue.pop();
				return t;
			}

			static void *ThreadRoutine(void *arg)
			{
				pthread_detach(pthread_self());
				ThreadPool *tp = (ThreadPool*)arg;
				for(; ; )
				{
					tp->LockQueue();
					while(tp->IsQueueEmpty())
					{
						tp->ThreadIdle();
					}

					Task t = tp->PopTask();
					tp->UnLockQueue();
					t.Run();
				}
			}

			void InitThreadPool()
			{
				pthread_t pid;
				for(int i=0;i<nums;i++)
				{
						pthread_create(&pid,NULL,ThreadRoutine,(void*)this);
				}
			}

			void PushTask(const Task &t)
			{
				LockQueue();
				task_queue.push(t);
				WakeUpOneThread();
				UnLockQueue();
			}

			~ThreadPool()
			{
				pthread_mutex_destroy(&lock);
				pthread_cond_destroy(&cond);
			}
};

#endif
