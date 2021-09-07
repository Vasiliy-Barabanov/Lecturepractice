#include <string.h>
int srtConteins(char* a, char* str) 
{
	int n = strlen(str) - strlen(a);
	int k = 0;
	while (k != n + 1) 
	{
		for (int i = 0; i < strlen(a); i++) 
		{
			if (a[i] != str[k+i]) {
				break;
			}
			else
			{
				if (i == strlen(a) - 1) {
					return k;
				}
			}
		}
		k++;
	}
	return -1;
}