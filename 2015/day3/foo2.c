#include <stdio.h>

#define HOUSES 1000000

typedef struct
{
    int x;
    int y;
}House;


int house_exists(House visited[], int x, int y, int index)
{
    for(int i = 0; i < index; i++)
    {
        if(visited[i].x == x && visited[i].y == y)
        {
            return 1;
        }
    }

    return 0;
}

int main(int argc, char* argv[])
{
    
    int index = 1;

    int santa_x = 0, santa_y = 0;
    int npc_x = 0, npc_y = 0;

    FILE *fn;

    fn = fopen(argv[1], "r");

    if(fn == NULL)
    {
        printf("There was error opening file");
        return 1;
    }

    char ch;

    House visited[HOUSES];

    int who_is = 0;

    while((ch = fgetc(fn)) != EOF)
    {
        int *x = (who_is % 2 == 0) ? &santa_x : &npc_x;
        int *y = (who_is % 2 == 0) ? &santa_y : &npc_y;

        if(ch == '>') (*y)++;
        else if(ch == '<') (*y)--;
        else if(ch == '^') (*x)++;
        else if(ch == 'v') (*x)--;

        if(!house_exists(visited, *x, *y, index))
        {
            visited[index].x = *x;
            visited[index].y = *y;
            index++;
        }

        who_is++;
    }



    fclose(fn);
    
    printf("Number of houses: %d\n", index);

    return 1;
}