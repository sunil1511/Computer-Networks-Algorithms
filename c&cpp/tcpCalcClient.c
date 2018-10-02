#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>
#include<netdb.h>
#include<sys/socket.h>
#define PORT 8080

int main(int argc, const char * argv[])
{
        struct sockaddr_in c_addr;
        int valueread, sock=0;
        struct sockaddr_in s_addr;
        char *hello= "Hello from Client";
        char data[1024]= {0};
        char filename[20]={0};
        
        if((sock= socket(AF_INET, SOCK_STREAM, 0))<0)
        {
                printf("\nSocket not created");
                return -1;
        }
        
        memset(&s_addr, '0', sizeof(s_addr));
        
        s_addr.sin_family= AF_INET;
        s_addr.sin_port= htons(PORT);
        
        if(inet_pton(AF_INET, "127.0.0.1", &s_addr.sin_addr)<=0)
        {
                printf("\nInvalid address");
                return -1; 
        }
        
        if((connect(sock, (struct sockaddr* ) &s_addr, sizeof(s_addr)))<0)
        {
                printf("\nConnection failed");
                return -1;
                
        }

printf("enter first no:");
scanf("%s",&data);
write(sock,data,100);
printf("enter operation no:");
scanf("%s",&data);
write(sock,data,100);
printf("enter second no:");
scanf("%s",&data);
write(sock,data,100);
        return 0;
}
