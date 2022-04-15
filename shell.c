#include "shell.h"

void blue()
{
    printf("\033[0;34m");
}
void green()
{
    printf("\033[0;32m");
}
void purple()
{
    printf("\033[0;35m");
}

void reset()
{
    printf("\033[0m");
}
void welcom()
{
    char *logo[] = {"                     aRTI//BARK             ____\n",
                    "             simpleSH//////////Shl         |B//S|", "    |\n",
                    "          SH//////YS           shell//Sh   |A@@I|", "    | Welcome to simple shell\n",
                    " Sim aSystemSH//Sh              sys//B     |R$$M|", "    | Version 1.0\n",
                    " ArtABBBaraKk///Sh               sM//E     |A^^P|", "    |\n",
                    "         pCCCCY//h          eSS@@ y//E     |K**L|", "    | https://github.com/\n",
                    "         SPPPP///a          pP///AC//E     |&&&E|", "    |\n",
                    "              A//A            smP////S     |A**S|", "    | Have fun!\n",
                    "              p///Ac            sE///a     |R##H|", "    |\n",
                    "              P////YCpc           L//L     |T!!E|", "    | Wanna support simple shell?\n",
                    "       scccccp///pSP///p          p//l     |I%%L|", "    |\n",
                    "      sY/////////y  caa           S//h     |U--L|", "    |\n",
                    "       shsSellH//Ya              pY/Sh     |MIGT|", "    |\n",
                    "        sH/ShS////YCc          aC//Yp      |____|", "    |\n",
                    "         Si  shlll//SHsimpleSH//LSs\n",
                    "                  shell//////IPSHs\n",
                    "                       artium\n", '\0'};
    int i = 0;
    purple();
    printf("\n------------------------------------\033[1m Barak Sharabi && Artium Shabalin\033[0m------------------------------------\n\n");
    green();
    do
    {
        printf("%s", logo[i++]);
        if (i % 2 != 0 || i > 26)
            green();
        else
            blue();
    } while (logo[i]);
    reset();
    puts("\n\n");
}
/**
 * @brief Check the current location
 *
 * @param loc : current location
 */
void check_location(char *loc)
{
    if (getcwd(loc, max_length) == NULL)
    {
        printf("error in finding the location, check again later...\n");
    }
    else
    {
        printf("%d\n", local_);
        if (local_)
        {
            _local();
            printf("%s>", loc);
            blue();
            printf("$ ");
            dup2(1, 123);
            dup2(sock, 1);
            return;
        }
        printf("%s>", loc);
        blue();
        printf("$ ");
    }
}
/**
//  * @brief Return the current directory
//  *
//  */
void get_dir()
{

    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir("./")) != NULL)
    {
        /* print all the files and directories within directory */
        while ((ent = readdir(dir)) != NULL)
        {
            printf("%s\n", ent->d_name);
        }
        closedir(dir);
    }
    else
    {
        /* could not open directory */
        perror("");
        return;
    }
}
int _copy()
{
    char ch;
    FILE *source, *target;
    source = fopen(comArr[1], "r");
    if (source == NULL)
    {
        printf("Error...\n");
        return -1;
    }
    target = fopen(comArr[2], "w");
    if (target == NULL)
    {
        printf("Error...\n");
        fclose(source);
        return -1;
    }
    while ((ch = fgetc(source)) != EOF)
        fputc(ch, target);

    printf("File copied successfully.\n");
    fclose(source);
    fclose(target);
    return 1;
}
void split(char *comm)
{
    char *token;
    /* get the first token */
    token = strtok(comm, " ");
    int i = 0;
    while (*(token + i))
    {
        *(token + i) = toupper(*(token + i));
        i++;
    }
    /* walk through other tokens */
    i = 0;
    while (token != NULL)
    {
        comArr[i++] = token;
        token = strtok(NULL, " ");
    }
    comArr[i] = NULL;
}
int _local()
{
    dup2(123, 1);
    local_ = 0;
    return 1;
}
int _Echo()
{
    int i = 0;
    while (comArr[++i] != NULL)
        printf("%s ", comArr[i]);
    puts("");
    return 1;
}
int _TCP()
{
    local_ = (strcmp(comArr[1], "PORT") == 0) ? client() : -1;
    if (local_)
    {
        dup2(1, 123);
        dup2(sock, 1);
    }
    return local_;
}
int _Dir()
{
    get_dir();
    return 1;
}
int _cd()
{
    if (chdir(comArr[1]) != 0)
    {
        printf("error in changing directory...\n");
        return -1;
    }
    return 1;
}
int _Delete()
{
    unlink(comArr[1]);
    return 1;
}
int Exit()
{
    return 0;
}
int run()
{
    int sys = 1;
    int ans = 1;
    while (ans)
    {
        sys = 1;
        green();
        check_location(loc);

        gets(com);
        split(com);
        for (int i = 0; i < sizeof(commands) / sizeof(commands[0]); i++)
        {
            if (strcasecmp(comArr[0], commands[i].comm) == 0)
            {
                ans = commands[i].func_ptr();
                sys = 0;
            }
        }
        /**
         * system is a system call function
         */
        if (sys)
            system(com);
    }
    return 1;
}
int main()
{
    welcom();
    return run();
}