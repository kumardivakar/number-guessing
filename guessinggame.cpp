#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int  secret_num(){
    srand(time(0));
    return (rand()%10+1);
}

bool game_over(int guess){
    int secret=secret_num();
    if(secret==guess){
        return true;
    }
    return false;
}
int main(){
    int num,i=0;
    int attempt;
    
    cout<<"Guess a number b/w 1 and 10... "<<endl;
    cout<<"Attempts you want: ";
    cin>>attempt;
    while(attempt<=0 || attempt>=10){
        cout<<"Choose attempt b/w 1 and 9."<<endl;
        cin>>attempt;
    }
    int n=attempt;
    int arr[attempt]={0};
    cout<<"Toatal Attempt: "<<attempt<<endl;
    while(attempt>0){
        cout<<"Guess: "<<endl;
        cin>>num;
        arr[i++]=num;
        if(game_over(num)==1){
            cout<<"Congrats!!!"<<"You guessed in "<<(n+1-attempt)<<" attempts."<<endl;
            attempt--;
            break;
        }
        else{
            attempt--;
            cout<<"Wrong Guess!!\n...............\nTry Again."<<endl;
            cout<<"Attempt Remaining : "<<attempt<<endl;
        }
    }
    
    if(attempt==0){
        cout<<"Oops!! Ran out of Attempt!!"<<endl;
        cout<<"The Secret number is: "<<secret_num()<<endl;
    }
    cout<<"Your Guess.."<<endl;
    for(int i=0;i<(n-attempt);i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}