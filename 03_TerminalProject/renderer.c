#define ARGC 2
#define SEPARATOR '\n'

#include <ncurses.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

void PrintUsage(char *file_name) {
    fprintf(stderr, "Usage: %s.o <input file name>\n", file_name);
}

int HandleArguments(int eargc, int argc, char *argv[]) {
    if (argc != eargc) {
        fprintf(stderr, "Incorrect number of arguments\n");
	PrintUsage(argv[0]);
        return -1;
    }

    if (argv == NULL) {
        fprintf(stderr, " Bad argument vector\n");
        return -1;
    }

    return 0;
}

int CopyFile(char **data, char *file_name, char separator) {
    FILE *f = fopen(file_name, "rt,ccs=UTF-8");

    if(f == NULL) {
        fprintf(stderr, "Cannot open the file\n");
        return -1;
    }

    int linec = 1;
    int idx = 0;
    char ch = (char)fgetwc(f);
    while(ch != EOF) {
        if (ch == separator) {
	    data[0][idx] = '\0';
	    linec++;
        } else {
            data[0][idx] = ch;
        }
        ch = (char)fgetwc(f);
        idx++;
    }
    data[0][idx] = '\0';

    fclose(f);

    return linec;
}

int LoadFile(char **data, char ***parts, char *file_name, char separator ) {
    struct stat info;

    stat(file_name, &info);
    *data = (char*)calloc(info.st_size + 1, sizeof(char));
    if(*data == NULL) {
        fprintf(stderr, "Cannot allocate a storage for the file\n");
        return -1;
    }

    int linec = CopyFile(/*out*/ data, file_name, separator);

    *parts = (char**)calloc(linec + 1, sizeof(char*));
    if(*parts == NULL) {
        fprintf(stderr, "Cannot allocate memory for file lines\n");
        return -1;
    }

    parts[0][0] = data[0];
    for(int i = 0, k = 1; i < info.st_size; i++)
        if(data[0][i] == '\0') {
	    parts[0][k] = data[0] + i + 1;
            k++;
        }

    return linec;
}

int RenderFile(char **parts, char* file_name, int linec) {
    initscr();
    noecho();
    cbreak();
    WINDOW *window = newwin(LINES-2*3, COLS-2*3, 3, 3);
    if (window == NULL) {
        fprintf(stderr, "Cannot render the window\n");
        return -1;
    }

    mvprintw(0, 0, "File: %s", file_name);
    refresh();
    keypad(window, TRUE);

    int max_size = 0;
    int *sizes = (int*)calloc(linec, sizeof(int));
    for(int i = 0; i < linec; i++) {
        int s = 0;
        for(int j = 0; parts[i][j] != '\0'; j++) {
            s++;
        }
	sizes[i] = s + 1;
	if (s + 1 > max_size) {
            max_size = s + 1;
	}
    }

    int x = 0;
    int y = 0;
    int hight = window->_maxy - 2;
    int go = TRUE;
    for(; go ;) {
	werase(window);
	box(window, 0, 0);
        int k = 0;
        for(int i = 0; k <= hight && i < linec; i++) {
            if (i < y) {
                continue;
            }
            const char* line_data = x < sizes[i] ? parts[i] + x : "";
            mvwprintw(window, k + 1, 2, "%i %.80s", i + 1, line_data);
            k++;
        }
	wrefresh(window);

        switch(wgetch(window)) {
            case 'q':
            case 0x1B: { // KEY_ESCAPE
                go = FALSE;
            } break;
            case 0x20: { // KEY_SPACE
                y = y + 3 < linec ? y + 3 : (y + 2 < linec ? y + 2 : (y + 1 < linec ? y + 1 : y));
            } break;
            case KEY_UP: {
                y = y > 0 ? y - 1 : y;
            } break;
            case KEY_DOWN: {
                y = y + 1 < linec ? y + 1 : y;
            } break;
            case KEY_RIGHT: {
               x = x + 1 < max_size ?  x + 1 : x;
            } break;
            case KEY_LEFT: {
                x = x > 0 ? x - 1 : x;
            } break;
            default:
                break;
	}
    }

    free(sizes);
    endwin();
    return 0;
}


int main(int argc, char *argv[]) {
    char *storage;
    char **segments;

    setlocale(LC_ALL, "");

    if(HandleArguments(ARGC, argc, argv) == -1) {
        return -1;
    }

    int linec = LoadFile(/*out*/ &storage, /*out*/ &segments, argv[1], SEPARATOR);
    if(linec == -1) {
        return -1;
    }

    if (RenderFile(segments, argv[1], linec) == -1) {
        return -1;
    }

    free(segments);
    free(storage);
    return 0;
}
