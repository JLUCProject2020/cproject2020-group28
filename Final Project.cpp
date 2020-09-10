#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PAGEMAX 100 //日记总篇数最大值
#define PASSAGEMAX 500 //日记内容最大值
#define SIZE 20 //最多注册人数

int NUM = 2;//已存在注册数
int z;//日期检查变量

typedef struct
{
    char message[PAGEMAX][3][PASSAGEMAX]; //日记信息，massage[i][0]表示第i篇日记内容，message[i][1]表示第一篇日记的关键字，message[i][2]表示第i篇日记的日期
    char password[15];
    char name[18];
    int total; //日记总篇数
} People;

void Change_Password(People pd[], int num); //修改密码
void Enter(People pd[], int num); //用户登录成功，选择页面
void Input_Diary(People pd[], int num); //写日记
void Insert(People pd[]); //已注册的用户及保存的信息
void Output(People pd[], int num, int j); //打印日记信息
void Save(People pd[]); //日记保存
void Search(People pd[], int num); //查询日记
void Search_Date_Keyword(People pd[], int num, int j); //按日期或关键字查找
void User_Login(People pd[]); //用户名登录
void User_Register(People pd[]); //新用户注册及登录
void User_Check(People pd[], int num);//新用户用户名检测
int Color();//修改程序颜色
void Date_Check(People pd[], int num, int i);//日期检测
void Input_DATE(People pd[], int num);//标日期
void Input_Keyword(People pd[], int num);//标关键字
void Game_Start();//游戏开始
void Question();//选项
void Question_Link();//测试与结果中间文案
void Login_link();//与登录界面链接

//修改密码，num为用户名前号码
void Change_Password(People pd[], int num)
{
    system("cls");
    int i;
    char p[10];
    printf("\n\t\t请输入你的新密码（不超过10位）：\n");
    scanf("%s", p);
    for (i = 0; i < 10; i++)
        pd[num - 1].password[i] = 3 * p[i] + 1;
    printf("\n\t\t密码修改成功！");
    system("pause");
    Save(pd);
    Enter(pd, num);
    return;
}

//用户登录成功，选择页面
void Enter(People pd[], int num)
{
    system("cls");
    char choose;
    int x;
    printf("\n\t\t\t请选择你想进行的操作\n");
    printf("\n\t\t\t===========================\n");
    printf("\n\t\t\t     1.写日记\n");
    printf("\t\t\t     2.查找日记\n");
    printf("\t\t\t     3.修改密码\n");
    printf("\t\t\t     4.返回登录页面\n");
    printf("\t\t\t     随意输入一个字母退出\n");
    printf("\n\t\t\t============================\n");
    getchar();
    choose = getchar();
    x = (int)choose - 48;
    if (x == 1)
    {
        Input_Diary(pd, num);
        return;
    } //写日记
    else if (x == 2)
    {
        Search(pd, num);
        return;
    } //查询日记
    else if (x == 3)
    {
        Change_Password(pd, num);
        return;
    } //修改密码
    else if (x == 4)
    {
        User_Login(pd);
        return;
    }
    return;
}

//写日记
void Input_Diary(People pd[], int num)
{
    int i;
    i = pd[num - 1].total;
    printf("\t\t请输入日记内容：\n");
    scanf("%s", pd[num - 1].message[i][0]);
    Input_Keyword(pd, num);
    Input_DATE(pd, num);
    return;
}

//标关键字
void Input_Keyword(People pd[], int num)
{
    int i;
    i = pd[num - 1].total;
    printf("\t\t请输入日记记录关键字：\n");
    scanf("%s", pd[num - 1].message[i][1]);
}

//标日期
void Input_DATE(People pd[], int num)
{
    int i;
    i = pd[num - 1].total;
    printf("\t\t请输入日记记录日期（格式为20000101）：\n");
    scanf("%s", pd[num - 1].message[i][2]);
    Date_Check(pd, num, i);
    if (z == 1)
    {
        pd[num - 1].total++;
        printf("你已经写了%d篇日记", pd[num - 1].total);
        Save(pd); //保存日记
        system("pause");
        Enter(pd, num); //返回初始界面
        return;
    }
    if (z == 0)
    {
        Input_DATE(pd, num);
    }
}

