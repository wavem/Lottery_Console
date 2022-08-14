// Lottery_Console.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>


void GetLotteryNum(int* _pBuff) {
    
    int t_Count = 0;
    int t_Value = 0;
    bool t_bDuplicated = false;

    while (t_Count <= 5) {
        // Init Routine
        t_bDuplicated = false;

        // Making Value
        t_Value = rand() % 46;
        
        // Search Routine        
        for (int i = 0; i < 6; i++) {
            if (*(_pBuff + i) == t_Value) {
                t_bDuplicated = true;
            }
        }

        // Check Duplicated Number
        if (t_bDuplicated) continue;

        *(_pBuff + t_Count) = t_Value;
        t_Count++;
    }
}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_BLUE);

    srand((unsigned int)GetTickCount64());

    int LNum[6] = { 0, };
    GetLotteryNum(LNum);
    
    std::cout << "===============================================================\n"; // 63
    std::cout << "\t\t\tWelcome !!\n\n";
    std::cout << "\t\t  Today's L-Number is...\n\n";
    std::cout << "\t\t  ";
    SetConsoleTextAttribute(hConsole, 10);
    for (int i = 0; i < 6; i++) {
        std::cout << LNum[i] << "   ";
    }
    std::cout << "\n";
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << "===============================================================\n"; // 63    
    
    std::cout << "\nGood Luck...\n";


    std::cout << "\nTest\n";
    for (int i = 0; i < 10; i++) {
        GetLotteryNum(LNum);
            
        for (int k = 0; k < 6; k++) {
            std::cout << LNum[k] << "\t";
        }
        std::cout << "\n";
    }

}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
