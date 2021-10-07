#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int action,escape_check,fight_action,defend_checker;
struct player
{
    char name[20];
    int max_hp,hp,atk,gold;
    int item[10];
};
struct player tester = { "test" ,100,100,50,200,{0,0,0,0,0,0,0,0,0,0}};
struct monster
{
    char name[20];
    int max_hp,hp,atk,drop;
    char skill[30],item[30];
};
struct monster mon[27] =
{
    /*1*/ {"Pink slime",20,20,3,5,"slime attack(Dmg 3)","Slime ball"},
    /*2*/ {"Blue slime",20,20,3,5,"slime attack(Dmg 3)","Slime ball"},
    /*3*/ {"Black slime",20,20,3,5,"slime attack(Dmg 3)","Slime ball"},
    /*4*/ {"Yellow slime",20,20,3,5,"slime attack(Dmg 3)","Slime ball"},
    /*5*/ {"Purple slime",20,20,3,5,"slime attack(Dmg 3)","Slime ball"},
    /*6*/ {"Warrior goblin",50,50,15,15,"Flame cutting(Dmg 15) ","Goblin frame sword (Atk+15)"},
    /*7*/ {"Wizard goblin",35,35,20,15,"Meteor(Dmg 20)","Ice wand (Atk+18)"},
    /*8*/ {"**BOSS Goblin king",80,80,20,50,"Comet sword(Dmg 20)","King goblin sword(Hp+35 Atk+25)"},
    /*9*/ {"Gunslinger goblin",35,35,18,15,"Dark Bullet(Dmg 18)","Goblin armor (Hp+20)"},
    /*10*/{"Green Orge",55,55,13,18,"Flashing attack(Dmg 13)","leader armor(Hp+25)"},
    /*11*/{"Red Orge",55,55,14,19,"Flashing flame attack(Dmg 14)","leader armor(Hp+26)"},
    /*12*/{"Black Spider",45,45,17,20,"Spinning Assault(Dmg 17)","Black armor(Hp+28)"},
    /*13*/{"Revenge zombie",60,60,20,30,"Ravenge blade(Dmg 20)","Black Blade(Atk+25)"},
    /*14*/{"*BOSS Leader zombie",120,120,25,70,"Shadow swoop(Dmg 25)","ghost sword & armor(Hp+50 Atk+40)"},
    /*15*/{"Noble",70,70,22,40,"Deadly crossing(Dmg 22)","Dark sword & armor (Hp+30 Atk+30)"},
    /*16*/{"chevalier",70,70,23,42,"Lightning Strike(Dmg 23)","Lighting sword & armor(Hp+31 Atk+31)"},
    /*17*/{"Assasin",60,60,25,50,"Double blad(Dmg 25)","Double sword & armor(Hp+27 Atk+35)"},
    /*18*/{"*BOSS Knight Lord",250,250,40,150,"Glacial Retreat(Dmg 40)","Frost sword & armor(Hp+80 Atk+60)"},
    /*19*/{"Warlord",80,80,35,60,"Flame Pillar(Dmg 35)","Solar sword & armor(Hp+35 Atk+38)"},
    /*20*/{"Warlock",90,90,40,70,"Arcane Pulse(Dmg 40)","Arcane sword & armor(Hp+45 Atk+48)"},
    /*21*/{"Dark tera",110,110,40,75,"Fairy blade(Dmg 40)","double fairy sword & armor(Hp+48 Atk+50)"},
    /*22*/{"Moon tera",110,110,40,75,"Fairy blade(Dmg 40)","double fairy sword & armor(Hp+48 Atk+50)"},
    /*23*/{"Sun tera",110,110,40,75,"Fairy blade(Dmg 40)","double fairy sword & armor(Hp+48 Atk+50)"},
    /*24*/{"Storm golem",350,350,50,250,"Arcane Pulse(Dmg 50)","Golem sword & armor(Hp+100 Atk+80)"},
    /*25*/{"Light golem",350,350,50,250,"Arcane Pulse(Dmg 50)","Golem sword & armor(Hp+100 Atk+80)"},
    /*26*/{"Dark golem",350,350,50,250,"Arcane Pulse(Dmg 50)","Golem sword & armor(Hp+100 Atk+80)"},
    /*27*/{"*BOSS Tera Lord",300,300,45,150,"Mars Phalanx(Dmg 45)","Tera’s queen sword & armor(Hp+90 Atk+70)"}
};
void escape(int a){

    escape_check=rand()%10;
    if(escape_check>6){
        printf("escape success\n");
        found(a);

    }else {
        tester.hp = tester.hp-mon[a].atk;
        if(tester.hp<=0){
                dead(a);}
        printf("cant escape\n");
        printf("result player hp: %d\n mon hp: %d\n",tester.hp,mon[a].hp);
        fight(a);

    }
}

