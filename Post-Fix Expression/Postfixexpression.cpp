#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

//node structure
struct node
{
	int data;
	node *next;
}*p = NULL, *top = NULL, *save = NULL, *ptr;

//void to push the ints into a a node/stack
void push(int x)
{
	p = new node;
	p->data = x;
	p->next = NULL;
	if (top == NULL)
	{
		top = p;
	}
	else
	{
		save = top;
		top = p;
		p->next = save;
	}
}

//pop the top of the stack depending on the next item in the expression
char pop()
{
	if (top == NULL)
	{
		cout << "underflow!!";
	}
	else
	{
		ptr = top;
		top = top->next;
		return(ptr->data);
		delete ptr;
	}
}

//main void of the program
int main()
{
	//char for the answer and ints for the expression
	char x[30];
	int a, b;
	//asks the user to enter and expression
	cout << "Enter an expression\n";
	cin >> x;
	//for the entered expression use it's length to run it through the program till it hits the end
	for (int i = 0; i < strlen(x); i++)
	{
		//if the number in the string is greater than 48 and less than 57 push the int
		if (x[i] >= 48 && x[i] <= 57)
			push(x[i] - '\0');
		//otherwise pop based on the symbol
		else if (x[i] >= 42 && x[i] <= 47)
		{
			a = pop();
			b = pop();
			//adds the two ints
			switch (x[i])
			{
			case '+':
				push(a + b);
				break;
			//minus the two ints
			case '-':
				push(a - b);
				break;
			//multiplies the two ints
			case '*':
				push(a*b);
				break;
			//divides the two ints
			case '/':
				push(a / b);
				break;
			}
		}
	}
	//diplays the answer to the expression
	cout << "Answer to the expression is " << pop() << endl;
	//pauses the system so you can look at the displayed text
	system("Pause");
}