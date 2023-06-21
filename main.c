#include <stdio.h>
#include <stdlib.h>

char** readLinesFromFile(FILE* file, int* numLines) {
    char** lines = NULL;
    char* line = NULL;
    size_t bufsize = 0;
    ssize_t linelen;
    int count = 0;

    while ((linelen = getline(&line, &bufsize, file)) != -1) {
        lines = realloc(lines, (count + 1) * sizeof(char*));
        lines[count] = malloc((linelen + 1) * sizeof(char));
        if (lines[count] == NULL) {
            perror("Memory allocation error");
            exit(1);
        }

        line[linelen] = '\0';  // Null-terminate the line
        strcpy(lines[count], line);

        count++;
    }

    free(line);
    *numLines = count;

    return lines;
}

int main() {
    FILE* file = fopen("example.txt", "r");
	char **lines;
	int i, numLines;

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    lines = readLinesFromFile(file, &numLines);
    fclose(file);
    for (i = 0; i < numLines; i++) {
        printf("Line %d: %s\n", i + 1, lines[i]);
        free(lines[i]);
    }

    free(lines);

    return 0;
}
