#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

typedef struct {
    char r;
    int t;
} tally;

void display ( tally *l, int n) {
    puts(" character | repetition ");
    for ( tally *a = l; a < l + n; ++a )
        printf(" %5c %5c %5d\n", a->r, '|', a->t);
}

void strtolower ( char *str ) {
    for ( char *s = str; *s; ++s )
        *s = tolower( *s );
}

void swap ( char *a, char *b ) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

void bubbles ( char *str ) {
    int iend = strlen(str) - 1;
    char *cend = str + iend;
    for ( int i = 0; i <= iend; ++i )
        for ( char *j = str; j < cend; ++j )
            if ( *j > *(j + 1) )
                swap( j, j + 1 );
}

tally* count ( char *str, int *n ) {
    int k = 0;
    tally *l = ( tally* ) calloc ( strlen(str),  sizeof( tally ) );
    assert ( l != NULL );
    
    strtolower(str);
    bubbles(str);
    
    for ( char *i = str; *i; ++i){
        int c = 1;
        
        while( *(i + 1) && *i == *(i + 1) ){
            i++;
            c++;
        }
        
        l[k].r = *i;
        l[k++].t = c;
    }
    
    l = ( tally* ) realloc ( l, k * sizeof( tally ) );
    assert ( l != NULL );
    
    *n = k;
    
    return l;
}

int main() {
    int n;
    char *str = ( char* ) malloc ( 400 );
    assert ( str != NULL );
    
    printf(" string: ");
    gets(str);
    
    str = (char *)realloc(str, strlen(str) + 1);
    assert ( str != NULL );
    
    tally *l = count( str, &n );
    
    display( l, n );
    
    free(str);
    str = NULL;
    free(l);
    l = NULL;
    
    return 0;
}
