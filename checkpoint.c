#include <stdio.h>

int checkpoint[10];
int top = -1;

void saveCheckpoint(int score){
    checkpoint[++top] = score;
}

void loadCheckpoint(){
    if(top > 0)
        top--;
}

int main(){
    saveCheckpoint(500);
    saveCheckpoint(1200);
    saveCheckpoint(2000);

    loadCheckpoint();

    printf("Player Restored Score: %d", checkpoint[top]);
    return 0;
}
