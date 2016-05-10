#pragma comment (lib,"ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <WinSock2.h>
//struct  hostent {
//  char    FAR * h_name;           /* official name of host */
//  char    FAR * FAR * h_aliases;  /* alias list */
//  short   h_addrtype;             /* host address type */
//  short   h_length;               /* length of address */
//  char    FAR * FAR * h_addr_list; /* list of addresses */ 문자열이아니라 in_addr 구조체 변수의 주소값을 가르킴
//#define h_addr  h_addr_list[0]          /* address, for backward compat */
//};
using namespace std;
void main() {
  WSADATA wsaData;
  WSAStartup(MAKEWORD(2, 2), &wsaData);
  struct hostent *host;
  
  host = gethostbyname("www.naver.com"); 
  if (!host) {
    cout << "gethost err" << endl;
  }

  cout << "official name : " << host->h_name << endl;
  for (int i = 0; host->h_aliases[i]; i++) {
    cout << i + 1 << " " << host->h_aliases[i] << endl;
  }
  printf("Address type : %s \n", (host->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6");

  for (int i = 0; host->h_addr_list[i]; i++) {
    cout << i + 1 << " " << inet_ntoa(*(struct in_addr*)host->h_addr_list[i]) << endl;
  }
  WSACleanup();
}