//已注册的用户及保存的信息
void Insert(People pd[])
{
    int i, j;
    char p[10];
    for (i = 0; i < NUM; i++)
        if (i == 0) //第一个用户的信息
        {
            strcpy(pd[i].name, "小张");
            strcpy(p, "1234567890");
            for (j = 0; j < 10; j++) //密码加密
            {
                p[j] = 3 * p[j] + 1;
            }
            strcpy(pd[i].password, p);
            pd[i].total = 3;
            for (j = 0; j < 3; j++) //3篇日记具体内容
            {
                if (j == 0)
                {
                    strcpy(pd[i].message[0][0], "快考试了");
                    strcpy(pd[i].message[0][1], "考试");
                    strcpy(pd[i].message[0][2], "20200606");
                }
                else if (j == 1)
                {
                    strcpy(pd[i].message[1][0], "快开学了");
                    strcpy(pd[i].message[1][1], "开学");
                    strcpy(pd[i].message[1][2], "20200706");
                }
                else if (j == 2)
                {
                    strcpy(pd[i].message[2][0], "快搬寝了");
                    strcpy(pd[i].message[2][1], "搬寝");
                    strcpy(pd[i].message[2][2], "20200806");
                }
            }
        }
        else if (i == 1)
        {
            strcpy(pd[i].name, "小王");
            strcpy(p, "0987654321");
            for (j = 0; j < 10; j++)
            {
                p[j] = 3 * p[j] + 1;
            }
            strcpy(pd[i].password, p);
            pd[i].total = 1;
            strcpy(pd[i].message[0][0], "快开课了");
            strcpy(pd[i].message[0][1], "开课");
            strcpy(pd[i].message[0][2], "20200906");
        }
    return;
}

//打印日记信息
void Output(People pd[], int num, int j)
{
    FILE* fp;
    fp = fopen("My_diary.txt", "r");
    printf("\n\t\t============================\n");
    printf("\n\t\t该日记的内容为：%s\n", pd[num - 1].message[j][0]);
    printf("\n\t\t发表于：%s\n", pd[num - 1].message[j][2]);
    fclose(fp);
}

//日记保存
void Save(People pd[])
{
    FILE* fp;
    int i;
    if ((fp = fopen("My_diary.txt", "w")) == NULL)
    {
        printf("cannot open file\n");
        return;
    }
    for (i = 0; i < NUM; i++)
    {
        if (fwrite(&pd[i], sizeof(People), 1, fp) != 1)
            printf("file write error\n");
    }
    fclose(fp);
}

//查询日记
void Search(People pd[], int num)
{
    system("cls");
    int i;
    char choose;
    printf("\n\t\t\t请选择你想进行的操作\n");
    printf("\n\t\t\t===========================\n");
    printf("\n\t\t\t     1.按日期查看\n");
    printf("\t\t\t     2.按关键字查看\n");
    printf("\t\t\t     3.按顺序查看\n");
    printf("\t\t\t     4.返回上一页面\n");
    printf("\t\t\t     随意输入一个字母退出\n");
    printf("\n\t\t\t============================\n");
    getchar();
    choose = getchar();
    if (choose == '1') //按日期查看
    {
        Search_Date_Keyword(pd, num, 1);
        return;
    }
    else if (choose == '2') //按关键字查看
    {
        Search_Date_Keyword(pd, num, 2);
        return;
    }
    else if (choose == '3') //按顺序查看
    {
        for (i = 0; i <= pd[num - 1].total; i++)
            Output(pd, num, i);
        printf("\n\t\t\t============================\n");
        system("pause");
        Enter(pd, num);
        return;
    }
    else if (choose == '4')
    {
        Enter(pd, num);
        return;
    }
    return;
}

