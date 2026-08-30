#include <stdio.h>
#include <string.h>

int main() {
    char input[100];

    while (1) {
        printf("myshell> ");
        scanf("%s", input);

        if (strcmp(input, "exit") == 0) {
            printf("Exiting shell...\n");
            break;
        }

        printf("You typed: %s\n", input);
    }

    return 0;
}
