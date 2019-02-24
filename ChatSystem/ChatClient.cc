#include<iostream>
#include "ChatClient.hpp"

void Usage(char *argv)
{

}
static void menu()
{
    std::cout<<"********************"<<std::endl;
    std::cout<<"******Register******"<<std::endl;
    std::cout<<"******Login*********"<<std::endl;
    std::cout<<"*********************"<<std::endl;

}
int main(int argc , char *argv[])
{
    if(argc !=2 )
    {
        Usage(argv[0]);
        exit(0);
    }

    menu();
    int select = -1;
    while(1){
        std::cin >> select;
        switch (select)
        {
            case 1:
                
                break;
        
            default:
                break;
        }
    }
    


    ChatClient *cp = new ChatClient(argv[0]);
    cp->InitClient();
    if(cp->ConnectServer())
    {
        
    }

}