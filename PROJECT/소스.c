//헤더파일 선언
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define _CRT_SECURE_NO_WARNINGS
#define NUM 100

//구조체 선언
typedef struct line {
    char a[NUM];
} line;

//함수선언
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
    int number = 0; //사용자 입력 변수
    line* p[NUM]; //구조체 변수

    system("mode con cols=32 lines=30"); //콘솔창 크기 조정

    necrophilia(); //함수호출

    fx();

    printf("\n1. 회원가입 / 2. 로그인 : ");
    scanf_s("%d", &number);

    switch (number) {

    case 1: //number(입력받은숫자)가 1이면 signup함수로 이동
        signup(p);
        break;

    case 2: //number가 2이면 login함수로 이동
        login(p);
        break;

    default: //number가 1, 2 중에 없다면 종료
        hprintf();
        return;
    }
}

//회원가입된 계정
void fx(void) {
    int a = 0; //for문용 변수

    FILE* fs;
    fopen_s(&fs, "privacy.txt", "r"); //읽기모드로 파일 제작

    if (fs == NULL) { //fs가 NULL이면 쓰기모드로 파일을 제작
        fopen_s(&fs, "privacy.txt", "w");
    }

    printf("\n현재 회원가입된 계정\n");

    //파일읽기
    while (feof(fs) == 0) {
        char iary[NUM]; //파일읽기용 변수
        fgets(iary, NUM, fs);
        a++;
    }

    fseek(fs, 0, SEEK_SET);  //파일의 커서 위치를 맨처음으로 이동

    //파일읽고 출력
    if (a != 1) {
        for (int i = 0; i < a - 1; i++) {
            char str[NUM];
            fgets(str, NUM, fs);
            char* ptr = strtok(str, " ");
            printf("\n%s\n", ptr);
        }
    }

    else if (a == 1) {
        printf("\n회원가입된 계정이 없습니다.\n");
    }

    printf("================================\n");
    fclose(fs); //파일닫기
}

