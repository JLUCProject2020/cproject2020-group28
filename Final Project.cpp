#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PAGEMAX 100 //�ռ���ƪ�����ֵ
#define PASSAGEMAX 500 //�ռ��������ֵ
#define SIZE 20 //���ע������

int NUM = 2;//�Ѵ���ע����
int z;//���ڼ�����

typedef struct
{
    char message[PAGEMAX][3][PASSAGEMAX]; //�ռ���Ϣ��massage[i][0]��ʾ��iƪ�ռ����ݣ�message[i][1]��ʾ��һƪ�ռǵĹؼ��֣�message[i][2]��ʾ��iƪ�ռǵ�����
    char password[15];
    char name[18];
    int total; //�ռ���ƪ��
} People;

void Change_Password(People pd[], int num); //�޸�����
void Enter(People pd[], int num); //�û���¼�ɹ���ѡ��ҳ��
void Input_Diary(People pd[], int num); //д�ռ�
void Insert(People pd[]); //��ע����û����������Ϣ
void Output(People pd[], int num, int j); //��ӡ�ռ���Ϣ
void Save(People pd[]); //�ռǱ���
void Search(People pd[], int num); //��ѯ�ռ�
void Search_Date_Keyword(People pd[], int num, int j); //�����ڻ�ؼ��ֲ���
void User_Login(People pd[]); //�û�����¼
void User_Register(People pd[]); //���û�ע�ἰ��¼
void User_Check(People pd[], int num);//���û��û������
int Color();//�޸ĳ�����ɫ
void Date_Check(People pd[], int num, int i);//���ڼ��
void Input_DATE(People pd[], int num);//������
void Input_Keyword(People pd[], int num);//��ؼ���
void Game_Start();//��Ϸ��ʼ
void Question();//ѡ��
void Question_Link();//���������м��İ�
void Login_link();//���¼��������

//�޸����룬numΪ�û���ǰ����
void Change_Password(People pd[], int num)
{
    system("cls");
    int i;
    char p[10];
    printf("\n\t\t��������������루������10λ����\n");
    scanf("%s", p);
    for (i = 0; i < 10; i++)
        pd[num - 1].password[i] = 3 * p[i] + 1;
    printf("\n\t\t�����޸ĳɹ���");
    system("pause");
    Save(pd);
    Enter(pd, num);
    return;
}

//�û���¼�ɹ���ѡ��ҳ��
void Enter(People pd[], int num)
{
    system("cls");
    char choose;
    int x;
    printf("\n\t\t\t��ѡ��������еĲ���\n");
    printf("\n\t\t\t===========================\n");
    printf("\n\t\t\t     1.д�ռ�\n");
    printf("\t\t\t     2.�����ռ�\n");
    printf("\t\t\t     3.�޸�����\n");
    printf("\t\t\t     4.���ص�¼ҳ��\n");
    printf("\t\t\t     ��������һ����ĸ�˳�\n");
    printf("\n\t\t\t============================\n");
    getchar();
    choose = getchar();
    x = (int)choose - 48;
    if (x == 1)
    {
        Input_Diary(pd, num);
        return;
    } //д�ռ�
    else if (x == 2)
    {
        Search(pd, num);
        return;
    } //��ѯ�ռ�
    else if (x == 3)
    {
        Change_Password(pd, num);
        return;
    } //�޸�����
    else if (x == 4)
    {
        User_Login(pd);
        return;
    }
    return;
}

//д�ռ�
void Input_Diary(People pd[], int num)
{
    int i;
    i = pd[num - 1].total;
    printf("\t\t�������ռ����ݣ�\n");
    scanf("%s", pd[num - 1].message[i][0]);
    Input_Keyword(pd, num);
    Input_DATE(pd, num);
    return;
}

//��ؼ���
void Input_Keyword(People pd[], int num)
{
    int i;
    i = pd[num - 1].total;
    printf("\t\t�������ռǼ�¼�ؼ��֣�\n");
    scanf("%s", pd[num - 1].message[i][1]);
}

