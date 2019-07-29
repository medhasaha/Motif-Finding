#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<process.h>
#include<time.h>
#include<bits/stdc++.h>
#define MAX 50
using namespace std;

int maxi = 0;
char ans[7];
int i,j;
int nos[7];
int cc=0;
int nmer=7;
//string str[12];
//string strnew[12];
int a[7];
int c[7];
int g[7];
int t[7];
struct node
{
    char data;
    unsigned endofstring: 1;
    int Count;
    struct node *left, *right, *eq;
};

struct node* newnode(char data)
{
    struct node* root = (struct node*) malloc(sizeof( struct node ));
    root->data = data;
    root->endofstring = 0;
    root->Count = 0;
    root->left = root->right = root->eq = NULL;
    return root;
}

void insert(struct node** root, char* word)
{
    if(!(*root))
        *root = newnode(*word);
    if((*root)->data > (*word))
        insert(&((*root)->left), word);
    else if((*root)->data < (*word))
        insert(&((*root)->right), word);
    else
    {
        if(*(word+1))
            insert(&((*root)->eq), word+1);
        else
            (*root)->endofstring = 1;
    }
}


int search(struct node *root, char *word)
{
    if (!root)
        return 0;

    if (*word < (root)->data)
        return search(root->left, word);

    else if (*word > (root)->data)
        return search(root->right, word);

    else
    {
        while(*(word+1) == '\0')
        {
            root->Count = root->Count + 1;
            return root->endofstring;
        }

        return search(root->eq, word+1);
    }
}

void Mtraverse(struct node* root, char* buffer, int depth)
{
    if (root)
    {
        Mtraverse(root->left, buffer, depth);

        buffer[depth] = root->data;
        if(root->Count > ::maxi)
        {
            ::maxi = root->Count;
            buffer[depth+1] = '\0';
            for(int h=0;h<7;h++)
            {
                ::ans[h] = *(buffer+h);
            }
        }

        Mtraverse(root->eq, buffer, depth + 1);

        Mtraverse(root->right, buffer, depth);
    }
}

void Motiftraverse(struct node* root)
{
    char buffer[MAX];
    Mtraverse(root, buffer, 0);
}

int maxj(int q,int w,int e,int r)
{
    if((q>=w)&&(q>=e)&&(q>=r))
        return q;
    else if((w>=q)&&(w>=e)&&(w>=r))
        return w;
    else if((e>=w)&&(e>=q)&&(e>=r))
        return e;
    else
     return r;
}

COORD coord={0,0};
void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void con(string a1,int i)
{

    if(i==7)
    {
        j=0;
        for(j=0;j<7;j++)
        {
            gotoxy(23+j*2,23+cc);
            cout<<a1[j];
        }
        cc++;
        }
    else
    {
    if(a[i]==maxj(a[i],c[i],g[i],t[i]))
    {
        a1.push_back('A');
        con(a1,i+1);
        a1= a1.substr(0, a1.size()-1);
    }
    if(c[i]==maxj(a[i],c[i],g[i],t[i]))
    {
        a1.push_back('C');
        con(a1,i+1);
        a1= a1.substr(0, a1.size()-1);
    }
    if(t[i]==maxj(a[i],c[i],g[i],t[i]))
    {
        a1.push_back('T');
        con(a1,i+1);
        a1= a1.substr(0, a1.size()-1);
    }
    if(g[i]==maxj(a[i],c[i],g[i],t[i]))
    {
        a1.push_back('G');
        con(a1,i+1);
        a1= a1.substr(0, a1.size()-1);
    }
    }
}



