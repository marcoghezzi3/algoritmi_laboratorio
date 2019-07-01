#include<stdio.h>
#include<stdlib.h>

struct element {
	int val;
	int row;
	int col;
	struct element *right;
	struct element *down;
};

typedef struct element *Element;

typedef struct {
	Element head;
	int rows;
	int cols;
} linkedMatrix;


linkedMatrix leggiMatrice( void );
linkedMatrix trasponiMatrice ( linkedMatrix m );
void stampaMatrice ( linkedMatrix m );
void stampaMatriceTrasposta ( linkedMatrix m );



int main () {
	linkedMatrix m = leggiMatrice();
	stampaMatrice(m);
	printf( "\n" );
	stampaMatriceTrasposta(m);
	return 0;

}


linkedMatrix leggiMatrice( void ){

	int r,c;
	scanf( "%d%d", &r,&c );
	int t = r*c;
	Element curr; // puntatore all'elemento corrente della matrice
	Element first = NULL; // puntatore al primo elemento della riga corrente
	Element top = NULL; // puntatore all'elemento sopra a quello corrente (oppure NULL)

	linkedMatrix m;
	curr = malloc( sizeof (struct element) );
	m.head = curr;
	m.rows = r;
	m.cols = c;
	first = curr;

	int i=0, j=0, n;
	while ( --t >= 0 ) {
		scanf( "%d", &n );
		curr -> val = n;
		curr -> row = i;
		curr -> col = j;
		curr -> down = NULL;

		// collego l'elemento top all'elemento corrente
		if( top ) {
			top -> down = curr;
		}

		if ( t == 0 ) {
			curr -> right = NULL;
			break;
		}

		// creo spazio per il prossimo elemento
		Element new = malloc( sizeof (struct element) );

		// posiziono new
		// a destra dell'elemento corrente oppure all'inizio della prossima riga,
		// aggiorno first e top di conseguenza
		if ( j % c == c-1 ) {
			curr -> right = NULL;
			j = 0;

			first -> down = new;
			top = first;
			first = new;
			i++;
		}
		else {
			curr -> right = new;
			j++;
			if ( top )
				top = top->right;
		}

		// sposto curr sulla prossima posizione
//		printElement( curr );
		curr = new;
	}

return m;
}

void stampaMatrice ( linkedMatrix m ) {
	Element primo = m.head;
	Element curr = m.head;
	while (curr) {
		printf("%d ", curr -> val);
		if (curr -> right == NULL) {
			printf("\n");
			curr = primo -> down;
			primo = primo -> down;
		}
		else
			curr = curr -> right;
	}
}


void stampaMatriceTrasposta ( linkedMatrix m ) {
	Element first = m.head;
	Element curr = m.head;
	while (curr) {
		printf("%d ", curr -> val);
		if (curr -> down == NULL) {
			printf("\n" );
			curr = first -> right;
			first = first -> right;
		}
		else
			curr = curr -> down;
	}
}

linkedMatrix trasponiMatrice ( linkedMatrix m ) {
	linkedMatrix tras;
	tras.head = m.head;
	tras.rows = m.cols;
	tras.cols = m.rows;
	Element curr_tras; // puntatore all'elemento corrente della matrice
	Element first = NULL; // puntatore al primo elemento della riga corrente
	Element top = NULL; // puntatore all'elemento sopra a quello corrente (oppure NULL)
	Element curr = m.head;
	int t = m.rows*m.cols;
	curr = malloc(sizeof(struct element));
	curr_tras = tras.head;
	int i = 0, j = 0;
	first = curr_tras;
	while (curr -> right && curr -> down) {
		curr_tras -> val = curr -> val;
		curr_tras -> row = i;
		curr_tras -> col = j;
		curr_tras -> down = NULL;
	}


}
