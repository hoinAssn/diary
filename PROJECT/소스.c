//������� ����
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define NUM 100

//����ü ����
typedef struct line {
    char a[NUM];
} line;

//�Լ�����
void hprintf(void);
void necrophilia(void);
void fx(void);
void signup(line* p[]);
void login(line* p[]);
void import(line* p[], char x[], char y[]);
char* ecyto(char y[]);
char* encryption(char x[], char y[]);
void dcyto(char x[], char y[]);

int main()
{
    int number = 0; //����� �Է� ����
    line* p[NUM]; //����ü ����

    system("mode con cols=32 lines=30"); //�ܼ�â ũ�� ����

    necrophilia(); //�Լ�ȣ��

    fx();

    printf("\n1. ȸ������ / 2. �α��� : ");
    scanf_s("%d", &number);

    switch (number) {

    case 1: //number(�Է¹�������)�� 1�̸� signup�Լ��� �̵�
        signup(p);
        break;

    case 2: //number�� 2�̸� login�Լ��� �̵�
        login(p);
        break;

    default: //number�� 1, 2 �߿� ���ٸ� ����
        hprintf();
        return;
    }
}

//ȸ�����Ե� ����
void fx(void) {
    int a = 0; //for���� ����

    FILE* fs;
    fopen_s(&fs, "privacy.txt", "r"); //�б���� ���� ����

    if (fs == NULL) { //fs�� NULL�̸� ������� ������ ����
        fopen_s(&fs, "privacy.txt", "w");
    }

    printf("\n���� ȸ�����Ե� ����\n");

    //�����б�
    while (feof(fs) == 0) {
        char iary[NUM]; //�����б�� ����
        fgets(iary, NUM, fs);
        a++;
    }

    fseek(fs, 0, SEEK_SET);  //������ Ŀ�� ��ġ�� ��ó������ �̵�

    //�����а� ���
    if (a != 1) {
        for (int i = 0; i < a - 1; i++) {
            char str[NUM];
            fgets(str, NUM, fs);
            char* ptr = strtok(str, " ");
            printf("\n%s\n", ptr);
        }
    }

    else if (a == 1) {
        printf("\nȸ�����Ե� ������ �����ϴ�.\n");
    }

    printf("================================\n");
    fclose(fs); //���ϴݱ�
}

//ȸ������
void signup(line* p[]) {
    int number = 0; //����� �Է� ����
    char ID[NUM]; //����� �Է� ����
    char pswd[NUM]; //����� �Է� ����
    char result[NUM]; //����� ����

    system("mode con cols=50 lines=16");
    system("cls");
    printf("\n                    ----------");
    printf("\n                    |ȸ������|\n");
    printf("                    ----------");

    printf("\n\n\n\n���̵� �Է����ּ��� : ");
    scanf_s(" %s", &ID, sizeof(ID));
    printf("��й�ȣ�� �Է����ּ��� : ");
    scanf_s(" %s", &pswd, sizeof(pswd));

    FILE* fs;
    fopen_s(&fs, "privacy.txt", "a+"); //����,�б���� ���� ����

    //�ִ� �������� Ȯ��
    while (feof(fs) == 0) {
        char str[NUM]; //�����б�� ����

        fgets(str, NUM, fs);
        char* ptr = strtok(str, " ");

        while (ptr != NULL) {

            if (strcmp(ptr, ID) == 0) {
                printf("\n�̹� �ִ� ���̵��Դϴ�. �ٽ� �Է����ּ���.");
                fclose(fs);
                Sleep(1500);
                signup(p);
            }

            else
                break;
        }
    }

    strcpy(result, ecyto(pswd));
    strcat(ID, " ");
    strcat(result, "\n");

    fputs(ID, fs);
    fputs(result, fs);
    fclose(fs);

    system("cls");
    Sleep(1000);
    printf("\n\n\n\n\n\n\n                  ȸ������ ����!\n");
    Sleep(1000);
    system("cls");
    system("mode con cols=32 lines=30");

    necrophilia();

    fx();

    printf("\n1. ȸ������ / 2. �α��� : ");
    scanf_s("%d", &number, sizeof(number));

    switch (number) {

    case 1:
        signup(p);
        break;

    case 2:
        login(p);
        break;

    default:
        hprintf();
        break;
    }
}