//회원가입
void signup(line* p[]) {
    int number = 0; //사용자 입력 변수
    char ID[NUM]; //사용자 입력 변수
    char pswd[NUM]; //사용자 입력 변수
    char result[NUM]; //저장용 변수

    system("mode con cols=50 lines=16");
    system("cls");
    printf("\n                    ----------");
    printf("\n                    |회원가입|\n");
    printf("                    ----------");

    printf("\n\n\n\n아이디를 입력해주세요 : ");
    scanf_s(" %s", &ID, sizeof(ID));
    printf("비밀번호를 입력해주세요 : ");
    scanf_s(" %s", &pswd, sizeof(pswd));

    FILE* fs;
    fopen_s(&fs, "privacy.txt", "a+"); //쓰기,읽기모드로 파일 제작

    //있는 계정인지 확인
    while (feof(fs) == 0) {
        char str[NUM]; //파일읽기용 변수

        fgets(str, NUM, fs);
        char* ptr = strtok(str, " ");

        while (ptr != NULL) {

            if (strcmp(ptr, ID) == 0) {
                printf("\n이미 있는 아이디입니다. 다시 입력해주세요.");
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
    printf("\n\n\n\n\n\n\n                  회원가입 성공!\n");
    Sleep(1000);
    system("cls");
    system("mode con cols=32 lines=30");

    necrophilia();

    fx();

    printf("\n1. 회원가입 / 2. 로그인 : ");
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

//로그인
void login(line* p[]) {
    char ID[NUM]; //사용자 입력 변수
    char pswd[NUM]; //사용자 입력 변수
    char result[NUM]; //저장용 변수
    char ps[NUM]; //저장용 변수

    system("mode con cols=50 lines=16");
    system("cls");
    printf("\n                    --------");
    printf("\n                    |로그인|\n");
    printf("                    --------");

    printf("\n\n\n\n아이디를 입력해주세요 : ");
    scanf_s(" %s", &ID, sizeof(ID));
    printf("비밀번호를 입력해주세요 : ");
    scanf_s(" %s", &pswd, sizeof(pswd));

    strcpy(ps, pswd);

    FILE* fs;
    fopen_s(&fs, "privacy.txt", "r"); //읽기모드로 파일 제작

    strcpy(result, ecyto(pswd));
    strcat(result, "\n");

    //회원가입한 계정과 맞는지 확인
    while (feof(fs) == 0) {
        int a; //사용자 입력 변수
        char str[NUM];

        fgets(str, NUM, fs);
        char* ptr = strtok(str, " ");

        while (ptr != NULL) {

            if (strcmp(ptr, ID) == 0) {
                ptr = strtok(NULL, " ");
                if (strcmp(ptr, result) == 0) {

                    system("cls");
                    Sleep(1000);
                    printf("\n\n\n\n\n\n\n                   로그인 성공!\n");
                    Sleep(1000);
                    system("cls");
                    system("mode con cols=38 lines=30");

                    necrophilia();
                    printf("유저 : ");
                    printf(ID);
                    printf("\n======================================\n");

                    printf("\n1. 문장 입력 / 2. 문장 복호화 : ");
                    scanf_s("%d", &a, sizeof(a));
                    switch (a) {
                    case 1: //입력한 숫자(a)가 1이면 import함수로 이동
                        import(p, ID, ps);
                        return;
                    case 2: //a가 2이면 dcyto함수로 이동
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

    printf("\n회원 가입된 계정이 아닙니다.");
    fclose(fs);
}

//문장입력
void import(line* p[], char x[], char y[]) {
    char stc[NUM]; //사용자 입력 변수
    char result[NUM]; //저장용 변수
    char x1[NUM]; //저장용 변수

    strcpy(x1, x);
    strcat(x, ".txt");

    FILE* fs;
    fopen_s(&fs, x, "a"); //이어쓰기모드로 파일 제작

    for (int i = 0; i < NUM; i++) {
        p[i] = NULL; //구조체 배열 초기화
    }

    system("cls");
    system("mode con cols=50 lines=30");

    necrophilia();
    printf("현재 파일 : ");
    printf(x);
    printf("\n유저 : ");
    printf(x1);
    printf("\n==================================================");

    printf("\n\n#end#를 입력하시면 종료됩니다.\n(*엔터를 누르면 수정 불가*)\n\n");

    //문장입력
    for (int i = 0; i < NUM; i++) {

        if (p[i] == NULL) {
            p[i] = (line*)malloc(sizeof(line)); //동적할당 메모리 생성
            scanf_s("%s", &stc, sizeof(stc));

            if (strcmp(stc, "#end#") == 0) { //종료 문자열 입력시 종료
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

//비밀번호 암호화
char* ecyto(char y[]) {
    int a = 0, b = 0; //저장용 변수

    for (int k = 0; k < 2; k++) {
        for (int i = 0; i < strlen(y); i++) { //약수의 개수만큼 더하기(카이사르)
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

//문장 암호화
char* encryption(char x[], char y[]) {
    int j = 0; //for문용 변수
    int len = strlen(y); //저장용 변수
    for (int i = 0; i < strlen(x); i++,j++) { //비즈네르
        x[i] += y[j%len];
    }

    return x;
}

//입력 문장 복호화
void dcyto(char x[], char y[]) {
    char str[NUM]; //암호화 문장 변수
    int j = 0; //for문용 변수
    int len = strlen(y); //저장용 변수

    strcat(x, ".txt");

    FILE* fs;
    fopen_s(&fs, x, "r"); //읽기모드로 파일 제작

    printf("\n");

    //복호화
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

//시간
void necrophilia(void) {
    time_t tnow;
    struct tm* t;
    time(&tnow);
    t = (struct tm*)localtime(&tnow);
    printf("%d년 %d월 %d일 ", 1900 + t->tm_year, t->tm_mon + 1, t->tm_mday);

    switch (t->tm_wday) {
    case 0:printf("일요일 "); break;
    case 1:printf("월요일 "); break;
    case 2:printf("화요일 "); break;
    case 3:printf("수요일 "); break;
    case 4:printf("목요일 "); break;
    case 5:printf("금요일 "); break;
    case 6:printf("토요일 "); break;
    }

    printf("%d:%02d", t->tm_hour, t->tm_min);
    printf("\n");
}

//오류
void hprintf(void) {
    printf("\n잘못입력되었습니다.\n");
}
d