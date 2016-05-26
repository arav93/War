/*

In this war, the are 3 kind of people involved : Swordsemen, Foot-Soldier and Archer. The harm they cause is also in that order. 
Here, it's assumed that if two people of the same kind fight, 50% of harm is done for both. 20% harm is done, if someone just below
attacks and 10% harm if the one below that attacks. At regular intervals, the overall health percentage of the entire set is shown

NOTE: Only Swordsmen, Foot-Soldier and Archers are considered here. It's possible to add more easily.
*/

#include<iostream>
#include<vector>
#include <stdlib.h> /*srand,rand */
#include <time.h>  /*time */

using namespace std;

vector<int> A;
vector<int> B;
vector<string> Name;

void init_army(vector<float>& ArmyA,int size)
/*
Minimum one person present in each position i.e. atleast 1 Swordsman, 1 Foot-Soldier and 1 Archer
*/
{
    int army_1 = rand()%(size-2)+1;  
    ArmyA.push_back(army_1);
    int army_2 = rand()%(size-army_1-1)+1;
    ArmyA.push_back(army_2);
    int army_3 = size - army_1-army_2;
    ArmyA.push_back(army_3);


}

void copyVal(vector<float> P, vector<float> Q)
/*
This function is to copy the initial values to print the percentage.
*/
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
/*
The reports are displayed here
*/
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
/*
Here the health deteroriation occurs. Once health becomes 0, that set cannot attack 
i.e. If Swordsmen of Army has health = 0.0% there can be no more attacks to or from Swordsmen of Army A
*/
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
/*
Here, we check if the all the members of a particular Army is dead or not
The other army wins if this occurs
*/
{
    return (A[0]<=0 && A[1]<=0 && A[2]<=0);
}

string fight(vector<float> &A, vector<float> &B)
{

    while(!isDead(A)&&!isDead(B))
    {
        start(A,B);
        display(A,B);
        start(B,A);
        display(A,B);
    }

    if(isDead(A))
        return "B won the fight!";
    else
        return "A won the fight!";
}

int main()
{

    int size;
    srand((int)time(0));
    vector<float> ArmyA;  //A and B are the different armies
    vector<float> ArmyB;
    cout<<"Enter the size of the army:\n->"; //Here, the total number of people in an army is obtained.
    cin>>size;
    init_army(ArmyA,size);
    init_army(ArmyB,size);
    copyVal(ArmyA,ArmyB);
    string result= fight(ArmyA,ArmyB);
    cout<<result;
    return 0;
}
