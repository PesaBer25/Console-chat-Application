#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <winsock2.h>

void start(void){
    WSADATA data;
    if(WSAStartup(MAKEWORD(2,2),&data) != 0)
        printf("Winsock initialization failed\n");
}

void stop(){
    WSACleanup();
}

int main(void){
    start();
    SOCKET socket_fd = socket(AF_INET,SOCK_STREAM,0);
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(2000);
    address.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(socket_fd,(struct sockaddr *)&address,sizeof(address)) == SOCKET_ERROR){
        printf("Connection Failed\n");
        closesocket(socket_fd);
        stop();
        return 1;
    }else{
        printf("Connected successfully\n");
    }
    char message[1024];
    char response[1024];
    while(1){
        printf("\nType message (Q to quit): ");
        fgets(message,1024,stdin);
        if(strcmp("Q\n",message) == 0 || strcmp("q\n",message) == 0){
            break;
        }
        if(send(socket_fd,message,strlen(message),0) != INVALID_SOCKET){
            printf("Sent success\n");
        }else{
            printf("Not Sent\n");
            printf("Server Down\n");
        }
        int len = recv(socket_fd,response,1024,0);
        if(len > 0){
            response[len] = '\0';
            printf("The response was: \n%s",response);
         }
    
    }
  
    closesocket(socket_fd);
    stop();
    return 0;
}