#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<event2/event.h>
#include<fcntl.h>
#include<stdlib.h>
void cb_func(evutil_socket_t fd, short what,void *arg){
  const char *data =(char*)arg;
  printf("Got an event on socket %d:%s%s%s%s[%s]\n",
      (int)fd,
     (what&EV_TIMEOUT)?"timeout":"",
     (what&EV_WRITE)? "write":"",
     (what&EV_READ) ?"read":"",
     (what&EV_SIGNAL)? "signal":"",
     data
     ); 
}

void main_loop(evutil_socket_t fd1, evutil_socket_t fd2){
  struct event *ev1,*ev2;
  struct timeval five_seconds = {5,0};
  struct event_base *base = event_base_new();

  ev1 = event_new(base,fd1,EV_TIMEOUT|EV_READ|EV_PERSIST,cb_func,(char*)"Reading event");
  
  ev2 = event_new(base,fd2,EV_WRITE,cb_func,(char*)"Writing event");
  event_add(ev1,&five_seconds);
  event_add(ev2,NULL);

  event_base_dispatch(base);
}
int main(){

  const char *fifo = "event.fifo";
  int fd1,fd2;
//  unlink(fifo);

  if(mkfifo(fifo,0644)){
    perror("mkfifo error");
    exit(1);
  }
  fd1 = open(fifo,O_RDONLY|O_NONBLOCK,0644);
  if(fd1<0){
    perror("open fifo error");
    exit(1);
  }
  
  fd2 = open(fifo,O_WRONLY|O_NONBLOCK,0644);
  if(fd2<0){
    perror("open fifo error");
    exit(1);
  }  
  main_loop(fd1,fd2);
  close(fd1);
  close(fd2);
  return 0;
}
