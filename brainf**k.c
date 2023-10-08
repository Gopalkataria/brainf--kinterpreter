#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char CODE[10001], CELLS[30000] = {0};
int ptr = 0;
int validatechar(char c)
{
    char valid[] = "+-.,<>[]";
    for (int i = 0; i < 8; i++)
        if (c == valid[i])
            return 1;
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Brainf**k interpreter \n Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Error opening file");
        return 2;
    }

    CODE[0] = '\0';
    int c, opening_brack = 0, closing_brack = 0;
    int char_count = 0;
    while ((c = fgetc(file)) != EOF && char_count < 10000)
    {
        if (validatechar((char)c))
        {
            CODE[char_count] = (char)c;
            opening_brack += ((char)c) == '[';
            closing_brack += ((char)c) == ']';

            char_count++;
        }
    }
    if (opening_brack != closing_brack)
    {
        printf("\nError : All brackets dont match\n");
        return -1;
    }

    CODE[char_count] = '\0';
    fclose(file);

    char curr;
    int count = 0;
    int codelen = strlen(CODE);
    for (int i = 0; i < codelen; i++)
    {
        if (ptr < 0 || ptr > 30000)
        {
            // throw an error
            printf("Error : Pointer out of bounds \n while executing char %d \n", i );
            return -1;
        }

        curr = CODE[i];

        switch (curr)
        {
        case '>':
            ptr++;
            break;
        case '<':
            ptr--;
            break;
        case '+':
            CELLS[ptr]++;
            break;
        case '-':
            CELLS[ptr]--;
            break;
        case ',':
            CELLS[ptr] = getchar();
            break;

        case '.':
            printf("%c", CELLS[ptr]);
            break;

        case '[':
            count = 0;
            if (CELLS[ptr] == 0)
            {
                do
                {
                    count += CODE[i] == '[';
                    count -= CODE[i] == ']';
                    i++;
                } while (count != 0);
                i--; // to compensate for the i++ in the for loop
            }
            break;
        case ']':
            count = 0;
            if (CELLS[ptr] != 0)
            {
                do
                {
                    count += CODE[i] == ']';
                    count -= CODE[i] == '[';
                    i--;
                } while (count != 0);
                i++; // to compensate for the i-- in the for loop
            }
            break;

        default:
            break;
        }
        // printf("%c", curr);
    }

    return 0;
}
