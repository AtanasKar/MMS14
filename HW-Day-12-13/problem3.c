#include <stdio.h>

void VMirror(unsigned char *pImage)
{
    int front = 0, end = 0;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 4; j++)
        {
            front = !!(pImage[i] & (1 << j));
            end = !!(pImage[i] & (1 << 7 - j));

            if (front)
            {
                pImage[i] |= (1 << (7 - j));
            }
            else
            {
                pImage[i] &= ~(1 << (7 - j));
            }

            if (end)
            {
                pImage[i] |= (1 << j);
            }
            else
            {
                pImage[i] &= ~(1 << j);
            }
        }
    }
}

int main()
{
    unsigned char image[8] = {0x7F, 0x40, 0x40, 0x40, 0x7F, 0x00, 0x00, 0x00};
    
    VMirror(image);
    
    for (size_t i = 0; i < 8; i++)
    {
        printf("%x ", image[i]);
    }

    putchar('\n');

    return 0;
}