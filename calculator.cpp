#include "calculator.h"

Calculator::Calculator()
{
    reset();
}

bool Calculator::getResult(const string &expression){
    //初始化
    reset();
    //判断是否滥用括号
    if(!isBracketCorrect(expression)){return false;}
    //控制数字读取
    double base = 1;
    for(unsigned int i = 0;i < expression.size();i++){
        //是数字
        cch = expression[i];
        if(cch == '.') {if(base > 1){base = 0.1; continue;}else{error_message = "Error:Misuse Point."; return false;}}
        if(isdigit(cch)){
            //整数部分
            double num = (int)cch-'0';
            if(base == 1){opnd.push(num); base = 10; pch = cch; continue;}
            if(base == 10){num+=base*opnd.pop(); opnd.push(num); pch = cch; continue;}
            //小数部分
            if(base < 1){num=opnd.pop()+num*base; opnd.push(num); base*=0.1; pch = cch; continue;}
        }
        //是操作符
        else if(isOperator(cch)){
            //重置数字读取
            base = 1;
            //防止操作符连用，乱用
            if(isOperator(pch)) {if((pch == '='||pch == '(')&&(cch == '-'||cch == '+')){double num = 0;opnd.push(num);optr.push(cch);pch = cch;continue;}
                else if(cch == '('||cch == '='){optr.push(cch);pch = cch;continue;}
                else{error_message = "Error:Misuse operators."; return false;}}
            //当上一个字符为数字时，执行以下操作
            if(isdigit(pch)){
                //实现计算过程
                if(isp(optr.topValue())>osp(cch)) {
                    while(isp(optr.topValue())>osp(cch)){
                        y=opnd.pop();  x=opnd.pop(); cop=optr.pop();
                        if(!cal(cop,x,y,result)) return false;
                        opnd.push(result);
                    }
                }
                if(isp(optr.topValue())<osp(cch)) {optr.push(cch); pch=cch; continue;}
                if(isp(optr.topValue())==osp(cch)){
                    optr.pop();
                    pch = '0';
                }
            }
        }
        //非法
        else{
            error_message = "Error:Illegal character.";
            return false;
        }
    }
    result = opnd.pop();
    return true;
}

void Calculator::reset(){
    optr.clear();
    opnd.clear();
    pch = '=';
    result = 0;
    optr.push(pch);
}

int Calculator::isp(char ch){
    switch (ch) {
    case '=': return 0;
        break;
    case '+': return 3;
        break;
    case '-': return 3;
        break;
    case '*': return 5;
        break;
    case '/': return 5;
        break;
    case '%': return 5;
        break;
    case '(': return 1;
        break;
    case ')': return 8;
        break;
    case '^': return 7;
        break;
    case '&': return 7;
        break;
    default: return -1;
        break;
    }
}

int Calculator::osp(char ch){
    switch (ch) {
    case '=': return 0;
        break;
    case '+': return 2;
        break;
    case '-': return 2;
        break;
    case '*': return 4;
        break;
    case '/': return 4;
        break;
    case '%': return 4;
        break;
    case '(': return 8;
        break;
    case ')': return 1;
        break;
    case '^': return 6;
        break;
    case '&': return 6;
        break;
    default: return -1;
        break;
    }
}

bool Calculator::isdigit(char ch){
    if(ch >= '0'&& ch <= '9') return true;
    return false;
}

bool Calculator::isOperator(char ch){
    switch (ch) {
    case '=': return true;
        break;
    case '+': return true;
        break;
    case '-': return true;
        break;
    case '*': return true;
        break;
    case '/': return true;
        break;
    case '%': return true;
        break;
    case '(': return true;
        break;
    case ')': return true;
        break;
    case '^': return true;
        break;
    case '&': return true;
        break;
    default: return false;
        break;
    }
}

bool Calculator::cal(char op, double x, double y, double &r){
    switch (op) {
    case '=': return true;
        break;
    case '+': r=x+y; return true;
        break;
    case '-': r=x-y; return true;
        break;
    case '*': r=x*y; return true;
        break;
    case '/': if(y == 0){error_message = "Error:Divide by zero.(/)";return false;}else{r=x/y;return true;}
        break;
    case '%': if(y == 0){error_message = "Error:Divide by zero.(%)";return false;}else{r=fmod(x,y);return true;}
        break;
    case '(': return true;
        break;
    case ')': return true;
        break;
    case '^': if(x < 0 && (int)y != y){error_message = "Error:The power of a negative number to the decimal.";return false;}
              if(x == 0 && y <= 0){error_message = "Error:Non positive power of zero.";return false;}
              r=pow(x,y);return true;
        break;
    case '&': if(x < 0 && fmod(y,2) == 0){error_message = "Error:Even root of negative number.";return false;}
              if(x == 0 && y < 0){error_message = "Error:Negative root of zero.";return false;}
              if(y == 0){error_message = "Error:Cannot be written to the zero power.";return false;}
              r=pow(x,1.0/y); return true;
            break;
    default: error_message = "Error:Illegal character."; return false;
        break;
    }
}

bool Calculator::isBracketCorrect(const string &expression){
    bool left = false;
    for(unsigned int i = 0;i < expression.size();i++){
        if((expression[i] == '(' && left == false)||(expression[i] == ')' && left == true)) {left = !left;continue;}
        if((expression[i] == '(' && left == true)||(expression[i] == ')' && left == false)) {error_message = "Error:Incorrect use of brackets.";return false;}
    }
    return true;
}