void fight(a){
    while(tester.hp>0 && mon[a].hp>0){
    printf("fighting select choice **out of these mean escape\n");
    fight_action=0;
    printf(" 1:attack\n");
    printf(" 2:def\n");
    printf(" 3:item\n");
    printf(" 4:escape\n");
    scanf(" %d",&fight_action);
        switch (fight_action){
            case 1 : attack(a); break;
            case 2 : defend(a); break;
            case 3 : use_item(); break;
            case 4 : escape(a);break;
            default : escape(a);break;
    }
    }
}
void attack(a){
    mon[a].hp = mon[a].hp-tester.atk;
    tester.hp = tester.hp-mon[a].atk;
    if(mon[a].hp<0) mon[a].hp = 0;
    printf("result player hp: %d\n mon hp: %d\n",tester.hp,mon[a].hp);
    if(tester.hp<=0) dead(a);
    if(tester.hp>0 && mon[a].hp<=0) win(a);

}
void defend(a){
    defend_checker=rand()%10;
    if(defend_checker>4){
        printf("defend success\n");
        tester.hp--;

    }else {
        printf("cant defend\n");
       tester.hp = tester.hp-mon[a].atk;
    }
    if(tester.hp<=0) dead(a);
    printf("result player hp: %d\n mon hp: %d\n",tester.hp,mon[a].hp);

}
void use_item(a){
    tester.hp = tester.hp+100;
    tester.hp = tester.hp-mon[a].atk;
    if(tester.hp<=0) dead(a);
    printf("result player hp: %d\n mon hp: %d\n",tester.hp,mon[a].hp);
}
void dead(a){
    printf("You dead\n");
    printf("You position is 1 hp is %d\n",tester.hp);
    tester.hp = 50;
    mon[a].hp = mon[a].max_hp;
    tester.atk=50;
}
void win(a){
    printf("Congratulation you win \n");
    tester.gold+=mon[a].drop;
    tester.item[6]++;
    printf("You get %d gold and a %s \n",mon[a].drop,mon[a].item);
    printf("Now you have %d gold\n",tester.gold);
}
int equip(int a,int b){
    int eq_hp=a,eq_atk=b;
    tester.hp = tester.hp+eq_hp;
    tester.atk = tester.atk+eq_atk;
printf("You has hp %d and atk %d \n", tester.hp, tester.atk);
}
void found(a){

        printf("found %s(%d hp,%d atk) select choice **out of these mean fight\n",mon[a].name,mon[a].hp,mon[a].atk);
        escape_check=0;
        printf(" 1:fight\n");
        printf(" 2:escape\n");
        scanf(" %d",&action);
        switch (action){
            case 1 : fight(a); break;
            case 2 : escape(a);break;
            default : fight(a); break;
        }
}
int merchant(){
int input;
printf("You come in to buy something select 1 thing to buy **out of these mean nothing\n");
printf("Welcome to my shop\n");
printf("NO. of item   Price\n");
    printf(" 1:potion(+100 hp)   50 gold\n");
    printf(" 2:wooden sword (+10 atk,+50hp)    100 gold\n");
    printf(" 3:iron sword(+25 atk,+100hp)    200 gold\n");
scanf(" %d",&input);
switch (input){
            case 1 : tester.item[0]+=1; tester.gold -= 50; break;
            case 2 : equip(50,10); tester.gold -= 100;break;
            case 3 : equip(100,25); tester.gold -= 200; break;
            default :  break;
        }
printf("%s has %d gold \n",tester.name,tester.gold);
}
void nothing(){
printf("Nothing here let's go");
}
int main()
{
    printf("Input your name:");
    gets(tester.name);
    srand(time(NULL));
    int n = (rand()%27)+1;
    found(n);
}
