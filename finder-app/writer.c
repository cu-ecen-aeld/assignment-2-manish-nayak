#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        openlog("writer", LOG_PID, LOG_USER);
        syslog(LOG_ERR, "Invalid number of arguments: %d", argc - 1);
        closelog();
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];

    // Open syslog
    openlog("writer", LOG_PID, LOG_USER);

    // Open file for writing
    FILE *fp = fopen(writefile, "w");
    if (!fp) {
        syslog(LOG_ERR, "Failed to open file: %s", writefile);
        closelog();
        return 1;
    }

    // Write string to file
    if (fprintf(fp, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Failed to write to file: %s", writefile);
        fclose(fp);
        closelog();
        return 1;
    }

    // Log the write operation
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    fclose(fp);
    closelog();
    return 0;
}