//按日期或关键字查找
void Search_Date_Keyword(People pd[], int num, int j)
{
    char words[PASSAGEMAX]; //输入的查询内容
    int i, k;
    int flag;
    if (j == 1)
    {
        printf("\t\t请输入你要查询的日记记录日期（格式为20000101）：\n");
        flag = 1;
    }
    else if (j == 2)
    {
        printf("\t\t请输入你要查询的关键字：\n");
        flag = -1;
    }
    scanf("%s", words);
    for (i = 0; i < pd[num - 1].total; i++)
        if (strcmp(words, pd[num - 1].message[i][j + flag]) == 0)
        {
            Output(pd, num, i);
            flag = 0;
        }
    if (i >= pd[num - 1].total && flag != 0)
    {
        printf("\n\t\t该日记不存在");
        system("pause");
        Enter(pd, num);
        return;
    }
    system("pause");
    Enter(pd, num);
    return;
}

//用户名登录
void User_Login(People pd[])
{
    getchar();
    char p[10], q[10];
    int i, j, times, num;
    char choose;
    times = 3; //用户可输错密码次数
    system("cls");
    printf("\n\t\t\t============================\n");
    printf("\n\t\t\t     用户名\n");
    for (i = 0; i < NUM; i++)
        printf("\n\t\t\t     %d.%s\n", i + 1, pd[i].name);
    printf("\n\t\t\t     %d.注册\n", i + 1);
    printf("\n\t\t\t请选择你的用户名序号，未注册请先注册\n");
    choose = getchar();
    num = (int)choose - 48; //用户序号
    system("cls");
    if (num == i + 1)
    {
        User_Register(pd);
        system("cls");
        return;
    }
    else
    {
        if (num >= 1 && num <= NUM)
        {
            while (times > 0)
            {
                printf("\n\t\t\t     密码：\n");
                scanf("%s", p);
                int templen = strlen(p);
                for (i = 0; i < templen; i++)
                {
                    p[i] = 3 * p[i] + 1;
                }
                if (strcmp(p, pd[num - 1].password) == 0)
                {
                    printf("\n\t\t\t============================\n");
                    Enter(pd, num);
                    return;
                }
                else
                {
                    if (times != 1)
                    {
                        printf("\n\t\t对不起，密码错误！~\n");
                        times--;
                        printf("\n\t\t你还有%d个机会！\n", times);
                    }
                    else
                    {
                        printf("\n\t\t\t你已经连续三次输入错误密码，系统将直接退出.\n");
                        printf("\n\t\t\t============================\n");
                        return;
                    }
                }
            }
        }
        else
        {
            printf("程序出错 不存在此用户 访问越界\n");
        }
    }
    system("cls");
    system("pause");
    return;
}

//用户注册及新用户登陆
void User_Register(People pd[])
{
    int i;
    int num;
    char choose;    //新用户是否登陆
    char q[10];
    printf("\n\t\t\t请设定登陆的用户名：\n");
    scanf("%s", pd[NUM].name);
    User_Check(pd, NUM);
    printf("\n\t\t\t请设定登录密码（不超过10位）：\n");
    scanf("%s", q);
    for (i = 0; i < 10; i++)
        pd[NUM].password[i] = 3 * q[i] + 1;
    printf("\n\t\t恭喜你，注册成功！\n");
    NUM++;        //用户人数加一
    printf("\t\t\t是否现在写日志？是请按“Y”，按其他键退出\n");
    getchar();
    choose = getchar();
    if (choose == 'Y')
    {
        Input_Diary(pd, NUM);       //写日记
        Save(pd);
        return;
    }
}

People user[SIZE];

int jiance()//检测用户信息
{
    for (int i = 0; i < NUM; i++)
    {
        printf("%s %s\n", user[i].name, user[i].password);
        for (int k = 0; k < user[i].total; k++)
        {
            for (int j = 0; j < 3; j++)
            {
                printf("%s ", user[i].message[k][j]);
            }
            printf("\n");
        }
    }
    return 0;
}

//改变日记本背景与颜色
int Color()
{
    system("color f3");
    return 0;
}

//新用户用户名检测
void User_Check(People pd[], int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        if (strcmp(pd[num].name, pd[i].name) == 0)
        {
            printf("用户名重复，请重新填写");
            scanf("%s", pd[num].name);
            system("cls");
        }
        else
            break;

    }
}

