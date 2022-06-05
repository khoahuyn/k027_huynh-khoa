#include "Player.cpp"
class Midfielder:public Player
{
	private:
	string defenseSupport;
	string attackSupport;
	float distanceMove;
	string cornerKick;
	public:
	void setDefenseSupport(string defenseSupport)
	{
	    this->defenseSupport=defenseSupport;
	}
	string getDefenseSupport()
	{
	    return this->defenseSupport;
	}
	void setAttackSupport(string attackSupport)
	{
	    this->attackSupport=attackSupport;
	}
	string getAttackSupport()
	{
	    return this->attackSupport;
	}
	void setDistanceMove(float distanceMove)
	{
	    this->distanceMove=distanceMove;
	}
	float getDistanceMove()
	{
	    return this->distanceMove;  
	}  
	void setCornerKick(string cornerKick)
	{
	    this->cornerKick=cornerKick;
	}
	string getCornerKick()
	{
	    return this->cornerKick; 
	}  
	Midfielder()
	{
		
	} 
	Midfielder(string idMembers,string contractTerm,int idCardNumber,string fullName,int age,long long salary,int numberOfShirt,int Appearance,int numOfYellowCard,int numOfRedCard,int techniqueStat,int assistNumInSeason,int goalsNumInSeason,float height,float weight,string injury,string position,string escapeOffside,	string penaltyAble,	string combiWithOther,	int numOfGodenGoals):Player(idMembers,contractTerm,idCardNumber,fullName,age,salary,numberOfShirt,Appearance,numOfYellowCard,numOfRedCard,techniqueStat,assistNumInSeason,goalsNumInSeason,height,weight,injury,position) {
		this->defenseSupport=defenseSupport;
		this->attackSupport=attackSupport;
		this->distanceMove=distanceMove ;
		this->cornerKick=cornerKick ;

	}
	void input()
	{
		Player::input();
		cout<<"Enter the defenseSupport:";
		getline(cin,this->defenseSupport);
		cout<<"Enter the attackSupport:";
		getline(cin,this->attackSupport);
		cout<<"Enter the distanceMove:";
		cin>>this->distanceMove;
		cin.ignore();
		cout<<"Enter the cornerKick:";
		getline(cin,this->cornerKick);
	}
	void output()
	{
		Player::output();
		cout<<"defenseSupport:"<<this->defenseSupport<<"  "<<"attackSupport:"
		<<this->attackSupport<<"  "<<"distanceMove:"<<this->distanceMove<<"  "<<"cornerKick:"<<this->cornerKick<<endl;
	}
	string mission()
	{
		string a="\nThe main task is to control the gameplay\n";
		return a;
		string b="\nMust play well with feet to support strikers\n";
		return b;
		if(this->getTechniqueStat()>90 ||this->getAssistNumInSeason()>20 ||this->getGoalsNumInSeason()>12 )
		{
			cout<<"\nCan participate in creating or making merit\n";
			cout<<"\nCan retreat to defense when needed\n";
		}
	}
	long long calculateWage()
	{
		long long bonus,wage,salary;
		if(this->attackSupport=="good" ||this->defenseSupport=="good" ||this->cornerKick=="good")
		{
			salary=4000000;
		}else if(this->attackSupport=="normal" ||this->defenseSupport=="normal" ||this->cornerKick=="normal")
		{
			salary=3000000;
		}else
		{
			salary=1800000;
		}
		
		for(int i=1;i<this->distanceMove;i++)
		{
			bonus+=1000000;
		}
		wage=bonus+salary;
		cout<<"\nThe total bonus is:";
		return wage;
	}
	
	bool signingCondition()
	{
		if(this->getTechniqueStat()<70 ||this->getNumOfRedCard()==3)
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
		if(this->attackSupport=="bad" ||this->defenseSupport=="bad" ||this->cornerKick=="bad")
		{
			cout<<"\nFull contract termination is possible\n";
		}else if(this->attackSupport=="normal" ||this->defenseSupport=="normal" ||this->cornerKick=="normal")
		{
			cout<<"\nContract termination is unlikely\n";
		}else
		{
			cout<<"\nTermination of the contract cannot happen\n";
		}
	}
	void oppRenewContract()
	{
		if(this->cornerKick=="good"||this->distanceMove>70)
		{
			cout<<"\nMost likely will sign a contract extension\n";
		}else if(this->cornerKick=="normal"||this->distanceMove>60)
		{
			cout<<"\nExtension may be considered\n";
		}else
		{
			cout<<"\nUnable to extend\n";
		}
	}
	
	
};

