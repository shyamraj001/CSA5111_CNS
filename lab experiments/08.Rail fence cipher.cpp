#include <stdio.h>
#include <string.h>
void encrypt(char text[], int rails)
{
    int len = strlen(text);
    char rail[100][100];
    int row = 0, direction = 1;
    int i, j;
    /* Initialize */
    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            rail[i][j] = '\0';
        }
    }
    /* Create Rail Fence pattern */
    for (i = 0; i < len; i++)
    {
        rail[row][i] = text[i];
        if (row == 0)
            direction = 1;
        else if (row == rails - 1)
            direction = -1;
        row += direction;
    }
    /* Read row by row */
    printf("Encrypted Text: ");
    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (rail[i][j] != '\0')
                printf("%c", rail[i][j]);
        }
    }

    printf("\n");
}
void decrypt(char cipher[], int rails)
{
    int len = strlen(cipher);
    char rail[100][100];
    int row = 0, direction = 1;
    int i, j, index = 0;
    /* Initialize */
    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            rail[i][j] = '\0';
        }
    }
    /* Mark the positions */
    for (i = 0; i < len; i++)
    {
        rail[row][i] = '*';
        if (row == 0)
            direction = 1;
        else if (row == rails - 1)
            direction = -1;

        row += direction;
    }
    /* Fill the marked positions with cipher text */
    for (i = 0; i < rails; i++)
    {
        for (j = 0; j < len; j++)
        {
            if (rail[i][j] == '*')
            {
                rail[i][j] = cipher[index++];
            }
        }
    }
    /* Read the zigzag pattern */
    row = 0;
    direction = 1;
    printf("Decrypted Text: ");
    for (i = 0; i < len; i++)
    {
        printf("%c", rail[row][i]);
        if (row == 0)
            direction = 1;
        else if (row == rails - 1)
            direction = -1;
        row += direction;
    }
    printf("\n");
}
int main()
{
    char text[100];
    int rails, choice;
    printf("RAIL FENCE CIPHER\n");
    printf("\n1. Encryption");
    printf("\n2. Decryption");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);
    printf("Enter number of rails: ");
    scanf("%d", &rails);
    printf("Enter text: ");
    scanf("%s", text);
    if (rails < 2)
    {
        printf("Number of rails must be at least 2.\n");
        return 0;
    }
    if (choice == 1)
    {
        encrypt(text, rails);
    }
    else if (choice == 2)
    {
        decrypt(text, rails);
    }
    else
    {
        printf("Invalid choice!\n");
    }
    return 0;
}
