#include "Player.cpp"
class Defender:public Player
{
	private:
	string tackleAbility;
	string defense1vs1;
	string offsideTrap;
	string areaDefense;
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
	void setAreaDefense(string areaDefense)
	{
	    this->areaDefense=areaDefense;
	}
	string getAreaDefense()
	{
	    return this->areaDefense; 
	}  
	Defender()
	{
	this->tackleAbility="";
	this->defense1vs1="";
	this->offsideTrap="";
	this->areaDefense="";
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
		cout<<"Enter the areaDefense :";
		getline(cin,this->areaDefense);
	}
	void output()
	{
		Player::output();
		cout<<"tackleAbility:"<<this->tackleAbility<<"  "<<"defense1vs1:"
		<<this->defense1vs1<<"  "<<"offsideTrap:"<<this->offsideTrap<<" "<<
		"areaDefense:"<<this->areaDefense<<endl;
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
		if(this->areaDefense=="good" ||this->tackleAbility=="good" ||this->offsideTrap=="good"||this->defense1vs1=="good")
		{
			salary=2500000;
		}else if(this->areaDefense=="normal" ||this->tackleAbility=="normal" ||this->offsideTrap=="normal"||this->defense1vs1=="normal")
		{
			salary=1200000;
		}else
		{
			salary=800000;
		}

		if(this->getGoalsNumInSeason()>8 ||this->getAssistNumInSeason()>11 ||this->getEscapePressing()=="good"||this->getHeader()=="good")
		{
			bonus=500000;
		}else if(this->getGoalsNumInSeason()>6 ||this->getAssistNumInSeason()>9 ||this->getEscapePressing()=="normal"||this->getHeader()=="normal")
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
		if(this->getAppearance()<6 ||this->getWeight()>80 ||this->getSpeed()<50 || this->getInjury()=="bad")
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
		if(this->areaDefense=="bad" ||this->tackleAbility=="bad" ||this->offsideTrap=="bad"||this->defense1vs1=="bad")
		{
			cout<<"\nFull contract termination is possible\n";
		}else if(this->areaDefense=="normal" ||this->tackleAbility=="normal" ||this->offsideTrap=="normal"||this->defense1vs1=="normal")
		{
			cout<<"\nContract termination is unlikely\n";
		}else
		{
			cout<<"\nTermination of the contract cannot happen\n";
		}
	}
	void oppRenewContract()
	{
		if(this->getTechniqueStat()>85 ||this->getWeight()<72 || this->getEscapePressing()=="good" ||this->getPassingBall()=="good" )
		{
			cout<<"\nMost likely will sign a contract extension\n";
		}else if(this->getTechniqueStat()>75 ||this->getWeight()<77 || this->getEscapePressing()=="normal" ||this->getPassingBall()=="normal")
		{
			cout<<"\nExtension may be considered\n";
		}else
		{
			cout<<"\nUnable to extend\n";
		}
	}
	
};

