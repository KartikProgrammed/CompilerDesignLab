#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include<fstream>

int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '=');
}

int is_identifier(char *str) {
    if (!isalpha(str[0]) && str[0] != '_')  // First character must be letter or '_'
        return 0;
    for (int i = 1; str[i] != '\0'; i++) {
        if (!isalnum(str[i]) && str[i] != '_')  // All other characters must be alphanumeric or '_'
            return 0;
    }
    return 1;
}

void count_and_replace(FILE *input_file, FILE *output_file) {
    char line[1024];
    int scanf_count = 0, printf_count = 0;

    while (fgets(line, sizeof(line), input_file)) {
        // Count and replace 'scanf' statements
        if (strstr(line, "scanf")) {
            scanf_count++;
            char *ptr = strstr(line, "scanf");
            memmove(ptr + 4, ptr + 5, strlen(ptr + 5) + 1);  // Shift after "scanf"
            strncpy(ptr, "read", 4);  // Replace with 'read'
        }

        // Count and replace 'printf' statements
        if (strstr(line, "printf")) {
            printf_count++;
            char *ptr = strstr(line, "printf");
            memmove(ptr + 5, ptr + 6, strlen(ptr + 6) + 1);  // Shift after "printf"
            strncpy(ptr, "write", 5);  // Replace with 'write'
        }

        fprintf(output_file, "%s", line);  // Write modified line to output file
    }

    printf("Number of 'scanf' statements: %d\n", scanf_count);
    printf("Number of 'printf' statements: %d\n", printf_count);
}

void count_identifiers(FILE *input_file) {
    char word[1024];
    int identifier_count = 0;

    while (fscanf(input_file, "%s", word) != EOF) {
        if (is_identifier(word)) {
            identifier_count++;
        }
    }

    printf("Number of identifiers: %d\n", identifier_count);
}

void analyze_expression(const char *expression) {
    char token[1024];
    int i = 0, j = 0;

    printf("Identifiers: ");
    while (expression[i] != '\0') {
        if (isalnum(expression[i]) || expression[i] == '_') {
            token[j++] = expression[i];
        } else {
            if (j > 0) {
                token[j] = '\0';
                if (is_identifier(token))
                    printf("%s ", token);
                j = 0;
            }
            if (is_operator(expression[i])) {
                printf("\nOperator: %c", expression[i]);
            }
        }
        i++;
    }

    if (j > 0) {
        token[j] = '\0';
        if (is_identifier(token))
            printf("%s ", token);
    }
    printf("\n");
}

int main() {
    FILE *input_file = fopen("input.c", "r");
    if (!input_file) {
        printf("Could not open input file.\n");
        return 1;
    }

    FILE *output_file = fopen("output.c", "w");
    if (!output_file) {
        printf("Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    // Task 1: Count and replace 'scanf' and 'printf'
    count_and_replace(input_file, output_file);
    printf("\n");

    // Reset input file pointer for Task 2
    fclose(input_file);
    input_file = fopen("input.c", "r");

    // Task 2: Count identifiers in the file
    count_identifiers(input_file);
    printf("\n");

    // Task 3: Analyze a sample arithmetic expression
    const char *expression = "a + b * c - d / e = f";
    printf("Analyzing the expression: %s\n", expression);
    analyze_expression(expression);

    fclose(input_file);
    fclose(output_file);

    return 0;
}
