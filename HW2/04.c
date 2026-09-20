#include <stdio.h>
#include <windows.h>

int main(void)
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
	
    int A, B;

    printf(" A B | A->B | !A||B | Проверка | A<->B | Итог\n");
    printf("---------------------------------------------------\n");

    for (A = 0; A <= 1; A++)
    {
        for (B = 0; B <= 1; B++)
        {
            int implication = !A || B;
            int implication_formula = (!A) || B;

            int equivalence = (A == B);
            int equivalence_formula = (A && B) || (!A && !B);

            printf(" %d %d |   %d  |   %d   |    %d    |   %d   |    %d\n",
                   A,
                   B,
                   implication,
                   implication_formula,
                   implication == implication_formula,
                   equivalence,
                   equivalence_formula);
        }
    }

    return 0;
}

