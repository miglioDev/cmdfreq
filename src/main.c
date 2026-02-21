#include <stdio.h>
#include <stdlib.h>
#include "history.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <history_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    Entry entries[MAX_COMMANDS];
    int unique_count = 0;

    process_history(fp, entries, &unique_count);

    fclose(fp);

    sort_entries(entries, unique_count);
    print_entries(entries, unique_count);

    return 0;
}