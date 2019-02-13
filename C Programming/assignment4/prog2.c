#include<stdio.h>
void main()
{

char *color[6] = {"red", "green", "blue", "white", "black", "yellow"};
printf("%u\n",color);
printf("%u\n",color+2);
printf("%s\n",*color);
printf("%s\n",*(color+2));
printf("%s\n",*(color+5));

}
