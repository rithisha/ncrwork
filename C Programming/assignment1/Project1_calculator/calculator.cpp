#include<stdio.h>
#include<iostream>
using namespace std;
#pragma warning(disable:4996)
#include<stack>
int add(int, int);
int sub(int, int);
int mul(int, int);
int divi(int, int);
int check_prec(char operators) {
	if (operators == '+' || operators == '-')
		return 1;
	if (operators == '*' || operators == '/')
		return 2;
	return 0;
}		
int performOP(int a, int b, char op) {
	int res;
	switch (op) {
	case '+': res = add(a, b); break;
	case '-': res = sub(a, b); break;
	case '*': res = mul(a, b); break;
	case '/': res = divi(a, b); break;
	default:cout << "invalid operator\n";
	}
	return res;
}

int evaluate(char *in_string)
{
	stack<int> operand;
	stack<char> operators;
	int i;
	for (i = 0; in_string[i] != '\0'; i++)
	{
		if (in_string[i] == ' ')//if space is encountered
			continue;
		else if (in_string[i] == '(')//for open brace push into character stack
			operators.push(in_string[i]);
		else if (isdigit(in_string[i]))//for digits
		{
			int value_1 = 0;
			while (in_string[i] != '\0' && isdigit(in_string[i]))
			{
				value_1 = value_1 * 10 + in_string[i] - '0';//calculating its value if more than 1 digit no.s
				i++;
			}
			i--;//to point back as it doesn't get evaluated due to major for loop(i++)
			operand.push(value_1);//pushing value of no. obtained into integer stack
			cout << value_1 << endl;
		}
		else if (in_string[i] == ')')
		{
			while ((!operators.empty()) && operators.top() != '(')//if char stack isnt empty
			{
				int op1 = operand.top();
				operand.pop();
				int op2 = operand.top();
				operand.pop();
				char op = operators.top();
				operators.pop();

				operand.push(performOP(op2, op1, op));
			}
			operators.pop();

		}
		else
		{
			while (!operators.empty() && check_prec(operators.top()) >= check_prec(in_string[i]))//checking precedence of operators
			{
				float op1 = operand.top();
				operand.pop();
				int op2 = operand.top();
				operand.pop();

				char op = operators.top();
				operators.pop();
				operand.push(performOP(op2, op1, op));
			}
			operators.push(in_string[i]);
		}
	}
	while (!operators.empty())
	{
		int op1 = operand.top();
		operand.pop();
		int op2 = operand.top();
		operand.pop();

		char op = operators.top();
		operators.pop();
		operand.push(performOP(op2, op1, op));
	}
	cout << operand.top();
	return operand.top();
}
int main()
{
	int size;
	char *in_string;
	printf("enter size of input\n");
	scanf("%d", &size);
	in_string = (char *)malloc(size * sizeof(char));
	printf("Enter input expression to evaluate\n");
	cin>>in_string;
	printf("Result = %d\n", evaluate(in_string));
	free(in_string);
	system("pause");
	return 0;
}