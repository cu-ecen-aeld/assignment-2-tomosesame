#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    openlog("writer", LOG_PID | LOG_CONS, LOG_USER);

    // 檢查參數數量是否正確
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file> <string>\n", argv[0]);
        syslog(LOG_ERR, "Invalid number of arguments: %d", argc);
        syslog(LOG_ERR, "Usage: %s <file_path> <string>", argv[0]);
        exit(EXIT_FAILURE);
    }

    // 獲取文件路徑和要寫入的字符串
    const char *file_path = argv[1];
    const char *string_to_write = argv[2];

    // 打開文件
    FILE *file = fopen(file_path, "w");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        syslog(LOG_ERR, "Error opening file %s: %s", file_path, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // 寫入字符串到文件
    fprintf(file, "%s", string_to_write);
    syslog(LOG_DEBUG, "Writing %s to %s", string_to_write, file_path);

    // 關閉文件
    if (fclose(file) != 0) {
        syslog(LOG_ERR, "Failed to close file %s: %s", file_path, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // 關閉日誌
    closelog();

    return EXIT_SUCCESS;
}
