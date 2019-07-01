#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *readline() {
	char *s;
	char c;
	int size = 2;
	int i = 0;
	s = malloc ( size );

	while ( ( c = getchar() ) != '\0') {
		if ( i >= size) {
			size *= 2;
			s = realloc ( s, size );

		}
		if (c=='\n') {
			s[i] = '\0';
			break;
		}
		s[i++] = c;

	}
	//printf( "%s
	return s;
}



int main() {
	int n, i, left, right, mid;
	char *x[100], *y;
	scanf("%d ",&n);

	for (i=0;i<n;i++)			//con n = 10, leggo le prime n righe e le inserisco nell'array
		x[i] = readline();


	y = readline();

	left=0; right=n-1;
	while (left<=right) {
		mid=(left+right)/2;
		if ( strcmp( x[mid], y) == 0 ) {
			printf("= %s\n", y);
			return 0;
		} else if (strcmp(x[mid],y)< 0 ) {
			printf("> %s\n",x[mid]);
			left=mid+1;
		} else {
			printf("< %s\n",x[mid]);
			right=mid-1;
		}
	}
}
