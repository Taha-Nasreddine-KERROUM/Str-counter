#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char r;
    int t;
} tally;

void display ( tally *l ) {
    puts(" character | repetition ");
    for ( tally *a = l; a->t; ++a )
        printf(" %5c %5c %5d\n", a->r, '|', a->t);
}

void strtolower ( char *str ) {
    for ( char *s = str; *s; ++s )
        *s = tolower( *s );
}

tally* count ( char *str ) {
    tally *l = ( tally* ) calloc ( strlen(str),  sizeof( tally ) );
    if ( l == NULL ) {
        puts(" l's memory contiguousing fail ");
        abort();
    }
    
    int n = strlen( str ), k = 0;
    
    strtolower(str);
    
    for ( int i = 0; i < n; ++i ){
        if ( !str[i] ) continue;
        
        char s = str[i], *p = &str[i];
        int c = 0;
        
        k++;
        
        while ( p ) {
            c++;
            *p = '\0';
            
            p = memchr( p + 1, s, n - i );
        }
        
        l[k-1].r = s;
        l[k-1].t = c;
        
    }
    
    l = ( tally* ) realloc ( l, (k + 1) * sizeof( tally ) );
    if ( l == NULL ) {
        puts(" l's memory re-allocation fail ");
        abort();
    }
    
    return l;
}

int main() {
    char *str = ( char* ) malloc ( 400 );
    if ( str == NULL ) {
        puts(" str's memory allocation fail ");
        abort();
    }
    
    printf(" string: ");
    gets(str);
    
    str = (char *)realloc(str, strlen(str) + 1);
    if ( str == NULL ) {
        puts(" str's memory re-allocation fail ");
        abort();
    }
    
    tally *l = count( str );
    display( l );
    
    free(str);
    str = NULL;
    free(l);
    l = NULL;
    return 0;
}