//�α���
void login(line* p[]) {
    char ID[NUM]; //����� �Է� ����
    char pswd[NUM]; //����� �Է� ����
    char result[NUM]; //����� ����
    char ps[NUM]; //����� ����

    system("mode con cols=50 lines=16");
    system("cls");
    printf("\n                    --------");
    printf("\n                    |�α���|\n");
    printf("                    --------");

    printf("\n\n\n\n���̵� �Է����ּ��� : ");
    scanf_s(" %s", &ID, sizeof(ID));
    printf("��й�ȣ�� �Է����ּ��� : ");
    scanf_s(" %s", &pswd, sizeof(pswd));

    strcpy(ps, pswd);

    FILE* fs;
    fopen_s(&fs, "privacy.txt", "r"); //�б���� ���� ����

    strcpy(result, ecyto(pswd));
    strcat(result, "\n");

    //ȸ�������� ������ �´��� Ȯ��
    while (feof(fs) == 0) {
        int a; //����� �Է� ����
        char str[NUM];

        fgets(str, NUM, fs);
        char* ptr = strtok(str, " ");

        while (ptr != NULL) {

            if (strcmp(ptr, ID) == 0) {
                ptr = strtok(NULL, " ");
                if (strcmp(ptr, result) == 0) {

                    system("cls");
                    Sleep(1000);
                    printf("\n\n\n\n\n\n\n                   �α��� ����!\n");
                    Sleep(1000);
                    system("cls");
                    system("mode con cols=38 lines=30");

                    necrophilia();
                    printf("���� : ");
                    printf(ID);
                    printf("\n======================================\n");

                    printf("\n1. ���� �Է� / 2. ���� ��ȣȭ : ");
                    scanf_s("%d", &a, sizeof(a));
                    switch (a) {
                    case 1: //�Է��� ����(a)�� 1�̸� import�Լ��� �̵�
                        import(p, ID, ps);
                        return;
                    case 2: //a�� 2�̸� dcyto�Լ��� �̵�
                        dcyto(ID, ps);
                        return;
                    }
                }
            }

            else if (strcmp(ptr, ID) != 0) {
                break;
            }
        }
    }

    printf("\nȸ�� ���Ե� ������ �ƴմϴ�.");
    fclose(fs);
}

//�����Է�
void import(line* p[], char x[], char y[]) {
    char stc[NUM]; //����� �Է� ����
    char result[NUM]; //����� ����
    char x1[NUM]; //����� ����

    strcpy(x1, x);
    strcat(x, ".txt");

    FILE* fs;
    fopen_s(&fs, x, "a"); //�̾����� ���� ����

    for (int i = 0; i < NUM; i++) {
        p[i] = NULL; //����ü �迭 �ʱ�ȭ
    }

    system("cls");
    system("mode con cols=50 lines=30");

    necrophilia();
    printf("���� ���� : ");
    printf(x);
    printf("\n���� : ");
    printf(x1);
    printf("\n==================================================");

    printf("\n\n#end#�� �Է��Ͻø� ����˴ϴ�.\n(*���͸� ������ ���� �Ұ�*)\n\n");

    //�����Է�
    for (int i = 0; i < NUM; i++) {

        if (p[i] == NULL) {
            p[i] = (line*)malloc(sizeof(line)); //�����Ҵ� �޸� ����
            scanf_s("%s", &stc, sizeof(stc));

            if (strcmp(stc, "#end#") == 0) { //���� ���ڿ� �Է½� ����
                char tmp[] = "--------";
                strcpy(result, encryption(tmp, y));
                fputs(result, fs);
                fputs("\n", fs);
                free(p[i]);
                break;
            }

            strcpy(result, encryption(stc, y));
            fputs(result, fs);
            fputs("\n", fs);
            free(p[i]);
        }
    }
    fclose(fs);
}

//��й�ȣ ��ȣȭ
char* ecyto(char y[]) {
    int a = 0, b = 0; //����� ����

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < strlen(y); i++) { //����� ������ŭ ���ϱ�(ī�̻縣)
            a = 0;
            for (int j = 1; j <= y[i] + b; j++) {
                if ((y[i] + b) % j == 0) {
                    a += 1;
                }
            }
            b = a;
            y[i] += b;
        }
    }
    return y;
}

//���� ��ȣȭ
char* encryption(char x[], char y[]) {
    int j = 0; //for���� ����
    int len = strlen(y); //����� ����
    for (int i = 0; i < strlen(x); i++,j++) { //����׸�
        x[i] += y[j%len];
    }

    return x;
}

//�Է� ���� ��ȣȭ
void dcyto(char x[], char y[]) {
    char str[NUM]; //��ȣȭ ���� ����
    int j = 0; //for���� ����
    int len = strlen(y); //����� ����

    strcat(x, ".txt");

    FILE* fs;
    fopen_s(&fs, x, "r"); //�б���� ���� ����

    printf("\n");

    //��ȣȭ
    while (feof(fs) == 0) {

        char str[NUM];
        fgets(str, NUM, fs);

        if (strcmp(str, "--------\n") == 0) {
            break;
        }

        for (int i = 0, j = 0; i < strlen(str); i++, j++) {
            if (strcmp(&str[i], "\n") == 0) {
                continue;
            }
            
            str[i] -= y[j % len];
        }

        printf("%s", str);
    }

    fclose(fs);
}

//�ð�
void necrophilia(void) {
    time_t tnow;
    struct tm* t;
    time(&tnow);
    t = (struct tm*)localtime(&tnow);
    printf("%d�� %d�� %d�� ", 1900 + t->tm_year, t->tm_mon + 1, t->tm_mday);

    switch (t->tm_wday) {
    case 0:printf("�Ͽ��� "); break;
    case 1:printf("������ "); break;
    case 2:printf("ȭ���� "); break;
    case 3:printf("������ "); break;
    case 4:printf("����� "); break;
    case 5:printf("�ݿ��� "); break;
    case 6:printf("����� "); break;
    }

    printf("%d:%02d", t->tm_hour, t->tm_min);
    printf("\n");
}

//����
void hprintf(void) {
    printf("\n�߸��ԷµǾ����ϴ�.\n");
}
d