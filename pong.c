#include <stdio.h>

#define W 80
#define H 25

void start();
void field(int *count_r, int *count_l, int *r_tacket, int *l_racket, int *ball_x, int *ball_y);
void rackets(int *r_racket, int *l_racket, int *flag);
void ball(int *ball_x, int *ball_y, int *r_racket, int *l_racket, int *Vx, int *Vy);
void count(int *ball_x, int *count_r, int *count_l);

int main() {
    int count_r = 0, count_l = 0;
    int r_racket = 12, l_racket = 12;
    int ball_x = 40, ball_y = 12;
    int Vx = 1, Vy = 1;
    int flag = 1;
    start();
    while((count_l < 21 || count_l < 21) && flag) {
    field(&count_r, &count_l, &r_racket, &l_racket, &ball_x, &ball_y);
    rackets(&r_racket, &l_racket, &flag);
    ball(&ball_x, &ball_y, &r_racket, &l_racket, &Vx, &Vy);
    count(&ball_x, &count_r, &count_l);
    }
    return 0;
}

void start() {
    char key;
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            if(x == 37 && y == 12)
                printf("Hello");
            else
                printf(" ");
        }
        printf("\n");
    }
    key = getchar();
}

void field(int *count_r, int *count_l, int *r_racket, int *l_racket, int *ball_x, int *ball_y) {
    printf("\033[1m\033[0d\033[2J");
   for (int y = 0; y < H; y++) {;
        for (int x = 0; x < W; x++) {
            if (x == W / 4 && y == H - 22)
                printf("%d",*count_l); //счет левого игрока 
            else if (x == W - 20 && y == H - 22)
                printf("%d",*count_r); //счет правого игрока
            else if (x == *ball_x && y == *ball_y)
                printf("o"); //отрисовка мячика
            else if(y == H - 1 && x != 0 && x != W - 1)
                printf("‾"); //нижняя граница
            else if (y == 0 && x != 0 && x != W - 1)
                printf("_"); //верхняя граница
            else if ((x == 0 && y != 0 && y != H - 1) || (x == W - 1 && y != 0 && y != H - 1))
                printf("|"); //левая и правая границы
            else if ((x == 1 && y == *l_racket) || (x == 1 && y == *l_racket + 1) || (x == 1 && y == *l_racket - 1))
                printf("["); //отрисовка левой ракетки
            else if ((x == W - 2 && y == *r_racket) || (x == W - 2 && y == *r_racket + 1) || (x == W - 2 && y == *r_racket - 1))
                printf("]"); //отрисовка правой ракетки
            else
                printf(" ");
            }
        printf("\n");
        }
    }

    void rackets(int *r_racket, int *l_racket, int *flag) {
        char button;
        scanf("%c\n",&button);
        if (button == 'a' || button == 'A') {
            if (*l_racket - 2 != 0)
            (*l_racket)--;
        }
        if (button == 'z' || button == 'Z') {
            if (*l_racket + 2 != 24)
            (*l_racket)++;
        }
        if (button == 'k' || button == 'K') {
            if (*r_racket - 2 != 0)
            (*r_racket)--;
        }
        if (button == 'm' || button == 'M') {
            if (*r_racket + 2 != 24)
            (*r_racket)++;
        }
        if (button == 'q' || button == 'Q') {
            *flag = 0;
        }
    }

    void ball(int *ball_x, int *ball_y, int *r_racket, int *l_racket, int *Vx, int *Vy) {
        if (*ball_x == 1 || *ball_x == W - 2) { //возвращение мяча в центр после гола
            *ball_x = 39;
            *ball_y = 11;
        }
        else if (*ball_y == 1 || *ball_y == H - 2)
            *Vy *= -1; //отскок мяча от нижней и верхней стенки
        else if ((*ball_y == *l_racket - 1 && *ball_x == 2) || (*ball_y == *l_racket && *ball_x == 2) || (*ball_y == *l_racket + 1 && *ball_x == 2))
            *Vx *= -1; //отскок мяча от левой ракетки
        else if ((*ball_y == *r_racket - 1 && *ball_x == 77) || (*ball_y == *r_racket && *ball_x == 77) || (*ball_y == *r_racket + 1 && *ball_x == 77))
            *Vx *= -1; //отскок мяча от правой ракетки
        *ball_x += *Vx; //общее движение мяча
        *ball_y += *Vy;  
    }

    void count(int *ball_x, int *count_r, int *count_l) {
        if(*ball_x == 1)
            (*count_r)++;
        if(*ball_x == 78)
            (*count_l)++; 
    }