#include "ChatClient.hpp"

void Usage(std::string port)
{
    std::cout<<"Usage:"<<"ip:"<<port<<std::endl;
}
static void menu()
{
    std::cout<<"********************"<<std::endl;
    std::cout<<"* 1.Register******"<<std::endl;
    std::cout<<"* 2.Login 3.exit *"<<std::endl;
    std::cout<<"*********************"<<std::endl;

}

// ./ChatClient ip
int main(int argc , char *argv[])
{
    if(argc !=2 )
    {
        Usage(argv[0]);
        exit(1);
    }

    ChatClient *cp = new ChatClient(argv[1]);
    cp->InitClient();
    if(cp->ConnectServer())
    {
        // cp->Chat();
        std::cout<<"connect server"<<std::endl;
    }


    // menu();
    // int select = -1;
    // ChatClient *cc = new ChatClient(argv[0]);
    // while(1){
    //     std::cin >> select;
    //     switch (select)
    //     {
    //         case 1:
    //             cc->Register();
    //             break;
    //         case 2:
    //             if(cc->Login()){
    //                 cc->Chat();
    //             }
    //         default:
    //             break;
    //     }
    // }
    



}