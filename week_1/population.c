#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //get starting population
    float start;
    do
    {
        start = get_int("what is starting population ");
    }
    while (start < 9);


    //get ending pop
    int end;
    do
    {
        end = get_int("what is ending population ");
    }
    while (end < start);

    //calculate years
    int years_passed = 0;
    double growth_rate;
    do
    {
        growth_rate = ((13 * start) / 12);
        start = growth_rate;
        years_passed++;
        printf("Years: %i\n", years_passed);
        //printf("new_pop = %f, years passed = %i\n", start, years_passed);
    }
    while (growth_rate < end);

    //printf("new_pop = %f, years passed = %i\n", start, years_passed);
}
