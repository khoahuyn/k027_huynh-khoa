#include<iostream>
#include<algorithm>
#include<vector>
#include<fstream>
#include<string.h>
#include<bits/stdc++.h>
#include<conio.h>
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
	}
	
	FootballClub(string idMembers , string contractTerm) {
		this->idMembers = idMembers;
		this->contractTerm = contractTerm;
	}
	
	virtual void input(){
		cout<<"\n\nWe need the ID for this person : ";
		cin>>this->idMembers;
		for(int i=0;i<=10;i++){
			if(this->idMembers[i]>=97&&this->idMembers[i]<=122)
				this->idMembers[i]-=32;
		}
		cin.ignore();
		cout<<"\nHow long do you want your contract to last?(Format DD/MM/YYYY): \n\n";
		int day,month,year;
		do {
			cout << "Day : ";
			cin >> day;
			cout << "Month : ";
			cin >> month;
			cout << "Year : ";
			cin >> year;
		}while(checkDate(day,month,year)==false);
		cout<<"\n";
		string sday,smonth,syear;
		sday = to_string(day);
		smonth = to_string(month);
		syear = to_string(year);
		this->contractTerm = sday+'/'+smonth+'/'+syear;
	}
	virtual void output(){
		cout<<"ID of Members: "<<this->idMembers<<endl<<endl;
		cout<<"Contract Term: "<<this->contractTerm<<endl;
	}
	virtual string mission() = 0;
	virtual bool signingCondition() = 0;
	virtual void oppRenewContract() = 0;
	long long calculateWage() {
	}
	void riskOfTerminateContract() {
	}
};
class Person:public FootballClub  {
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
			
		}
		
		Person(string idMembers , string contractTerm , int idCardNumber , string fullName , int age , long long salary) : FootballClub(idMembers,contractTerm) {
			this->idCardNumber = idCardNumber;
			this->fullName = fullName;
			this->age = age;
			this->salary = salary;
		}
		
		void input () {
		FootballClub::input() ;
		cout<<"\nIdentity card number : " ;
		cin>>this->idCardNumber ;
		cin.ignore();
		cout << "\nFull name : ";
		getline(cin,this->fullName);
		string s = "";
		stringstream st(fullName);
		string token;
		while(st>>token) {
		s += toupper(token[0]);
		for(int i=1 ; i<token.length() ; i++) {
	   		s += tolower(token[i]);
		}
			s += " ";
		}
		s.erase(s.length()-1);
		fullName=s ;
		cout<<"\nAge :" ;
		cin>>this->age ;
		cout<<"\nSalary :" ;
		cin>>this->salary ;
		
		} 
		void output() {
		FootballClub::output() ; 
		cout<<"\nCardNumber :"<<this->idCardNumber<<"\n\n";
		cout<<"Full Name :" <<this->fullName<<"\n\n" ;
		cout<<"Age :" <<this->age<<"\n\n" ;
		cout<<"Salary :"<<this->salary<<"\n\n" ;
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
		float height; // Chieu cao
		float weight; // Can nang
		string injury; // Loai chan thuong
		string position; // vi tri
	public:
		void setInjury(string injury){
			this->injury = injury;
		}
		string getInjury(){
			return this->injury;
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
	
																				
		Player() {
		} 
		Player(	string idMembers,string contractTerm,int idCardNumber,string fullName,int age,long long salary,int numberOfShirt,int Appearance,int numOfYellowCard,int numOfRedCard,int techniqueStat,int assistNumInSeason,int goalsNumInSeason,float height,float weight,string injury,string position) :Person(idMembers, contractTerm,idCardNumber, fullName, age, salary)
		{	
	     this->numberOfShirt=numberOfShirt ;
	     this->Appearance=Appearance ;
	     this->numOfYellowCard=numOfYellowCard ;
	     this->numOfRedCard=numOfRedCard ;
	     this->techniqueStat=techniqueStat;
	     this->assistNumInSeason=assistNumInSeason ;
	     this->goalsNumInSeason=goalsNumInSeason ;
	     this->height=height;
	     this->weight=weight ;
	     this->injury=injury ;
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
			cout<<"Injury: ";
			cin.ignore();
			getline(cin,injury);
			cout<<"Appearance: ";
			cin>>Appearance;
			cout<<"Number of Yellow Card: ";
			cin>>numOfYellowCard;
			cout<<"Number of Red Card: ";
			cin>>numOfRedCard;
			cout<<"The number of assistance in Season: ";
			cin>>assistNumInSeason;
			cout<<"The number of goals in Season: ";
			cin>>goalsNumInSeason;	
			cout<<"Position: ";
			getline(cin,position);		
		}
		void output()
		{
			cout<<"--------------------------------------------------"<<endl;
			cout<<"                         OUTPUT THE PLAYER'S INFORMATION'"<<endl;
			Person::output();
			cout<<"Number of shirt: "<<numberOfShirt<<"  "<<"Height: "<<height<<"  "<<"Weight: "<<weight<<endl;                
			cout<<"Injury: "<<injury<<"  "<<"Appearance: "<<Appearance<<endl;
			cout<<"Number of Yellow Card: "<<numOfYellowCard<<"  "<<"Number of Red Card: "<<numOfRedCard<<"  "<<endl;
			cout<<"The technique stat: "<<techniqueStat<<endl;
			cout<<"The number of assistance in Season: "<<assistNumInSeason<<"  "<<"The number of goals in Season: "<<goalsNumInSeason<<endl;		
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



class listDefender:public Defender
{
	public:
		vector<Defender> v;
		int n;
		string searchinfo;
		void inputlist(){
			cout<<"Enter the Defender :";
			cin>>n;
			for(int i=0;i<n;i++)
 			{
 				Defender arnold;
 				arnold.input();
 				v.push_back(arnold);
			 }
			ofstream fo;
			fo.open("D:\\danh sach.txt");
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
			fo.open("D:\\danh sach_new.txt");
			if(fo.is_open()){
					cout<<"Enter the searchinfo:";
					getline(cin,this->searchinfo);
					for(int i=0;i<v.size();i++){
					if(this->searchinfo==v[i].getFullName()){
					fo<<"\t\t======The information you need about defender====="<<endl;	
					cout<<"\t\t======The information you need about defender====="<<endl;
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
	listDefender li;
	li.inputlist();
	cout<<endl<<"\t\t=====Enter the name of defender====="<<endl;
	li.search();
	return 0;
}
