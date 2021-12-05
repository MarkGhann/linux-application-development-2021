#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>

#define _(string) gettext(string)

int mid(int bot, int top) {
    int av = (top - (bot + 1));

    if (av % 2 != 0) {
        av += 1;
    }

    return bot + av/2;
}

int takePoint(int *bot, int *top, int basis) {
    char answer[8];
    printf(_("The number greater than %d (yes/no) ?\n"), basis);
    int flag = 0;
    for(; flag == 0 ;) {
        flag = -1;
        scanf("%s", answer);
        if (!strcmp(answer, _("yes"))) {
            *bot = basis + 1;
        } else if (!strcmp(answer, _("no"))) {
            *top = basis;
        } else {
            printf(_("That's not what's being needed ! Try again: yes/no.\n"));
            flag = 0;
        }
    }
    return mid(*bot, *top);
}

int main(void) {
    setlocale(LC_ALL, "");
    bindtextdomain("100","po");
    textdomain("100");

    int bot = 1;
    int top = 100;
    int basis = top / 2;
    for(; bot != top ;) {
        basis = takePoint(&bot /* out */, &top /* out */, basis);
    }
    printf(_("Guessed number is %d !\n"), bot);

    return 0;
}