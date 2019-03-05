#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<string>
void Expand(char *s1, char *s2)
{
	int i,k;//loop iterators
	int j=0;
	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] != '-')//identification of dash
			s2[j++] = s1[i];
		else
		{
			if (isdigit(s1[i - 1]))//checking for digits
			{
				for (k = s1[i - 1] - 47; k < s1[i + 1] - 48; k++)//ASCII range of numbers 0(48) to 9(57)
					s2[j++] = k + 48;
			}
			else if(s1[i-1]>=97&&s1[i-1]<=122) //lowercase alphabets
			{
				for (k = s1[i - 1] - 96; k < s1[i + 1] - 97; k++)
					s2[j++] = k + 97;
			}
			else
            {  for(k = s1[i - 1] - 64; k < s1[i + 1] - 65; k++)//uppercase alphabets(65-90)
                    s2[j++] = k + 65;

			}
		}
	}
	s2[j] = '\0';
}
int main()
{
	string s1,s2;
	printf("enter string 1 \n");
	scanf("%s", s1);
	Expand(s1, s2);
	printf(" Expanded String is %s", s2);
	return 0;
}
