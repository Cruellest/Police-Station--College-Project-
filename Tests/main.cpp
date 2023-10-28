#include <stdio.h>

void decript(char *senha, char *var){
    int m = 0;
    for (int i = 0; senha[i] != '\0'; i++)
    {
        if((senha[i]> 64 && senha[i] < 91)||(senha[i]> 96 && senha[i] < 123)){
            senha[i] = senha[i] - 3;
    }
    m++;
    }
    for (int i = 0,k = m-1; i < m; i++,k--)
    {
        var[i] = senha[k];
}
    var[m] = '\0';
}


int main(int argc, char const *argv[])
{
    char senha[25], var[25];

    scanf("%s",senha);

    decript(senha,var);

    printf("\n%s\n",var);

    return 0;
}
