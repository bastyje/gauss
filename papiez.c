#include <stdio.h>
#include <string.h>

int main()
{
    char papiez[7];
    strcpy(papiez, "papiez");
    
    while (strcmp(papiez, "papiez") == 0)
        printf("%s\n", papiez);

    return 0;
}
