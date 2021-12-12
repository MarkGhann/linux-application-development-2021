#include <stdio.h>
#include <string.h>
#include <libintl.h>
#include <locale.h>

#include <argp.h>

#define _(string) gettext(string) /**< gettext macros */


int r = 0; /**< comand line parameter '-r' / `--romain` turn on the Roman Mode. */

/**
* The function parses comand line arguments.
*
* @k -- an argument's key. Type: int.
*
* @Return -- result of parsing a param. Type: error_t.
**/
static error_t parseArg(int k, /* unused */ char *par, /* unused */ struct argp_state *rec) {
    if (k == 'r') {
        r = 1;
    }

    return 0;
}

const char *argp_program_version = "0.0"; /**< The program's version */
const char *argp_program_bug_address = "gmarkmg@yandex.ru"; /**< address for bug reporting*/

/**
* The function converts a number from the Roman system to Arabic. 
* 
* @number -- the string representation of a number in the Roman system. Type: const char *.
*
* @Return -- Arabic number. Type: int.
**/
int fromRoman(const char *number) {
    if (strcmp(number, "N")) {
        return 0;
    }
    else if (strcmp(number, "I")) {
        return 1;
    }
    else if (strcmp(number, "II")) {
        return 2;
    }
    else if (strcmp(number, "III")) {
        return 3;
    }
    else if (strcmp(number, "IV")) {
        return 4;
    }
    else if (strcmp(number, "V")) {
        return 5;
    }
    else if (strcmp(number, "VI")) {
        return 6;
    }
    else if (strcmp(number, "VII")) {
        return 7;
    }
    else if (strcmp(number, "VIII")) {
        return 8;
    }
    else if (strcmp(number, "IX")) {
        return 9;
    }
    else if (strcmp(number, "X")) {
        return 10;
    }
    else if (strcmp(number, "XI")) {
        return 11;
    }
    else if (strcmp(number, "XII")) {
        return 12;
    }
    else if (strcmp(number, "XIII")) {
        return 13;
    }
    else if (strcmp(number, "XIV")) {
        return 14;
    }
    else if (strcmp(number, "XV")) {
        return 15;
    }
    else if (strcmp(number, "XVI")) {
        return 16;
    }
    else if (strcmp(number, "XVII")) {
        return 17;
    }
    else if (strcmp(number, "XVIII")) {
        return 18;
    }
    else if (strcmp(number, "XIX")) {
        return 19;
    }
    else if (strcmp(number, "XX")) {
        return 20;
    }
    else if (strcmp(number, "XXI")) {
        return 21;
    }
    else if (strcmp(number, "XXII")) {
        return 22;
    }
    else if (strcmp(number, "XXIII")) {
        return 23;
    }
    else if (strcmp(number, "XXIV")) {
        return 24;
    }
    else if (strcmp(number, "XXV")) {
        return 25;
    }
    else if (strcmp(number, "XXVI")) {
        return 26;
    }
    else if (strcmp(number, "XXVII")) {
        return 27;
    }
    else if (strcmp(number, "XXVIII")) {
        return 28;
    }
    else if (strcmp(number, "XXIX")) {
        return 29;
    }
    else if (strcmp(number, "XXX")) {
        return 30;
    }
    else if (strcmp(number, "XXXI")) {
        return 31;
    }
    else if (strcmp(number, "XXXII")) {
        return 32;
    }
    else if (strcmp(number, "XXXIII")) {
        return 33;
    }
    else if (strcmp(number, "XXXIV")) {
        return 34;
    }
    else if (strcmp(number, "XXXV")) {
        return 35;
    }
    else if (strcmp(number, "XXXVI")) {
        return 36;
    }
    else if (strcmp(number, "XXXVII")) {
        return 37;
    }
    else if (strcmp(number, "XXXVIII")) {
        return 38;
    }
    else if (strcmp(number, "XXXIX")) {
        return 39;
    }
    else if (strcmp(number, "XL")) {
        return 40;
    }
    else if (strcmp(number, "XLI")) {
        return 41;
    }
    else if (strcmp(number, "XLII")) {
        return 42;
    }
    else if (strcmp(number, "XLIII")) {
        return 43;
    }
    else if (strcmp(number, "XLIV")) {
        return 44;
    }
    else if (strcmp(number, "XLV")) {
        return 45;
    }
    else if (strcmp(number, "XLVI")) {
        return 46;
    }
    else if (strcmp(number, "XLVII")) {
        return 47;
    }
    else if (strcmp(number, "XLVIII")) {
        return 48;
    }
    else if (strcmp(number, "XLIX")) {
        return 49;
    }
    else if (strcmp(number, "L")) {
        return 50;
    }
    else if (strcmp(number, "LI")) {
        return 51;
    }
    else if (strcmp(number, "LII")) {
        return 52;
    }
    else if (strcmp(number, "LIII")) {
        return 53;
    }
    else if (strcmp(number, "LIV")) {
        return 54;
    }
    else if (strcmp(number, "LV")) {
        return 55;
    }
    else if (strcmp(number, "LVI")) {
        return 56;
    }
    else if (strcmp(number, "LVII")) {
        return 57;
    }
    else if (strcmp(number, "LVIII")) {
        return 58;
    }
    else if (strcmp(number, "LIX")) {
        return 59;
    }
    else if (strcmp(number, "LX")) {
        return 60;
    }
    else if (strcmp(number, "LXI")) {
        return 61;
    }
    else if (strcmp(number, "LXII")) {
        return 62;
    }
    else if (strcmp(number, "LXIII")) {
        return 63;
    }
    else if (strcmp(number, "LXIV")) {
        return 64;
    }
    else if (strcmp(number, "LXV")) {
        return 65;
    }
    else if (strcmp(number, "LXVI")) {
        return 66;
    }
    else if (strcmp(number, "LXVII")) {
        return 67;
    }
    else if (strcmp(number, "LXVIII")) {
        return 68;
    }
    else if (strcmp(number, "LXIX")) {
        return 69;
    }
    else if (strcmp(number, "LXX")) {
        return 70;
    }
    else if (strcmp(number, "LXXI")) {
        return 71;
    }
    else if (strcmp(number, "LXXII")) {
        return 72;
    }
    else if (strcmp(number, "LXXIII")) {
        return 73;
    }
    else if (strcmp(number, "LXXIV")) {
        return 74;
    }
    else if (strcmp(number, "LXXV")) {
        return 75;
    }
    else if (strcmp(number, "LXXVI")) {
        return 76;
    }
    else if (strcmp(number, "LXXVII")) {
        return 77;
    }
    else if (strcmp(number, "LXXVIII")) {
        return 78;
    }
    else if (strcmp(number, "LXXIX")) {
        return 79;
    }
    else if (strcmp(number, "LXXX")) {
        return 80;
    }
    else if (strcmp(number, "LXXXI")) {
        return 81;
    }
    else if (strcmp(number, "LXXXII")) {
        return 82;
    }
    else if (strcmp(number, "LXXXIII")) {
        return 83;
    }
    else if (strcmp(number, "LXXXIV")) {
        return 84;
    }
    else if (strcmp(number, "LXXXV")) {
        return 85;
    }
    else if (strcmp(number, "LXXXVI")) {
        return 86;
    }
    else if (strcmp(number, "LXXXVII")) {
        return 87;
    }
    else if (strcmp(number, "LXXXVIII")) {
        return 88;
    }
    else if (strcmp(number, "LXXXIX")) {
        return 89;
    }
    else if (strcmp(number, "XC")) {
        return 90;
    }
    else if (strcmp(number, "XCI")) {
        return 91;
    }
    else if (strcmp(number, "XCII")) {
        return 92;
    }
    else if (strcmp(number, "XCIII")) {
        return 93;
    }
    else if (strcmp(number, "XCIV")) {
        return 94;
    }
    else if (strcmp(number, "XCV")) {
        return 95;
    }
    else if (strcmp(number, "XCVI")) {
        return 96;
    }
    else if (strcmp(number, "XCVII")) {
        return 97;
    }
    else if (strcmp(number, "XCVIII")) {
        return 98;
    }
    else if (strcmp(number, "XCIX")) {
        return 99;
    }
    else if (strcmp(number, "C")) {
        return 100;
    }
}

