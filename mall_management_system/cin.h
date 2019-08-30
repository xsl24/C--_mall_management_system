/*
 * =====================================================================================
 *
 *       Filename:  cin_h.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2019/08/26 20时27分46秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef __CIN_H__

#define __CIN_H__
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <cstring>
#include <cstdio>
#include <ctime>

using namespace std;
int cin_top();
void show_top();
void show_second();
void login();
int check(string& name,string& pwd);
void register_user();
void cin_second(int,string&);
void change_user();
void del_user();
void change_mine(string& name);
void show_third();
void insert_goods(string& name);
void del_goods(string& name1);
void cp_file(const char* dest ,const char* src,int sw,string& name1);
void skim();
void shell(string& name1);
void lost();
void today_check(string& name1);
void someday_info(string& name1);



class user_info{
private:
    string name;
    string pwd;
    int power;
public:
    user_info(string name,string pwd):name(name),pwd(pwd){}
    user_info(){}
    user_info(string name,string pwd,int power):name(name),pwd(pwd),power(power){}
    int get_power(){
        return this->power;
    }
    string& get_name(){
        return this->name;
    }
    string& get_pwd(){
        return this->pwd;
    }
    void set_pwd(string& pwd){
        this->pwd=pwd;
    }
    void set_power(int power){
        this->power=power;
    }
};

typedef struct Goods{
    int id;
    char name[20];
    float stock;
    float price;
    int count;
}goods;


typedef struct Receipt{
    char name[20];
    float price;
    float price_dif;
    int sum;
    float profit;
    struct tm t;
}receipt;

typedef struct Counter{
    string countor;
    float subprice;
    float profit;
    struct tm t;
}counter;


#endif
