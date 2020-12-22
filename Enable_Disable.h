#ifndef __ENABLE_DISABLE_H
#define __ENABLE_DISABLE_H
#include "Database.h"
#include <cstdint>
#include <string>
#pragma once


class Enable_Disable : public Database {
protected:
 string s1;
 char ch;
 int check,t;

public:

int check_wireless(const char* ifname, char* protocol);
void ipa();
void operation(int check,string s);
void operation2(int check,string s);
int retrieve();
void delete_data(string res[],int r1);
int network();
 };
#endif