#ifndef __DATABASE_H
#define __DATABASE_H

#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ifaddrs.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/wireless.h>
#include <arpa/inet.h>
   #include <netdb.h>
   #include <stdlib.h>
   #include <linux/if_link.h>
   #include <bits/stdc++.h> 
   #include <sqlite3.h> 

  using namespace std;
static string che;

class Database{
protected :
   	sqlite3* DB; 
    int exit = 0;
    char* messaggeError; 
    

public :

static int callback(void* data, int argc, char** argv, char** azColName) ;
static int callback1(void* data, int argc, char** argv, char** azColName);
static int callback8(void* data, int argc, char** argv, char** azColName);
static int test(string name, string status);
void status(int check,string s);



};

#endif 
