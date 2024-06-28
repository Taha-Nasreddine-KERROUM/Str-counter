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

tally* count ( char *str, int *n ) {
    int k = 0;
    tally *l = ( tally* ) calloc ( strlen(str),  sizeof( tally ) );
    assert ( l != NULL );
    
    strtolower(str);
    
    for ( char *i = str; *i; ++i ){
        if ( strchr(str, *i ) < i ) continue;
        
        char *p = strchr(str, *i);
        int c = 0;
        
        while ( p ) {
            c++;
            p = strchr(p + 1, *i);
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
