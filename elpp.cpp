#include <iostream>
#include <windows.h>

#pragma execution_character_set("utf-8")

using namespace std;

void showHelp(){
    cout<<"사용법\n"<<
          "elpp 파일이름.elpp"<<endl;
}

int main(int argc,char* argv[]){
    SetConsoleOutputCP(65001);

    if(argc==2){
    }else{
        showHelp();
    }
    system("pause");
    return 0;
}
