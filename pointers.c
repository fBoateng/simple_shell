# include <stdio.h>
/*Playing with pointers
*Author: Andrew
*/


int main()

{
    int myAge = 24;
    int *ptr = &myAge;

	printf("%d\n", myAge);
	printf("%p\n", &myAge);
	printf("%p\n", ptr);
	printf("%p\n", *ptr);
    return 0;
}