//������
void Input_DATE(People pd[], int num)
{
    int i;
    i = pd[num - 1].total;
    printf("\t\t�������ռǼ�¼���ڣ���ʽΪ20000101����\n");
    scanf("%s", pd[num - 1].message[i][2]);
    Date_Check(pd, num, i);
    if (z == 1)
    {
        pd[num - 1].total++;
        printf("���Ѿ�д��%dƪ�ռ�", pd[num - 1].total);
        Save(pd); //�����ռ�
        system("pause");
        Enter(pd, num); //���س�ʼ����
        return;
    }
    if (z == 0)
    {
        Input_DATE(pd, num);
    }
}

//��ע����û����������Ϣ
void Insert(People pd[])
{
    int i, j;
    char p[10];
    for (i = 0; i < NUM; i++)
        if (i == 0) //��һ���û�����Ϣ
        {
            strcpy(pd[i].name, "С��");
            strcpy(p, "1234567890");
            for (j = 0; j < 10; j++) //�������
            {
                p[j] = 3 * p[j] + 1;
            }
            strcpy(pd[i].password, p);
            pd[i].total = 3;
            for (j = 0; j < 3; j++) //3ƪ�ռǾ�������
            {
                if (j == 0)
                {
                    strcpy(pd[i].message[0][0], "�쿼����");
                    strcpy(pd[i].message[0][1], "����");
                    strcpy(pd[i].message[0][2], "20200606");
                }
                else if (j == 1)
                {
                    strcpy(pd[i].message[1][0], "�쿪ѧ��");
                    strcpy(pd[i].message[1][1], "��ѧ");
                    strcpy(pd[i].message[1][2], "20200706");
                }
                else if (j == 2)
                {
                    strcpy(pd[i].message[2][0], "�������");
                    strcpy(pd[i].message[2][1], "����");
                    strcpy(pd[i].message[2][2], "20200806");
                }
            }
        }
        else if (i == 1)
        {
            strcpy(pd[i].name, "С��");
            strcpy(p, "0987654321");
            for (j = 0; j < 10; j++)
            {
                p[j] = 3 * p[j] + 1;
            }
            strcpy(pd[i].password, p);
            pd[i].total = 1;
            strcpy(pd[i].message[0][0], "�쿪����");
            strcpy(pd[i].message[0][1], "����");
            strcpy(pd[i].message[0][2], "20200906");
        }
    return;
}

//��ӡ�ռ���Ϣ
void Output(People pd[], int num, int j)
{
    FILE* fp;
    fp = fopen("My_diary.txt", "r");
    printf("\n\t\t============================\n");
    printf("\n\t\t���ռǵ�����Ϊ��%s\n", pd[num - 1].message[j][0]);
    printf("\n\t\t�����ڣ�%s\n", pd[num - 1].message[j][2]);
    fclose(fp);
}

//�ռǱ���
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

