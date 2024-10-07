/*
 * @Author: SingleBiu
 * @Date: 2024-10-06 18:44:32
 * @LastEditors: SingleBiu
 * @LastEditTime: 2024-10-07 19:39:47
 * @Description: file content
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DEBUG 0

int main()
{
    char c_str_tesseract[128] = "tesseract ";
    char c_str_lang[12] = " -l chi_sim";
    char c_filename[32];
    char c_user_input[64];
    int  i_choice;    

    system("clear");
    memset(c_filename,0,sizeof(c_filename));
    memset(c_user_input,0,sizeof(c_user_input));
    printf("Welcome to use tesseract-ocr demo\n");
    printf("---1--- store in file\n");
    printf("---2--- display on command line\n");
    printf("---0--- exit\n");
    printf("Please choose the command:\n");
    scanf("%d",&i_choice);
    if(i_choice <= 0 || i_choice > 2)
    {
        return 0;
    }
    switch(i_choice)
    {
        case 1:        
            printf("Please input the url of the picture:\n");
            scanf("%s",c_user_input);
            printf("Please intput file name:\n");
            scanf("%s",c_filename);
            strcat(c_str_tesseract,c_user_input);
            strcat(c_str_tesseract," ");
            strcat(c_str_tesseract,c_filename);
            strcat(c_str_tesseract,c_str_lang);
            #if DEBUG
                printf("Output:\n%s\n",c_str_tesseract);
            #endif
            // system(c_str_tesseract);
            break;
        case 2:
            printf("Please input the url of the picture:\n");
            scanf("%s",c_user_input);
            strcat(c_str_tesseract,c_user_input);
            strcat(c_str_tesseract," ");
            strcat(c_str_tesseract,"stdout");
            strcat(c_str_tesseract,c_str_lang);
            #if DEBUG
                printf("Output:\n%s\n",c_str_tesseract);
            #endif
            system(c_str_tesseract);
            break;
        default:
            return 0;
    }
    return 0;
}
