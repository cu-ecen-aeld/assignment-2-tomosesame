#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <errno.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file> <string>\n", argv[0]);
        syslog(LOG_ERR, "Invalid number of arguments: %d", argc);
        return 1;
    }

    // Get file and string from arguments
    const char *file_path = argv[1];
    const char *string_to_write = argv[2];

    // Open the log
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);
    
    // Open file
    FILE *file = fopen(file_path, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        syslog(LOG_ERR, "Error opening file %s: %s", file_path, strerror(errno));
        return 1;
    }

    // Write string to file
    fprintf(file, "%s", string_to_write);
    syslog(LOG_DEBUG, "Writing %s to %s", string_to_write, file_path);

    // Close file
    fclose(file);

    // Close the log
    closelog();

    return 0;
}
