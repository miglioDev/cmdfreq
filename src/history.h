#ifndef HISTORY_H
#define HISTORY_H

#include <stdio.h>

#define MAX_COMMANDS 1000
#define MAX_LEN 64

typedef struct {
    char name[MAX_LEN];
    int total;
} Entry;

void process_history(FILE *fp, Entry entries[], int *unique_count);
void sort_entries(Entry entries[], int count);
void print_entries(Entry entries[], int count);

#endif