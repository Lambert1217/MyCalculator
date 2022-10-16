#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "mylstack.h"
#include <string>
#include <QString>
#include <cmath>

using namespace std;

class Calculator
{
private:
    MyLStack<char> optr;  //操作符栈
    MyLStack<double> opnd;  //操作数栈
    double x,y; //需要计算的两个操作数
    char cch; //当前处理的操作符
    char pch = '='; //前一个操作符
    char cop; //当前计算的操作符
public:
    Calculator();
    bool getResult(const string &expression); //返回结果
    void reset();
    double result; //结果
    QString error_message;
private:
    int isp(char ch); //栈内优先级
    int osp(char ch); //栈外优先级
    bool cal(char op,double x,double y,double &r);
    bool isdigit(char ch);
    bool isOperator(char ch);
    bool isBracketCorrect(const string &expression);
};

#endif // CALCULATOR_H
