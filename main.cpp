#include <iostream>
#include <fstream>

using namespace std;

void getFile(char* path){
    std::ifstream ifs;
    ifs.open(path,ios::in);
    if (ifs.fail()){
        cerr<<"Could not load file: "<<path<<endl;
    }else{
        //test
        char line[256] = { 0, };
        while (ifs.getline(line, 256)) {
            std::cout << line << std::endl;
        }
    }
    ifs.close();
}

int main(int argc,char* argv[]){
    if(argc==2){
        getFile(argv[1]);
    }else{
        char path[1024];
        cout<<"path :";
        cin.getline(path,1024);
        getFile(path);
    }
    return 0;
}
