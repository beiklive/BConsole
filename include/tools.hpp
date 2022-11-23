#include <termio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>


class DJ{
public:
    DJ() = default;
    ~DJ() = default;

public:
    static int getch(void)
    {
        int ch;
        struct termios tm, tm_old;
        tcgetattr(STDIN_FILENO, &tm);
        tm_old = tm;
        tm.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &tm);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &tm_old);
        return ch;
    }

    static void screenClear()
    {
    #ifdef __linux__
        std::cout << "\033c";
    #else
        system("cls");
    #endif
    }



};
