#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *d;
    struct dirent *dir;
    char dirname[100];

    printf("Enter directory name: ");
    fgets(dirname, sizeof(dirname), stdin);
    dirname[strcspn(dirname, "\n")] = '\0';

    d = opendir(dirname);

    if (d == NULL) {
        printf("Directory cannot be opened\n");
        return 0;
    }

    printf("Directory opened successfully\n");

    while ((dir = readdir(d)) != NULL) {
        printf("%s\n", dir->d_name);
    }

    closedir(d);
    printf("Directory closed\n");

    return 0;
}
