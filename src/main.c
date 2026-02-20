#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COMMANDS 1000
#define MAX_LEN 64
#define LINE_BUF 1024

typedef struct {
    char name[MAX_LEN];
    int total;
} Entry;

void extract_base_command(char *line, char *out);
int find_command(Entry entries[], int count, char *cmd);
int compare_desc(const void *a, const void *b);

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <history_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: unable to open file");
        return 1;
    }

    Entry entries[MAX_COMMANDS];
    int unique_count = 0;

    char line[LINE_BUF];
    char cmd[MAX_LEN];

    while (fgets(line, sizeof(line), fp)) {

        extract_base_command(line, cmd);

        if (strlen(cmd) == 0)
            continue;

        int idx = find_command(entries, unique_count, cmd);

        if (idx != -1) {
            entries[idx].total++;
        } else {
            if (unique_count < MAX_COMMANDS) {
                strcpy(entries[unique_count].name, cmd);
                entries[unique_count].total = 1;
                unique_count++;
            }
        }
    }

    fclose(fp);

    qsort(entries, unique_count, sizeof(Entry), compare_desc);

    printf("\nRank  Command           Total\n");
    printf("-------------------------------\n");

    for (int i = 0; i < unique_count; i++) {
        printf("%-5d %-15s %d\n", i + 1, entries[i].name, entries[i].total);
    }

    return 0;
}

void extract_base_command(char *line, char *out)
{
    char *token = strtok(line, " \t\n");

    if (token && strcmp(token, "sudo") == 0)
        token = strtok(NULL, " \t\n");

    if (token)
        strncpy(out, token, MAX_LEN - 1);
    else
        out[0] = '\0';

    out[MAX_LEN - 1] = '\0';
}

int find_command(Entry entries[], int count, char *cmd)
{
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].name, cmd) == 0)
            return i;
    }
    return -1;
}

int compare_desc(const void *a, const void *b)
{
    Entry *ea = (Entry *)a;
    Entry *eb = (Entry *)b;
    return eb->total - ea->total;
}