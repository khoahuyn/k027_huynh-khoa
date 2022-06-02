#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream> 
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

class FootballClub {
	private:
		string idMembers;
		string contractTerm;
	public:
		bool checkDate(int day, int month, int year) {
		switch (month) {
			case 1 :
			case 3:
			case 5 :
			case 7 :
			case 8 :
			case 10 :
			case 12 :
					if(day<1 || day > 31) {
						return false;
					}
					break;
			case 4 :
			case 6 :
			case 9 :
			case 11 :
				if(day < 1 || day > 30) {
					return false;
				}
				break;
			case 2 :
				if (year % 4 == 0) {
  					if (year % 100 == 0) {
   						 if (year % 400 == 0) {
							if(day < 1 || day > 29) {
								return false;
							}
					}else{
						if(day < 1 || day > 28) {
								return false;
					}}
				}else {
						if(day < 1 || day > 29) {
								return false;
							}
				}}else{
						if(day < 1 || day > 28) {
								return false;
				}}
					
				break;
			default :
				return false;
		}
		if(year <= 2022) {
			return false;
		} 
		return true;
		}
		void setMember(string idMembers){
			this->idMembers = idMembers;
		}
		string getMember(){
			return this->idMembers;
		}
		void setcontract(string contractTerm){
			this->contractTerm = contractTerm;
		}
		string getcontract(){
			return this->contractTerm;
		}
	FootballClub(){
		this->idMembers = " ";
		this->contractTerm = " ";
	}
	void input(){
		cout<<"Enter the ID.Members: ";
		cin>>this->idMembers;
		for(int i=0;i<=10;i++){
			if(this->idMembers[i]>=97&&this->idMembers[i]<=122)
				this->idMembers[i]-=32;
		}
		cin.ignore();
		cout<<"Enter the ContractTerm(Format DD/MM/YYYY): \n\n";
		int day,month,year;
		do {
			cout << "Day : ";
			cin >> day;
			cout << "Month : ";
			cin >> month;
			cout << "Year : ";
			cin >> year;
		}while(checkDate(day,month,year)==false);
		string sday,smonth,syear;
		sday = to_string(day);
		smonth = to_string(month);
		syear = to_string(year);
		this->contractTerm = sday+'/'+smonth+'/'+syear;
	}
	void output(){
		cout<<"*ID of Members: "<<this->idMembers<<endl;
		cout<<"*Contract Term: "<<this->contractTerm<<endl;
	}
//	virtual string mission() = 0;
//	virtual long long calculateWage() = 0;
//	virtual bool signingCondition() = 0;
//	virtual void riskOfTerminateContract() = 0;
//	virtual void oppRenewContract() = 0;
//	virtual bool valueBringingLastSeason() = 0;
};
class Person : public FootballClub {
	private : 
		int idCardNumber ;
		string fullName ;
		int age ;
		long long salary  ;
	public :
		int getIDCardNumber ()  {
		  return this->idCardNumber ;
		} 
		string getFullName() {
		return this->fullName ;	
		} 
		int getAge() {
			return this->age ;
		} 
		int getSalary() {
			return this->salary ;
		} 
		
		void setIDCardNumber (int ID) {
			this->idCardNumber=ID ;
		} 
		void setFullName (string name) {
			this->fullName=name ;
		} 
		void setAge(float age) {
			this->age=age ;
		} 
		void setSalary(long long salary) {
			this->salary=salary ;
		} 

		Person() {
			this->idCardNumber=0;
			this->fullName="" ;
			this->age=0;
			this->salary=0;
		} 
		
