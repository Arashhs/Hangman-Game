#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FILE *fp2;

int word_in_list_number;
char topics[10][100];
float topic_score[5];
float topic_final_score[5];
float topic_high_score[5];

struct node{
char info[50];
struct node *next;
};

void save_game(char *name )
{
    FILE *save;
    save=fopen(name,"wb");
    fwrite(name,sizeof(char),20,save);
    fwrite(topic_high_score,sizeof(float),5,save);
}

void read_save_data(char *name)
{
    FILE *save;
    save=fopen(name,"rb");
    char tmp[20];
    fread(tmp,sizeof(char),20,save);
    fread(topic_high_score,sizeof(float),5,save);

}

void check_quit(char *gamer_name)
{
    printf("\nAre you sure you want to quit? [y/n]\n\n");
        char input2;
    do{
    scanf("%c",&input2);
    }
    while(input2!='n'&&input2!='y');

    if(input2=='n')
    {
        printf("\n\n");
        return;
    }
    else
    {
    printf("\nDo you want to save? [y/n]\n\n> ");
    char input3;
    do{
    scanf("%c",&input3);
    }
    while(input3!='n'&&input3!='y');
    if (input3=='n'){
        printf("\nGoodbye!\n\n");
        exit(0);
    }
    else if(input3=='y')
    {
        save_game(gamer_name);
        printf("\nGoodbye!\n");
        exit(0);
    }
    }
}


void drown_0_of_5(void)
{
FILE *show;
show=fopen("res\\drowning_0_of_5.txt","r");
char c;
while(!feof(show))
{
    c=fgetc(show);
    printf("%c",c);
}


}

void drown_1_of_5(void)
{
FILE *show;
show=fopen("res\\drowning_1_of_5.txt","r");
char c;
while(!feof(show))
{
    c=fgetc(show);
    printf("%c",c);
}


}

void drown_2_of_5(void)
{
FILE *show;
show=fopen("res\\drowning_2_of_5.txt","r");
char c;
while(!feof(show))
{
    c=fgetc(show);
    printf("%c",c);
}


}

void drown_3_of_5(void)
{
FILE *show;
show=fopen("res\\drowning_3_of_5.txt","r");
char c;
while(!feof(show))
{
    c=fgetc(show);
    printf("%c",c);
}


}

void drown_4_of_5(void)
{
FILE *show;
show=fopen("res\\drowning_4_of_5.txt","r");
char c;
while(!feof(show))
{
    c=fgetc(show);
    printf("%c",c);
}


}

void drown_5_of_5(void)
{
FILE *show;
show=fopen("res\\drowning_5_of_5.txt","r");
char c;
while(!feof(show))
{
    c=fgetc(show);
    printf("%c",c);
}


}




int random(int n)
{
    int random_number = (rand())%n; //Too bazeye [0 , 1) dar miad //res: adadi sahih ozve {0 , 1 , ... , n-1}
    return random_number;
}

struct node * create_node(char word[49]){
struct node * nn;
nn = (struct node *) malloc(sizeof(struct node));
strncpy(nn->info,word,49);
nn->next = NULL;
return nn;
}

void add_end(struct node *list, struct node *new_node)
{
    struct node *current;
    for(current = list; current->next!=NULL; current=current->next);
    current->next=new_node;
    new_node->next=NULL;
}

void delete_first(struct node **plist)
{
    struct node *current;
    current= *plist;
    current=current->next;
    free(plist);
    *plist=current;
}

void delete_selected_word(struct node **plist,int word_number, int number_of_words)
{
    if (word_number==0)
        {
            struct node * current = *plist;
            current=current->next;
            *plist=current;
        }
    else if(word_number<number_of_words-1)
    {
        struct node *list=*plist;
        int i;
        struct node *current=list;
        struct node *tmp;
        for(i=1;i<word_number;current=current->next,i++);
        tmp=current->next->next;
        free(current->next);
        current->next=tmp;
    }
    else
    {
        struct node *list=*plist;
        struct node *current=list;
        while(current->next->next != NULL)
        current = current->next;
        free(current->next);
        current->next = NULL;
    }
}



