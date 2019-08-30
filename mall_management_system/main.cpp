
#include "cin.h"

int main(){
top:
    show_top();
    int num =cin_top();
    if(num!=1&&num!=0){
        cout<<"选项不存在!\n";
        system("clear");
        goto top;
    }
    switch (num) {
        case 1:
            login();
            break;
        case 0:
            exit(0);
            break;
        default:
            cout<<"无选项"<<endl;
            system("clear");
            goto top;
            break;
    }
    return 0;
}