		string chuanHoaTen(string name) {
			string s = "";
			stringstream st(name);
			string token;
			while(st>>token) {
			s += toupper(token[0]);
			for(int i=1 ; i<token.length() ; i++) {
				s += tolower(token[i]);
			}
			s += " ";
			}
			s.erase(s.length()-1);
			name = s;
			return name;
		}
		void input () {
			FootballClub::input() ;
			cout<<"\nCardNumber : " ;
			cin>>this->idCardNumber;
			cin.ignore();
			cout<<"\nFull name : " ;
			getline(cin,this->fullName) ;
			this->setFullName(this->chuanHoaTen(this->fullName));
			cout<<"\nAge : " ;
			cin>>this->age ;
			cout<<"\nSalary : " ;
			cin>>this->salary ;
		} 
		void output() {
			FootballClub::output() ; 
			cout<<"\nCard Number : "<<this->idCardNumber<<"\n";
			cout<<"\nFull Name : " <<this->fullName <<"\n" ;
			cout<<"\nAge : " <<this->age<<"\n" ;
			cout<<"\nSalary : "<<this->salary<<"\n" ;
		} 
	   
}; 
class Player:public Person
{
	private:
		int numberOfShirt; // So ao dau
		int Appearance; // So lan tham gia tran dau
		int numOfYellowCard; // So the vang
		int numOfRedCard; // So the do
		int techniqueStat; // Chi so ki thuat
		int assistNumInSeason; // So luong kien tao trong 1 mua
		int goalsNumInSeason; // SO luong ban thang trong 1 mua
		int assistNumInCareer; // So luong kien tao trong su nghiep cau thu
		int goalsNumInCareer; // So luong ban thang trong su nghiep cau thu
		float height; // Chieu cao
		float weight; // Can nang
		float speed; // Toc do
		float scoreAverage; // Trung binh so ban thang
		string injury; // Loai chan thuong
		string dutyInTeam; // Vai tro trong doi bong
		string escapePressing; // Kha nang thoat Pressing
		string  passingBall; // Kha nang chuyen bong
		string shootBall; // Kha nang sut bong
		string header; // Kha nang lanh dao
		string specialGoals; // Ban thang dac biet
		string position; // vi tri
	public:
		void setInjury(string injury){
			this->injury = injury;
		}
		string getInjury(){
			return this->injury;
		}			
		void setDutyInTeam(string dutyInTeam){
			this->dutyInTeam = dutyInTeam;
		}
		string getDutyInTeam(){
			return this->dutyInTeam;
		}			
		void setEscapePressing(string escapePressing){
			this->escapePressing = escapePressing;
		}
		string getEscapePressing(){
			return this->escapePressing;
		}			
		void setPassingBall(string passingBall){
			this->passingBall = passingBall;
		}			
		string getPassingBall(){
			return this->passingBall;
		}			
		void setShootBall(string shootBall){
			this->shootBall = shootBall;
		}		
		string getShootBall(){
			return this->shootBall;
		}		
		void setHeader(string header){
			this->header = header;
		}			
		string getHeader(){
			return this->header;
		}			
		void setSpecialGoals(string specialGoals){
			this->specialGoals = specialGoals;
		}			
		string getSpecialGoals(){
			return this->specialGoals;	
		}		
		void setPosition(string position)
		{
			this->position = position;
		}	
		string getPosition()
		{
			return this->position;
		}


		void setNumberOfShirt(int numberOfShirt){
			this->numberOfShirt = numberOfShirt;
		}			
		int getNumberOfShirt(){
			return this->numberOfShirt;
		}			
		void setAppearance(int Appearance){
			this->Appearance = Appearance;
		}			
		int getAppearance(){
			return this->Appearance;
		}			
		void setNumOfYellowCard(int numOfYellowCard){
			this->numOfYellowCard = numOfYellowCard;
		}			
		int getNumOfYellowCard(){
			return this->numOfYellowCard;
		}			
		void setNumOfRedCard(int numOfRedCard){
			this->numOfRedCard = numOfRedCard;
		}			
		int getNumOfRedCard(){
			return this->numOfRedCard;
		}			
		void setTechniqueStat(int techniqueStat){
			this->techniqueStat = techniqueStat;
		}					
		int getTechniqueStat(){
			return this->techniqueStat;
		}			
		void setAssistNumInSeason(int assistNumInSeason){
			this->assistNumInSeason = assistNumInSeason;
		}			
		int getAssistNumInSeason(){
			return this->assistNumInSeason;
		}			
		void setGoalsNumInSeason(int goalsNumInSeason){
			this->goalsNumInSeason = goalsNumInSeason;
		}			
		int getGoalsNumInSeason(){
			return this->goalsNumInSeason;
		}			
		void setAssistNumInCareer(int assistNumInCareer){
			this->assistNumInCareer = assistNumInCareer;
		}			
		int getAssistNumInCareer(){
			return this->assistNumInCareer;
		}			
		void setGoalsNumInCareer(int goalsNumInCareer){
			this->goalsNumInCareer = goalsNumInCareer;
		}			
		int getGoalsNumInCareer(){
			return this->goalsNumInCareer;
		}			
		
		
		void setHeight(float height){
			this->height = height;
		}			
		float getHeight(){
			return this->height;
		}			
		void setWeight(float weight){
			this->weight = weight;
		}			
		float getWeight(){
			return this->weight;
		}			
		void setSpeed(float speed){
			this->speed = speed;
		}			
		float getSpeed(){
			return this->speed;
		}			
		void setScoreAverage(float scoreAverage){
			this->scoreAverage = scoreAverage;
		}			
		float getScoreAverage(){
			return this->scoreAverage;		
		}
																				
