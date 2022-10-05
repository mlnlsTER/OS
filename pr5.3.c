#include <stdio.h>
#include <stdlib.h>

struct student {
    char secondName[12];
    int numberOfGroup;
    int infSystDesign;
    int webTechnologies;
    int ukrainianLanguage;
} students[30];

void printSt(int curStud) {
    int i;
    printf("\tФамилия\t Группа\tУкр\tВеб\tИнф.сист");
    for (i = 0; i < curStud; i++) 
        printf("\n%d. %12s\t %d\t%d\t%d\t%d", i + 1, students[i].secondName, students[i].numberOfGroup, students[i].ukrainianLanguage, students[i].webTechnologies, students[i].infSystDesign);
    printf("\n\n");
}

void addSt(int curStud) {
    if (curStud + 1 == 30) {
        printSt(curStud);
        printf("\n\nПревышено кол-во студентов. Введите номер студента, которого хотите перезаписать: ");
        scanf("%d", &curStud);
    }
    printf("\nФамилия: ");
    scanf("%s", &students[curStud].secondName);
    while (students[curStud].numberOfGroup > 4 || students[curStud].numberOfGroup < 1) {
        printf("Номер группы (1-4): ");
        scanf("%d", &students[curStud].numberOfGroup);
        if (students[curStud].numberOfGroup > 4 || students[curStud].numberOfGroup < 1) {
            printf("\nНеверная группа!\n");
        }
    }
    printf("Оценка по ПИС: ");
    scanf("%d", &students[curStud].infSystDesign);
    printf("Оценка по ВТ: ");
    scanf("%d", &students[curStud].webTechnologies);
    printf("Оценка по Укр: ");
    scanf("%d", &students[curStud].ukrainianLanguage);
    printf("\n");
}

void deleteStudent(int curStud) {
    int index;
    printSt(curStud);
    while (index > 30 || index < 1) {
        printf("\nНомер студента для удаления: ");
        scanf("%d", &index);
        if (index < 1 || index > 30) {
            printf("Неверный номер!\n");
        }
    }
    int i;
    for (i = index - 1; i < curStud - 1; i++) {
        students[i] = students[i + 1];
    }
}

void printPenaltyStudents(int curStud) {
    int i, j = 0;
    for (i = 0; i < curStud; i++) {
        if (students[i].ukrainianLanguage < 50 || students[i].webTechnologies < 50 || students[i].infSystDesign < 50) {
            printf("\n%d. %s;", j + 1, students[i].secondName);
            j++;
        }
    }
    printf("\n");
}

void worstGroup(int curStud) {
    int i, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for (i = 0; i < curStud; i++) {
        if (students[i].numberOfGroup == 1) {
            sum1 += students[i].ukrainianLanguage;
            sum1 += students[i].infSystDesign;
            sum1 += students[i].webTechnologies;
        }
        else if (students[i].numberOfGroup == 2) {
            sum2 += students[i].ukrainianLanguage;
            sum2 += students[i].infSystDesign;
            sum2 += students[i].webTechnologies;
        }
        else if (students[i].numberOfGroup == 3) {
            sum3 += students[i].ukrainianLanguage;
            sum3 += students[i].infSystDesign;
            sum3 += students[i].webTechnologies;
        }
        else {
            sum4 += students[i].ukrainianLanguage;
            sum4 += students[i].infSystDesign;
            sum4 += students[i].webTechnologies;
        }
    }

    if (sum1 < sum2 && sum1 < sum3 && sum1 < sum4)  {
        printf("\nХудшая группа: 1.\n");
    }
    else if (sum2 < sum1 && sum2 < sum3 && sum2 < sum4) printf("\nХудшая группа: 2.\n");
    else if (sum3 < sum1 && sum3 < sum2 && sum3 < sum4) printf("\nХудшая группа: 3.\n");
    else printf("\nХудшая группа: 4.\n");
}

void goodStudentsPercentage(int curStud) {
    int numb = 0, i;

    for (i = 0; i < curStud; i++) {
        if (students[i].ukrainianLanguage > 70 && students[i].webTechnologies > 70 && students[i].infSystDesign > 70) {
            numb++;
        }
    }
    printf("\nПроцент: %.2f\n", (float)numb / curStud * 100);
}

void bestSubject(int curStud) {
    int sumWT = 0, sumUL = 0, sumIS = 0, i;
    for (i = 0; i < curStud; i++) {
        sumWT += students[i].webTechnologies;
        sumUL += students[i].ukrainianLanguage;
        sumIS += students[i].infSystDesign;
    }
	printf("\nЛучший предмет: ");
    if (sumWT > sumUL && sumWT > sumIS) 
		printf("Веб-технологии.\n");
    else if (sumIS > sumWT && sumIS > sumUL) printf("Проектирование информационных систем.\n");
    else printf("Украинский язык.\n");
}

int main() {
	system("chcp 1251");
	system("cls");
    int choice, curStud = 0;
    while (1) {
        printf("Главное меню:\n1. Добавить студента;\n2. Удалить студента;\n3. Меню студентов;\n4. Список студентов;\n5. Выход.\n");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            addSt(curStud);
            if (curStud + 1 < 30) curStud++;
            break;
        case 2:
            deleteStudent(curStud);
            if (curStud + 1 > 1) curStud--;
            break;
        case 3:
            while (choice != 5) {
                printf("\nМеню студентов:\n1. Студенты с задолженностью;\n2. Процент студентов, сдавших все экзамены на хорошо и отлично;\n3. Название предмета, который был сдан лучше всего;\n4. Номер группы с наихудшей успеваемостью;\n5. Выход в главное меню.\n");
                scanf("%d", &choice);
                switch (choice) {
                case 1:
                    printPenaltyStudents(curStud);
                    break;
                case 2:
                    goodStudentsPercentage(curStud);
                    break;
                case 3:
                    bestSubject(curStud);
                    break;
                case 4:
                    worstGroup(curStud);
                    break;
                case 5:
                    printf("\n");
                    break;
                default:
                    printf("Неверная команда!");
                    break;
                }
            }
            break;
        case 4:
            printSt(curStud);
            break;
        case 5:
            exit(-1);
        default:
            printf("Неверная команда!");
        }
    }
}
