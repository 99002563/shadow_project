#include "Database.h"
#include "Enable_Disable.h"
#include <gtest/gtest.h>


namespace {

class Enable_Disable_Test : public ::testing::Test {
    protected:
    void SetUp(){
        en.operation2(1,"eno1");
        en.operation2(1,"lo");
        
    }
void TearDown(){}
Enable_Disable en;

};
/*
TEST_F(Enable_Disable_Test,getStatus){
    string result= en.getStatus("eno1",1);
    string result2= en.getStatus("lo",0);

    EXPECT_EQ("ON",result);
    EXPECT_EQ("OFF",result2);
}
*/
TEST_F(Enable_Disable_Test,compare){
    string s1[]={"net1","net2","net3","net4"};
    string s2[]={"net1","net2"};

    string s3[]={"net1","net2"};
    string s4[]={"net1","net2"};

    int res= en.mismatch(s1,s2,sizeof(s1)/sizeof(s1[0]),sizeof(s2)/sizeof(s2[0]));
    int res2= en.mismatch(s3,s4,sizeof(s3)/sizeof(s3[0]),sizeof(s4)/sizeof(s4[0]));

    EXPECT_EQ(2,res);
    EXPECT_EQ(0,res2);
}

TEST_F(Enable_Disable_Test,networks){
  
    int res=en.network();
      

    EXPECT_EQ(2,res);
}

TEST_F(Enable_Disable_Test,ON_STATUS){
  
  string s1[]={"ON","OFF","ON","OFF"};
    int res=en.statusOn(s1,sizeof(s1)/sizeof(s1[0]));
      

    EXPECT_EQ(2,res);
}


}