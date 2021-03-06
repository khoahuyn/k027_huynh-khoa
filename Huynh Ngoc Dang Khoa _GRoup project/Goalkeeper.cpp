#include "Player.cpp"
class Goalkeeper:public Player
{
	private:
	string reflexesAble;
	int numOfKeptCleanSheet;
	int goalSaveRate;
	public:
	void setReflexesAble(string reflexesAble)
	{
	    this->reflexesAble=reflexesAble;
	}
	string getReflexesAble()
	{
	    return this->reflexesAble;
	}
	void setNumOfKeptCleanSheet(int numOfKeptCleanSheet)
	{
	    this->numOfKeptCleanSheet=numOfKeptCleanSheet;
	}
	int getNumOfKeptCleanSheet()
	{
	    return this->numOfKeptCleanSheet;
	}
	void setGoalSaveRate(int goalSaveRate)
	{
	    this->goalSaveRate=goalSaveRate;
	}
	int getGoalSaveRate()
	{
	    return this->goalSaveRate;
	}
	Goalkeeper()
	{
		
	} 
	Goalkeeper(string idMembers,string contractTerm,int idCardNumber,string fullName,int age,long long salary,int numberOfShirt,int Appearance,int numOfYellowCard,int numOfRedCard,int techniqueStat,int assistNumInSeason,int goalsNumInSeason,float height,float weight,string injury,string position,	string reflexesAble,int numOfKeptCleanSheet,int goalSaveRate):Player(idMembers,contractTerm,idCardNumber,fullName,age,salary,numberOfShirt,Appearance,numOfYellowCard,numOfRedCard,techniqueStat,assistNumInSeason,goalsNumInSeason,height,weight,injury,position) {
		this->reflexesAble=reflexesAble;
		this->numOfKeptCleanSheet=numOfKeptCleanSheet;
		this->goalSaveRate=goalSaveRate ;
	}
	void input()
	{
		Player::input();
		cout<<"Enter the reflexesAble:";
		getline(cin,this->reflexesAble);
		cout<<"Enter the numOfKeptCleanSheet:";
		cin>>this->numOfKeptCleanSheet;
		cout<<"Enter the goalSaveRate:";
		cin>>this->goalSaveRate;
	}
	void output()
	{
		Player::output();
		cout<<"reflexesAble:"<<this->reflexesAble<<endl;
		cout<<"numOfKeptCleanSheet:"<<this->numOfKeptCleanSheet<<endl;
		cout<<"goalSaveRate:"<<this->goalSaveRate<<endl;
	}
	string mission()
	{
		string a="\nThe main task is to keep a clean sheet\n";
		return a;
		string b="\nYou should also be good at playing with your feet to help with ball rotation\n";
		return b;
	}
	long long calculateWage()
	{
		long long bonus,wage,salary;
		if(this->goalSaveRate>8 ||this->reflexesAble=="good")
		{
			salary=3000000;
		}else if(this->goalSaveRate>6 ||this->reflexesAble=="normal")
		{
			salary=1800000;
		}else
		{
			salary=1000000;
		}
		for(int i=1;i<this->numOfKeptCleanSheet;i++)
		{
			bonus+=100000;
		}
		wage=bonus+salary;
		cout<<"\nThe total bonus is:";
		return wage;
	}
	bool signingCondition()
	{
		if(this->getAppearance()<5 ||this->getHeight()<1.8 )
		{
			return false;
			cout<<"\nUnsatisfactory\n";
		}else
		{
			return true;
			cout<<"\nShould sign a contract with them\n";
		}
	}
	void riskOfTerminateContract()
	{
		if(this->goalSaveRate<5 || this->reflexesAble=="bad" || this->numOfKeptCleanSheet<6)
		{
			cout<<"\nFull contract termination is possible\n";
		}else if(this->goalSaveRate<7 || this->reflexesAble=="normal" || this->numOfKeptCleanSheet<8)
		{
			cout<<"\nContract termination is unlikely\n";
		}else
		{
			cout<<"\nTermination of the contract cannot happen\n";
		}
	}
	void oppRenewContract()
	{
		if(this->goalSaveRate<9 || this->reflexesAble=="good" || this->numOfKeptCleanSheet<10)
		{
			cout<<"\nMost likely will sign a contract extension\n";
		}else if(this->goalSaveRate<7 || this->reflexesAble=="normal" || this->numOfKeptCleanSheet<8)
		{
			cout<<"\nExtension may be considered\n";
		}else
		{
			cout<<"\nUnable to extend\n";
		}
	}
	
};

