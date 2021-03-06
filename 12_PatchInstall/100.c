#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>

#include <argp.h>

#define _(string) gettext(string) /**< gettext macros using to echange english strings*/

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

const char *argp_program_version = "0.0"; /**< The program's version */
const char *argp_program_bug_address = "gmarkmg@yandex.ru"; /**< address for bug reporting*/

int main(int argc, char *argv[]) {
    const char *doc = _("The program tries to guess the number that you have guessed."); /**< The program about */
    const struct argp argp = {0, 0, 0, doc};
    argp_parse(&argp, argc, argv, 0, 0, 0);

    setlocale(LC_ALL, "");
    bindtextdomain("100","./share/locale");
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