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

int stalin( tally *t, int size ) {
    int k = 1;
    for ( tally *p = t + 1; p < t + size; ++p) {
        if ( p->r == (p - 1)->r ) continue;
        *(t + k++) = *p;
        
    }
    return k;
}

int cmpfun(const void *a, const void *b) {
    return (*(const char*)b - *(const char*)a);
}

tally* count ( char *str, int *n ) {
    int k = 0;
    tally *l = ( tally* ) calloc ( strlen(str),  sizeof( tally ) );
    assert ( l != NULL );
    
    strtolower(str);
    qsort(str, strlen(str), sizeof(char), cmpfun);
    
    for ( char *i = str; *i; ++i ){
        
        char *p = strchr(str, *i);
        int c = 0;
        
        while ( p ) {
            c++;
            p = strchr(p + 1, *i);
        }
        
        l[k].r = *i;
        l[k++].t = c;
        
    }
    
    
    *n = stalin( l, strlen(str) );
    
    l = ( tally* ) realloc ( l, *n * sizeof( tally ) );
    assert ( l != NULL );
    
    
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