//��ѯ�ռ�
void Search(People pd[], int num)
{
    system("cls");
    int i;
    char choose;
    printf("\n\t\t\t��ѡ��������еĲ���\n");
    printf("\n\t\t\t===========================\n");
    printf("\n\t\t\t     1.�����ڲ鿴\n");
    printf("\t\t\t     2.���ؼ��ֲ鿴\n");
    printf("\t\t\t     3.��˳��鿴\n");
    printf("\t\t\t     4.������һҳ��\n");
    printf("\t\t\t     ��������һ����ĸ�˳�\n");
    printf("\n\t\t\t============================\n");
    getchar();
    choose = getchar();
    if (choose == '1') //�����ڲ鿴
    {
        Search_Date_Keyword(pd, num, 1);
        return;
    }
    else if (choose == '2') //���ؼ��ֲ鿴
    {
        Search_Date_Keyword(pd, num, 2);
        return;
    }
    else if (choose == '3') //��˳��鿴
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

//�����ڻ�ؼ��ֲ���
void Search_Date_Keyword(People pd[], int num, int j)
{
    char words[PASSAGEMAX]; //����Ĳ�ѯ����
    int i, k;
    int flag;
    if (j == 1)
    {
        printf("\t\t��������Ҫ��ѯ���ռǼ�¼���ڣ���ʽΪ20000101����\n");
        flag = 1;
    }
    else if (j == 2)
    {
        printf("\t\t��������Ҫ��ѯ�Ĺؼ��֣�\n");
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
        printf("\n\t\t���ռǲ�����");
        system("pause");
        Enter(pd, num);
        return;
    }
    system("pause");
    Enter(pd, num);
    return;
}

//�û�����¼
void User_Login(People pd[])
{
    getchar();
    char p[10], q[10];
    int i, j, times, num;
    char choose;
    times = 3; //�û�������������
    system("cls");
    printf("\n\t\t\t============================\n");
    printf("\n\t\t\t     �û���\n");
    for (i = 0; i < NUM; i++)
        printf("\n\t\t\t     %d.%s\n", i + 1, pd[i].name);
    printf("\n\t\t\t     %d.ע��\n", i + 1);
    printf("\n\t\t\t��ѡ������û�����ţ�δע������ע��\n");
    choose = getchar();
    num = (int)choose - 48; //�û����
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
                printf("\n\t\t\t     ���룺\n");
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
                        printf("\n\t\t�Բ����������~\n");
                        times--;
                        printf("\n\t\t�㻹��%d�����ᣡ\n", times);
                    }
                    else
                    {
                        printf("\n\t\t\t���Ѿ�������������������룬ϵͳ��ֱ���˳�.\n");
                        printf("\n\t\t\t============================\n");
                        return;
                    }
                }
            }
        }
        else
        {
            printf("������� �����ڴ��û� ����Խ��\n");
        }
    }
    system("cls");
    system("pause");
    return;
}

//�û�ע�ἰ���û���½
void User_Register(People pd[])
{
    int i;
    int num;
    char choose;    //���û��Ƿ��½
    char q[10];
    printf("\n\t\t\t���趨��½���û�����\n");
    scanf("%s", pd[NUM].name);
    User_Check(pd, NUM);
    printf("\n\t\t\t���趨��¼���루������10λ����\n");
    scanf("%s", q);
    for (i = 0; i < 10; i++)
        pd[NUM].password[i] = 3 * q[i] + 1;
    printf("\n\t\t��ϲ�㣬ע��ɹ���\n");
    NUM++;        //�û�������һ
    printf("\t\t\t�Ƿ�����д��־�����밴��Y�������������˳�\n");
    getchar();
    choose = getchar();
    if (choose == 'Y')
    {
        Input_Diary(pd, NUM);       //д�ռ�
        Save(pd);
        return;
    }
}

People user[SIZE];

int jiance()//����û���Ϣ
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

//�ı��ռǱ���������ɫ
int Color()
{
    system("color f3");
    return 0;
}

//���û��û������
void User_Check(People pd[], int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        if (strcmp(pd[num].name, pd[i].name) == 0)
        {
            printf("�û����ظ�����������д");
            scanf("%s", pd[num].name);
            system("cls");
        }
        else
            break;

    }
}

//���ڼ��
void Date_Check(People pd[], int num, int i)
{
    if (strlen(pd[num - 1].message[i][2]) != 8) {
        printf("�����ڸ�ʽ����ȷ\n");
        z = 0;
    }

    else
        z = 1;
}

//��Ϸ��ʼ
void Game_Start()
{
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t��ӭʹ���ռǱ�ϵͳ\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t�ռǼ�¼�Ĳ�ֻ������\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t��������ÿ���˶�һ�޶���\t\n");
    printf("\n\t\t\t\t��������\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t��ô��������\t\t\t\t\n");
    printf("\n\t\t\t\t���������ü���С����\t\t\n");
    printf("\n\t\t\t\t�����ǵ����������\t\t\n");
    printf("\n\t\t\t**********************************\n");

    getchar();
    system("pause");

    Question();
    return;
}


