#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

//����ջ
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

//���ĳ���ַ������ȼ�
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

//�Ƚ������ַ������ȼ�
bool isLargeThan(char a, char b)
{
    return GetPriority(a) > GetPriority(b);
}

//��׺���ʽ��Ϊ��׺���ʽ
string Change(string s)
{
    stack<char> temp;
    string result = "";
    //�������ҿ�ʼɨ����׺���ʽ
    for (int i = 0; i < s.length(); i ++)
    {
        //��������ʱ�����׺���ʽ
        if (s[i] >= 'a' and s[i] <= 'z')
            result.append(1, s[i]);
        
        //���������ʱ
        else if (s[i] == '(')    //(1)���ǡ�(������ջ
            temp.push(s[i]);
        
        else if (s[i] == ')')   //(2)���ǡ�)�������ΰ�ջ�е���������뵽��׺���ʽ,ֱ������"(",����ջ��ɾ��"("
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
        
        else  //(3)���ǽ��յ����������ߵ������ʱ���������ȼ����ջ���������Ҫ��ʱ����ջ��Ϊ"("����ջΪ�գ�ֱ����ջ�������ջ����ʼ�����ε����ȵ�ǰ�������������ȼ��ߺ����ȼ���ȵ����������׺���ʽ�У�ֱ��һ���������ȼ��͵Ļ�����һ��"("Ϊֹ
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
        
        cout << "��" << i+1 << "�������ջ�����: ";
        StackTraverse(temp);
    }
    
    while (!temp.empty())
    {
        result.append(1, temp.top());
        temp.pop();
    }
    
    return result;
}

//����
int main()
{
    string s = "10*(3-2)+8/4";
    string s2 = "a+b*(c-d)-e/f";
    cout << Change(s) << endl;
    cout << endl << Change(s2) << endl;
}

