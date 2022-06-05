#include "Player.cpp"
class Defender:public Player
{
	private:
	string tackleAbility;
	string defense1vs1;
	string offsideTrap;
	public:
	void setTackleAbility(string tackleAbility)
	{
	    this->tackleAbility=tackleAbility;
	}
	string getTackleAbility()
	{
	    return this->tackleAbility;
	}
	void setDefense1vs1(string defense1vs1)
	{
	    this->defense1vs1=defense1vs1;
	}
	string getDefense1vs1()
	{
	    return this->defense1vs1;
	}
	void setOffsideTrap(string offsideTrap)
	{
	    this->offsideTrap=offsideTrap;
	}
	string getOffsideTrap()
	{
	    return this->offsideTrap;
	}
	Defender()
	{
		
	} 
	Defender(string idMembers,string contractTerm,int idCardNumber,string fullName,int age,long long salary,int numberOfShirt,int Appearance,int numOfYellowCard,int numOfRedCard,int techniqueStat,int assistNumInSeason,int goalsNumInSeason,float height,float weight,string injury,string position,string escapeOffside,	string penaltyAble,	string combiWithOther,	int numOfGodenGoals):Player(idMembers,contractTerm,idCardNumber,fullName,age,salary,numberOfShirt,Appearance,numOfYellowCard,numOfRedCard,techniqueStat,assistNumInSeason,goalsNumInSeason,height,weight,injury,position) {
		this->tackleAbility=tackleAbility;
		this->defense1vs1=defense1vs1;
		this->offsideTrap=this->offsideTrap ;
	}
	void input()
	{
		Player::input();
		cout<<"Enter the tackleAbility :";
		getline(cin,this->tackleAbility);
		cout<<"Enter the defense1vs1:";
		getline(cin,this->defense1vs1);
		cout<<"Enter the offsideTrap :";
		getline(cin,this->offsideTrap);
	}
	void output()
	{
		Player::output();
		cout<<"tackleAbility:"<<this->tackleAbility<<"  "<<"defense1vs1:"
		<<this->defense1vs1<<"  "<<"offsideTrap:"<<this->offsideTrap<<endl;
	}
	string mission()
	{
		string a="\nThe main task is not to let the opponent pass\n";
		return a;
		string b="\nYou should also be good at playing with your feet to help escape pressing\n";
		return b;
		if(this->getAssistNumInSeason()>10 ||this->getGoalsNumInSeason()>7)
		{
			string c="\nShould participate in creating or creating merit\n";
			return c;
		}
	}
	long long calculateWage()
	{
		long long bonus,wage,salary;
		if(this->tackleAbility=="good" ||this->offsideTrap=="good"||this->defense1vs1=="good")
		{
			salary=2500000;
		}else if(this->tackleAbility=="normal" ||this->offsideTrap=="normal"||this->defense1vs1=="normal")
		{
			salary=1200000;
		}else
		{
			salary=800000;
		}

		if(this->getGoalsNumInSeason()>8 ||this->getAssistNumInSeason()>11 )
		{
			bonus=500000;
		}else if(this->getGoalsNumInSeason()>6 ||this->getAssistNumInSeason()>9 )
		{
			bonus=300000;
		}else
		{
			bonus=150000;
		}
		wage=bonus+salary;
		cout<<"\nThe total bonus is:";
		return wage;
	}
	
	bool signingCondition()
	{
		if(this->getAppearance()<6 ||this->getWeight()>80  || this->getInjury()=="bad")
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
		if(this->tackleAbility=="bad" ||this->offsideTrap=="bad"||this->defense1vs1=="bad")
		{
			cout<<"\nFull contract termination is possible\n";
		}else if(this->tackleAbility=="normal" ||this->offsideTrap=="normal"||this->defense1vs1=="normal")
		{
			cout<<"\nContract termination is unlikely\n";
		}else
		{
			cout<<"\nTermination of the contract cannot happen\n";
		}
	}
	void oppRenewContract()
	{
		if(this->getTechniqueStat()>85 ||this->getWeight()<72  )
		{
			cout<<"\nMost likely will sign a contract extension\n";
		}else if(this->getTechniqueStat()>75 ||this->getWeight()<77 )
		{
			cout<<"\nExtension may be considered\n";
		}else
		{
			cout<<"\nUnable to extend\n";
		}
	}
	
};

