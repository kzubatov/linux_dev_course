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
WINDOW *recreate_window()
{
  WINDOW *win = newwin(WINDOW_LINES, WINDOW_COLS, DY + 1, DX + 1);
  keypad(win, TRUE);
  scrollok(win, TRUE);
  return win;
}

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

  FILE *file = fopen(argv[1], "r");
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

  WINDOW *frame;
  {
    frame = newwin(LINES - 2 * DY, COLS - 2 * DX, DY, DX);
    box(frame, 0, 0);
    const char *lastSlash = strrchr(argv[1], '/');
    const char *filename = lastSlash ? lastSlash + 1 : argv[1]; // adlfndnlafladflladfnljandsfjlnljnfa
    mvwaddstr(frame, 0, 1, filename);
    wprintw(frame, " (%d x %d)", WINDOW_LINES, WINDOW_COLS);
    wrefresh(frame);
  }

  WINDOW *win = recreate_window();
  int xPos = 0;
  {
    int c = 0;
    char *line = NULL;
    size_t read = 0;
    // size_t total = 0;
    int linesToRead = WINDOW_LINES;
    int lineNo = 0;
    wmove(win, 0, 0);
    do
    {
      if (c == ' ')
      {
        linesToRead = 1;
        // wmove(win, WINDOW_LINES - 1, 0);
      }
      // if (c == KEY_LEFT || c == KEY_RIGHT)
      // {
      //   if (c == KEY_LEFT)
      //   {
      //     xPos = xPos > 0 ? xPos - 1 : 0;
      //   }
      //   else
      //   {
      //     xPos++;
      //   }
      //   wmove(win, 0, xPos);
      //   wrefresh(win);
      // }

      // if (c == KEY_UP)
      // {
      //   wscrl(win, -1);
      //   refresh();
      // }

      while (linesToRead > 0)
      {
        lineNo++;
        linesToRead--;
        ssize_t nread = 0;
        nread =  getline(&line, &read, file);
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
        line[nread - 1] = '\0';
        waddnstr(win, line, WINDOW_COLS);
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
