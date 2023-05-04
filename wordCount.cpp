#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LEN 100

int main(int argc, char *argv[]) {
    FILE *file;
    char *filename;
    char ch;
    int char_count = 0, word_count = 0;
    int in_word = 0;
    char word[MAX_WORD_LEN];

    if (argc < 2 || argc > 3) {
        printf("参数错误! 用法: wordCount.exe (-c|-w) [input_file_name]\n");
        exit(1);
    }

    if (strcmp(argv[1], "-c") != 0 && strcmp(argv[1], "-w") != 0) {
        printf("未知的控制参数: %s\n", argv[1]);
        exit(1);
    }
    if (argc == 3) {
        filename = argv[2];
    } else {
        filename = "sample.txt";
    }

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("无法打开文件: %s\n", filename);
        exit(1);
    }

    while ((ch = fgetc(file)) != EOF) {
        char_count++;

        if (ch == ' ' || ch == ',' || ch == '\n' || ch == '\t') {
            if (in_word) {
                in_word = 0;
                word_count++;
            }
        }
        else {
            if (!in_word) {
                in_word = 1;
                word[0] = ch;
                word[1] = '\0';
            }
            else {
                if (strlen(word) < MAX_WORD_LEN - 1) {
                    int len = strlen(word);
                    word[len] = ch;
                    word[len+1] = '\0';
                }
            }
        }
    }
    if(in_word==1){
    	word_count++;
	}

    fclose(file);

    if (strcmp(argv[1], "-c") == 0) {
        printf("字符数: %d\n", char_count);
    } else {
        printf("单词数: %d\n", word_count);
    }

    return 0;
}
