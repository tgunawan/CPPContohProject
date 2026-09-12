// Love your self
// Tycoon Gold mine
//pABRUK mAKE STUFF TO SELL FOR CASH
//USE CASH LVL UP MORE CASH

//upgrade to make more cash,more mines to use
//market price fluctuates
//pause while mining for selling

#include<iostream>
#include<string>
#include<random>
#include<vector>
#include<chrono>
#include<thread>
#include<mutex>
#include <future>

using namespace std;
mutex mx;
float marketPrice = 10.0f;
//Upgrades
bool drillsnum[5]={true,false,false,false,false};
int drillspeed[5]={1,3,1,1,1};
int cpers=1;
struct pabric{
    int cash=0;
    int gold=0;
};
//int Load(A){
//	for(int i = O;i<A)
//    #ifdef _WIN32
//        system("cls");
//    #else
//        system("clear");
//    #endif
//    chrono::seconds(1)
//    return 0;
//}
void Coingen(pabric& Mines,int A){

    cout<<"Minning"<<endl;
    this_thread::sleep_for(chrono::seconds(A));
    {	lock_guard<mutex> lock(mx);
    	Mines.gold += 1;
	}
    cout<<"You have made 1 H@n)s0meJ0s3phy Coin"<<endl;
}
void dsupgrade(pabric& Mines){
	if (Mines.cash>=20){
		Mines.cash-=20;
		drillspeed[1]++;
		cout<<"Yourdrill has been upgrade!"<<endl;
	}
	else{
		cout<<"Not Enough Cash To Upgrade"<<endl;
	}
}
void cpersupgrade(pabric& Mines){
		if (Mines.cash>=200){
		Mines.cash-=200;
		cpers++;
		cout<<"Yourdrill has been upgrade!"<<endl;
	}
	else{
		cout<<"Not Enough Cash To Upgrade"<<endl;
	}

}
void moredrill(){
	if (Mines.cash>=250){
		int x = 0;
		for(int i=0;i<5;i++){
			if (drillsnum[i]==true){
				x++;
			}
		}
		drillsnum[x]=true;
		cout<<"You Have a New Drill!"<<endl;
	}
	else{
		cout<<"Not Enough Cash To Upgrade"<<endl;
	}

}
void mine(pabric& Mines,int A){
    thread gold(Coingen,ref(Mines),A);
}

void Sell(pabric& Mines){
    Mines.cash+=Mines.gold*marketPrice;
    cout<<"You have sold "<<Mines.gold<<" H@n)s0meJ0s3phy Coins for $"<<Mines.gold*marketPrice<<endl;
}
int main(){

    cout<<"Welc0M3 tO E**9*l H*nd*0meJO$**hy Si*uL*Ti*N"<<endl;
    cout<<"Lets Continue The last yOU kNOW Dr *******"<<endl;
    cout<<"Wait, Your acc has been terminated Welp gtg make a new one"<<endl;
    cout<<"Enter YOur new Name: MR. ";
    string name;
    cin>>name;
    cout<<"Oh WOW DR "<<name<<" What a nice name"<<endl;
    cout<<"Now lets get started with your new acc"<<endl;
    
    pabric Mines;
    Mines.cash = 0;
    Mines.gold = 0;
    while(true){
        cout<<"What Whould you like to do? (1) Mine Gold (2) Sell Coin (3) Upgrade (4) Exit"<<endl;
        int choice;
        cin>>choice;
        if(choice==1){
        	vector<thread> miningthread;
        	for(int i=0;i<5;i++){
				if (drillsnum[i]==true){
					miningthread.emplace_back(Coingen,ref(Mines),11-drillspeed[i]);	
    			}
			} 
			for (thread& mines:miningthread){
				mines.join();
			}
        }
        else if(choice==2){
            Sell(Mines);    
        }
        else if(choice==3){
        	cout<<"What Whould you like to Upgrade? (1) DrillSpeed (20$) (2) More Coin (200$) (3) Buy a NEW DRILL (250$) (4) Exit"<<endl;
        	cin>>choice;
        	if(choice==1){
        		dsupgrade(Mines);        		
			}
			else if(choice==2){
				cpersupgrade(Mines);
			}
			else if(choice==3){
				moredrill();
			}
            //cout<<"Upgrade drill " n<<endl;
            //cout<<"Buy New drill"
        }
        else if(choice==4){
            cout<<"Exiting the game. Goodbye!"<<endl;
            break;
        }
        else{
            cout<<"Invalid choice. Please try again."<<endl;
        }
    }
    
    return 0;
}
