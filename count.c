#include <stdio.h>
#include <dirent.h>
#include <string.h>

int count_lines(char* directory, char* extensions[], int num_ext) {
    int line_count = 0;
    DIR* dir = opendir(directory);
    struct dirent* entry;
    while((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if(strcmp(entry->d_name, ".") == 0 ||strcmp(entry->d_name, "..") == 0) 
                continue;
            char path[1024];
            int len = snprintf(path, sizeof(path) - 1, "%s/%s", directory, entry->d_name);
            path[len] = 0;
            line_count += count_lines(path, extensions, num_ext);
        } else {
            char* file_ext = strrchr(entry->d_name, '.');
            for (int i = 0; i < num_ext; i++) {
                if (file_ext != NULL && strcmp(file_ext, extensions[i]) == 0) {
                    char path[1024];
                    int len = snprintf(path, sizeof(path) - 1, "%s/%s", directory, entry->d_name);
                    path[len] = 0;
                    int ch;
                    FILE* file = fopen(path, "r");
                    while((ch = fgetc(file)) != EOF) {
                        if (ch == '\n') 
                            line_count++;
                    }
                    fclose(file);
                    break;
                }
            }
        }
    }
    closedir(dir);
    return line_count;
}

int main (int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: directory extension1 extension2 ...\n");
        return 1;
    }
    int num_ext = argc - 2;
    char* extensions[num_ext];
    for (int i = 0; i < num_ext; i++) {
        extensions[i] = argv[i+2];
    }
    printf("Total line count: %d\n", count_lines(argv[1], extensions, num_ext));
    return 0;
}