		Player()
		{
			numberOfShirt = 0;
			height = 0;
			weight = 0;	
			speed = 0;
			scoreAverage = 0;
			injury = " ";
			Appearance = 0;
			numOfYellowCard = 0;
			numOfRedCard = 0;
			dutyInTeam = " ";
			techniqueStat = 0;
			escapePressing = " ";
			passingBall = " ";
			shootBall = " ";
			header = " ";
			assistNumInSeason = 0;
			goalsNumInSeason = 0;
			assistNumInCareer = 0;
			goalsNumInCareer = 0;
			specialGoals = " ";
		}
		void input()
		{
			cout<<"INPUT THE PLAYER'S INFORMATION'"<<endl;
			Person::input();
			cout<<"Number of shirt(1-25): ";
			cin>>numberOfShirt;
			cout<<"Height: ";
			cin>>height;
			cout<<"Weight: ";
			cin>>weight;
			cout<<"Speed: ";
			cin>>speed;
			cout<<"The average of score(1-10): ";
			cin>>scoreAverage;
			cout<<"Injury: ";
			cin.ignore();
			getline(cin,injury);
			cout<<"Appearance: ";
			cin>>Appearance;
			cout<<"Number of Yellow Card: ";
			cin>>numOfYellowCard;
			cout<<"Number of Red Card: ";
			cin>>numOfRedCard;
			cout<<"The duty in Team: ";
			cin.ignore();
			getline(cin,dutyInTeam);
			cout<<"The technique stat(1-4): ";
			cin>>techniqueStat;
			cout<<"The escapation of Pressing: ";
			cin.ignore();
			getline(cin,escapePressing);
			cout<<"The passing Ball: ";
			getline(cin,passingBall);
			cout<<"The ability of shooting Ball: ";
			getline(cin,shootBall);
			cout<<"The header: ";
			getline(cin,header);
			cout<<"The number of assistance in Season: ";
			cin>>assistNumInSeason;
			cout<<"The number of goals in Season: ";
			cin>>goalsNumInSeason;
			cout<<"The number of assistance in Career: ";
			cin>>assistNumInCareer;
			cout<<"The number of goals in Career: ";
			cin>>goalsNumInCareer;
			cout<<"The special goals: ";
			cin.ignore();
			getline(cin,specialGoals);	
			cout<<"Position: ";
			getline(cin,position);		
		}
		void output()
		{
			cout<<"--------------------------------------------------"<<endl;
			cout<<"                         OUTPUT THE PLAYER'S INFORMATION'"<<endl;
			Person::output();
			cout<<"Number of shirt: "<<numberOfShirt<<"  "<<"Height: "<<height<<"  "<<"Weight: "<<weight<<"  "<<"Speed: "<<speed<<endl;                
			cout<<"The average of score: "<<scoreAverage<<"  "<<"Injury: "<<injury<<"  "<<"Appearance: "<<Appearance<<endl;
			cout<<"Number of Yellow Card: "<<numOfYellowCard<<"  "<<"Number of Red Card: "<<numOfRedCard<<"  "<<"The duty in Team: "<<dutyInTeam<<endl;
			cout<<"The technique stat: "<<techniqueStat<<"  "<<"The escapation of Pressing: "<<escapePressing<<"  "<<"The passing Ball: "<<passingBall<<endl;
			cout<<"The ability of shooting Ball: "<<shootBall<<"  "<<"The header: "<<header<<"  "<<endl;
			cout<<"The number of assistance in Season: "<<assistNumInSeason<<"  "<<"The number of goals in Season: "<<goalsNumInSeason<<endl;
			cout<<"The number of assistance in Career: "<<assistNumInCareer<<"  "<<"The number of goals in Career: "<<goalsNumInCareer<<endl;
			cout<<"The special goals: "<<specialGoals<<" "<<"Position: "<<position<<endl;		
		}
		void longOrShortTermRest()
		{
			// injury
			cout<<"--------------------------------------------------"<<endl;
			cout<<"THE TIME NEED FOR THE TERM REST BECAUSE OF INJURY"<<endl;
			if(this->injury == "ligament rupture" )   // dut day chang
				cout<<"2 months for the term rest(Long term rest)"<<endl;
			else if(this->injury == "sprain")  // bong gan
				cout<<"1 moth for the term rest(Short term rest)"<<endl;
			else if(this->injury == "tendinitis")  // viem gan
				cout<<"1.5 months for the term rest(Long term rest)"<<endl;
			else if(this->injury == "fracture")  // gay xuong
				cout<<"from 6 months to 1 year for the term rest(Long term rest)"<<endl;
			else if(this->injury == "muscle injury")  // chan thuong co
				cout<<"1 month for the term rest(Short term rest)"<<endl;
			else if(this->injury == "tear cartilage")  // rach sun
				cout<<"2 months for the term rest(Long term rest)"<<endl;
			else if(this->injury == "minor injury")  // chan thuong nhe
				cout<<"from 1 to 2 weeks for the term rest(Short term rest)"<<endl;
			else 
				cout<<"NO TERM REST"<<endl;			
			}
		float numOfExpectedGoal()
		{
			// goalsNumInSeason & Appearance
			float Num_Of_Expected_Goals;
			cout<<"--------------------------------------------------"<<endl;
			cout<<"==========The Number Of Expected Goals=========="<<endl;
			Num_Of_Expected_Goals = this->goalsNumInSeason / this->Appearance;
			return Num_Of_Expected_Goals;	
		}	
		float numOfExpectedAssist()
		{
			// assistNumInSeason & Appearance
			float Num_Of_Expected_Assists;
			cout<<"--------------------------------------------------"<<endl;
			cout<<"==========The Number Of Expected Assists=========="<<endl;
			Num_Of_Expected_Assists = this->assistNumInSeason / this->Appearance;
			return Num_Of_Expected_Assists;
		}		
};

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