void show_topics()
{
    FILE *fp;
    printf("Choose one topic:\n\n");
    fp=fopen("res\\TOPICS\\AVAILABLE_TOPICS.txt","r");
    if(fp==NULL)
        printf("Error opening AVAILABLE_TOPICS.txt");
    int i;
    char tmp[10];
    for(i=0;!feof(fp);i++)
    {
        fgets(topics[i],50,fp);
    }
    int i1,i2;
    for(i1=0;i1<i;i1++)
    {
        i2=strlen(topics[i1]);
        tmp[i1]=topics[i1][i2-5];
        topics[i1][i2-5]='\0';
    }
    for(i1=0;i1<i;i1++)
        printf("[%c] %s\n\n",i1+97,topics[i1]);
    for(i1=0;i1<i;i1++)
    {
        i2=strlen(topics[i1]);
        topics[i1][i2]=tmp[i1];
    }
    fclose(fp);

}

struct node *select_word_number(struct node *list ,int num)
{
word_in_list_number = random(num);
 int i;
 struct node * current;
 current=list;
 for(i=0;i<word_in_list_number;i++)
 {
     current=current->next;
 }
 return current;
}

void play_turn(struct node * selected_node,int char_to_int,char *gamer_name)
{
    float turn_score;
    int win=strlen(selected_node->info),check_lose=5,check_win=0;
    char guess;
    char word[50]={'\0'};
    int i;
    for(i=0;i<strlen(selected_node->info);i++)
    {
        word[i]='-';
    }
    int first_use=0;
            if(first_use==0)
        {
            printf("\n");
                drown_0_of_5();
                first_use++;
        }
    printf("\n%s",word);
    int check_more_than_one;
    while(1)
    {
        printf("\n\n> ");
        scanf("\n%c",&guess);
        if(guess=='Q')
        {
            check_quit(gamer_name);
            scanf("\n%c",&guess);
        }

        if((strchr(selected_node->info,guess)!=NULL)&&(check_win<win))
        {
            check_more_than_one=0;
            for(i=0;i<strlen(selected_node->info);i++)
            {
                if((selected_node->info[i]==guess) && (word[i]=='-'))
                    {
                    word[i]=guess;
                    check_win++;
                }

            }
            if(check_win>=win)
                {
                printf("\nCorrect! The word was %s.\n",selected_node->info);
                turn_score = (3 * strlen(selected_node->info)) - (5-check_lose);
                topic_score[char_to_int]=topic_score[char_to_int]+turn_score;
                break;
                }
            printf("\nCorrect! (%d,%d)\n\n%s",check_lose,5,word);
        }

         else if(check_win>=win){
            printf("\nCorrect! The word was %s.\n",selected_node->info);
            turn_score = (3 * strlen(selected_node->info)) - (5-check_lose);
            topic_score[char_to_int]=topic_score[char_to_int]+turn_score;
            break;
        }

        else
        {
            if(first_use==1){
                drown_1_of_5();
            }
            if(first_use==2){
                drown_2_of_5();
            }
            if(first_use==3){
                drown_3_of_5();
            }
            if(first_use==4){
                drown_4_of_5();
            }
            if(--check_lose!=0)
            {
            printf("\nWrong! (%d,%d)\n\n%s",check_lose,5,word);
            }
            else
            {
            drown_5_of_5();
            printf("\nWrong!(0/5) you lost. The word was %s.\n", selected_node->info);
            break;
            }
            first_use++;
        }
    }

}


