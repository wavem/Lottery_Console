// Lottery_Console.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <Windows.h>


int g_WinNumber[7];
int g_G_4_Count;
int g_G_3_Count;
int g_G_2_Count;
int g_G_1_Count;

void GetLotteryNum(int* _pBuff) {
    
    int t_Count = 0;
    int t_Value = 0;
    bool t_bDuplicated = false;

    while (t_Count <= 6) {
        // Init Routine
        t_bDuplicated = false;

        // Making Value
        t_Value = rand() % 45 + 1;
        
        // Search Routine        
        for (int i = 0; i < 7; i++) {
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

void SortLotteryNum(int* _pBuff) {

    // Common
    int t_LNum[7] = { 0, };
    int t_Idx = 0;
    int t_Value = 0;
    bool t_bComplete = false;

    // Copy Routine
    for (int i = 0; i < 7; i++) {
        t_LNum[i] = *(_pBuff + i);
    }

    // Sorting Routine
    while (!t_bComplete) {

        if (t_Idx == 6) break;

        if (t_LNum[t_Idx] > t_LNum[t_Idx + 1]) {
            t_Value = t_LNum[t_Idx];
            t_LNum[t_Idx] = t_LNum[t_Idx + 1];
            t_LNum[t_Idx + 1] = t_Value;
            t_Idx = 0;
            continue;
        }
        else {
            t_Idx++;
        }
    }

    // Return Result
    for (int i = 0; i < 7; i++) {
        *(_pBuff + i) = t_LNum[i];
    }
}

void PrintGameInfo(__int64 _GameCount) {
    HANDLE t_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //COORD CursorPos;
    //CursorPos.X = 0;
    //CursorPos.Y = 8; 
    //SetConsoleCursorPosition(t_hConsole, CursorPos);
    __int64 t_TotalGameMoney = 0;
    SetConsoleTextAttribute(t_hConsole, 8);
    std::cout << "\nTOTAL GAME COUNT : ";
    SetConsoleTextAttribute(t_hConsole, 10);
    std::cout << _GameCount << "\n";
    
    SetConsoleTextAttribute(t_hConsole, 8);
    t_TotalGameMoney = _GameCount * 1000;
    std::cout << "TOTAL GAME MONEY : ";
    SetConsoleTextAttribute(t_hConsole, 10);
    std::cout << t_TotalGameMoney;
    SetConsoleTextAttribute(t_hConsole, 8);
    std::cout << " won\n";
    SetConsoleTextAttribute(t_hConsole, 15);
}

bool IsWinNumber(int _Num) {

    bool t_rst = false;
    for (int i = 0; i < 6; i++) {
        if (_Num == g_WinNumber[i]) t_rst = true;
    }
    return t_rst;
}

void PrintLotteryNum(int* _pBuff) {

    // Common
    int t_LNum[6] = { 0, };
    HANDLE t_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(t_hConsole, 15);
    int t_WinCount = 0;
    bool t_bGrade2 = false;

    // Copy Lottery Num
    for (int i = 0; i < 6; i++) {
        t_LNum[i] = *(_pBuff + i);
    }

    // Print and Check Routine
    for (int i = 0; i < 6; i++) {
        if (IsWinNumber(t_LNum[i])) {
            SetConsoleTextAttribute(t_hConsole, 6);
            t_WinCount++;
        }
        else {
            SetConsoleTextAttribute(t_hConsole, 15);
        }
        //std::cout << t_LNum[i] << "\t";
    }
    
    // Check Winner
    SetConsoleTextAttribute(t_hConsole, 10);
    if (t_WinCount == 4) {        
        //std::cout << "Grade 4 ! 50,000 won";
        g_G_4_Count++;
    }
    else if (t_WinCount == 5) {

        // Check Grade 2 Routine
        for (int i = 0; i < 6; i++) {
            if (g_WinNumber[6] == t_LNum[i]) {
                t_bGrade2 = true;
            }
        }

        if (t_bGrade2) {
            std::cout << "22222222222222222222";
            g_G_2_Count++;
        }
        else {
            std::cout << "Wow 3 !!!!!!!";
            g_G_3_Count++;
        }        
    }
    else if (t_WinCount == 6) {
        std::cout << "OMG 1 !!!!!!!!!!!!!!!!!!!!!!!";
        g_G_1_Count++;
    }

    //std::cout << "\n";
}

void PrintTotalResult() {
    HANDLE t_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(t_hConsole, 15);

    std::cout << "\n========================================\n"; // 40
    std::cout << "   Total Result\n";
    std::cout << "Grade 1 : ";
    SetConsoleTextAttribute(t_hConsole, 10);
    std::cout << g_G_1_Count << "\n";
    SetConsoleTextAttribute(t_hConsole, 15);

    std::cout << "Grade 2 : ";
    SetConsoleTextAttribute(t_hConsole, 10);
    std::cout << g_G_2_Count << "\n";
    SetConsoleTextAttribute(t_hConsole, 15);

    std::cout << "Grade 3 : ";
    SetConsoleTextAttribute(t_hConsole, 10);
    std::cout << g_G_3_Count << "\n";
    SetConsoleTextAttribute(t_hConsole, 15);

    std::cout << "Grade 4 : ";
    SetConsoleTextAttribute(t_hConsole, 10);
    std::cout << g_G_4_Count << "\n";
    SetConsoleTextAttribute(t_hConsole, 15);
}

int main()
{
    // Common
    srand((unsigned int)GetTickCount64());
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int LNum[7] = { 0, }; 
    __int64 TotalGameCount = 0;


    // START TEXT
    std::cout << "===============================================================\n"; // 63
    std::cout << "\t\t\tWelcome !!\n\n";
    std::cout << "\t\t  Today's L-Number is...\n\n";
    std::cout << "\t\t  ";
    SetConsoleTextAttribute(hConsole, 10);
    GetLotteryNum(g_WinNumber);
    SortLotteryNum(g_WinNumber);
    for (int i = 0; i < 6; i++) {
        std::cout << g_WinNumber[i] << "   ";
    }
    std::cout << "\n\t\t\t and Bonus : " << g_WinNumber[6];
    std::cout << "\n";
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << "===============================================================\n"; // 63    


    // INPUT ORDER
    std::cout << "How many game play do you want?  ";
    SetConsoleTextAttribute(hConsole, 6);
    std::cin >> TotalGameCount;    
    SetConsoleTextAttribute(hConsole, 15);
    PrintGameInfo(TotalGameCount);
        

    // TEST CODE
    COORD CursorPos;
    CursorPos.X = 0;
    CursorPos.Y = 12;

    while (1) {
        SetConsoleCursorPosition(hConsole, CursorPos);
        for (int k = 0; k < 15; k++) {
            for (int j = 0; j < 4; j++) {
                for (int i = 0; i < 6; i++) {
                    printf("%02X  ", rand() % 255);
                }
                printf("     ");
            }
            printf("\n");
        }
        Sleep(250);
    }
    

    
    
    

    
    
    




#if 0
    // GAME START
    std::cout << "\nGood Luck...\n";  
    for (int i = 0; i < TotalGameCount ; i++) {
        GetLotteryNum(LNum);
        SortLotteryNum(LNum);
        PrintLotteryNum(LNum);            
    }    


    // GAME OVER
    PrintTotalResult();
#endif
}



// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