class listMidfielder:public Midfielder
{
	public:
		vector<Midfielder> v;
		int n;
		string searchinfo;
		void inputlist(){
			cout<<"Enter the Midfielder :";
			cin>>n;
			for(int i=0;i<n;i++)
 			{
 				Midfielder dejong;
 				dejong.input();
 				v.push_back(dejong);
			 }
			ofstream fo;
			fo.open("D:\\test\\danh sach.txt");
			if(fo.is_open()){
				for(int i=0;i<v.size();i++){
					fo<<i+1<<"/"<<endl;
					fo<<"Name: "<<v[i].getFullName()<<endl;
					fo<<"Age: "<<v[i].getAge()<<endl;
					fo<<"Height: "<<v[i].getHeight()<<endl;
					fo<<"Weight: "<<v[i].getWeight()<<endl;
					fo<<"Position: "<<v[i].getPosition()<<endl;
				}
				fo.close();
			}else{
				cout<<"Error!!"<<endl;
			}
		}
	void search(){
		ofstream fo;
			fo.open("D:\\test\\danh sach_new.txt");
			if(fo.is_open()){
					cout<<"Enter the searchinfo:";
					getline(cin,this->searchinfo);
					for(int i=0;i<v.size();i++){
					if(this->searchinfo==v[i].getFullName()){
					fo<<"\t\t======The information you need about Midfielder====="<<endl;	
					cout<<"\t\t======The information you need about Midfielder====="<<endl;
					fo<<"Name: "<<v[i].getFullName()<<endl;
					cout<<"Name: "<<v[i].getFullName()<<endl;
					fo<<"Age: "<<v[i].getAge()<<endl;
					cout<<"Age: "<<v[i].getAge()<<endl;
					fo<<"Height: "<<v[i].getHeight()<<endl;
					cout<<"Height: "<<v[i].getHeight()<<endl;
					fo<<"Weight: "<<v[i].getWeight()<<endl;
					cout<<"Weight: "<<v[i].getWeight()<<endl;
					fo<<"Position: "<<v[i].getPosition()<<endl;
					cout<<"Position: "<<v[i].getPosition()<<endl;
					}
					}
				fo.close();
			}else{
				cout<<"Error!!"<<endl;
			}
	}	
};
int main(){
	listMidfielder li;
	li.inputlist();
	cout<<endl<<"\t\t=====Enter the name of Midfielder====="<<endl;
	li.search();
	return 0;
}
