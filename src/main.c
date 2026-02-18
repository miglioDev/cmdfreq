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
    
    if (load_history(&history, argv[1]) != 0) {
        fprintf(stderr, "Error loading history file\n");
        free_history(&history);
        return EXIT_FAILURE;
    }

    return 0;
}

int load_history(CmdHistory *history, const char *filename)
{
    FILE *fp = fopen(filename, "r");
    
    if (!fp)
        return -1;
    
    //while 
}
