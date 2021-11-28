#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include <math.h>
#include <conio.h>
#include <string.h>

int main(){

    int y = 22;
    int x = 80;

    char *tela;
    float A=0, B=0, i, j;
    DWORD dwBytesWritten = 0;
    COORD coordDest;
    tela = malloc (1760*sizeof(char));

    SMALL_RECT m_rectWindow = { 0, 0, (short)x - 1, (short)y - 1 };

    CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 4;
		cfi.dwFontSize.X = y/1.5;//aspect ratio 4:3
		cfi.dwFontSize.Y = x/2;
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;

    coordDest.X = 0; coordDest.Y = 0;

    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetCurrentConsoleFontEx(hConsole, FALSE, &cfi);
    SetConsoleWindowInfo(hConsole, TRUE, &m_rectWindow);
    COORD coord = { (short)x, (short)y };

    SetConsoleScreenBufferSize(hConsole, coord);

    SetConsoleActiveScreenBuffer(hConsole);

    while (1 == 1){

        memset(tela,32,1760);
        for(j=0; 6.28>j; j+=0.07) {
            for(i=0; 6.28 >i; i+=0.02) {
                float sini=sin(i),
                      cosj=cos(j),
                      sinA=sin(A),
                      sinj=sin(j),
                      cosA=cos(A),
                      cosj2=cosj+2,
                      mess=1/(sini*cosj2*sinA+sinj*cosA+5),
                      cosi=cos(i),
                      cosB=cos(B),
                      sinB=sin(B),
                      t=sini*cosj2*cosA-sinj* sinA;
                int x=40+30*mess*(cosi*cosj2*cosB-t*sinB),
                    y= 12+15*mess*(cosi*cosj2*sinB +t*cosB),
                    o=x+80*y,
                    N=8*((sinj*sinA-sini*cosj*cosA)*cosB-sini*cosj*sinA-sinj*cosA-cosi *cosj*sinB);
                if(22>y&&y>0&&x>0&&80>x){
                    tela[o]=".,-~:;=!*#$@"[N>0?N:0];
                }
            }
        }
        for(int k=0; 1761>k; k++)
            tela[k]=k%80?tela[k]:' ';

        A+=0.02;
        B+= 0.02;

        WriteConsoleOutputCharacter(hConsole, tela, y*x, coordDest, &dwBytesWritten);
    }
    free(tela);
    return 0;
}
