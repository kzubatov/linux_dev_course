#include <curses.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DX 0
#define DY 2

void show_help()
{
  printf("Usage: Show [file]\n");
}

#define WINDOW_LINES (LINES - 2 * DY - 2)
#define WINDOW_COLS (COLS - 2 * DX - 2)

// clang-format off
// very very very very loooooooong line a little bit more text at the end why are you still reading this line? I am not sure if you are reading this line or not but I will continue to write more text to make this line even longer and longer and longer and longer and that's it. Thanks for reading this line. Hope this would be enought to demo the truncation.
// clang-format on

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    show_help();
    return 1;
  }

  if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0)
  {
    show_help();
    return 0;
  }

  FILE* file = fopen(argv[1], "r");
  if (file == NULL)
  {
    fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
    return 1;
  }

  setlocale(LC_ALL, "");
  initscr();
  noecho();
  cbreak();
  refresh();

  WINDOW* frame;
  {
    frame = newwin(LINES - 2 * DY, COLS - 2 * DX, DY, DX);
    box(frame, 0, 0);
    const char* lastSlash = strrchr(argv[1], '/');
    const char* filename = lastSlash ? lastSlash + 1 : argv[1];
    mvwaddstr(frame, 0, 1, filename);
    wprintw(frame, " (%d x %d)", WINDOW_LINES, WINDOW_COLS);
    wrefresh(frame);
  }

  WINDOW* win;
  {
    win = newwin(WINDOW_LINES, WINDOW_COLS, DY + 1, DX + 1);
    keypad(win, TRUE);
    scrollok(win, TRUE);
  }

  {
    int c = 0;
    char* line = NULL;
    size_t read = 0;

    int linesToRead = WINDOW_LINES;
    int lineNo = 0;
    wmove(win, 0, 0);
    do
    {
      if (c == ' ')
      {
        linesToRead = 1;
      }

      while (linesToRead > 0)
      {
        linesToRead--;
        ssize_t nread = 0;
        nread = getline(&line, &read, file);
        if (nread == -1)
        {
          break;
        }
        if (lineNo >= WINDOW_LINES)
        {
          wscrl(win, 1);
          lineNo = WINDOW_LINES - 1;
        }
        wmove(win, lineNo, 0);
        wrefresh(win);
        line[nread - 1] = line[nread - 1] == '\n' ? '\0' : line[nread - 1];
        waddnstr(win, line, WINDOW_COLS - 1);
        lineNo++;
      }
    } while ((c = wgetch(win)) != 27);
    free(line);
  }

  delwin(win);
  delwin(frame);
  endwin();
  fclose(file);

  return 0;
}
