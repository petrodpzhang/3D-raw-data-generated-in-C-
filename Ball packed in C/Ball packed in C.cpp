#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
    int LX, LY, LZ, cons, size, R2;
    int LXC[9], LYC[9], LZC[9];
    unsigned char* raw;
    
    FILE* fd;
    LX = 100;
    LY = 100;
    LZ = 150;
    cons = 25;
    R2 = 25;

    for (int i = 1; i < 5; i++)
    {
        LZC[i] = 25 + cons;
    }
    LXC[1] = 25;
    LYC[1] = 25;
    LXC[2] = 25 + 50;
    LYC[2] = 25;
    LXC[3] = 25;
    LYC[3] = 25 + 50;
    LXC[4] = 25 + 50;
    LYC[4] = 25 + 50;

    for (int i = 5; i < 9; i++)
    {
        LZC[i] = 25 + 50 + cons;
    }
    LXC[5] = 25;
    LYC[5] = 25;
    LXC[6] = 25 + 50;
    LYC[6] = 25;
    LXC[7] = 25;
    LYC[7] = 25 + 50;
    LXC[8] = 25 + 50;
    LYC[8] = 25 + 50;

    size = LX * LY * LZ * sizeof(unsigned char);
    raw = (unsigned char*)malloc(size);
    fopen_s(&fd, "D:\\ball-C.raw", "w");

    int n = 0;
    for (int k = 0; k < LZ; k++)
    {
        for (int j = 0; j < LY; j++)
        {
            for (int i = 0; i < LX; i++)
            {
                raw[n] = 0;

                if ((k == 20 || k == 130) && (j % 2) == 0 && (i % 2) == 0) raw[n] = 255;
                for (int L = 1; L < 9; L++)
                {
                    if ((i - LXC[L]) * (i - LXC[L]) + (j - LYC[L]) * (j - LYC[L]) + (k - LZC[L]) * (k - LZC[L]) < R2 * R2)
                        raw[n] = 255;
                }
                n++;
            }
        }
    }

    cout << "print raw files" << endl;

    fwrite(raw, 1, size, fd);
    fclose(fd);
    return 0;
}

