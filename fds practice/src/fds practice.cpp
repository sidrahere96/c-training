#include <iostream>
using namespace std;

const int MAX=20;

class stack
{
	int top;
	char str[MAX];

public:
	stack()
	{
		top=-1;
	}

	bool isempty();
	bool isfull();
	char pop();
	void push(char a);
	void display();
	void check();
};

bool stack :: isempty() // @suppress("No return")
{
	if(top==-1)
		return 1;
}

bool stack :: isfull() // @suppress("No return")
{
	if(top== MAX-1)
		return 1;
}

char stack :: pop() // @suppress("No return")
{
	if(!isempty())
	{
		char a=str[top];
		top--;
		return a;
	}
	else
	    return '\0';
}

void stack :: push(char a)
{
	if(isfull() != 1)
	{
		top++;
		str[top]=a;
		display();
	}
}

void stack:: display()
{
	if(isempty() != 1)
	{
		for(int i=0;i<=top;i++)
			cout<<str[i]<<"  ";
	}
}

void stack :: check()
{
	char str[MAX];
	cout<<"******ENTER # TO TERMINATE YOUR STRING*****";
	cout<<"\nENTER YOUR STRING:";
	cin.getline(str,MAX,'#');
	bool flag=0;

	for (int i=0; str[i]!='\0';i++)
	{
	    if(str[i]=='(' || str [i]=='{' || str[i]=='[')
	    {
	        push(str[i]);
	    }
        else if(str[i]==')' || str [i]=='}' || str[i]==']')
        {
            char a=pop();
            if(str[i]==')' && a != '(' || str[i]=='}' && a != '{' || str[i]==']' && a != '[' )
            {
                cout<<"\nNOT PARENTHISED AT "<<i<<" = "<<str[i];
                flag =1;
                break;
            }
        }
	}

	if(isempty()==1 && flag ==0)
	    cout<<"\nWELL PARENTHISED!";
    else
	    cout<<"\nNOT WELL PARENTHISED!" ;
}

int main()
{
	stack st;
	int v;
	do
	{
		st.check();
		cout<<"\nENTER 1 TO CONTINUE:";
		cin>>v;
	}while(v==1);

	return 0;
}
