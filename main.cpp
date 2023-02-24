#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
//#include <windows.h>

using namespace std;

enum class tokenType{
    NONE=0,
    PRINT_NUM,
    PRINT_ASCII,
    NUMBER,
    MUL,
    DIV,
    OR,
    AND,
    XOR,
    VAR,
    FUNCTION,
    NAME,
    GOTO,
    JMP,
    CALL,
    IF,
    SET,
    RETURN,
    ENDLINE
};

constexpr const char* tokenTypeToString(tokenType e) throw(){
    switch (e){
        case tokenType::NONE: return "NONE";
        case tokenType::PRINT_NUM: return "PRINT_NUM";
        case tokenType::PRINT_ASCII: return "PRINT_ASCII";
        case tokenType::NUMBER: return "NUMBER";
        case tokenType::MUL: return "MUL";
        case tokenType::DIV: return "DIV";
        case tokenType::OR: return "OR";
        case tokenType::AND: return "AND";
        case tokenType::XOR: return "XOR";
        case tokenType::VAR: return "VAR";
        case tokenType::FUNCTION: return "FUNCTION";
        case tokenType::NAME: return "NAME";
        case tokenType::GOTO: return "GOTO";
        case tokenType::JMP: return "JMP";
        case tokenType::CALL: return "CALL";
        case tokenType::IF: return "IF";
        case tokenType::SET: return "SET";
        case tokenType::RETURN: return "RETURN";
        case tokenType::ENDLINE: return "ENDLINE";
        default: throw std::invalid_argument("Unimplemented item");
    }
}

struct token{
    tokenType type;
    int value;
};

