/*
Assignment name  : inter
Expected files   : inter.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and displays, without doubles, the
characters that appear in both strings, in the order they appear in the first
one.

The display will be followed by a \n.

If the number of arguments is not 2, the program displays \n.

Examples:

$>./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
padinto$
$>./inter ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6ewg4$
$>./inter "nothing" "This sentence hides nothing" | cat -e
nothig$
$>./inter | cat -e
$
*/

#include <unistd.h>

int main(int argc, char** argv) {
    int used[255];
    int i;
    int j;

    if (argc == 3) {
        i = 0;
        while(i < 255) {
            used[i++] = 0;
        }
        i = 2;
        while(i > 0) {
            j = 0;
            while (argv[i][j]) {
                if (!used[(unsigned int)argv[i][j]]) {
                    used[(unsigned int)argv[i][j]] = 1;
                }
                if (i == 1 && used[(unsigned int)argv[i][j]] == 1) {
                    used[(unsigned int)argv[i][j]] = 2;
                    write(1, &argv[i][j], 1);
                }
                j++;
            }
            i--;
        }
    }
    write(1, "\n", 1);
    return 0;
}