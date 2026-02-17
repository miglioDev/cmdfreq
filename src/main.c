#include <stdio.h>
#include <stdlib.h>
#include "history.h"

int main(int argc, char *argv[])  //now on set up and planning
{
    if (argc != 2) {
    fprintf(stderr, "Usage: %s <history_file>\n", argv[0]);
    return EXIT_FAILURE; }

    //CmdHistory 
    const char *history_file = get_default_history();

    CmdStats *stats = load_history(history_file);
    if (!stats) {
        fprintf(stderr, "Error loading history\n");
        return 1;
    }

    sort_stats(stats);
    print_stats(stats, 10);

    free_stats(stats);
    return 0;
}
