
#include "cin.h"
#include<fstream>

//登录
void login(){
    string name;
    string pwd;
    system("clear");
    cout<<"\t*******登录详情页*******"<<endl;
    
    cout<<"\t\t请输入账号"<<endl;
    cin>>name;
    cout<<"\t\t请输入密码"<<endl;
    cin>>pwd;
    int num;
    num = check(name,pwd);
    cin_second(num,name);
    
}


//注册
void register_user(){
    string name;
    string pwd;
    int power;
    system("clear");
    cout<<"\t*******注册页面********"<<endl;
    cout<<"\t请输入账号"<<endl;
    cin>>name;
    cout<<"\t请输入密码"<<endl;
    cin>>pwd;
    cout<<"\t请输入权限\n1为管理员，2为售货员"<<endl;
    cin>>power;
    user_info t;
    user_info u(name,pwd,power);
    
    ifstream fin("user_info.txt",ios::in);
    while (fin.peek()!=EOF) {
        fin.read((char*)&t,sizeof(user_info));
        if(t.get_name()==name){
            cout<<"\t\t用户名已存在！！！\n";
            fin.close();
            system("clear");
            register_user();
        }
    }
    ofstream fout("user_info.txt",ios::app);
    fout.write((const char*)&u,sizeof(user_info));
    cout<<"\t\t注册成功"<<endl;
//  char pause;
//  while(pause)
    fout.close();
    system("clear");
    cin_second(1,name);
}


//检查密码用户名
int check(string& name,string& pwd){
    ifstream fin("user_info.txt",ios::in);
    if(!fin){
        cout<<"文件未知错误或不存在\n";
        system("clear");
        fin.close();
        return -1;
    }
    user_info t;
    int num;
    while (fin.peek()!=EOF) {
        fin.read((char*)&t,sizeof(user_info));
        if(t.get_name()==name){
            if(t.get_pwd()==pwd){
                cout<<"\t\t验证成功!\n";
                num=t.get_power();//判断权限
                system("clear");
                fin.close();
                return num;
            }
        }
    }
    cout<<"验证失败!!!\n";
    cout<<"0.退出登录\n";
    char hh;
    cin>>hh;
    while(cin.get()!='\n') cin.clear();
    if(hh=='0'){
        exit(0);
    }
    else if(hh!='0'){
        system("clear");
        login();
    }
    return num;
}


//修改用户密码
void change_user(){
    string name;
    string pwd;
    user_info t;
    cout<<"\t\t输入需要修改的用户名:\n";
    cin>>name;
    fstream fin("user_info.txt",ios::in|ios::out);
    while (fin.peek()!=EOF) {
        fin.read((char*)&t,sizeof(user_info));
        if(t.get_name()==name){
            cout<<"\t\t输入新的密码\n";
            cin>>pwd;
            t.set_pwd(pwd);
            fin.seekp(-sizeof(user_info),ios::cur);
            fin.write((const char*)&t,sizeof(user_info));
            cout<<"修改成功!!!\n";
            fin.close();
            system("clear");
            cin_second(1,name);
        }
    }
    cout<<"\t\t用户名不存在！！！\n";
    fin.close();
    system("clear");
    cin_second(1,name);
}

//注销用户
void del_user(){
    string name;
    user_info t;
    cout<<"\t\t输入需要修改的用户名:\n";
    cin>>name;
    fstream fin("user_info.txt",ios::in|ios::out);
    while (fin.peek()!=EOF) {
        fin.read((char*)&t,sizeof(user_info));
        if(t.get_name()==name){
            t.set_power(0);
            fin.seekp(-sizeof(user_info),ios::cur);
            fin.write((const char*)&t,sizeof(user_info));
            cout<<"注销成功!!!\n";
            fin.close();
            system("clear");
            cin_second(1,name);
        }
    }
    cout<<"\t\t用户名不存在！！！\n";
    fin.close();
    system("clear");
    cin_second(1,name);
    
}


void change_mine(string& name){
    string pwd;
    user_info t;
    fstream fin("user_info.txt",ios::in|ios::out);
    while (fin.peek()!=EOF) {
        fin.read((char*)&t,sizeof(user_info));
        if(t.get_name()==name){
            cout<<"\t\t输入新的密码\n";
            cin>>pwd;
            t.set_pwd(pwd);
            fin.seekp(-sizeof(user_info),ios::cur);
            fin.write((const char*)&t,sizeof(user_info));
            cout<<"修改成功!!!\n";
            fin.close();
            system("clear");
            cin_second(2,name);
        }
        }
}


