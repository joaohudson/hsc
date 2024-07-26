#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static char* prefix = "<head><meta http-equiv=\"refresh\" content=\"0; url=";
static char* sufix = "\"></head>";
static char* extension = ".html";

int main(int argc, char **argv) {
    
    if(argc < 3) {
        printf("2 arguments are needed:\n"
                "- The name of the shortcut file\n"
                "- The link\n");
                return 1;
    }

    char *link = argv[2];
    char *fileName = argv[1];
    size_t fileContentCapacity = strlen(link) + strlen(prefix) + strlen(sufix) + 1;
    char *fileContent = calloc(fileContentCapacity, 1);
    size_t fileNameFullCapacity = strlen(fileName) + strlen(extension) + 1;
    char *fileNameFull = calloc(fileNameFullCapacity, 1);

    strcat(fileContent, prefix);
    strcat(fileContent, link);
    strcat(fileContent, sufix);

    strcat(fileNameFull, fileName);
    strcat(fileNameFull, extension);

    FILE *file = fopen(fileNameFull, "w");
    if(!file) {
        printf("Invalid file name!\n");
		free(fileNameFull);
		free(fileContent);
        return 1;
    }
    fprintf(file, "%s", fileContent);
    
    fclose(file);
    free(fileNameFull);
    free(fileContent);

    return 0;
}