/*
    Advent of Code - 2015
    Day 3 part one
    Solution by: Blixyk

    You will find the puzzle on their website, I only share my solution here.
*/


#include <stdio.h>

int main(int argc, char* argv[])
{

    FILE *file = fopen(argv[1], "r");

    if(file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int l = 0, w = 0, h = 0; 
    char ch;
    int counter = 1;

    int array[100000][2];
    for(int i = 0; i < 1000; i++)
    {
        array[i][0] = 0;
        array[i][1] = 0;
    }


    int x = 0, y = 0;
    

    array[0][0] = 0;
    array[0][1] = 0;

    
    int index = 1;

    while((ch = fgetc(file)) != EOF)
    {
        
        if(ch == '>')
        {
            y++;
            array[index][0] = x;
            array[index][1] = y;  
        }
        else if(ch == '<')
        {
            y--;
            array[index][0] = x;
            array[index][1] = y;
        }
        else if(ch == '^')
        {
            x++;
            array[index][0] = x;
            array[index][1] = y;
        }
        else if(ch == 'v')
        {
            x--;
            array[index][0] = x;
            array[index][1] = y;
        }
        counter++;
        index++;
    }

    int podminka = 0;

    int new_counter = 0;

    int cycle = counter;
    printf("Counter before for: %d\n", counter);

    int pointer = 0;
    for(int i = 0; i < cycle; i++)
    {
        for(int j = i+1; j < cycle; j++){
            if((array[i][0] == array[j][0]) && (array[i][1] == array[j][1]) && (i!=j))
            {
                counter--;
                break;
            }
        }
        
    }
    
    fclose(file);
    printf("\nCycle: %d\n", cycle);
    printf("Number of houses: %d\n", counter);

    return 1;
}