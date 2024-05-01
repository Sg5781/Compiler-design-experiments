#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    printf("\nEnter number of non terminals: ");
    scanf("%d", &n);

    char(*nonter)[100] = malloc(n * sizeof(*nonter));
    int *leftrecr = malloc(n * sizeof(int));
    if (nonter == NULL || leftrecr == NULL)
    {
        printf("Memory allocation failed.");
        return 1;
    }

    for (int i = 0; i < n; ++i)
    {
        printf("\nNon terminal %d : ", i + 1);
        scanf("%s", nonter[i]);
        leftrecr[i] = 0;
    }

    char(*prod)[10][100] = malloc(n * sizeof(*prod));
    if (prod == NULL)
    {
        printf("Memory allocation failed.");
        free(nonter);
        free(leftrecr);
        return 1;
    }

    printf("\nEnter 'esp' for null");
    for (int i = 0; i < n; ++i)
    {
        printf("\nNumber of %s productions: ", nonter[i]);
        int k;
        scanf("%d", &k);
        printf("\nOne by one enter all %s productions", nonter[i]);
        for (int j = 0; j < k; ++j)
        {
            printf("\nRHS of production %d: ", j + 1);
            scanf("%s", prod[i][j]);
            if (strlen(nonter[i]) <= strlen(prod[i][j]) && strncmp(nonter[i], prod[i][j], strlen(nonter[i])) == 0)
                leftrecr[i] = 1;
        }
    }

    for (int i = 0; i < n; ++i)
    {
        printf("%d", leftrecr[i]);
    }

    for (int i = 0; i < n; ++i)
    {
        if (leftrecr[i] == 0)
            continue;
        strcat(nonter[i], "'");
        for (int j = 0; j < n; ++j)
        {
            if (strlen(nonter[i]) <= strlen(prod[i][j]) && strncmp(nonter[i], prod[i][j], strlen(nonter[i])) == 0)
            {
                char abc[100];
                strcpy(abc, prod[i][j] + strlen(nonter[i]));
                strcat(abc, nonter[i]);
                strcpy(prod[i][j], abc);
            }
            else
            {
                strcat(prod[i][j], nonter[i]);
            }
        }
        strcpy(prod[i][n], "esp");
    }

    printf("\n\n");
    printf("\nNew set of non-terminals: ");
    for (int i = 0; i < n; ++i)
        printf("%s ", nonter[i]);
    printf("\n\nNew set of productions: ");
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            printf("\n%s -> %s", nonter[i], prod[i][j]);
        }
    }

    free(nonter);
    free(leftrecr);
    free(prod);
    return 0;
}
