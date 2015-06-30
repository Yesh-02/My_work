#include<iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
    struct Node *snake;
    struct Node *ladder;
}*head;
int no_of_players;
static struct Node *tail = head;
struct Node *player[100];
struct Node* createBoard(int data)
{
    static struct Node *sHead = head;
    struct Node *nNode = new Node();
    if(sHead == NULL)
    {
        nNode->data = data;
        nNode->next = NULL;
        nNode->snake = NULL;
        nNode->ladder = NULL;
        nNode->prev = NULL;
        sHead=nNode;
        tail=nNode;
    }
    else
    {
        nNode->data = data;
        nNode->next = NULL;
        nNode->snake = NULL;
        nNode->ladder = NULL;
        tail->next = nNode;
        nNode->prev = tail;
        tail=tail->next;
    }
    return sHead;
}
struct Node* createSnakeAndLadder(int first, int last, int isSnake)
{
    struct Node *start = head, *end = head;
    if (first == last)
    {
        cout<<"Start and end cannot be the same\nRETRY:\n";
        int start,end;
        cout<<"start:";
        cin>>start;
        cout<<"end:";
        cin>>end;
        head = createSnakeAndLadder(start - 1,end - 1 ,isSnake);
        return head;
    }
    else if(first < last && isSnake == 1)
    {
        cout<<"Snake can only decrement your position\nRETRY:\n";
        int start,end;
        cout<<"start of Snake:";
        cin>>start;
        cout<<"end of snake:";
        cin>>end;
        head = createSnakeAndLadder(start - 1,end - 1 ,1);
        return head;
    }
    else if(first > last && isSnake == 0)
    {
        cout<<"Ladder can only increment your position\nRETRY:\n";
        int start,end;
        cout<<"start of ladder:";
        cin>>start;
        cout<<"end of ladder:";
        cin>>end;
        head = createSnakeAndLadder(start - 1,end - 1 ,0);
        return head;
    }
    while(first--)
        start = start->next;
    while(last--)
        end = end->next;
    cout<<"start:"<<start->data<<endl;
    cout<<"end:"<<end->data<<endl;
    if(isSnake == 1)
        if(start->ladder == NULL)
            start->snake = end;
        else
        {
            cout<<"ladder already exists at this posistion \nRETRY:"<<endl;
            int start,end;
            cout<<"start of Snake:";
            cin>>start;
            cout<<"end of snake:";
            cin>>end;
            head = createSnakeAndLadder(start - 1,end - 1 ,1);
            return head;
        }
    else
        if(start->snake == NULL)
            start->ladder = end;
        else
        {
            cout<<"snake already exists at this posistion\nRETRY:\n"<<endl;
            int start,end;
            cout<<"start of ladder:";
            cin>>start;
            cout<<"end of ladder:";
            cin>>end;
            head = createSnakeAndLadder(start - 1,end - 1 ,0);
            return head;
        }
    return head;
}
void printBoard()
{
    struct Node *temp = tail,*temp1;
    for(int i=5;i>0;i--)
    {
        for(int j=0;j<10;j++)
        {
            cout<<temp->data;
            for(int i=1;i<=no_of_players;i++)
                if(player[i] == temp)
                    cout<<' '<<i;
            cout<<"\t\t";
            temp=temp->prev;
        }
        cout<<endl;
        for(int j=0;j<9;j++)
        {
            temp=temp->prev;
        }
        temp1=temp;
        for(int j=0;j<10;j++)
        {
            cout<<temp1->data;
            for(int i=1;i<=no_of_players;i++)
                if(player[i] == temp1)
                    cout<<' '<<i;
            cout<<"\t\t";
            temp1=temp1->next;
        }
        temp=temp->prev;
        cout<<endl;
    }
}
int main()
{
    int No_of_snakes, No_of_ladders, boardSize = 1, val, winner;
    struct Node *temp;
    cout<<"enter the number of snakes:"<<endl;
    cin>>No_of_snakes;
    cout<<"enter the number of ladders:"<<endl;
    cin>>No_of_ladders;
    cout<<"enter the number of players:"<<endl;
    cin>>no_of_players;
    while(boardSize <= 100)
    {
        head = createBoard(boardSize);
        boardSize++;
    }
    for(int i = 1; i <= no_of_players; i++)
        player[i] = NULL;
    printBoard();
    while(No_of_snakes--)
    {
        int start,end;
        cout<<"start of snake "<<No_of_snakes+1<<" :";
        cin>>start;
        cout<<"end of snake "<<No_of_snakes+1<<" :";
        cin>>end;
        head = createSnakeAndLadder(start - 1,end - 1 ,1);
    }
    while(No_of_ladders--)
    {
        int start,end;
        cout<<"start of ladder "<<No_of_ladders+1<<" :";
        cin>>start;
        cout<<"end of ladder "<<No_of_ladders+1<<" :";
        cin>>end;
        head = createSnakeAndLadder(start - 1,end - 1 ,0);
    }
    srand(0);
    while(1)
    {
        int i;
        for(i=1;i<=no_of_players;i++)
        {
            temp = player[i];
            cout<<"Player "<<i<<"'s Turn.."<<endl;
            val = (rand()%6)+1;
            cout<<"rolling Dice"<<endl;
            cout<<"number is : "<<val<<endl;
            if(temp == NULL && val == 1)
                temp = head;
            else if(temp == tail)
            {
                winner = i;
                goto exit;
            }
            else if(temp != NULL)
            {
                for(int x=0;x<val;x++)
                    temp=temp->next;
                if(temp == NULL)
                    continue;
            }
            else
                continue;
            if(temp->snake != NULL)
            {
                temp=temp->snake;
                cout<<"OOPS!! you found a snake\n";
            }
            if(temp->ladder != NULL)
            {
                temp = temp->ladder;
                cout<<"YAY!! you found a Ladder\n";
            }
            player[i] = temp;
            printBoard();
            if(temp == tail)
            {
                winner = i;
                goto exit;
            }
        }
        i=1;
    }
exit:
    cout<<"Winner is player "<<winner<<endl;
    return 0;
}