//日期检测
void Date_Check(People pd[], int num, int i)
{
    if (strlen(pd[num - 1].message[i][2]) != 8) {
        printf("该日期格式不正确\n");
        z = 0;
    }

    else
        z = 1;
}

//游戏开始
void Game_Start()
{
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t欢迎使用日记本系统\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t日记记录的不只是生活\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t还有我们每个人独一无二的\t\n");
    printf("\n\t\t\t\t内心世界\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t那么，接下来\t\t\t\t\n");
    printf("\n\t\t\t\t就让我们用几个小测试\t\t\n");
    printf("\n\t\t\t\t打开我们的心灵世界吧\t\t\n");
    printf("\n\t\t\t**********************************\n");

    getchar();
    system("pause");

    Question();
    return;
}


//选择
void Question()
{
    char choose[5],one[1],two[1],three[1],four[1];
    int i;
    system("cls");
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t测试一\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\t双手交握之时\t\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\tA:右手大拇指在上\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\tB:左手大拇指在上\t\t\t\t\t\t\t\n\n");
    printf("\n\t\t\t\t请做出你的选择：\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    scanf("%s", one);
    strcat(choose,one);
    getchar();
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t测试二\t\t\t\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\t用一只眼睛瞄准看不清的东西时\t\t\n");
    printf("\n\t\t\t\tA:用右眼\t\t\t\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t\tB:用左眼\t\t\t\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\t请做出你的选择：\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    scanf("%s", two);
    strcat(choose, two);
    getchar();
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t测试三\t\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\t双臂交叉抱胸时\t\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\tA:右手臂搭在上面\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\tB:左手臂搭在上面\t\t\t\t\t\t\t\t\n\n");
    printf("\n\t\t\t\t请做出你的选择：\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    scanf("%s", three);
    strcat(choose, three);
    getchar();
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t测试四\t\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\t鼓掌的时候\t\t\t\t\t\t\t\t\t\t\t");
    printf("\n\t\t\t\tA:右手拍左手\t\t\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\tB:左手拍右手\t\t\t\t\t\t\t\t\t\t\n\n");
    printf("\n\t\t\t\t请做出你的选择：\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    scanf("%s", four);
    strcat(choose, four);
    getchar();
    system("pause");
    system("cls");

    Question_Link();//测试与结果中间文案

    if (strcmp(choose, "AAAAA") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t你是右撇子，");
        printf("\n\t\t\t\t思想比较保守，");
        printf("\n\t\t\t\t性情平和，");
        printf("\n\t\t\t\t不喜欢与人争执。\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "AAAAB") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t你是右撇子，");
        printf("\n\t\t\t\t思想比较保守，");
        printf("\n\t\t\t\t性情平和，");
        printf("\n\t\t\t\t不喜欢与人争执。\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "AAABA") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t你是一个平易近人的人，");
        printf("\n\t\t\t\t风情万种，");
        printf("\n\t\t\t\t行事果断，");
        printf("\n\t\t\t\t富有幽默感，");
        printf("\n\t\t\t\t具有艺术天赋（通常指女性）。\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "AAABB") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t少见的组合。");
        printf("\n\t\t\t\t风情万种，");
        printf("\n\t\t\t\t行事果断，");
        printf("\n\t\t\t\t富有幽默感，");
        printf("\n\t\t\t\t十分温柔，");
        printf("\n\t\t\t\t具有艺术天赋（通常指女性）。\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "AABAA") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t你性格温和，");
        printf("\n\t\t\t\t头脑聪明，");
        printf("\n\t\t\t\t善于分析，");
        printf("\n\t\t\t\t适应力差，");
        printf("\n\t\t\t\t在人际交往时小心翼翼，");
        printf("\n\t\t\t\t性情宽容，");
        printf("\n\t\t\t\t略有些冷淡（通常指女性）。\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "AABAB") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t最罕见的组合。");
        printf("\n\t\t\t\t你缺乏安全感，");
        printf("\n\t\t\t\t对外界刺激很敏感（通常指女性）。\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "AABBA") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t你是一个洒脱的人，");
        printf("\n\t\t\t\t能轻松与人交往，");
        printf("\n\t\t\t\t避免与人冲突，");
        printf("\n\t\t\t\t交游甚广，");
        printf("\n\t\t\t\t兴趣常常变化。\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "AABBB") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t你是一个独立的人，");
        printf("\n\t\t\t\t什么事都要自己动手。\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "BBAAA") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t常见的组合。");
        printf("\n\t\t\t\t你是一个情感丰富的人，");
        printf("\n\t\t\t\t但是在决定重大问题时不够坚定顽强，");
        printf("\n\t\t\t\t容易受到干扰，");
        printf("\n\t\t\t\t适应力强，");
        printf("\n\t\t\t\t待人友好，");
        printf("\n\t\t\t\t能轻松与人交流。\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "BBAAB") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t你是一个性情温和、");
        printf("\n\t\t\t\t天真纯洁的人。\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "BBBAA") == 0)
    {
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t你是一个性格质朴的人，");
    printf("\n\t\t\t\t待人友好，");
    printf("\n\t\t\t\t喜欢自我反省。\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    }

    else if (strcmp(choose, "BBBAB") == 0)
    {
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t你心性质朴，");
    printf("\n\t\t\t\t性格温柔，");
    printf("\n\t\t\t\t容易轻信他人。\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    }

    else if (strcmp(choose, "BBBBA") == 0)
    {
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t你是一个情感丰富、");
    printf("\n\t\t\t\t充满活力、");
    printf("\n\t\t\t\t处事果断的人。\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    }

    else if (strcmp(choose, "BBBBB") == 0)
    {
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t你是左撇子，");
    printf("\n\t\t\t\t性格自由不羁。");
    printf("\n\t\t\t\t你能够用新观点看待旧问题，");
    printf("\n\t\t\t\t个人主义，");
    printf("\n\t\t\t\t自我中心，");
    printf("\n\t\t\t\t固执，");
    printf("\n\t\t\t\t有时甚至一意孤行。\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    }

    else if (strcmp(choose, "BBABA") == 0)
    {
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t最强势的性格。");
    printf("\n\t\t\t\t你难以改变自己的观点，");
    printf("\n\t\t\t\t充满活力，");
    printf("\n\t\t\t\t能朝预定目标坚持不懈地努力 。\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    }

    else if (strcmp(choose, "BBABB") == 0)
    {
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t你难以改变自己的观点，");
    printf("\n\t\t\t\t充满活力，");
    printf("\n\t\t\t\t能朝预定目标坚持不懈地努力 。");
    printf("\n\t\t\t\t但不那么固执，");
    printf("\n\t\t\t\t你会在别人的影响下反省自己，");
    printf("\n\t\t\t\t要花费一番工夫才能交到朋友。\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    }

    Login_link();
}

//测试与结果中间文案
void Question_Link()
{
    system("cls");
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t恭喜你，已完成测试\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t我们放眼世界\t\t\n");
    printf("\n\t\t\t\t也要了解自己\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t日记不只是记录生活\n");
    printf("\n\t\t\t\t更是与自己对话的最佳方式\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t那么，接下来\t\t\t\t\n");
    printf("\n\t\t\t\t让我们揭晓答案吧！\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");
}

//与登录界面链接
void Login_link()
{
    system("cls");
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t通过这些答案\t\t\n");
    printf("\n\t\t\t\t相信你对自己有了更深的了解\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t然而\t\t\n");
    printf("\n\t\t\t\t世人的形象不能以16种一概论之\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t正如我们的形象\n");
    printf("\n\t\t\t\t不会拘于任何一个答案\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t而日记的记录\n");
    printf("\n\t\t\t\t是我们认清自己的方式\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t所以\t\t\t\t\n");
    printf("\n\t\t\t\t欢迎，new user\t\t\n");
    printf("\n\t\t\t\t请开启你的心灵之路\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    User_Login(user);//用户登录
    getchar();
}

int main()
{
    Color();
    Insert(user);           //初始化日记管理系统里的用户信息
//  jiance();
//	Save(user);             //保存用户信息
    Game_Start();           //游戏开始
    //User_Login(user);      //用户登录
    system("pause");
    return 0;
}