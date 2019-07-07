#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<unistd.h>
#include<event.h>

int main(int argc, char *argv[]){
  
  struct event_base *base;
  
  //创建一个base对象
  base = event_base_new();
  
  //向base中安插监听事件
  
  //获取当前系统所支持的多路io机制

  int i;
  const char **method = event_get_supported_methods();
  printf("Starting Libevent %s.Available methods are:\n",event_get_version());
  for(i=0;method[i] != NULL;++i){
    printf("%s\n",method[i]);
  }


//监听base上的事件，满足后回调相应的函数
  event_base_dispatch(base); //自带循环机制while(1)
  
// 释放base
  event_base_free(base);
  return 0;
}
