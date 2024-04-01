#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

//遍历栈
void StackTraverse(stack<char> a)
{
    string temp;
    while (!a.empty())
    {
        temp.append(1, a.top());
        a.pop();
    }
    reverse(temp.begin(),temp.end());
    for (int i = 0; i < temp.length(); i ++)
    {
        cout << temp[i];
        a.push(temp[i]);
    }
    cout << endl;
}

//获得某个字符的优先级
int GetPriority(char Operator)
{
    switch(Operator)
    {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

//比较两个字符的优先级
bool isLargeThan(char a, char b)
{
    return GetPriority(a) > GetPriority(b);
}

//中缀表达式变为后缀表达式
string Change(string s)
{
    stack<char> temp;
    string result = "";
    //从左向右开始扫描中缀表达式
    for (int i = 0; i < s.length(); i ++)
    {
        //遇到数字时加入后缀表达式
        if (s[i] >= 'a' and s[i] <= 'z')
            result.append(1, s[i]);
        
        //遇到运算符时
        else if (s[i] == '(')    //(1)若是“(”则入栈
            temp.push(s[i]);
        
        else if (s[i] == ')')   //(2)若是“)”则依次把栈中的运算符加入到后缀表达式,直到出现"(",并从栈中删除"("
        {
            if (temp.empty())
                cout << "Error!" << endl;
            else {
                while (temp.top() != '(' and !temp.empty())
                {
                    char k = temp.top();
                    result.append(1, k);
                    temp.pop();
                }
                temp.pop();
            }
        }
        
        else  //(3)若是接收到除以上两者的运算符时，若其优先级相对栈顶的运算符要高时或者栈顶为"("或者栈为空，直接入栈，否则从栈顶开始，依次弹出比当前处理的运算符优先级高和优先级相等的运算符到后缀表达式中，直到一个比它优先级低的或遇到一个"("为止
        {
            if (!temp.empty())
            {
                char top = temp.top();
                if (top == '(')
                    temp.push(s[i]);
                else if (isLargeThan(s[i], top))
                    temp.push(s[i]);
                else
                {
                    while (temp.top() != '(')
                    {
                        if (!isLargeThan(s[i], top))
                        {
                            result.append(1, top);
                            temp.pop();
                            if (temp.empty())
                                break;
                            else
                                top = temp.top();
                        }
                        else
                            break;
                    }
                    temp.push(s[i]);
                }
            }
            else
                temp.push(s[i]);
        }
        
        cout << "第" << i+1 << "次运算符栈的情况: ";
        StackTraverse(temp);
    }
    
    while (!temp.empty())
    {
        result.append(1, temp.top());
        temp.pop();
    }
    
    return result;
}

//测试
int main()
{
    string s = "10*(3-2)+8/4";
    string s2 = "a+b*(c-d)-e/f";
    cout << Change(s) << endl;
    cout << endl << Change(s2) << endl;
}

