/*
    Advent of Code - 2015
    Day 1 part two
    Solution by: Blixyk

    --- Part Two ---

    Now, given the same instructions, find the position of the first character that causes him to 
    enter the basement (floor -1). The first character in the instructions has position 1, 
    the second character has position 2, and so on.

    For example:

    ) causes him to enter the basement at character position 1.
    ()()) causes him to enter the basement at character position 5.
    What is the position of the character that causes Santa to first enter the basement?
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

    char ch;
    int position = 0, counter = 0;

    while((ch = fgetc(file)) != EOF)
    {
        if(ch == '(')
        {
            position++;
            counter++;
        }
        else if(ch == ')'){
            position--;
            counter++;
        } 

        if(position == -1) break;

    }

    printf("Final number from counter: %d\n", counter);

    return 1;
}