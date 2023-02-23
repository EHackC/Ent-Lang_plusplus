#include <iostream>
#include <fstream>
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
        std::ifstream ifs;
        ifs.open(argv[1],ios::in);
        if (ifs.fail()){
            cerr<<"파일을 불러올수 없습니다: "<<argv[1]<<endl;
        }else{
            char line[256] = { 0, };
            while (ifs.getline(line, 256)) {
                std::cout << line << std::endl;
            }
        }
        ifs.close();
    }else{
        showHelp();
    }
    system("pause");
    return 0;
}
