#include "Enable_Disable.h"
#include "Database.h"

int Enable_Disable :: check_wireless(const char* ifname, char* protocol){
int sock = -1;
 
  struct iwreq pwrq;
  memset(&pwrq, 0, sizeof(pwrq));
  strncpy(pwrq.ifr_name, ifname, IFNAMSIZ);

  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    return 0;
  }

  if (ioctl(sock, SIOCGIWNAME, &pwrq) != -1) {
    if (protocol) strncpy(protocol, pwrq.u.name, IFNAMSIZ);
    close(sock);
    return 1;
  }

  close(sock);
  return 0;
}
void Enable_Disable :: ipa(){


struct ifaddrs * ifAddrStruct=NULL;
    struct ifaddrs * ifa=NULL;
    void * tmpAddrPtr=NULL;

    getifaddrs(&ifAddrStruct);
  printf("IP ADDRESS is :\n");
    for (ifa = ifAddrStruct; ifa != NULL; ifa = ifa->ifa_next) {
        if (!ifa->ifa_addr) {
            continue;
        }
        if (ifa->ifa_addr->sa_family == AF_INET) { // check it is IP4
            // is a valid IP4 Address
            tmpAddrPtr=&((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
            char addressBuffer[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, tmpAddrPtr, addressBuffer, INET_ADDRSTRLEN);
            printf("%s IPV4 Address %s\n", ifa->ifa_name, addressBuffer);
        } else if (ifa->ifa_addr->sa_family == AF_INET6) { // check it is IP6
            // is a valid IP6 Address
            tmpAddrPtr=&((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
            char addressBuffer[INET6_ADDRSTRLEN];
            inet_ntop(AF_INET6, tmpAddrPtr, addressBuffer, INET6_ADDRSTRLEN);
            printf("%s IPV6 Address %s\n", ifa->ifa_name, addressBuffer);
        }
    }
    if (ifAddrStruct!=NULL) freeifaddrs(ifAddrStruct);
}
void Enable_Disable :: operation(int check,string s){


 if(check == 0){
      //string s=ifa->ifa_name;
     // strcpy(command,ifa->ifa_name);
      string str ="sudo ifconfig " + s + " down";
       const char *co = str.c_str();
      system(co);
     cout<< "Interface "<< s << " is disabled " << endl;
   
    }
    if(check == 1){
      // string s1=ifa->ifa_name;
     // strcpy(command1,ifa->ifa_name);
      string str1 ="sudo ifconfig " + s + " up";
       const char *co1 = str1.c_str();
      system(co1);
      cout<< "Interface "<< s << " is enabled " << endl;
    }

}



void Enable_Disable ::operation2(int check,string s){

 if(check == 0){
      //string s=ifa->ifa_name;
     // strcpy(command,ifa->ifa_name);
      string str ="sudo ifconfig " + s + " down";
       const char *co = str.c_str();
      system(co);
     cout<< "Interface "<< s << " is disabled " << endl;
   
    }
    if(check == 1){
      // string s1=ifa->ifa_name;
     // strcpy(command1,ifa->ifa_name);
      string str1 ="sudo ifconfig " + s + " up";
       const char *co1 = str1.c_str();
      system(co1);
      cout<< "Interface "<< s << " is enabled " << endl;
    }

}


int Enable_Disable ::retrieve(){

sqlite3* DB; 
    int exit = 0; 
    exit = sqlite3_open("example.db", &DB); 
    string data("CALLBACK FUNCTION"); 
  
    string sql("SELECT * FROM BLOCK_32;"); 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback8, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        cerr << "Error SELECT" << endl; 
    else { 
        cout << "Operation OK!" << endl; 
    } 
  
    sqlite3_close(DB); 
 


//sqlite3* db;
    exit = sqlite3_open("example.db", &DB); 

sqlite3_stmt* stmt;
sqlite3_prepare_v2(DB, "select NAME, STATUS from BLOCK_32", -1, &stmt,NULL);
string s1[100];
int j=0;
/*
while (sqlite3_step(stmt) == SQLITE_ROW) {
	s1[j]=(char*)sqlite3_column_text(stmt, 0);
	j++;
  cout << (char*)sqlite3_column_text(stmt, 0) << ' ' <<
    (char*)sqlite3_column_text(stmt, 1) << endl;}
	//' ' <<
  //  sqlite3_column_int(stmt, 2) << endl; }

sqlite3_finalize(stmt);
sqlite3_close(DB);
for(int i=0;i<j;i++){
	cout << s1[i] << endl;
}
*/
string s10[100],s11[100];
while (sqlite3_step(stmt) == SQLITE_ROW) {
	s10[j]=(char*)sqlite3_column_text(stmt, 0);
  s11[j]=(char*)sqlite3_column_text(stmt, 1);

	j++;
 // cout << (char*)sqlite3_column_text(stmt, 0) << ' ' <<
 //   (char*)sqlite3_column_text(stmt, 1) << endl;}
	//' ' <<
  //  sqlite3_column_int(stmt, 2) << endl; 
  }

sqlite3_finalize(stmt);
sqlite3_close(DB);
//for(int i=0;i<j;i++){
//	cout << s10[i] << " "<< s11[i] << endl;
//}
int t;
for(int i=0;i<j;i++){
//t= test1(s10[i],s11[i]); 
int l;
if(s11[i]=="ON")
l=1;
else
{
    l=0;

}
operation(l,s10[i]);

}

}

int Enable_Disable :: network(){

  char command[100],command1[100];
  struct ifaddrs *ifaddr, *ifa;
   int family, s, n;
     char host[NI_MAXHOST];
  if (getifaddrs(&ifaddr) == -1) {
    perror("getifaddrs");
    return -1;
  }

  /* Walk through linked list, maintaining head pointer so we
     can free list later */
           printf("Networks are :\n ");
           int g=0;
           string arr[100];
  for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
    char protocol[IFNAMSIZ]  = {0};

    if (ifa->ifa_addr == NULL ||
        ifa->ifa_addr->sa_family != AF_PACKET) continue;

    if (check_wireless(ifa->ifa_name, protocol)) {
         arr[g]=ifa->ifa_name;
        g++;
      printf("%d - interface %s is wireless: %s\n",g, ifa->ifa_name, protocol);
    } else {
        arr[g]=ifa->ifa_name;
        g++;
      printf("%d - interface %s is wired\n",g, ifa->ifa_name);
    

    }


    }
    return g;

}


void Enable_Disable ::delete_data(string res[],int r1){
   char* messaggeError;

  exit = sqlite3_open("example.db", &DB);
   for(int i=0 ;i < r1;i++){
         string sql = "DELETE FROM BLOCK_32 WHERE NAME = '"+ res[i]+"';"; 
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError); 
    if (exit != SQLITE_OK) { 
        std::cerr << "Error DELETE" << std::endl; 
        sqlite3_free(messaggeError); 
    } 
    else
        std::cout << "Record deleted Successfully!" << std::endl; 
  
    cout << "STATE OF TABLE AFTER DELETE OF ELEMENT" << endl; 
    sqlite3_exec(DB, sql.c_str(), callback, NULL, NULL); 
   }
    sqlite3_close(DB);
 
}

string Enable_Disable::  getStatus(string st,int check){
if(check == 1)
return "ON";
return "OFF";
}


int Enable_Disable::totatNetworks(int a){
  return a;
}


int  Enable_Disable:: mismatch(string arr[],string s10[],int g,int j){


  string res[100];
int g1=0,j1=0,r1=0;
while(g1<g && j1<j){
  if(arr[g1]!=s10[j1])
{
   res[r1] = s10[j1];
   r1++;
   
}
   g1++;
   j1++;
  // r1++;
}

if(j1< j || g1<g){
while(j1<j){
  res[r1]=s10[j1];
  j1++;
  r1++;
}

while(g1<g){
  res[r1]=arr[g1];
  g1++;
  r1++;
}
}
return r1;
}

int Enable_Disable:: statusOn(string s11[],int j){
int count=0;
for(int i=0;i<j;i++){
  if(s11[i]=="ON"){
        count++;
  }
 
}
 return count;

}
