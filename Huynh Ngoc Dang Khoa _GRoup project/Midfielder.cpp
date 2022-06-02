#include "Player.cpp"
class Midfielder:public Player
{
	private:
	string defenseSupport;
	string attackSupport;
	string boxToBoxAble;
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
	void setBoxToBoxAble(string boxToBoxAble)
	{
	    this->boxToBoxAble=boxToBoxAble;
	}
	string getBoxToBoxAble()
	{
	    return this->boxToBoxAble;
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
	this->defenseSupport="";
	this->attackSupport="";
	this->boxToBoxAble="";
	this->distanceMove=0;
	this->cornerKick="";
	}
	void input()
	{
		Player::input();
		cout<<"Enter the defenseSupport:";
		getline(cin,this->defenseSupport);
		cout<<"Enter the attackSupport:";
		getline(cin,this->attackSupport);
		cout<<"Enter the boxToBoxAble:";
		getline(cin,this->boxToBoxAble);
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
		<<this->attackSupport<<"  "<<"boxToBoxAble:"<<this->boxToBoxAble<<"  "<<
		"distanceMove:"<<this->distanceMove<<"  "<<"cornerKick:"<<this->cornerKick<<endl;
	}
	string mission()
	{
		string a="\nThe main task is to control the gameplay\n";
		return a;
		string b="\nMust play well with feet to support strikers\n";
		return b;
		if(this->getTechniqueStat()>90 ||this->getAssistNumInSeason()>20 ||this->getGoalsNumInSeason()>12 ||this->getShootBall()=="good")
		{
			cout<<"\nCan participate in creating or making merit\n";
			cout<<"\nCan retreat to defense when needed\n";
		}
	}
	long long calculateWage()
	{
		long long bonus,wage,salary;
		if(this->attackSupport=="good" ||this->defenseSupport=="good" ||this->boxToBoxAble=="good"||this->cornerKick=="good")
		{
			salary=4000000;
		}else if(this->attackSupport=="normal" ||this->defenseSupport=="normal" ||this->boxToBoxAble=="normal"||this->cornerKick=="normal")
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
		if(this->getTechniqueStat()<70 ||this->getShootBall()=="bad" || this->getEscapePressing()=="bad"||this->getNumOfRedCard()==3)
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
		if(this->attackSupport=="bad" ||this->defenseSupport=="bad" ||this->boxToBoxAble=="bad"||this->cornerKick=="bad")
		{
			cout<<"\nFull contract termination is possible\n";
		}else if(this->attackSupport=="normal" ||this->defenseSupport=="normal" ||this->boxToBoxAble=="normal"||this->cornerKick=="normal")
		{
			cout<<"\nContract termination is unlikely\n";
		}else
		{
			cout<<"\nTermination of the contract cannot happen\n";
		}
	}
	void oppRenewContract()
	{
		if(this->getSpecialGoals()=="good"||this->cornerKick=="good"||this->getPassingBall()=="good"||this->distanceMove>70)
		{
			cout<<"\nMost likely will sign a contract extension\n";
		}else if(this->getSpecialGoals()=="normal"||this->cornerKick=="normal"||this->getPassingBall()=="normal"||this->distanceMove>60)
		{
			cout<<"\nExtension may be considered\n";
		}else
		{
			cout<<"\nUnable to extend\n";
		}
	}
	
	
};

