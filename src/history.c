#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "history.h"

#define LINE_BUF 1024

static void extract_base_command(char *line, char *out)
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

static int find_command(Entry entries[], int count, char *cmd)
{
    for (int i = 0; i < count; i++) {
        if (strcmp(entries[i].name, cmd) == 0)
            return i;
    }
    return -1;
}

void process_history(FILE *fp, Entry entries[], int *unique_count)
{
    char line[LINE_BUF];
    char cmd[MAX_LEN];

    while (fgets(line, sizeof(line), fp) != NULL) {

        extract_base_command(line, cmd);

        if (strlen(cmd) == 0)
            continue;

        int idx = find_command(entries, *unique_count, cmd);

        if (idx != -1) {
            entries[idx].total++;
        } else {
            if (*unique_count < MAX_COMMANDS) {
                strcpy(entries[*unique_count].name, cmd);
                entries[*unique_count].total = 1;
                (*unique_count)++;
            }
        }
    }
}

static int compare_desc(const void *a, const void *b)
{
    Entry *ea = (Entry *)a;
    Entry *eb = (Entry *)b;
    return eb->total - ea->total;
}

void sort_entries(Entry entries[], int count)
{
    qsort(entries, count, sizeof(Entry), compare_desc);
}

void print_entries(Entry entries[], int count)
{
    printf("\nRank  Command           Total\n");
    printf("-------------------------------\n");

    for (int i = 0; i < 10; i++) {
        printf("%-5d %-15s %d\n", i + 1, entries[i].name, entries[i].total);
    }
}