#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
int action,escape_check,fight_action,defend_checker,position = 1;
FILE *mon_data,*drop_data,*full_story;
char s[100];

void space(char str[100],int len);
void status();
void equip(int a,int b);
void hp_cap();
void item_drop();
int get_drop(int a);
int win();
void merchant();
void nothing();
float delay(float num_of_second);
void fullstory_v2();
int warp(int a);
int dice();
int casino();
int RPS();
int dead();
int attack();
int defend();
int use_item();
int fight();
void found();
int select_map(int position);
int escape();
void ending();
int intro();

struct player {
    char name[100];
    int max_hp,hp,atk,gold;
    int item[5];
};
struct player tester = { "test",200,200,15,200,{2,2,1,0,0}};
struct monster {
    char name[50];
    int max_hp,hp,atk,drop;
    char skill[100],item[100];
    int drop_hp,drop_atk;
};
struct item {
    char item_name[100];
    int gold,item_hp,item_atk;
};
struct monster mon = {"name",0,0,0,0,"skill","item"};
struct item drop = {"drop",0,0,0};
void space(char str[100],int len) {
    for(int i=0; i<len; i++) {
        if(str[i]=='_')
            str[i]= ' ' ;
        if(str[i]=='-')
            str[i]= '\'' ;
    }
}
void print_slime() {
    printf("\n");
    /*32*/ printf("\t                  ####################\n");
    /*31*/ printf("\t                ##--------------------##\n");
    /*30*/ printf("\t            #####----------------------#####\n");
    /*27*/ printf("\t          ##--------------------------------##\n");
    /*28*/ printf("\t          ##------II----------------II------##\n");
    /*19*/ printf("\t        ##----------I--------------I----------##\n");
    /*19*/ printf("\t        ##-----------I------------I-----------##\n");
    /*19*/ printf("\t      ##---------------------------------------##\n");
    /*19*/ printf("\t      ##----------------------------------------##\n");
    /*22*/ printf("\t      ##----------------------------------------##\n");
    /*23*/ printf("\t      ##----------------------------------------##\n");
    /*32*/ printf("\t       ##########################################\n");
}
void print_goblin() {

    printf("\n");
    /*31*/ printf("\t                [][][][]\n");
    /*31*/ printf("\t              [][][][][][][]\n");
    /*31*/ printf("\t           [][][][][][]   [][]\n");
    /*30*/ printf("\t         [][][][][][][]  \n");
    /*27*/ printf("\t        [][][][][][][][][]\n");
    /*28*/ printf("\t      [][][][][][][][][][][]\n");
    /*19*/ printf("\t    [][]__[][][][][]__[][][][]\n");
    /*19*/ printf("\t  [][][|__|][][][][|__|][][][]\n");
    /*19*/ printf("\t     [][|[][][][][][][][][]\n");
    /*22*/ printf("\t      [][][]________[][][]\n");
    /*23*/ printf("\t      [][][]________[][][]\n");
    /*19*/ printf("\t       [][][][][][][][][]\n");
    /*24*/ printf("\t        [][][][][][][][]\n");
    /*26*/ printf("\t            [][][][]\n");
    /*27*/ printf("\t          [][][][][][]\n");
    /*28*/ printf("\t        [][][][][][][][]\n");
    /*30*/ printf("\t        [][][][][][][][]\n");
    /*30*/ printf("\t          [][][][][][]\n");
    /*30*/ printf("\t          [][][][][][]\n");
    /*30*/ printf("\t          [][]    [][]\n");


}
void print_orge() {
    printf("\n");
    /*31*/ printf("\t                #######\n");
    /*31*/ printf("\t               #       #\n");
    /*31*/ printf("\t          #   #         #   #\n");
    /*30*/ printf("\t          #####  __  __  #####\n");
    /*27*/ printf("\t           ##    []  []    ##\n");
    /*28*/ printf("\t             #      V     #\n");
    /*19*/ printf("\t               #   ___  #\n");
    /*19*/ printf("\t              ## ##  ## ##\n");
    /*19*/ printf("\t          ###### ###### ######\n");
    /*22*/ printf("\t         ##                  ##\n");
    /*23*/ printf("\t       ##    * *      *  *     ##\n");
    /*19*/ printf("\t       ##      #       #       ##\n");
    /*24*/ printf("\t         ##    ##       ##    ##\n");
    /*26*/ printf("\t       ##   ##             ##  ##\n");
    /*27*/ printf("\t      ##           ***          ##\n");
    /*28*/ printf("\t        #######################\n");
    /*30*/ printf("\t            #####      #####\n");
    /*30*/ printf("\t          ##    #      #    ##\n");
    /*30*/ printf("\t         #  *   #      #   *   #\n");
    /*30*/ printf("\t        #########      ##########\n");


}
void print_golem() {
    printf("\n");
    printf("\t                ########\n");
    printf("\t                #______#\n");
    printf("\t                #[]  []#\n");
    printf("\t                #  VV  #\n");
    printf("\t        ########################\n");
    printf("\t        ########################\n");
    printf("\t        ########################\n");
    printf("\t        ### ################ ###\n");
    printf("\t        ### ################ ###\n");
    printf("\t        ### ################ ###\n");
    printf("\t        ### ################ ###\n");
    printf("\t        ### ################ ###\n");
    printf("\t        ### ################ ###\n");
    printf("\t        ### ################ ###\n");
    printf("\t        ### ################ ###\n");
    printf("\t        ### #######  ####### ###\n");
    printf("\t        ### ######    ###### ###\n");
    printf("\t            ####        ####\n");
    printf("\t            ####        ####\n");
    printf("\t            ####        ####\n");
}
void print_spider() {

    printf("\n");
    /*31*/ printf("\t            /   /            \\  \\         \n");
    /*31*/ printf("\t          HH  HH              HH  HH       \n");
    /*31*/ printf("\t         HH  HH                 HH  HH         \n");
    /*30*/ printf("\t        HH  HH                   HH  HH       \n");
    /*27*/ printf("\t         HH  HH                 HH  HH        \n");
    /*28*/ printf("\t          HH  HH     *   *    HH  HH          \n");
    /*19*/ printf("\t            H   H     /-\\    H   H       \n");
    /*19*/ printf("\t              HHHHHHHHHHHHHHHHHHH       \n");
    /*19*/ printf("\t             H    |HHHHHHHH|    H              \n");
    /*22*/ printf("\t             H    |HHHHHHHH|    H           \n");
    /*23*/ printf("\t            H   |HHHHHHHHHHH|   H            \n");
    /*19*/ printf("\t           HH   H  |HHHHHH|  H   HH        \n");
    /*24*/ printf("\t          HH   HH   |HHHH|   HH   HH             \n");
    /*26*/ printf("\t       | HH   HH     |HH|     HH   HH |         \n");
    /*27*/ printf("\t        HH    HH     |__|     HH    HH              \n");
    /*28*/ printf("\t         HH   HH              HH   HH   \n");
    /*30*/ printf("\t           HH   HH           HH   HH              \n");
    /*30*/ printf("\t             HH   HH        HH   HH         \n");
    /*30*/ printf("\t               HH   HH     HH   HH          \n");
    /*30*/ printf("\t                 \\    \\   /    /            \n");


}
void print_assasin() {
    printf("\n");
    /*31*/ printf("\t                            []       \n");
    /*31*/ printf("\t                          [][][]              \n");
    /*31*/ printf("\t                        [][][][][]                                       // \n");
    /*30*/ printf("\t                      [][]__[]__[][]                                   []\n");
    /*27*/ printf("\t                   [][]   [][][]    [][]                             []\n");
    /*28*/ printf("\t                 []    \\\\[] [] []//    []                          []\n");
    /*19*/ printf("\t               [][][][] [][]  [][] [][][][]                     []\n");
    /*19*/ printf("\t             [][][][][]  [][][][]  [][][][][]        []       []\n");
    /*19*/ printf("\t           []   [][][][][][][][][][][][[]    []     [] []  []\n");
    /*22*/ printf("\t         []___________[][][][][][]____________[]         []\n");
    /*23*/ printf("\t        []              |[][][]|               []      []  []\n");
    /*19*/ printf("\t       []               |[][][]|                []  []    [][]\n");
    /*24*/ printf("\t      []               []______[]                [] \n");
    /*26*/ printf("\t     []               []        []            []  [] \n");
    /*27*/ printf("\t    []               []          []         []     []\n");
    /*28*/ printf("\t                     []          []                 []\n");
    /*30*/ printf("\t                     []          []            \n");
    /*30*/ printf("\t                     []          []           \n");
    /*30*/ printf("\t                     []          []            \n");
    /*30*/ printf("\t                     []          []        \n");



}
void print_dragon() {
    printf("\n");
    printf("\t           HHHHH     HHHHHHHHHHHHHHHHHH      \n");
    printf("\t    HHHHHH   HHH HHHHHHH              H       \n");
    printf("\t   HHHHHHHH    HHHH                  H          \n");
    printf("\t  HHHHHHHH   HHHHH                    H        \n");
    printf("\t  HH   HH HHHHHH                       H       \n");
    printf("\t  H      HHHHHH    HHHHHHHHHHHHHHHHHHH  H      \n");
    printf("\t    HH  HH  HH  HHHHH                HHH H    \n");
    printf("\t     HH     HHHHHH                     HH    \n");
    printf("\t      H HHHH   HHHHHH                    H   \n");
    printf("\t        HHHHHH  HHH                       H    \n");
    printf("\t   HH     HHHH    HHHHHHHHHHHHHHHHH        H    \n");
    printf("\t    HH HHH  HH    HHH             HHHH    H    \n");
    printf("\t     H HHHHH      HH                 HHH H     \n");
    printf("\t  H    HH HHHH    HHHHHHHHHHHHHH       HH    \n");
    printf("\t  HH   HH  HH   HH       HHHHHHHH        H    \n");
    printf("\t  HHH   H  H   HHH  HHHH       HHHH       H    \n");
    printf("\t   HH HHH    HHHH HHHHH HHHHH    HHH      H    \n");
    printf("\t  H H H HH   HHH       HH   HH     HH    H      \n");
    printf("\t  HH  H H  HHHH     HHH H H HHH     HHH H      \n");
    printf("\t   HH H HH        HHHHH HH HHHH        H     \n");
    printf("\t   H HH HH HHHH H      H HH HHH HHHH H       \n");
    printf("\t     HH  H  HHH HH    HHH HH HH HHHH HH      \n");
    printf("\t      HH HH  HH      HHH   HH   HHHH HHH     \n");
    printf("\t       HHH  HHH H   HHHHHHHHH                \n");
    printf("\t       HHHH  HH HH  HH    HHHH  HHHH H       \n");
    printf("\t       HHH  HHH HHH  H H        HHHH HH      \n");
    printf("\t        HHHH        HH HH H      HHH HHH     \n");
    printf("\t        HHHHH       HH  HH     HHH           \n");
    printf("\t                     HHH      HHHHHH H       \n");
    printf("\t                               HHHH  HH      \n");
    printf("\t  HHHH HHHHHH               HHHH   HHHHHH    \n");
    printf("\t   HHH HHHHHHH HHH HHH HHH HHHH  HHHHH       \n");
    printf("\t     H HH HHH  HHH HHH HHH HHHHH HHH  HHHH    \n");
    printf("\t        HHHH   HHH HHH HHHH HHHH HH   HHHHH    \n");
}
void print_fire() {
    printf("\n");
    printf("\t                HH                             H  \n");
    printf("\t               H H                            HH  \n");
    printf("\t               H H        HHHH          H    H H  \n");
    printf("\t              H H        HHH           HH    HH   \n");
    printf("\t              HH       HH  H          H H         \n");
    printf("\t              H       H    H         H H   HH     \n");
    printf("\t                      H   H         H  H  HH      \n");
    printf("\t               H     H   H       HHH  H HH H      \n");
    printf("\t              HH     H   H   HHHH    HHH  H       \n");
    printf("\t             H H     H   HHHH            H        \n");
    printf("\t            H  H    H                   HH        \n");
    printf("\t           H   H    H                    HHH          H\n");
    printf("\t         HH     HHHH                       HHH        HH\n");
    printf("\t       HH                                     HH     H H\n");
    printf("\t      H                                      HH      H H\n");
    printf("\t     H                                      HH      H  H\n");
    printf("\t    H                                     HH        H H\n");
    printf("\t    H                        H           H           H\n");
    printf("\t    H  H                    HH           H         \n");
    printf("\t   H  HH                  HH H          H         H\n");
    printf("\t   H H  H               HH   H          H        HH\n");
    printf("\t   H H   H             H     H          H    HHH H\n");
    printf("\t   H H     H         HH     H            HHHH   H\n");
    printf("\t   H  H    HH       HH     H                    H\n");
    printf("\t   H  H      HH    H    HHH                    H\n");
    printf("\t    H  HHHHHHH   HHHHHHH                       H\n");
    printf("\t    H                      H                  H\n");
    printf("\t     H     HHH  HHH  HHH  H H                 H\n");
    printf("\t     H    H  HHHH  HHH  HH  H                H\n");
    printf("\t     H    H                  H             HH\n");
    printf("\t      H   H                  H        H  HH\n");
    printf("\t       H   HH                H        HHHH\n");
    printf("\t       H    HHH HH   HH     H       HHH\n");
    printf("\t         HH    H  HHHH  HHHH    HHH\n");
    printf("\t          H                    HHHH\n");
    printf("\t           HHHHHHHHHHHHHHHHHHHHH\n");
}
void print_zombie() {
    printf("\n");

    printf("\t     H    HHHHHHHHHH  HHH\n");
    printf("\t     H  HH          HH\n");
    printf("\t      HH              HHH\n");
    printf("\t   H  H               H\n");
    printf("\t    HHH                HHHH\n");
    printf("\t     H         HHHHH   H   H\n");
    printf("\t     HHHH     H     H  H   \n");
    printf("\t    H    H    H     H   H  \n");
    printf("\t    H    H    H     H   HHH\n");
    printf("\t     HHHH      HHHHH    H  H \n");
    printf("\t      H                H H   \n");
    printf("\t      HH HHH H HH     H   HH  \n");
    printf("\t        H        H   H H    H\n");
    printf("\t         H      H    H  H    H\n");
    printf("\t        H  HHH H    HH   H    H\n");
    printf("\t         HH   HHHHHH  H H      H\n");
    printf("\t           HHH H   H H  H     H H\n");
    printf("\t               H   H H  H   HH   H \n");
    printf("\t             HH    HH   H HH     H\n");
    printf("\t            HH     H   HHH       H\n");
    printf("\t             HHHHHHHHHHHH        H\n");
    printf("\t              H   H     H       H\n");
    printf("\t             H    H HH  HH      H\n");
    printf("\t              HHHHHHH HH  HHHHHH    \n");
}
void print_human() {
    printf("\n");
    printf("\t        HHHHHHHHHHHHHHHH\n");
    printf("\t       H                H\n");
    printf("\t      H                  H\n");
    printf("\t     H                    H\n");
    printf("\t    H                      H\n");
    printf("\t    H   H  HHHH  H   HHHH   H\n");
    printf("\t   H   H HH    HH HHH    H   H\n");
    printf("\t   H   H                 H   H\n");
    printf("\t   H   H  HHHHH   HHHHH  H   H\n");
    printf("\t    H  H                 H  H \n");
    printf("\t     HH H    HHHHHHH    H HH  \n");
    printf("\t         H              H\n");
    printf("\t          HHHHHHHHHHHHH\n");
    printf("\t             H      H\n");
    printf("\t           HH        HH \n");
    printf("\t          H  HH    HH  H \n");
    printf("\t        HH     HHHH     HH   \n");
    printf("\t       H    H        H    H \n");
    printf("\t       H    HHHHHHHHHH    H \n");
    printf("\t       HHHHHH        HHHHHH \n");
    printf("\t       H    H        H    H \n");
    printf("\t       HHHHHHHHHHHHHHHHHHHH \n");
    printf("\t        H   H   HH   H   H  \n");
    printf("\t        H  HH  H  H  HH  H  \n");
    printf("\t         HH H H    H H HH   \n");
}
void print_human2() {
    printf("\n");
    printf("\t        HHHHHHHHHHHHHHHH        \n");
    printf("\t       H H              H       \n");
    printf("\t      H   H            H H      \n");
    printf("\t     H     HH         H   H     \n");
    printf("\t    H        HH      H     H     \n");
    printf("\t    H   H  HH  HHH   HHHH   H    \n");
    printf("\t    H  H HH       HHH    H   H   \n");
    printf("\t    H  H    HH      HH   H   H   \n");
    printf("\t   H   H    HH      HH   H   H\n");
    printf("\t  H H  H    HH      HH   H  H H  \n");
    printf("\t H H HH H               H HH H H \n");
    printf("\t HH      H    HHHHH    H      HH \n");
    printf("\t          HHHHHHHHHHHHH\n");
    printf("\t             H      H\n");
    printf("\t           HH        HH \n");
    printf("\t          H  HH    HH  H \n");
    printf("\t        HH     HHHH     HH   \n");
    printf("\t       H    H        H    H \n");
    printf("\t       H    HH      HH    H \n");
    printf("\t       H    H H    H H    H \n");
    printf("\t       H    H  HHHH  H    H \n");
    printf("\t       HHHHHHHHHHHHHHHHHHHH \n");
    printf("\t        H   H   HH   H   H  \n");
    printf("\t        H  HH   HH   HH  H  \n");
    printf("\t         HH H   HH   H HH   \n");
}
void print_warlord() {
    printf("\n");
    printf("                        *           \n");
    printf("                      ** **         \n");
    printf("                     **   **        \n");
    printf("                   ***********      \n");
    printf("               *  **         **  *  \n");
    printf("               * *** *  *  * *** *  \n");
    printf("                * ** *  *  * ** *   \n");
    printf("                 *** *  *  * ***    \n");
    printf("                   **  * *  **      \n");
    printf("                  *  ** * **  *     \n");
    printf("                ***           **\n");
    printf("              *** ***  ***     **\n");
    printf("              ** *****  *      ** \n");
    printf("                ******* *  ** ** * \n");
    printf("                 ***** *** * *  **\n");
    printf("                  ***  ***  ****\n");
    printf("                   **  **  ***   \n");
    printf("                  **  *   *** *\n");
    printf("                  *  *   ***  *\n");
    printf("                  *  *  ** *  *\n");
    printf("                   **       **\n");

}
void print_warlock() {
    printf("\n");
    printf("                ***\n");
    printf("               *   *\n");
    printf("              **   **\n");
    printf("            ***     **\n");
    printf("           ***       *\n");
    printf("      ******          **\n");
    printf("     **                ** \n");
    printf("         * ****          *\n");
    printf("          **  *******    **\n");
    printf("         **          ***** **\n");
    printf("        **   ** **    *** *\n");
    printf("       **    ** **     **\n");
    printf("        **             **\n");
    printf("         *****      **** \n");
    printf("             *******\n");
    printf("           **        **\n");
    printf("          ***         **\n");
    printf("         ** **         **\n");
    printf("         **  **        **\n");
    printf("         **   **        **\n");
    printf("         **    ***       **\n");
    printf("        **     *  **   ** **\n");
    printf("         ******    *****   **\n");
}
void print_knight() {
    printf("\n");
    printf("                **              **\n");
    printf("               *  *             *  *\n");
    printf("              *  *     ******    *  *\n");
    printf("              *  *   **      **  *  *\n");
    printf("              *  *  *          * *  *\n");
    printf("               * **   *    **  **  *\n");
    printf("                ****  **   **  *** \n");
    printf("                  **   *****   **\n");
    printf("                   **   * *   **\n");
    printf("                    *   **    **\n");
    printf("                 *****************\n");
    printf("               ******         *****\n");
    printf("              ***   *           ***\n");
    printf("              ***  *          H* ***  \n");
    printf("               **** *       HH** *** \n");
    printf("                *********  HHH**H***H      \n");
    printf("            HHHHHHHHHHHHHH  HH**HH***H  \n");
    printf("    HHHHHHHHH              HHHHH*****HH \n");
    printf(" HHH                       HHHHH*****H \n");
    printf("H                HHHHHHHHHH HH   ***   \n");
    printf(" HHHHH      HHHHHH  ***   *HHH       \n");
    printf("     HHHHHHH       ***    **HH \n");
    printf("                   ***     *H* \n");
    printf("                  ****     ****   \n");
    printf("                ** **       ** **      \n");
}