float topic_select(char c,char *gamer_name)
{
    int char_to_int=(int)c-97;
    topic_score[char_to_int]=0;
    switch(c){
        case 'a':
            fp2=fopen("res\\TOPICS\\fruits.txt","r");
            break;
        case 'b':
            fp2=fopen("res\\TOPICS\\soccer_players.txt","r");
            break;
        case 'c':
            fp2=fopen("res\\TOPICS\\programming_languages.txt","r");
            break;
        case 'd':
            fp2=fopen("res\\TOPICS\\computer_networks.txt","r");
            break;
        case 'e':
            fp2=fopen("res\\TOPICS\\video_games.txt","r");
            break;
    }
    int i,check=0,check_2;
    char tmp[50],tmp2,tmp3[20]="aa";
    struct node *list, *current;
    current=create_node("temp");
    for(check_2=0;!feof(fp2);check_2++)
    {
        i=0;
        while(tmp2=fgetc(fp2))
        {
            if(feof(fp2))
            {
                check=1;
                break;
            }
            if(tmp2==' ')
                break;
            tmp[i]=tmp2;
            i++;
        }
        if(check==1)
            break;
        tmp[i]='\0';
        current->next=create_node(tmp);
        current=current->next;
        if(check_2==0)
            list=current;
    }
    while(check_2>1){
    struct node * select_word = select_word_number(list,check_2); //check_2 tedade kalamate liste
    play_turn(select_word,char_to_int,gamer_name);
    delete_selected_word(&list, word_in_list_number ,check_2);
    check_2--;
    }
    play_turn(list,char_to_int,gamer_name);
    free(list);

}



int main()
{
    srand(time(NULL));
    clock_t begin, end;
    double time_spent;
    printf("Enter your name:\n\n> ");
    char gamer_name[20];
    gets(gamer_name);
    printf("\n\nWelcome %s!\n\n", gamer_name);
    printf("[1] new game\n\n[2] resume game\n\n> ");
    char input_tmp;
    do{
        scanf("%c",&input_tmp);}while(input_tmp!='1' && input_tmp!='2');
    if(input_tmp=='2')
        read_save_data(gamer_name);
    int char_to_int;
    while(1){
    show_topics();
    char select_topic;
    printf("> ");
    do{
    scanf("%c", &select_topic);
        if(select_topic=='Q')
        check_quit(gamer_name);
    }while(select_topic==' '|| select_topic=='\r' || select_topic=='\n'||select_topic=='Q');
    char_to_int=(int)select_topic-97;
    printf("\nGame started!\n");
    begin = clock();  //Starte timer
    topic_select(select_topic,gamer_name);
    end = clock();  //Payane timer
    time_spent = ((double)(end - begin)) / CLK_TCK;
    topic_final_score[char_to_int]=topic_score[char_to_int]/((float)time_spent);
    printf("\n\n\nTopic score: Total score = %f\n\nTime = %lf\n\nFinal score = %f\n\n",topic_score[char_to_int],time_spent,topic_final_score[char_to_int]);
    if(topic_final_score[char_to_int]>topic_high_score[char_to_int])
    {
        topic_high_score[char_to_int]=topic_final_score[char_to_int];
        printf("New topic highscore! %f\n\n\n",topic_high_score[char_to_int]);
    }
    else
        printf("Current topic highscore: %f\n\n\n", topic_high_score[char_to_int]);

    printf("Do you want to quit? [y/n]\n\n> ");
    char input2;
    do{
    scanf("%c",&input2);
    }
    while(input2!='n'&&input2!='y');

    if(input2=='n')
    {
        printf("\n\n");
        continue;
    }
    else
    {
    printf("\nDo you want to save? [y/n]\n\n> ");
    char input3;
    do{
    scanf("%c",&input3);
    }
    while(input3!='n'&&input3!='y');
    if (input3=='n'){
        printf("\nGoodbye!\n\n");
        exit(0);
    }
    else if(input3=='y')
    {
        save_game(gamer_name);
        printf("\nGoodbye!\n");
        exit(0);
    }
    }
    }
    return 0;
}
