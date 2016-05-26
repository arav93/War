#include<iostream>
#include<vector>
#include <stdlib.h> /*srand,rand */
#include <time.h>  /*time */

using namespace std;

vector<int> A;
vector<int> B;
vector<string> Name;

void init_army(vector<float>& ArmyA,int size)
{
    int army_1 = rand()%(size-2)+1;  //Minimum one person present in each position
    ArmyA.push_back(army_1);
    int army_2 = rand()%(size-army_1-1)+1;
    ArmyA.push_back(army_2);
    int army_3 = size - army_1-army_2;
    ArmyA.push_back(army_3);


}

void copyVal(vector<float> P, vector<float> Q)
{
    for(int i=0;i<3;i++)
    {
        A.push_back(P[i]);
        B.push_back(Q[i]);
    }

    Name.push_back("Swordsmen");
    Name.push_back("Foot-Soldiers");
    Name.push_back("Archers");
}

void display(vector<float> ArmyA, vector<float> ArmyB)
{
    cout<<"Army A report:\n";
    for(int i=0;i<3;i++)
    {
        cout<<((ArmyA[i])/A[i])*100<<"% health for the "<<Name[i]<<endl;
    }
    cout<<"Army B report:\n";
    for(int i=0;i<3;i++)
    {
        cout<<((ArmyB[i])/B[i])*100<<"% health for the "<<Name[i]<<endl;
    }
}

void start(vector<float> &A , vector<float> &B)
{
    B[0]=B[0]-0.5*A[0]-0.2*A[1]-0.1*A[2];
    B[1]=B[1]-0.8*A[0]-0.5*A[1]-0.2*A[2];
    B[2]=B[2]-0.8*A[0]-0.2*A[1]-0.5*A[2];

    if(B[0]<0)
        B[0]=0;
    if(B[1]<0)
        B[1]=0;
    if(B[2]<0)
        B[2]=0;

}

bool isDead(vector<float> &A)
{
    return (A[0]<=0 && A[1]<=0 && A[2]<=0);
}

void fight(vector<float> &A, vector<float> &B)
{

    while(!isDead(A)&&!isDead(B))
    {
        start(A,B);
        display(A,B);
        start(B,A);
        display(A,B);
    }

    if(isDead(A))
        cout<<"B won the fight!";
    else
        cout<<"A won the fight!";


}

int main()
{

    int size;
    srand((int)time(0));
    vector<float> ArmyA;  //A and B are the different armies
    vector<float> ArmyB;
    cout<<"Enter the size of the army:\n->";
    cin>>size;
    init_army(ArmyA,size);
    init_army(ArmyB,size);
    copyVal(ArmyA,ArmyB);
    fight(ArmyA,ArmyB);
    return 0;
}
