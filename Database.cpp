#include "Database.h"
#include <iostream>

 int Database :: callback(void* data, int argc, char** argv, char** azColName){
    
    int i; 
    fprintf(stderr, "%s: ", (const char*)data); 
  
    for (i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    } 
  
    printf("\n"); 
    return 0; 

}

 int Database :: callback1(void* data, int argc, char** argv, char** azColName){
    
    int i; 
    fprintf(stderr, "%s: ", (const char*)data); 
  
    for (i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    } 
  
    printf("\n"); 
    return 0; 

}

 int Database :: callback8(void* data, int argc, char** argv, char** azColName){
    
    int i; 
    fprintf(stderr, "%s: ", (const char*)data); 
  
    for (i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    } 
  
    printf("\n"); 
    return 0; 

}

 int Database :: test(string name, string status){
     	sqlite3* DB; 
	int exit = 0; 
	exit = sqlite3_open("example.db", &DB); 

	if (exit) { 
		std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
		return (-1); 
	} 
	else
		std::cout << "Opened Database Successfully!" << std::endl; 
	sqlite3_close(DB); 

    //Create Table

std::string sql = "CREATE TABLE IF NOT EXISTS BLOCK_32("
                      "NAME   TEXT PRIMARY KEY   NOT NULL, "
                      "STATUS           INT     NOT NULL); ";
                      
     exit = 0; 
    exit = sqlite3_open("example.db", &DB); 
    char* messaggeError; 
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError); 
  
    if (exit != SQLITE_OK) { 
        std::cerr << "Error Create Table" << std::endl; 
        sqlite3_free(messaggeError); 
    } 
    else
        std::cout << "Table created Successfully" << std::endl; 
    sqlite3_close(DB); 

    // INsert Values

      
    
       
     //  cin >> name3;


          exit = sqlite3_open("example.db", &DB); 
    string query = "SELECT * FROM BLOCK_32 ;"; 
  
    cout << "STATE OF TABLE BEFORE INSERT" << endl; 
  
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL); 
  
   sql = "INSERT INTO BLOCK_32 VALUES ('"+ name +"','" + status + "');";
  
    exit = sqlite3_exec(DB, sql.c_str(), NULL, 0, &messaggeError); 
    if (exit != SQLITE_OK) { 
        std::cerr << "Error Insert" << std::endl; 
        sqlite3_free(messaggeError); 
    } 
    else
        std::cout << "Records created Successfully!" << std::endl; 
  
    cout << "STATE OF TABLE AFTER INSERT" << endl; 
  
    sqlite3_exec(DB, query.c_str(), callback, NULL, NULL);

          sqlite3_close(DB);


 /* Open database */
   exit = sqlite3_open("example.db", &DB);
   
   if( exit ) {
      fprintf(stderr, "Can't open database: %s\n",sqlite3_errmsg(DB));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create merged SQL statement */
   sql = "UPDATE BLOCK_32 set STATUS = '"+status +"' where name='"+name+"'; " \
         "SELECT * from BLOCK_32";

   /* Execute SQL statement */
   exit = sqlite3_exec(DB, sql.c_str(), callback, NULL, &messaggeError);



  /* if( exit != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", &messaggeError);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "Operation done successfully\n");
   }
*/
if (exit != SQLITE_OK) { 
        std::cerr << "Error Update" << std::endl; 
        sqlite3_free(messaggeError); 
    } 
    else
        std::cout << "Operation done Successfully" << std::endl; 
    sqlite3_close(DB);


  // sqlite3_close(DB);






exit = sqlite3_open("example.db", &DB); 
    string data("CALLBACK FUNCTION"); 
  
     sql = "SELECT * FROM BLOCK_32;"; 
    if (exit) { 
        std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl; 
        return (-1); 
    } 
    else
        std::cout << "Opened Database Successfully!" << std::endl; 
  
    int rc = sqlite3_exec(DB, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        cerr << "Error SELECT" << endl; 
    else { 
        cout << "Operation OK!" << endl; 
    } 
  
    sqlite3_close(DB); 


return 0;
 }


void Database :: status(int check,string s){
  
   if(check == 1){
      cout << s << " - " << "ON"<<endl;
    }
      else
      {
          cout << s << " - " << "OFF"<<endl;
      }

}