//ѡ��
void Question()
{
    char choose[5],one[1],two[1],three[1],four[1];
    int i;
    system("cls");
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t����һ\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\t˫�ֽ���֮ʱ\t\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\tA:���ִ�Ĵָ����\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\tB:���ִ�Ĵָ����\t\t\t\t\t\t\t\n\n");
    printf("\n\t\t\t\t���������ѡ��\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    scanf("%s", one);
    strcat(choose,one);
    getchar();
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t���Զ�\t\t\t\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\t��һֻ�۾���׼������Ķ���ʱ\t\t\n");
    printf("\n\t\t\t\tA:������\t\t\t\t\t\t\t\t\t\t\t\n");
    printf("\t\t\t\tB:������\t\t\t\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\t���������ѡ��\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    scanf("%s", two);
    strcat(choose, two);
    getchar();
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t������\t\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\t˫�۽��汧��ʱ\t\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\tA:���ֱ۴�������\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\tB:���ֱ۴�������\t\t\t\t\t\t\t\t\n\n");
    printf("\n\t\t\t\t���������ѡ��\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    scanf("%s", three);
    strcat(choose, three);
    getchar();
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t������\t\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\t���Ƶ�ʱ��\t\t\t\t\t\t\t\t\t\t\t");
    printf("\n\t\t\t\tA:����������\t\t\t\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t\tB:����������\t\t\t\t\t\t\t\t\t\t\n\n");
    printf("\n\t\t\t\t���������ѡ��\t\t\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    scanf("%s", four);
    strcat(choose, four);
    getchar();
    system("pause");
    system("cls");

    Question_Link();//���������м��İ�

    if (strcmp(choose, "AAAAA") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t������Ʋ�ӣ�");
        printf("\n\t\t\t\t˼��Ƚϱ��أ�");
        printf("\n\t\t\t\t����ƽ�ͣ�");
        printf("\n\t\t\t\t��ϲ��������ִ��\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "AAAAB") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t������Ʋ�ӣ�");
        printf("\n\t\t\t\t˼��Ƚϱ��أ�");
        printf("\n\t\t\t\t����ƽ�ͣ�");
        printf("\n\t\t\t\t��ϲ��������ִ��\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "AAABA") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t����һ��ƽ�׽��˵��ˣ�");
        printf("\n\t\t\t\t�������֣�");
        printf("\n\t\t\t\t���¹��ϣ�");
        printf("\n\t\t\t\t������Ĭ�У�");
        printf("\n\t\t\t\t���������츳��ͨ��ָŮ�ԣ���\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "AAABB") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t�ټ�����ϡ�");
        printf("\n\t\t\t\t�������֣�");
        printf("\n\t\t\t\t���¹��ϣ�");
        printf("\n\t\t\t\t������Ĭ�У�");
        printf("\n\t\t\t\tʮ�����ᣬ");
        printf("\n\t\t\t\t���������츳��ͨ��ָŮ�ԣ���\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "AABAA") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t���Ը��ºͣ�");
        printf("\n\t\t\t\tͷ�Դ�����");
        printf("\n\t\t\t\t���ڷ�����");
        printf("\n\t\t\t\t��Ӧ���");
        printf("\n\t\t\t\t���˼ʽ���ʱС������");
        printf("\n\t\t\t\t������ݣ�");
        printf("\n\t\t\t\t����Щ�䵭��ͨ��ָŮ�ԣ���\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "AABAB") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t�������ϡ�");
        printf("\n\t\t\t\t��ȱ����ȫ�У�");
        printf("\n\t\t\t\t�����̼������У�ͨ��ָŮ�ԣ���\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "AABBA") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t����һ�����ѵ��ˣ�");
        printf("\n\t\t\t\t���������˽�����");
        printf("\n\t\t\t\t�������˳�ͻ��");
        printf("\n\t\t\t\t�������㣬");
        printf("\n\t\t\t\t��Ȥ�����仯��\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "AABBB") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t����һ���������ˣ�");
        printf("\n\t\t\t\tʲô�¶�Ҫ�Լ����֡�\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "BBAAA") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t��������ϡ�");
        printf("\n\t\t\t\t����һ����зḻ���ˣ�");
        printf("\n\t\t\t\t�����ھ����ش�����ʱ�����ᶨ��ǿ��");
        printf("\n\t\t\t\t�����ܵ����ţ�");
        printf("\n\t\t\t\t��Ӧ��ǿ��");
        printf("\n\t\t\t\t�����Ѻã�");
        printf("\n\t\t\t\t���������˽�����\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "BBAAB") == 0)
    {
        printf("\n\t\t\t**********************************\n");
        printf("\n\t\t\t\t����һ�������º͡�");
        printf("\n\t\t\t\t���洿����ˡ�\n");
        printf("\n\t\t\t**********************************\n");
        system("pause");
    }

    else if (strcmp(choose, "BBBAA") == 0)
    {
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t����һ���Ը����ӵ��ˣ�");
    printf("\n\t\t\t\t�����Ѻã�");
    printf("\n\t\t\t\tϲ�����ҷ�ʡ��\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    }

    else if (strcmp(choose, "BBBAB") == 0)
    {
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t���������ӣ�");
    printf("\n\t\t\t\t�Ը����ᣬ");
    printf("\n\t\t\t\t�����������ˡ�\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    }

    else if (strcmp(choose, "BBBBA") == 0)
    {
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t����һ����зḻ��");
    printf("\n\t\t\t\t����������");
    printf("\n\t\t\t\t���¹��ϵ��ˡ�\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    }

    else if (strcmp(choose, "BBBBB") == 0)
    {
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t������Ʋ�ӣ�");
    printf("\n\t\t\t\t�Ը����ɲ��");
    printf("\n\t\t\t\t���ܹ����¹۵㿴�������⣬");
    printf("\n\t\t\t\t�������壬");
    printf("\n\t\t\t\t�������ģ�");
    printf("\n\t\t\t\t��ִ��");
    printf("\n\t\t\t\t��ʱ����һ����С�\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    }

    else if (strcmp(choose, "BBABA") == 0)
    {
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t��ǿ�Ƶ��Ը�");
    printf("\n\t\t\t\t�����Ըı��Լ��Ĺ۵㣬");
    printf("\n\t\t\t\t����������");
    printf("\n\t\t\t\t�ܳ�Ԥ��Ŀ���ֲ�и��Ŭ�� ��\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    }

    else if (strcmp(choose, "BBABB") == 0)
    {
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t�����Ըı��Լ��Ĺ۵㣬");
    printf("\n\t\t\t\t����������");
    printf("\n\t\t\t\t�ܳ�Ԥ��Ŀ���ֲ�и��Ŭ�� ��");
    printf("\n\t\t\t\t������ô��ִ��");
    printf("\n\t\t\t\t����ڱ��˵�Ӱ���·�ʡ�Լ���");
    printf("\n\t\t\t\tҪ����һ��������ܽ������ѡ�\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    }

    Login_link();
}

//���������м��İ�
void Question_Link()
{
    system("cls");
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t��ϲ�㣬����ɲ���\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t���Ƿ�������\t\t\n");
    printf("\n\t\t\t\tҲҪ�˽��Լ�\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t�ռǲ�ֻ�Ǽ�¼����\n");
    printf("\n\t\t\t\t�������Լ��Ի�����ѷ�ʽ\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t��ô��������\t\t\t\t\n");
    printf("\n\t\t\t\t�����ǽ����𰸰ɣ�\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");
}

//���¼��������
void Login_link()
{
    system("cls");
    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\tͨ����Щ��\t\t\n");
    printf("\n\t\t\t\t��������Լ����˸�����˽�\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\tȻ��\t\t\n");
    printf("\n\t\t\t\t���˵���������16��һ����֮\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t�������ǵ�����\n");
    printf("\n\t\t\t\t��������κ�һ����\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t���ռǵļ�¼\n");
    printf("\n\t\t\t\t�����������Լ��ķ�ʽ\t\t\t\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    printf("\n\t\t\t**********************************\n");
    printf("\n\t\t\t\t����\t\t\t\t\n");
    printf("\n\t\t\t\t��ӭ��new user\t\t\n");
    printf("\n\t\t\t\t�뿪���������֮·\t\t\n");
    printf("\n\t\t\t**********************************\n");
    system("pause");
    system("cls");

    User_Login(user);//�û���¼
    getchar();
}

int main()
{
    Color();
    Insert(user);           //��ʼ���ռǹ���ϵͳ����û���Ϣ
//  jiance();
//	Save(user);             //�����û���Ϣ
    Game_Start();           //��Ϸ��ʼ
    //User_Login(user);      //�û���¼
    system("pause");
    return 0;
}