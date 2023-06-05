#include <cs50.h>
#include <stdio.h>
//mario v.1 only prints left hand stairs
//mario v.2 prints gap and mirrored stairs

int main(void)
{
    // ask user for height btwn 1 and 8
    int h = 3;
    do
    {
        h = get_int("what is height: \n");
    }
    while (h < 1 || h > 8);

    //print left stairs
    int s;
    int r;
    for (r = h; r > 0; r--)
    {
        for (s = 0; s < r - 1; s++)
        {
            printf(" ");
        }
        for (int j = 0; j < h - s; j++)
        {
            printf("#");
        }
        //print gap, ignore for mario v.1
        printf("  ");
        //print right stairs, ignore for mario v.1
        for (int m = 0; m < h -s; m++)
        {
            printf("#");
        }
        //print next row
        printf("\n");
    }
}