void insert_goods(string& name1){
//    int id;
//    char name[20];
//    float price;
//    int count;
    goods g;
    goods ck;
    int count;
    cout<<"\t********商品进货或修改页面*********\n";
    cout<<"\t\t输入商品ID:\n";
    cin>>g.id;
    cout<<"\t\t输入商品名:\n";
    cin>>g.name;
    cout<<"\t\t输入进价:\n";
    cin>>g.stock;
    cout<<"\t\t输入售价:\n";
    cin>>g.price;
    cout<<"\t\t输入进货量:\n";
    cin>>g.count;
   // tm* tm = local_time(&(g.t));
   // char time_N[26];
    //strftime(time_N,26,"%Y%m%d%H%M%S",tm);
    fstream ff("goods_info.txt",ios::in|ios::out);
    while (ff.peek()!=EOF) {
        ff.read((char*)&ck,sizeof(goods));
        if(ck.id==g.id ||strcmp(ck.name,g.name)==0){   //判断是否有相同商品
            cout<<"已存在商品信息，是否选择覆盖(y/n)\n";
            char choose;
            cin>>choose;
            while(cin.get()!='\n') cin.clear();
            if(choose=='y'||choose=='Y'){
                
                ff.seekp(-sizeof(goods),ios::cur);
                ff.write((char*)&g,sizeof(goods));
                ff.close();
                system("clear");
                 cout<<"修改成功!!!\n";
                cin_second(1,name1);
            }else if(choose=='n'||choose=='N'){
                system("clear");
                cout<<"请重输入:\n";
                insert_goods(name1);
                break;
            }
        }
    }
    ff.close();
    ofstream fout("goods_info.txt",ios::app);
    fout.write((char*)&g,sizeof(goods));
    fout.close();
    system("clear");
    cin_second(1,name1);
}

//删除内容
void del_goods(string& name1){
    char dest[]="goods_info.txt";
    char src[]="new_goods.txt";
    cp_file(dest,src,1,name1);
}


//多功能文件拷贝
void cp_file(const char* dest ,const char* src,int sw,string& name1){
    goods dl;
    char name[20];
    int id;
    ifstream fin(dest,ios::in);
    ofstream fout(src,ios::out);
    //如果是1就进行选择删除拷贝，如果不是就进行直接拷贝
    if(sw==1){
        system("clear");
        cout<<"\t请输入要删除的信息\n";
        cout<<"\t商品名\n";
        cin>>id;
        while (fin.peek()!=EOF) {
            fin.read((char*)&dl,sizeof(goods));
            //if(strcmp(name,dl.name)!=0){
            if(id!=dl.id){
                fout.write((char*)&dl,sizeof(goods));
            }
        }
        fout.close();
        fin.close();
        cp_file(src,dest,0,name1);
    }
    
    while (fin.peek()!=EOF) {
        fin.read((char*)&dl,sizeof(goods));
        fout.write((char*)&dl,sizeof(goods));
    }
    fout.close();
    fin.close();
    system("clear");
    cin_second(1,name1);
}

//查看库存
void skim(){
    system("clear");
    string name1;
    cout<<"\t\t\t\t******查看库存页面******\n";
    cout<<"\t\t商品ID   商品名   进价   售价   库存数量\n";
    ifstream fin("goods_info.txt",ios::in);
    goods s;
    while (fin.peek()!=EOF) {
        fin.read((char*)&s,sizeof(goods));
        cout<<"\t\t"<<s.id<<"     "<<s.name<<"     "<<s.stock<<"       "<<s.price<<"        "<<s.count<<endl;
    }
    cout<<"\n\n\n\n\n";
    fin.close();
    cin_second(1,name1);
}


