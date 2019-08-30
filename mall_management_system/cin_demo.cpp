#include "cin.h"


int cin_top(){
    int num;
    cout<<"请输入菜单选项\n";
    cin>>num;
    while(cin.get()!='\n') cin.clear();
    return num;
}




void cin_second(int power,string& name){
    if(power==1){
again:
        show_second();
        int num;
        num = cin_top();
        switch (num) {
            case 1:
                change_user();
                break;
            case 2:
                register_user();
                break;
            case 3:
                skim();
                break;
            case 4:
                del_goods(name);
                break;
            case 5:
                insert_goods(name);
                break;
            case 6:
                del_user();
                break;
            case 7:
                someday_info(name);
                
                break;
            case 0:
                login();
                break;
            default:
                cout<<"无该选项！！！\n";
                goto again;
                break;
        }
        
    }else if(power==2){
secondly:
        lost();
        show_third();
        int num;
        num = cin_top();
        switch (num) {
            case 1:
                change_mine(name);
                break;
            case 2:
                shell(name);
                break;
            case 3:
                today_check(name);
                break;
            case 4:
                system("clear");
                cout<<"\t\t\t\t******缺货商品******\n";
                lost();
                cin_second(2,name);
                break;
                
            case 0:
                login();
                break;
            default:
                cout<<"无该选项！！！\n";
                goto secondly;
                break;
        }
        
    }else if(power==0){
        cout<<"该用户已注销\n";
        system("clear");
        login();
    }
    
}
