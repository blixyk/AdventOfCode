/*
    Advent of Code - 2015
    Day 2 part one
    Solution by: Blixyk

    You will find the puzzle on their website, I only share my solution.
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
    int complete_result = 0;

    while(fscanf(file, "%dx%dx%d", &l, &w, &h) == 3)
    {
        int result = 0, extra_paper = 0;
        // 2*l*w + 2*w*h + 2*h*l
        result = (2*l*w) + (2*w*h) + (2*h*l);

        if(l*w <= w*h && l*w <= h*l)
        {
            extra_paper = l*w;
        }
        else if(w*h <= l*w && w*h <= h*l)
        {
            extra_paper = w*h;
        }
        else extra_paper = h*l;
        
        complete_result += result + extra_paper;
    }

    printf("Total square feet of wrapping paper: %d\n", complete_result);

    return 1;
}