void shell(string& name1){

again:
    system("clear");
    receipt r;
    goods s;
    counter ct;
    float money=0.0;
    cout<<"\t\t\t\t******售货页******\n";
    cout<<"\t\t输入商品名\n";
    cin>>r.name;
    while(cin.get()!='\n') cin.clear();
    cout<<"\t\t输入商品数量\n";
    cin>>r.sum;
    while(cin.get()!='\n') cin.clear();
    ofstream fc("counter.txt",ios::app);
    fstream fin("goods_info.txt",ios::in|ios::out);
    while (fin.peek()!=EOF) {
        fin.read((char*)&s,sizeof(goods));
        if(strcmp(s.name,r.name)==0 && s.count!=0){
            r.price=s.price;
            r.price_dif = s.price-s.stock;
            r.profit = (r.price_dif)*(r.sum);
            if((s.count-r.sum)>=0){
                s.count=s.count-r.sum;
                fin.seekp(-sizeof(goods),ios::cur);
                int wz = fin.tellg();
                fin.close();
                fstream ff("goods_info.txt",ios::out|ios::in);
                ff.seekp(wz);
                ff.write((char*)&s,sizeof(goods));
                ff.close();
                goto next;
            }else{
                cout<<"库存不足，缺货\n";
                fin.close();
                goto again;
            }
        }
    }
    cout<<"该商品不存在！";
    fin.close();
    goto again;
next:
    time_t now;
    time(&now);
    r.t=*(localtime(&now));
    ofstream fout("shell_info.txt",ios::app);
    fout.write((char*)&r,sizeof(receipt));
    fout.close();
    fin.close();
    
    char con;
    cout<<"是否继续售卖商品（y/n）\n";
    cin>>con;
    while(cin.get()!='\n') cin.clear();
    if(con=='Y'||con=='y'){
        goto again;
    }else{
        receipt r1;
        float add=0.00;
        float subprice=0.00;
        ifstream fin("shell_info.txt",ios::in);
        system("clear");
        cout<<"\t\t********小票清单*******"<<endl;
        cout<<name1<<"售货员\n";
        cout<<"商品名    商品数       金额"<<endl;
        while (fin.peek()!=EOF) {
            fin.read((char*)&r1,sizeof(receipt));
            cout<<r1.name<<"         "<<r1.sum<<"   ";
            printf("     ¥%.2f\n",(r1.sum*r1.price));
            add+=r1.profit;
            subprice+=(r1.sum*r1.price);
        }
        cout<<"\t\t\t$$$$总金额$$$$$$$\n"<<"\t\t\t\t"<<subprice<<endl;
        cout<<"\t\t输入收钱金额:\n";
        cin>>money;
        while(cin.get()!='\n') cin.clear();
        if(money>=subprice){
            cout<<"\n\t实收:";
            printf("¥%.2f\n",money);
            cout<<"\n\t找零";
            printf("¥%.2f\n",money-subprice);
            
        }else if(money<subprice){
            cout<<"\t\t金额不足!!!!!!!!!!\n\t\t###########需要再交  ¥"<<subprice-money<<"##########\n";
        }
        
        ct.profit=add;
        ct.subprice =subprice;
        ct.t=r1.t;
        ct.countor = name1;
        fc.write((char*)&ct,sizeof(counter));
        fc.close();
        cout<<"\t商品总金额\t\t 交易时间\n"<<endl;
        printf("\t¥%.2f   \t\t %d-%d-%d  %d:%d:%d",subprice,r1.t.tm_year+1900,r1.t.tm_mon+1,r1.t.tm_mday,r1.t.tm_hour,r1.t.tm_min,r1.t.tm_sec);
        cout<<"\n*************************************************"<<endl;
        fin.close();
        ofstream fg("shell_info.txt",ios::out);
        fg.close();
        
        cin_second(2,name1);
    }
}

void today_check(string& name1){
    system("clear");
    counter c;
    time_t now;
    time(&now);
    struct tm tt;
    tt =*(localtime(&now));
    float addprice=0.00;
    float addprofit=0.00;
    ifstream fin("counter.txt",ios::in);
    cout<<"当日总销售额\n";
    
    while (fin.peek()!=EOF) {
        fin.read((char*)&c,sizeof(counter));
        if(c.countor==name1 && c.t.tm_year==tt.tm_year && c.t.tm_mon==tt.tm_mon &&c.t.tm_mday==tt.tm_mday){
            addprice+=c.subprice;
            addprofit+=c.profit;
        }
    }
    printf("\t\t %d年%d月%d日\n",tt.tm_year+1900,tt.tm_mon+1,tt.tm_mday);
    cout<<name1<<"售货员\n";
    printf("总销售额¥%.2f\n总利润¥%.2f\n",addprice,addprofit);
    fin.close();
    cin_second(2,name1);
    
}

void someday_info(string& name1){
    system("clear");
    counter c;
    time_t now;
    time(&now);
    int year,month;
    float addprice,addprofit;
    struct tm tt;
    tt =*(localtime(&now));
    ifstream fin("counter.txt",ios::in);
    cout<<"*******查询指定日期的总销售额和利润******\n";
    cout<<"输入年份\n";
    cin>>year;
    tt.tm_year=year-1900;
    cout<<"输入月份\n";
    cin>>month;
    tt.tm_mon=month-1;
    cout<<"输入几号\n";
    cin>>tt.tm_mday;
    while (fin.peek()!=EOF) {
        fin.read((char*)&c,sizeof(counter));
        if(c.t.tm_year==tt.tm_year && c.t.tm_mon==tt.tm_mon &&c.t.tm_mday==tt.tm_mday){
            addprice+=c.subprice;
            addprofit+=c.profit;
        }
    }
    printf("\t\t %d年%d月%d日\n",tt.tm_year+1900,tt.tm_mon+1,tt.tm_mday);
    printf("总销售额¥%.2f\n总利润¥%.2f\n",addprice,addprofit);
    cin_second(1,name1);
}

void lost(){
    string name1;
    goods s;
    ifstream fin("goods_info.txt",ios::in);
    while (fin.peek()!=EOF) {
        fin.read((char*)&s,sizeof(goods));
        if(s.count==0){
            cout<<"\n\n提醒\t"<<s.name<<" 缺货"<<endl;
        }
    }
    cout<<"\n\n";
    fin.close();
}