void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
int main()
{
    struct node* root = NULL;
    string word[7];
    string worknew[7];
    int i,j,k = 0;
    system("cls");
    system("color 03");
	gotoxy(25,2);
	cout<<"**************** W E L C O M E  *********************** ";
	gotoxy(25,4);
	cout<<"   *** JAYPEE INSTITUTE OF INFORMATION TECHNOLOGY *** ";
	gotoxy(35,6);

	cout<<"------ M O T I F  F I N D I N G ------ ";
	gotoxy(35,8);
	system("color 0A");
	cout<<" M A D E  B Y :-  ";
	gotoxy(45,10);
	cout<<" Abhishek Dalakoti";
	gotoxy(45,12);
    cout<<" Chhavi Singhal";
    gotoxy(45,14);
    cout<<" Medha Saha";
    gotoxy(45,16);
    cout<<" Dara Nanda Gopala Krishna";
    delay(4000);

    system("cls");
    gotoxy(15,10);
    cout<<"P R O B L E M  S T A T E M E N T ";
    gotoxy(10,14);
    cout<<"Given a set of m DNA sequences each of length n nucleotides ,find the pattern p of length l ";
    gotoxy(10,15);
    cout<<"that is repeated in all the sequences.";
    delay(5000);

    system("cls");
    gotoxy(25,8);
    cout << "E N T E R  D N A  S T R U C T U R E ";

    for(i=0;i<7;i++)
    {
        gotoxy(23,12+i);
        cin >> word[i];
    }

    delay(1500);

    system("cls");
    gotoxy(30,15);
    cout<<" N O R M A L  S E A R C H  I N  P R O G R E S S.........";
    delay(2000);

    for(i=0;i<34;i++)
    {
        string a;
        a = word[0].substr(i,7);

        //cout << a << "\n";
        char* ch;
        ch = (char *)malloc(sizeof(char)*7);
        for(j=0;j<7;j++)
        {
            *(ch+j) = a[j];
            //cout << *(ch+j) << "\t";
        }
        insert(&root, ch);

       // cout << "\n";
    }


    for(i=1;i<7;i++)
    {
        for(j=0;j<34;j++)
        {
            string b;
            b = word[i].substr(j,7);

            //cout << b << "\n";
            char* ch1;
            ch1 = (char *)malloc(sizeof(char)*7);
            for(k=0;k<7;k++)
            {
                *(ch1+k) = b[k];
                //cout << *(ch1+k) << "\t";
            }
            //cout << "\n";
          int out =  search(root, ch1);
        }

    }
    Motiftraverse(root);
    if((maxi+1) == 7)
    {
        system("cls");
        gotoxy(25,6);
        cout << " N O R M A L  S E A R C H  S U C C E S S F U L L .......";
       /* gotoxy(25,8);
        cout << " The l-mer with maximum count\n";*/
        gotoxy(40,10);
        cout << " M O T I F -  ";
        cout <<::ans << endl;
       /* gotoxy(40,14);
        cout << " Count value of Motif -  ";
        cout << ::maxi+1 << endl;*/
    }
    else
    {

        system("cls");
        gotoxy(15,10);
        cout<<"N O R M A L  S E A R C H  failed";
        gotoxy(15,15);
        cout<<"The Genetic Sequence may be mutated so we will have to find a consensus string";
        gotoxy(15,17);
        cout<<"that may correspond to the mutated matrix";
        gotoxy(15,22);
        cout << "Now Motif Could Be Found Using A D V A N C E Search" << endl;
        delay(6500);

        system("cls");
        gotoxy(15,10);
        cout<<"P R O B L E M  S T A T E M E N T ";
        gotoxy(10,14);
        cout<<"Given a set of l-mers, construct the set of most probable consensus strings (motif) through profiling. ";
        delay(5000);

        string wordnew[7];
        for(i=0;i<nmer;i++)
        {
            a[i]=c[i]=g[i]=t[i]=0;
        }

        system("cls");
        gotoxy(25,10);
        cout << "E N T E R  S E Q U E N C E  S E T ";
        for(i=0;i<7;i++)
        {
            gotoxy(25,12+i);
            cin>>nos[i];
        }
        delay(3000);


        system("cls");
        gotoxy(30,15);
        cout<<" A D V A N C E   S E A R C H  I N  P R O G R E S S.........";
        delay(5000);

        for(i=0;i<7;i++)
        {
            wordnew[i] = word[i].substr(nos[i],nmer);
            //cout << wordnew[i] << endl;
        }

        for(i=0;i<7;i++)
        {
            for(j=0;j<nmer;j++)
            {
                char ch=wordnew[i][j];
                if(ch=='T')
                {
                    t[j]++;
                }
                else if(ch=='A')
                {
                    a[j]++;
                }
                else if(ch=='G')
                {
                    g[j]++;
                }
                else if(ch=='C')
                {
                    c[j]++;
                }
            }
        }

        system("cls");
        gotoxy(15,5);
        cout<<" ******* A L I G N M E N T  M A T R I X ******";

        for(i=0;i<7;i++)
        {
            for(j=0;j<nmer;j++)
            {
                gotoxy(23+j*2,7+i);
                cout<<wordnew[i][j];
            }
            cout<<"\n";
        }

        gotoxy(15,8+j);
        cout<<" ******* P R O F I L E  M A T R I X *******";

        gotoxy(19,10+j);
        cout<<" A |";

        gotoxy(23,10+j);
        for(i=0;i<nmer;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<"|"<<endl;

        gotoxy(19,11+j);
        cout<<" C |";

        gotoxy(23,11+j);
        for(i=0;i<nmer;i++)
        {
            cout<<c[i]<<" ";
        }
        cout<<"|"<<endl;

        gotoxy(19,12+j);
        cout<<" G |";

        gotoxy(23,12+j);
        for(i=0;i<nmer;i++)
        {
            cout<<g[i]<<" ";
        }
        cout<<"|"<<endl;

        gotoxy(19,13+j);
        cout<<" T |";

        gotoxy(23,13+j);
        for(i=0;i<nmer;i++)
        {
            cout<<t[i]<<" ";
        }
        cout<<"|"<<endl;
        gotoxy(15,22);
        cout<<" ******* C O N S E N S U S  M A T R I X *******";
        con("",0);


    }
    return 0;
}