/**
* The function converts the number from the Arabic system to the Roman one.
*
* @i -- the number that will be translated from the Arabic system to the Roman one. Type: int.
* @number -- the buffer supposed to contain the string representation of the result. Type: char * (out).
**/
void toRoman(int i, char *number /* out */) {
    static char* n[101] = {
                            "N",
                            "I",
                            "II",
                            "III",
                            "IV",
                            "V",
                            "VI",
                            "VII",
                            "VIII",
                            "IX",
                            "X",
                            "XI",
                            "XII",
                            "XIII",
                            "XIV",
                            "XV",
                            "XVI",
                            "XVII",
                            "XVIII",
                            "XIX",
                            "XX",
                            "XXI",
                            "XXII",
                            "XXIII",
                            "XXIV",
                            "XXV",
                            "XXVI",
                            "XXVII",
                            "XXVIII",
                            "XXIX",
                            "XXX",
                            "XXXI",
                            "XXXII",
                            "XXXIII",
                            "XXXIV",
                            "XXXV",
                            "XXXVI",
                            "XXXVII",
                            "XXXVIII",
                            "XXXIX",
                            "XL",
                            "XLI",
                            "XLII",
                            "XLIII",
                            "XLIV",
                            "XLV",
                            "XLVI",
                            "XLVII",
                            "XLVIII",
                            "XLIX",
                            "L",
                            "LI",
                            "LII",
                            "LIII",
                            "LIV",
                            "LV",
                            "LVI",
                            "LVII",
                            "LVIII",
                            "LIX",
                            "LX",
                            "LXI",
                            "LXII",
                            "LXIII",
                            "LXIV",
                            "LXV",
                            "LXVI",
                            "LXVII",
                            "LXVIII",
                            "LXIX",
                            "LXX",
                            "LXXI",
                            "LXXII",
                            "LXXIII",
                            "LXXIV",
                            "LXXV",
                            "LXXVI",
                            "LXXVII",
                            "LXXVIII",
                            "LXXIX",
                            "LXXX",
                            "LXXXI",
                            "LXXXII",
                            "LXXXIII",
                            "LXXXIV",
                            "LXXXV",
                            "LXXXVI",
                            "LXXXVII",
                            "LXXXVIII",
                            "LXXXIX",
                            "XC",
                            "XCI",
                            "XCII",
                            "XCIII",
                            "XCIV",
                            "XCV",
                            "XCVI",
                            "XCVII",
                            "XCVIII",
                            "XCIX",
                            "C"
                        };
    strcpy(number, n[i]);
}