void status() {
    char temp[5];
    int i,n=0;
    itoa(tester.hp,temp,10);
    n=n+strlen(temp);
    itoa(tester.max_hp,temp,10);
    n=n+strlen(temp);
    itoa(tester.atk,temp,10);
    n=n+strlen(temp);
    itoa(tester.gold,temp,10);//convert int to string (,,base number)
    n=n+strlen(temp);
    //printf("%d\n",strlen(tester.name));
    printf("+");
    for(i=0; i<strlen(tester.name)+n+23; i++)
        printf("-");
    printf("+\n");
    printf("| Name:%s HP %d/%d ATK %d gold %d |\n",tester.name,tester.hp,tester.max_hp,tester.atk,tester.gold);
    printf("+");
    for(i=0; i<strlen(tester.name)+n+23; i++)
        printf("-");
    printf("+\n");
}
void equip(int a,int b) {
    int eq_hp=a,eq_atk=b;
    tester.hp = tester.hp+eq_hp;
    tester.max_hp = tester.max_hp+eq_hp;
    tester.atk = tester.atk+eq_atk;
    status();
}
void hp_cap() {
    if(tester.hp>tester.max_hp)
        tester.hp = tester.max_hp;
}
void item_drop() {
    printf("you get gold: %d\nitem: %s\n",drop.gold,drop.item_name);
    tester.gold += drop.gold;
    equip(drop.item_hp,drop.item_atk);
}
int get_drop(int a) {
    drop_data = fopen("drop.txt", "r");
    for(int i=0; i<a; i++) {
        fscanf(drop_data,"%d %d %d %s",&drop.gold,&drop.item_hp,&drop.item_atk,drop.item_name);
        // printf(mon,"%d %d %d %s",drop.gold,drop.item_hp,drop.item_atk,drop.item_name);
    }
    fclose(drop_data);
    space(drop.item_name,strlen(drop.item_name));
    // printf("%d %d %d %s",drop.gold,drop.item_hp,drop.item_atk,drop.item_name);
    item_drop();


}
int win() {
    system("COLOR 07");
    printf("Congratulation you win \n");
    tester.gold+=mon.drop;
    printf("You get %d gold and a %s \n",mon.drop,mon.item);
    equip(mon.drop_hp,mon.drop_atk);
}
void merchant() {
    int input;
    printf("You come in to buy something select 1 thing to buy **out of these mean nothing\n");
    printf("Input a number only\n");
    printf("NO.        Name             Price       remain\n");
    printf(" 1: mini potion   +25hp    50 gold  you have %d\n",tester.item[0]);
    printf(" 2: small potion  +50hp   100 gold  you have %d\n",tester.item[1]);
    printf(" 3: medium potion +100hp  200 gold  you have %d\n",tester.item[2]);
    printf(" 4: high potion   +150hp  300 gold  you have %d\n",tester.item[3]);
    printf(" 5: god potion    +200hp  400 gold  you have %d\n",tester.item[4]);
    scanf(" %d",&input);
    switch (input) {
    case 1 :
        if(tester.gold - 50>=0) {
            tester.item[0]+=1;
            tester.gold -= 50;
            printf("%s buy mini potion\n",tester.name);
        } else
            printf("Cant Buy\n");
        break;
    case 2 :
        if(tester.gold - 100>=0) {
            tester.item[1]+=1;
            tester.gold -= 100;
            printf("%s buy small potion\n",tester.name);
        } else
            printf("Cant Buy\n");
        break;
    case 3 :
        if(tester.gold - 200>=0) {
            tester.item[2]+=1;
            tester.gold -= 200;
            printf("%s buy medium potion\n",tester.name);
        } else
            printf("Cant Buy\n");
        break;
    case 4 :
        if(tester.gold - 300>=0) {
            tester.item[3]+=1;
            tester.gold -= 300;
            printf("%s buy high potion\n",tester.name);
        } else
            printf("Cant Buy\n");
        break;
    case 5 :
        if(tester.gold - 400>=0) {
            tester.item[4]+=1;
            tester.gold -= 400;
            printf("%s buy god potion\n",tester.name);
        } else
            printf("Cant Buy\n");
        break;
    default :
        printf("you exit from shop\n");
        break;
    }
    printf("%s current gold %d\n",tester.name,tester.gold);
}
void nothing() {
    printf("Nothing here let's go\n");
}
float delay(float num_of_second) {
    float milli_seconds = 100*num_of_second;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds);

}
void fullstory_v2() {
    full_story = fopen("fullstor.txt","r");
    char txt;
    while(!feof(full_story)) {
        fscanf(full_story," %c",&txt);
        if(txt=='*') {
            printf("\n");
        } else if(txt=='_')
            printf(" ");
        else
            printf("%c",txt);
        delay(0.35);
        //printf("\n");
    }
}
int warp(int a) {
    position +=a;
    printf("%s is warped to position %d\n",tester.name,position);
    select_map(position);
}
int dice() {
    int dice;
    do {
        printf("Press Enter to roll\n");
        while(_getch() != '\r');
        dice=rand()%6;
        dice++;
        position+=dice;
        //  position =65;
        if(position>100)
            position = 100;
        system("cls");
        status();
        printf("You roll %d\n",dice);
        printf("%s position is %d\n",tester.name,position);
        select_map(position);

    } while(position<100);
}
int casino() {
    int c,n,bet,result;
    char start;
    printf("Welcome to Casino\n");
    printf("Do you want to go in casino?\n");
    printf(" 1.Go\n");
    printf(" 2.Not go\n");
    scanf("%d",&c);
    if(c==1) {
        do {
            if(tester.gold<200) {
                printf("Gold not enough (use 200 golds)\n");
                break;
            }
            printf("Bet money if you bet more than gold mean all in however bet less than 0 mean 0:");
            scanf("%d",&bet);
            if(bet>tester.gold)
                bet = tester.gold;
            if(bet<0)
                bet =0;

            printf("Head or Tail\n");
            printf("1 for Head\n");
            printf("2 for Tail\n");
            printf("etc. mean Head\n");
            scanf("%d",&n);
            result = 1+(rand()%2);
            if(n==result) {
                printf("You WIN\n");
                tester.gold = tester.gold + bet;
            } else {
                printf("You LOSE\n");
                tester.gold = tester.gold - bet;
            }

            printf("Now you have %d gold\n",tester.gold);
            printf("You want to continue any key for yes N for no\n");
            start = _getch();
            system("cls");
            status();
        } while(start!='N' && start !='n');
    } else
        dice();
}
int RPS() {
    printf("A child want to play Rock Paper Scissor with you\n");
    int a,b,c;
    char start;
    char janken[3][10] = {"Rock","Paper","Scissor"};
    printf("Do you want to play??\n");
    printf(" 1.Play\n");
    printf(" 2.Not play\n");
    scanf("%d",&c);
    if(c==1) {
        do {
            if(tester.gold<=0) {
                printf("Gold not enough (use 200 golds)\n");
                break;
            }

            printf("You choose\n");
            printf(" 1.Rock\n");
            printf(" 2.Paper\n");
            printf(" 3.Scissor\n");
            printf(" etc. mean Rock\n");
            scanf("%d",&a);
            if(a!=1 && a!=2 && a!=3)
                a=1;
            b=rand()%3;
            printf("You choose %s\n",janken[a-1]);
            printf("Enemy choose %s\n",janken[b]);
            b++;
            if(a-b==1 || b-a == 2) {
                printf("You WIN\n");
                printf("A child: Nani???\n");
                printf("you get 1 small potion\n");
                tester.item[1]++;

            } else if(a==b) {
                printf("DRAW\n");
                printf("A child: I will win in next time\n");
            } else {
                printf("You LOSE\n");
                printf("A child: So EZ\n");
                printf("you loss 200 gold\n");
                tester.gold -=200;
                if(tester.gold<0)
                    tester.gold =0;
                status();
            }
            printf("You want to continue any key for yes N for no\n");
            start = _getch();

            system("cls");
            status();
        } while(start!='N' && start !='n');
    } else
        dice();
}
int dead() {
    tester.max_hp = 200;
    tester.hp = tester.max_hp/2;
    position = 1;
    mon.hp = mon.max_hp;
    tester.atk=15;
    tester.gold -=100;
    if(tester.gold<0)
        tester.gold=0;
    printf("You dead you lose 100 gold\nGame RESET\n");
    printf("You position is %d hp is %d/%d atk is %d current gold %d\n",position,tester.hp,tester.max_hp,tester.atk,tester.gold);
    dice();
}
int attack() {
    mon.hp = mon.hp-tester.atk;
    tester.hp = tester.hp-mon.atk;
    printf("%s use %s\n",mon.name,mon.skill);
    if(mon.hp<0)
        mon.hp = 0;
    if(tester.hp<0)
        tester.hp = 0;
    printf("result player hp: %d/%d\n       mon    hp: %d/%d\n",tester.hp,tester.max_hp,mon.hp,mon.max_hp);
    if(tester.hp<=0)
        dead();
    if(tester.hp>0 && mon.hp<=0)
        win();
}
int defend() {
    defend_checker=rand()%10;
    if(defend_checker>4) {
        printf("%s use %s\n",mon.name,mon.skill);
        printf("defend success\n");
        tester.hp--;
    } else {
        printf("%s use %s\n",mon.name,mon.skill);
        printf("can't defend\n");
        tester.hp = tester.hp-mon.atk;
    }
    if(tester.hp<=0)
        dead();
    printf("result player hp: %d/%d\n       mon    hp: %d/%d\n",tester.hp,tester.max_hp,mon.hp,mon.max_hp);
}
int use_item() {
    int s,is;
    status();
    printf("Use item select choice **out of these mean nothing**\n");
    printf(" 1:mini   potion +25hp   you have %d\n",tester.item[0]);
    printf(" 2:small  potion +50hp   you have %d\n",tester.item[1]);
    printf(" 3:medium potion +100hp  you have %d\n",tester.item[2]);
    printf(" 4:high   potion +150hp  you have %d\n",tester.item[3]);
    printf(" 5:god    potion +200hp  you have %d\n",tester.item[4]);
    scanf("%d",&s);
    is=s-1;
    if(tester.item[is]<1) {
        printf("out of potion\n");
        tester.hp = tester.hp-mon.atk;
    } else {
        switch(s) {
        case 1 :
            tester.hp = tester.hp+25;
            hp_cap();
            tester.hp = tester.hp-mon.atk;
            tester.item[0]--;
            printf("%s use %s\n",mon.name,mon.skill);
            break;
        case 2 :
            tester.hp = tester.hp+50;
            hp_cap();
            tester.hp = tester.hp-mon.atk;
            tester.item[1]--;
            printf("%s use %s\n",mon.name,mon.skill);
            break;
        case 3 :
            tester.hp = tester.hp+100;
            hp_cap();
            tester.hp = tester.hp-mon.atk;
            tester.item[2]--;
            printf("%s use %s\n",mon.name,mon.skill);
            break;
        case 4 :
            tester.hp = tester.hp+150;
            hp_cap();
            tester.hp = tester.hp-mon.atk;
            tester.item[3]--;
            printf("%s use %s\n",mon.name,mon.skill);
            break;
        case 5 :
            tester.hp = tester.hp+200;
            hp_cap();
            tester.hp = tester.hp-mon.atk;
            tester.item[4]--;
            printf("%s use %s\n",mon.name,mon.skill);
            break;
        default :
            printf("no item in bag\n");
            tester.hp = tester.hp-mon.atk;
            break;
        }
    }

    if(tester.hp<=0)
        dead();
    printf("result player hp: %d/%d\n       mon    hp: %d/%d\n",tester.hp,tester.max_hp,mon.hp,mon.max_hp);
}
int fight() {
    while(tester.hp>0 && mon.hp>0) {
        status();
        printf("fighting select choice **out of these mean escape\n");
        fight_action=0;
        printf(" 1:attack\n");
        printf(" 2:def\n");
        printf(" 3:item\n");
        printf(" 4:escape\n");
        scanf(" %d",&fight_action);
        system("cls");
        system("COLOR 07");
        switch (fight_action) {
        case 1 :
            attack();
            break;
        case 2 :
            defend();
            break;
        case 3 :
            use_item();
            break;
        case 4 :
            escape();
            break;
        default :
            escape();
            break;
        }
    }
}
void found() {
    printf("found %s(%d hp,%d atk) select choice **out of these mean fight\n",mon.name,mon.hp,mon.atk);
    escape_check=0;
    printf(" 1:fight\n");
    printf(" 2:escape\n");
    scanf(" %d",&action);
    system("cls");
    system("COLOR 07");
    switch (action) {
    case 1 :
        fight();
        break;
    case 2 :
        escape();
        break;
    default :
        fight();
        break;
    }
}
int get_mon(int a) {
    mon_data = fopen("monster.txt", "r");
    for(int i=0; i<a; i++) {
        fscanf(mon_data,"%s %d %d %d %d %s %s %d %d",mon.name,&mon.max_hp,&mon.hp,&mon.atk,&mon.drop,mon.skill,mon.item,&mon.drop_hp,&mon.drop_atk);
        // printf("%s %d %d %d %d %s %s",mon1.name,mon1.max_hp,mon1.hp,mon1.atk,mon1.drop,mon1.skill,mon1.item);
    }
    fclose(mon_data);
    space(mon.name,strlen(mon.name));
    space(mon.skill,strlen(mon.skill));
    space(mon.item,strlen(mon.item));
    found();
}
int select_map(int position) {
    switch (position) {
    case 2 :
        system("COLOR 04");
        print_slime();
        get_mon(1);
        break;
    case 3 :
        get_drop(1);
        break;
    case 4 :
        merchant();
        break;
    case 5 :
        system("COLOR 09");
        print_slime();
        get_mon(2);
        break;
    case 6 :
        system("COLOR 08");
        print_slime();
        get_mon(3);
        break;
    case 7 :
        merchant();
        break;
    case 8 :
        system("COLOR 06");
        print_slime();
        get_mon(4);
        break;
    case 9 :
        system("COLOR 05");
        print_slime();
        get_mon(5);
        break;
    case 10 :
        system("COLOR 04");
        print_goblin();
        get_mon(6);
        break;
    case 11 :
        system("COLOR 09");
        print_goblin();
        get_mon(7);
        break;
    case 12 :
        system("COLOR 02");
        print_goblin();
        get_mon(8);
        break;
    case 13 :
        merchant();
        break;
    case 14 :
        system("COLOR 06");
        print_goblin();
        get_mon(9);
        break;
    case 15 :
        merchant();
        break;
    case 16 :
        casino();
        break;
    case 17 :
        system("COLOR 02");
        print_orge();
        get_mon(10);
        break;
    case 18 :
        system("COLOR 04");
        print_orge();
        get_mon(11);
        break;
    case 19 :
        merchant();
        break;
    case 20 :
        warp(5);
        break;
    case 21 :
        get_drop(2);
        break;
    case 22 :
        get_drop(3);
        break;
    case 23 :
        merchant();
        break;
    case 24 :
        system("COLOR 08");
        print_spider();
        get_mon(12);
        break;
    case 25 :
        RPS();
        break;
    case 26 :
        merchant();
        break;
    case 27 :
        get_drop(4);
        break;
    case 28 :
        get_drop(5);
        break;
    case 29 :
        get_drop(6);
        break;
    case 30 :
        get_drop(7);
        break;
    case 31 :
        get_drop(8);
        break;
    case 32 :
        get_drop(9);
        break;
    case 33 :
        merchant();
        break;
    case 34 :
        merchant();
        break;
    case 35 :
        merchant();
        break;
    case 36 :
        system("COLOR 02");
        print_zombie();
        get_mon(13);
        break;
    case 37 :
        system("COLOR 0C");
        print_zombie();
        get_mon(14);
        break;
    case 38 :
        warp(5);
        break;
    case 39 :
        get_drop(10);
        break;
    case 40 :
        item_drop(11);
        break;
    case 41 :
        merchant();
        break;
    case 42 :
        get_drop(12);
        break;
    case 43 :
        nothing();
        break;
    case 44 :
        get_drop(13);
        break;
    case 45 :
        get_drop(14);
        break;
    case 46 :
        get_drop(15);
        break;
    case 47 :
        get_drop(16);
        break;
    case 48 :
        merchant();
        break;
    case 49 :
        get_drop(17);
        break;
    case 50 :
        get_drop(18);
        break;
    case 51 :
        get_drop(19);
        break;
    case 52 :
        merchant();
        break;
    case 53 :
        merchant();
        break;
    case 54 :
        system("COLOR 08");
        print_human();
        get_mon(15);
        break;
    case 55 :
        system("COLOR 08");
        print_human2();
        get_mon(16);
        break;
    case 56 :
        system("COLOR 08");
        print_assasin();
        get_mon(17);
        break;
    case 57 :
        get_drop(20);
        break;
    case 58 :
        merchant();
        break;
    case 59 :
        system("COLOR 08");
        print_warlord();
        get_mon(18);
        break;
    case 60 :
        warp(5);
        break;
    case 61 :
        get_drop(21);
        break;
    case 62 :
        get_drop(22);
        break;
    case 63 :
        merchant();
        break;
    case 64 :
        get_drop(23);
        break;
    case 65 :
        casino();
        break;
    case 66 :
        get_drop(24);
        break;
    case 67 :
        get_drop(25);
        break;
    case 68 :
        get_drop(26);
        break;
    case 69 :
        get_drop(27);
        break;
    case 70 :
        merchant();
        break;
    case 71 :
        get_drop(28);
        break;
    case 72 :
        get_drop(29);
        break;
    case 73 :
        get_drop(30);
        break;
    case 74 :
        get_drop(31);
        break;
    case 75 :
        system("COLOR 09");
        print_warlock();
        get_mon(19);
        break;
    case 76 :
        merchant();
        break;
    case 77 :
        get_drop(32);
        break;
    case 78 :
        system("COLOR 0C");
        print_knight();
        get_mon(20);
        break;
    case 79 :
        get_drop(33);
        break;
    case 80 :
        get_drop(34);
        break;
    case 81 :
        get_drop(35);
        break;
    case 82 :
        get_drop(36);
        break;
    case 83 :
        system("COLOR 08");
        print_fire();
        get_mon(21);
        break;
    case 84 :
        get_drop(37);
        break;
    case 85 :
        system("COLOR 0E");
        print_fire();
        get_mon(22);
        break;
    case 86 :
        system("COLOR 04");
        print_fire();
        get_mon(23);
        break;
    case 87 :
        system("COLOR 09");
        print_golem();
        get_mon(24);
        break;
    case 88 :
        system("COLOR 0E");
        print_golem();
        get_mon(25);
        break;
    case 89 :
        get_drop(38);
        break;
    case 90 :
        get_drop(39);
        break;
    case 91 :
        merchant();
        break;
    case 92 :
        system("COLOR 08");
        print_golem();
        get_mon(26);
        break;
    case 93 :
        get_drop(40);
        break;
    case 94 :
        warp(6);
        break;
    case 95 :
        warp(5);
        break;
    case 96 :
        warp(4);
        break;
    case 97 :
        warp(3);
        break;
    case 98 :
        warp(2);
        break;
    case 99 :
        warp(1);
        break;
    case 100 :
        merchant();
        system("COLOR 0E");
        print_dragon();
        get_mon(30);
        break;
    }
}
int escape() {
    status();
    escape_check=rand()%10;
    if(escape_check>6) {
        system("COLOR 07");
        printf("escape success\n");
        dice();
    } else {
        tester.hp = tester.hp-mon.atk;
        printf("can't escape\n");
        printf("%s use %s\n",mon.name,mon.skill);
        if(tester.hp<=0) {
            dead();
        }
        printf("result player hp: %d/%d\n       mon    hp: %d/%d\n",tester.hp,tester.max_hp,mon.hp,mon.max_hp);
        fight();
    }
}
void ending() {
    printf("Now you're the hero who save the village and know true story that Gaia Dragon is spirit but possessed by bad spirit and rampaging\n");
    printf("CONGRATULATION %s You're winner!!",tester.name);
    _getch();
}
int intro() {
    int i;
    char col_1[100]  = {"\n\t  =======================================================================================\n"};
    char col_2[100]  = {"\t||                                                                                       ||\n"};
    char col_3[100]  = {"\t||  HHHHHH      HH       HH  HHHH     HH   HHHHHHHH   HHHHHHHH   HHHHHHHH   HHH      HH  ||\n"};
    char col_4[100]  = {"\t||  HH    HH    HH       HH  HH HH    HH  HH      HH  HH        HH      HH  HH HH    HH  ||\n"};
    char col_5[100]  = {"\t||  HH      H   HH       HH  HH  HH   HH  HH          HH        HH      HH  HH  HH   HH  ||\n"};
    char col_6[100]  = {"\t||  HH       H  HH       HH  HH   HH  HH  HH  HHHHH   HHHHHHHH  HH      HH  HH   HH  HH  ||\n"};
    char col_7[100]  = {"\t||  HH      H   HH       HH  HH    HH HH  HH      HH  HH        HH      HH  HH    HH HH  ||\n"};
    char col_8[100]  = {"\t||  HH    HH    HH       HH  HH     HHHH  HH      HH  HH        HH      HH  HH     HHHH  ||\n"};
    char col_9[100]  = {"\t||  HHHHHH        HHHHHHH    HH      HHH   HHHHHHHH   HHHHHHHH   HHHHHHHH   HH      HHH  ||\n"};
    char col_10[100] = {"\t||                                                                                       ||\n"};
    char col_11[100] = {"\t||  HHHHHHHH    HHHHHHHH    HH            HH          HHHHHHHH  HHH      HH   HHHHHHHH   ||\n"};
    char col_12[100] = {"\t||  HH    HH   HH      HH   HH            HH             HH     HH HH    HH  HH      HH  ||\n"};
    char col_13[100] = {"\t||  HH    HH   HH      HH   HH            HH             HH     HH  HH   HH  HH          ||\n"};
    char col_14[100] = {"\t||  HHHHHHHH   HH      HH   HH            HH             HH     HH   HH  HH  HH  HHHHH   ||\n"};
    char col_15[100] = {"\t||  HH  HH     HH      HH   HH            HH             HH     HH    HH HH  HH      HH  ||\n"};
    char col_16[100] = {"\t||  HH   HH    HH      HH   HH            HH             HH     HH     HHHH  HH      HH  ||\n"};
    char col_17[100] = {"\t||  HH    HH    HHHHHHHH    HHHHHHHHHH    HHHHHHHHHH  HHHHHHHH  HH      HHH   HHHHHHHH   ||\n"};
    char col_18[100] = {"\t||                                                                                       ||\n"};
    char col_19[100] = {"\t  =======================================================================================\n"};


    for(i=0 ; i<strlen(col_1); i++) {
        delay(0.05);
        printf("%c",col_1[i]);

    }

    for(i=0 ; i<strlen(col_2); i++) {
        delay(0.05);
        printf("%c",col_2[i]);

    }

    for(i=0 ; i<strlen(col_3); i++) {
        delay(0.05);
        printf("%c",col_3[i]);

    }

    for(i=0 ; i<strlen(col_4); i++) {
        delay(0.05);
        printf("%c",col_4[i]);

    }

    for(i=0 ; i<strlen(col_5); i++) {
        delay(0.05);
        printf("%c",col_5[i]);

    }

    for(i=0 ; i<strlen(col_6); i++) {
        delay(0.05);
        printf("%c",col_6[i]);

    }

    for(i=0 ; i<strlen(col_7); i++) {
        delay(0.05);
        printf("%c",col_7[i]);

    }

    for(i=0 ; i<strlen(col_8); i++) {
        delay(0.05);
        printf("%c",col_8[i]);

    }

    for(i=0 ; i<strlen(col_9); i++) {
        delay(0.05);
        printf("%c",col_9[i]);

    }

    for(i=0 ; i<strlen(col_10); i++) {
        delay(0.025);
        printf("%c",col_10[i]);

    }

    for(i=0 ; i<strlen(col_11); i++) {
        delay(0.05);
        printf("%c",col_11[i]);

    }

    for(i=0 ; i<strlen(col_12); i++) {
        delay(0.05);
        printf("%c",col_12[i]);

    }

    for(i=0 ; i<strlen(col_13); i++) {
        delay(0.05);
        printf("%c",col_13[i]);

    }

    for(i=0 ; i<strlen(col_14); i++) {
        delay(0.05);
        printf("%c",col_14[i]);

    }

    for(i=0 ; i<strlen(col_15); i++) {
        delay(0.05);
        printf("%c",col_15[i]);

    }

    for(i=0 ; i<strlen(col_16); i++) {
        delay(0.05);
        printf("%c",col_16[i]);

    }

    for(i=0 ; i<strlen(col_17); i++) {
        delay(0.05);
        printf("%c",col_17[i]);

    }

    for(i=0 ; i<strlen(col_18); i++) {
        delay(0.025);
        printf("%c",col_18[i]);

    }

    for(i=0 ; i<strlen(col_19); i++) {
        delay(0.05);
        printf("%c",col_19[i]);

    }

}
/*void save() {
    SAVE = fopen("save.txt","w");
    fprintf(SAVE,"%s\n",tester.name);
    fprintf(SAVE,"%d %d %d %d %d %d %d %d %d %d\n",tester.max_hp,tester.hp,tester.atk,tester.gold,tester.item[0],tester.item[1],tester.item[2],tester.item[3],tester.item[4],position);
    fclose(SAVE);
}*/
/*void load() {
    LOAD = fopen("save.txt","r");
    fgets(tester.name,100,LOAD);
    fscanf(LOAD,"%d %d %d %d %d %d %d %d %d %d\n",&tester.max_hp,&tester.hp,&tester.atk,&tester.gold,&tester.item[0],&tester.item[1],&tester.item[2],&tester.item[3],&tester.item[4],&position);
    fclose(LOAD);
}*/

int main() {
    system("COLOR 02");
    intro();
    printf("\n\n\nPress Enter to Start");
    while(_getch() != '\r');
    system("cls");
    system("COLOR 07");
    fullstory_v2();
    printf("\n\n\nPress Enter to Continue");
    while(_getch() != '\r');
    system("cls");
    srand(time(NULL));
    printf("Input your name:");
    gets(tester.name);
    status();
    //printf("%s has %d hp and %d atk\n",tester.name,tester.hp,tester.atk);
    printf("You position is %d\n",position);
    printf("Start\n");
    dice();
    ending();
    //_getch();
}


