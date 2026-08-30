#include <stdio.h>
int index_list(void) 
{
    FILE *file = fopen("/var/udf/index.txt", "r");

    if (file == NULL) {
        perror("Erreur");
        return 1;
    }

    char line[256];

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);

    return 0;
}

//int index_add(void) { 
//FILE *file = fopen("/var/udf/index.txt", "r");
  
//fclose(file);
//}

