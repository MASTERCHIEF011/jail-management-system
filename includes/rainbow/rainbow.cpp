#include<string>
#include"rainbow.h"


std::string rainbow::info(std::string str){
    std::string x;
    x.append("\e[33m");
    x.append(str);
    x.append("\e[0m");
    return x;
}

std::string rainbow::safe(std::string str){
    std::string x;
    x.append("\e[32m");
    x.append(str);
    x.append("\e[0m");
    return x;
}

std::string rainbow::warn(std::string str){
    std::string x;
    x.append("\e[31m");
    x.append(str);
    x.append("\e[0m");
    return x;
}