int mid(int bot, int top) {
    int av = (top - (bot + 1));

    if (av % 2 != 0) {
        av += 1;
    }

    return bot + av/2;
}

int takePoint(int *bot, int *top, int basis, int r) {
    char answer[8];
    if (r == 0) {
        printf(_("The number greater than %d (yes/no) ?\n"), basis);
    } else {
        char nn[5];
        toRoman(basis, nn);
        printf(_("The number greater than %s (yes/no) ?\n"), nn);
    }

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

int main(int argc, char *argv[]) {
    const char *doc = _("The program tries to guess the number that you have guessed."); /**< The program about */
    const struct argp_option opts[] = {{"roman", 'r', 0, 0, _("Use the Roman mode instead of Arabic one.")}, {0},};
    const struct argp argp = {opts, parseArg, 0, doc};
    argp_parse(&argp, argc, argv, 0, 0, 0);

    setlocale(LC_ALL, "");
    bindtextdomain("100","po");
    textdomain("100");
    int bot = 1;
    int top = 100;
    int basis = top / 2;
    for(; bot != top ;) {
        basis = takePoint(&bot /* out */, &top /* out */, basis, r);
    }

    if (r == 0) {
        printf(_("Guessed number is %d !\n"), bot);
    } else {
        char nn[5];
        toRoman(bot, nn);
        printf(_("Guessed number is %s !\n"), nn);
    }

    return 0;
}