#include "Database.h"
#include "Enable_Disable.h"

int main(int argc, char** argv) {

Enable_Disable ob;
ob.retrieve();

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

    if (ob.check_wireless(ifa->ifa_name, protocol)) {
         arr[g]=ifa->ifa_name;
        g++;
      printf("%d - interface %s is wireless: %s\n",g, ifa->ifa_name, protocol);
    } else {
        arr[g]=ifa->ifa_name;
        g++;
      printf("%d - interface %s is wired\n",g, ifa->ifa_name);
    

    }


    }

 ob.ipa();

string s1;

 char ch;

 int check,t;
 


do{
  printf("\n");
  printf("<<enter c to perform enable/disable operation>>\n<<enter e to exit>>\n");
       cin>>ch;

  
         
  
       switch(ch){
           case 'c': printf("<<enter network name>>\n<<1 to enable>> or <<0 to disable>>\n");
                    cin >>s1;
                    cin>>check;
                     // net= ifa->ifa_name;
                     // check1= to_string(check);  
                      // t= test(net,check1);
                   ob.operation(check,s1);
                      
                     if(check == 1){
                       che = "ON";
                     }
                     if(check == 0) {
                       che="OFF";
                     }

                    t= ob.test(s1,che);
                   ob.status(check,s1);
                   ob.ipa();
                       
                      break;
           case 'e'://exit(1);
         //  cout << "e is pressed"<<endl;
                   break;
           default:  cout<<"enter valid option"<< endl;
           break;
       }    
      
       
}while(ch!='e');



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
  
    int rc = sqlite3_exec(DB, sql.c_str(), ob.callback, (void*)data.c_str(), NULL); 
  
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
string s10[100],s11[100];
int j=0;
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
for(int i=0;i<j;i++){
	cout << s10[i] << " "<< s11[i] << endl;
}


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

for(int i=0 ;i<r1;i++){
  cout << res[i] << endl;
}
 ob.delete_data(res,r1);

  freeifaddrs(ifaddr);


     return (0);
}