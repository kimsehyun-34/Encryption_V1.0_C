// ++ VSC에서는 한글출력이 꺠저서 나오기 때문에 모든 출력단어를 영어로 대체하겠습니다. ++

#include <stdio.h>
#include <string.h>     // str조작에 필요한 라이브
#include <stdlib.h>     // rand()함수포함 라이브 (랜덤함수)
#define MAX_LENGTH 1000 // 매크로 상수로 문자열의 최대 길이를 정의

char str[MAX_LENGTH]; // ipk=실행할 기능선택을 위한 변수, 문자열 길이 선언
int ipk, shift, b;    // 전역변수로 시프트(아스키코드를 +할 수) 양을 선언, b=출력에 쉬프트 수를 숨긴 임이의 수

void encrypt() // 사용자 정의 함수 암호화 함수
{
    for (int i = 0; i < strlen(str); i++) // 문자수만큼 반복함 (모든 문자를 작업해야 하기때문)
    {
        str[i] = (str[i] + shift); // 입력한 수 만큼 해당 단어의 아스키코드를 + 함
    }
}

void decrypt() // 사용자 정의 함수 해독 함수
{
    for (int i = 0; i < strlen(str); i++) // 반복문으로 문자열의 각 문자에 대해
    {
        str[i] = (str[i] - shift); // 암호화에 더해진 만큼 해당 단어의 아스키코드를 - 함
    }
}

int main()
{
    printf("input:");
    scanf("%d", &ipk); // 작업할 기능 선택(1=암호화, 2=복호화)
    if (ipk == 1)      // 암호화 작업에 들어감
    {
        printf("Enter string: ");       //="암호화할 문장입력"
        fgets(str, sizeof(str), stdin); // 사용자로부터 문자열을 입력받음
        printf("\n");
        shift = rand() % 30;                    // 시프트 변수를 랜덤으로 생성함
        b = shift * 34;                         // 암호를 다시 복호화 할떄 필요한 암호수를 임이의 수(34)를 곱하여 암호화
        encrypt();                              // 암호화 함수 호출
        printf("Encrypted string: %s \n", str); // 암호화된 문자열 출력
        printf("Encrypted shift: %d \n", b);    // 복호화 암호키 출력
    }

    else if (ipk == 2) // 복호화 작업에 들어감
    {
        printf("Enter an encrypted string: "); //= "복호화할 문장입력 하세요: "
        fgets(str, sizeof(str), stdin);        // 사용자로부터 암호화된 문자열을 입력받음
        printf("Enter an encrypted shift: ");  //= "암호화된 시프트값을 이력하세요: "
        scanf("%d", &shift);                   // 사용자로부터 임이의 시프트 양을 입력받음

        // char *list[10], *ptr = strtok(str, " ");
        // int i = 0;
        // while (ptr != NULL)
        // {
        //     list[i++] = ptr;
        //     ptr = strtok(NULL, " ");
        // }
        // char *str = list[0];
        // int *shift = list[1];

        shift = shift / 34;                    // 사용자로부터 받은 임의이 수에서 시프트양을 구함
        decrypt();                             // 해독 함수 호출
        printf("Decrypted string: %s\n", str); // 해독된 문자열 출력
        return 0;
    }
    else
    {
        printf("return");
        return 0;
    }
}