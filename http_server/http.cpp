#include"http.h"
#include"log.h"
#include<unistd.h>
#include<fcntl.h>
#include<assert.h>

#include<sys/stat.h>
#include<sys/socket.h>
#include<sys/wait.h>

#include<iostream>
#include<string>
#include<algorithm>

#include<stdio.h>
#include<strings.h>
#include<stdlib.h>
#include<string.h>

std::map<std::string,std::string> Http::type_map;

void Http::insert_map(const std::string& key,const std::string& v){
  type_map[key] = "Content-type: "+ v +"\r\n";
}

void Http::init_map(){
  if(type_map.empty()){
    insert_map(".html","text/html");
    insert_map(".jpg","image/jpeg");
    insert_map(".png","image/png");
  }
}

std::string Http::get_type(const std::string& key){
  std::string res;
  std::map<std::string,std::string>::iterator it = type_map.find(key);
  if(it != type_map.end()){
    res = it->second;
  }
  return res;
}

void Http::read_cb(struct bufferevent *bev,void *ctx){
  DEBUG_LOG("read");
  Http* http = (Http*)ctx;

  if(http->bev == bev){
    while(http->loop());
  }else if(http->bev_cgi == bev){
    struct evbuffer *output,*input;
    output = bufferevent_get_output(bev);

    input = evbuffer_add_buffer(output,input);
    
  }else{
    DEBUG_LOG("error read_cb");
  }
}