vector<token> tokenizer(wstring line){
    vector<token> tokens;
    tokenType type=tokenType::NONE;
    int value;
    char prevStr[4];
    char str[4]={0};
    int length=line.size();
    for(int i=0;i<length;i++){
        strcpy(prevStr,str);
        if(line[i]<=127){
            str[0]=line[i];
            str[1]=0;
        }else{
            str[0]=line[i];
            str[1]=line[i+1];
            str[2]=line[i+2];
            str[3]=0;
            i+=2;
        }
        if(strcmp(str,".")==0||strcmp(str,",")==0){
            if(type!=tokenType::NUMBER){
                if(type!=tokenType::NONE){
                    throw runtime_error("unknown token");
                }
                type=tokenType::NUMBER;
                value=0;
            }
            if(strcmp(str,".")==0){
                value++;
            }else{
                value--;
            }
            char str[2];
            str[0]=line[i+1];
            str[1]=0;
            if(strcmp(str,".")!=0&&strcmp(str,",")!=0){
                tokens.push_back(token{tokenType::NUMBER,value});
                type=tokenType::NONE;
            }
        }else if(strcmp(str,"~")==0){
            if(type!=tokenType::NONE){
                throw runtime_error("unknown token");
            }
            tokens.push_back(token{tokenType::MUL,0});
            type=tokenType::NONE;
        }else if(strcmp(str,"-")==0){
            if(type!=tokenType::NONE){
                throw runtime_error("unknown token");
            }
            tokens.push_back(token{tokenType::DIV,0});
            type=tokenType::NONE;
        }else if(strcmp(str,"|")==0){
            if(type!=tokenType::NONE){
                throw runtime_error("unknown token");
            }
            tokens.push_back(token{tokenType::OR,0});
            type=tokenType::NONE;
        }else if(strcmp(str,"&")==0){
            if(type!=tokenType::NONE){
                throw runtime_error("unknown token");
            }
            tokens.push_back(token{tokenType::AND,0});
            type=tokenType::NONE;
        }else if(strcmp(str,"^")==0){
            if(type!=tokenType::NONE){
                throw runtime_error("unknown token");
            }
            tokens.push_back(token{tokenType::XOR,0});
            type=tokenType::NONE;
        }else if(strcmp(str,"만")==0||type==tokenType::PRINT_NUM){
            if(type!=tokenType::PRINT_NUM){
                if(type!=tokenType::NONE){
                    printf("%s %s\n",str,prevStr);
                    throw runtime_error("unknown token");
                }
                type=tokenType::PRINT_NUM;
                value=3;
            }else{
                int size=strlen(str);
                string name="만들기 ";
                if(strcmp(str,name.substr(value,size).c_str())!=0){
                    throw runtime_error("unknown token");
                }
                value+=size;
                if(strcmp(prevStr,"기")==0){
                    tokens.push_back(token{tokenType::PRINT_NUM,0});
                    type=tokenType::NONE;
                }
            }
        }else if(strcmp(str,"생")==0||type==tokenType::PRINT_ASCII){
            if(type!=tokenType::PRINT_ASCII){
                if(type!=tokenType::NONE){
                    printf("%s %s\n",str,prevStr);
                    throw runtime_error("unknown token");
                }
                type=tokenType::PRINT_ASCII;
                value=3;
            }else{
                int size=strlen(str);
                string name="생각하기 ";
                if(strcmp(str,name.substr(value,size).c_str())!=0){
                    throw runtime_error("unknown token");
                }
                value+=size;
                if(strcmp(prevStr,"기")==0){
                    tokens.push_back(token{tokenType::PRINT_ASCII,0});
                    type=tokenType::NONE;
                }
            }
        }else if(strcmp(str,"탈")==0||type==tokenType::RETURN){
            if(type!=tokenType::RETURN){
                if(type!=tokenType::NONE){
                    printf("%s %s\n",str,prevStr);
                    throw runtime_error("unknown token");
                }
                type=tokenType::RETURN;
                value=3;
            }else{
                int size=strlen(str);
                string name="탈트리 ";
                if(strcmp(str,name.substr(value,size).c_str())!=0){
                    throw runtime_error("unknown token");
                }
                value+=size;
                if(strcmp(prevStr,"리")==0){
                    tokens.push_back(token{tokenType::RETURN,0});
                    type=tokenType::NONE;
                }
            }
        }else if(strcmp(str,"에")==0||strcmp(str,"엔")==0||(strcmp(str,"트")==0&&type!=tokenType::FUNCTION)||(strcmp(str,"리")==0&&type!=tokenType::GOTO)){
            if(type!=tokenType::VAR){
                if(type!=tokenType::NONE){
                    throw runtime_error("unknown token");
                }
                type=tokenType::VAR;
                value=0;
            }
            if(strcmp(str,"에")==0){
                value++;
            }else if(strcmp(str,"트")==0&&strcmp(prevStr,"엔")!=0){
                throw runtime_error("unknown token");
            }else if(strcmp(str,"리")==0){
                if(strcmp(prevStr,"트")!=0){
                    throw runtime_error("unknown token");
                }
                tokens.push_back(token{tokenType::VAR,value});
                type=tokenType::NONE;
            }
        }else if(strcmp(str,"두")==0||strcmp(str,"둣")==0||(strcmp(str,"교")==0&&type!=tokenType::FUNCTION)){
            if(type!=tokenType::NAME){
                if(type!=tokenType::NONE){
                    throw runtime_error("unknown token");
                }
                type=tokenType::NAME;
                value=0;
            }
            if(strcmp(str,"두")==0){
                value++;
            }else if(strcmp(str,"교")==0){
                if(strcmp(prevStr,"둣")!=0){
                    throw runtime_error("unknown token");
                }
                tokens.push_back(token{tokenType::NAME,value});
                type=tokenType::NONE;
            }
        }else if(strcmp(str,"!")==0){
            if(type!=tokenType::NONE){
                throw runtime_error("unknown token");
            }
            tokens.push_back(token{tokenType::SET,0});
            type=tokenType::NONE;
        }else if(strcmp(str,"?")==0){
            if(type!=tokenType::NONE){
                throw runtime_error("unknown token");
            }
            tokens.push_back(token{tokenType::IF,0});
            type=tokenType::NONE;
        }else if(strcmp(str,"소")==0||type==tokenType::FUNCTION){
            if(type!=tokenType::FUNCTION){
                if(type!=tokenType::NONE){
                    printf("%s %s\n",str,prevStr);
                    throw runtime_error("unknown token");
                }
                type=tokenType::FUNCTION;
                value=3;
            }else{
                int size=strlen(str);
                string name="소프트웨어 교육의 첫걸음 ";
                if(strcmp(str,name.substr(value,size).c_str())!=0){
                    throw runtime_error("unknown token");
                }
                value+=size;
                if(strcmp(prevStr,"음")==0){
                    tokens.push_back(token{tokenType::FUNCTION,0});
                    type=tokenType::NONE;
                }
            }
        }else if(strcmp(str,"우")==0||type==tokenType::GOTO){
            if(type!=tokenType::GOTO){
                if(type!=tokenType::NONE){
                    printf("%s %s\n",str,prevStr);
                    throw runtime_error("unknown token");
                }
                type=tokenType::GOTO;
                value=3;
            }else{
                int size=strlen(str);
                string name="우리는 무엇이든 될수 있어요";
                if(strcmp(str,name.substr(value,size).c_str())!=0){
                    throw runtime_error("unknown token");
                }
                value+=size;
                if(strcmp(str,"요")==0){
                    tokens.push_back(token{tokenType::GOTO,0});
                    type=tokenType::NONE;
                }
            }
        }else if(strcmp(str,"커")==0||type==tokenType::JMP){
            if(type!=tokenType::JMP){
                if(type!=tokenType::NONE){
                    printf("%s %s\n",str,prevStr);
                    throw runtime_error("unknown token");
                }
                type=tokenType::JMP;
                value=3;
            }
            string name="커뮤니티";
            if(strcmp(str,name.substr(value,3).c_str())==0&&
               strcmp(prevStr,name.substr(value-3,3).c_str())!=0){
                throw runtime_error("unknown token");
            }
            value+=3;
            if(strcmp(str,"티")==0){
                tokens.push_back(token{tokenType::JMP,0});
                type=tokenType::NONE;
            }
        }else if(strcmp(str," ")!=0){
            throw runtime_error("unknown token");
        }
    }
    if(type!=tokenType::NONE){
        tokens.push_back(token{type,value});
    }
    tokens.push_back(token{tokenType::ENDLINE,0});
    return tokens;
}

int getFile(char* path){
    wifstream ifs;
    ifs.open(path,ios::in);
    if (ifs.fail()){
        cerr<<"Could not load file: "<<path<<endl;
    }else{
        vector<token> tokens{};
        int i=0;
        wstring line;
        while(getline(ifs,line)){
            i++;
            vector<token> newTokens;
            try {
                newTokens=tokenizer(line);
            }catch(const exception& ex){
                printf("%s (line %d)",ex.what(),i);
                return 1;
            }
            tokens.insert(tokens.end(),newTokens.begin(),newTokens.end());
        }
        for(token token:tokens){
            printf("%s | %d\n",tokenTypeToString(token.type),token.value);
        }
    }
    ifs.close();
    return 0;
}

int main(int argc,char* argv[]){
    //SetConsoleOutputCP(65001);

    char path[1024];
    if(argc==2){
        strncpy(path,argv[1],(sizeof path)-1);
        path[1023]=0;
    }else{
        cout<<"path :";
        cin.getline(path,1024);
        path[1023]=0;
    }
    return getFile(path);
}
