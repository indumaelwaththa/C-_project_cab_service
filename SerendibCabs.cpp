#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct addvehicle{
	string vehicleregno;
	string vehicletype;
    string vehiclemodel;
	double PPkm;

    bool available;
};

struct addsalescl{
    int salesid;
    string bookeddate,customerName;
    double distance;
    int totalcost;
};

addvehicle add[50];
int vehiclecount=0;



// this will return the current menu again into main menu

void returnkey(){

    
            cout << endl << endl << endl <<"press any key to go back to main menu"<<endl;
            cin.ignore();
            cin.get();
};



// this is for adding vehicles

void addvehicles(){
     cout << "............... Add Vehicles  ..............."<<endl<<endl;
    
    

        ifstream lookvehi("vehicals.txt");
        string r, type, model;
        double price;
        bool available;
        bool exists = false;


        cout <<"\n Enter Vehicle registration number :  ";
        cin >> add[vehiclecount].vehicleregno;

        while (lookvehi >> r >> type >> model >> price >> available) {
            if (r == add[vehiclecount].vehicleregno) {
                exists = true;
                break;
            }
        }
        lookvehi.close();


        if (exists) {
            cout << endl<< endl<<"........... vehicle with this registration number already exits .............. ";

            return; 
        }

        if (vehiclecount<50){
    cout <<"\n Enter Vehicle Type :  ";
        cin >> add[vehiclecount].vehicletype;
    
        cout <<"\n Enter Vehical model :  ";
        cin >> add[vehiclecount].vehiclemodel;
    
    cout <<"\n Enter price per kilometer :  ";
        cin >> add[vehiclecount].PPkm;

          if (add[vehiclecount].PPkm<=0){
        cout<<"\n the price per kilometer is needs to be more than 0" << endl;
        return;

        }
        else{

    
        cout <<"\n Enter availability (yes= 1 , no = 0):  ";
        cin >> add[vehiclecount].available;

        ofstream addvehi("vehicals.txt", ios::app);
        if (addvehi.is_open()) {
				addvehi << add[vehiclecount].vehicleregno << " " <<add[vehiclecount].vehicletype<<" "<<
                add[vehiclecount].vehiclemodel <<" "<< add[vehiclecount].PPkm<<"  "<<add[vehiclecount].available<<endl;
				addvehi.close();
                cout<<endl<<endl << "............... Vehical added successfully ..............."<<endl<<endl;
                 vehiclecount++;
			} 

        }
    }
        else{
                cout << "No enough space for anymore vehicals" << endl<<endl;
    }

    };


//this is for viewing vehicles

void viewvehicles(){
        cout<<".................... available Vehicles ...................."<<endl<<endl;


            
        ifstream vehicalfile("vehicals.txt");
        if (!vehicalfile.is_open()) {
            cout << "file not found" << endl;
            return ;
        }
        string vehicleregno;
        
	    string vehicletype,x;
	    string vehiclemodel;
        double PPkm;
        bool available ,vehi=false;
        int i=0;

        while (vehicalfile >> vehicleregno >> vehicletype>>vehiclemodel>>PPkm>>available) {
            if (available==1){

                
            cout<<++i<<". "<<endl<<"\nVehicle Registration NO : "<<vehicleregno<<endl;
           cout<<"Vehicle Type : "<<vehicletype<<endl;
           cout<<"Vehicle model : "<<vehiclemodel<<endl;
           cout<<"Price per Kilometer: "<<PPkm<<endl<<endl;
                vehi=true;



            }
        
        
        

        
        }

        if(!vehi){
                cout<<"NO available vehicles"<<endl;
            }
        vehicalfile.close();
        
        }
    
//this is for updating the vehicle details
void updatevehicle()
{

     cout <<endl<<endl<< "............... Update Vehicles  ..............."<<endl<<endl;
    string vehiid;
    int avail;
    cout<<"Enter vehicle registration number  :";
    cin>>vehiid;


    ifstream vehicalinfile("vehicals.txt");
    if(!vehicalinfile.is_open()){
        cout<<"file not found"<<endl;
    }

    
    vehiclecount=0;
    while (vehicalinfile>>add[vehiclecount].vehicleregno >>add[vehiclecount].vehicletype>>
            add[vehiclecount].vehiclemodel>>add[vehiclecount].PPkm>>add[vehiclecount].available)
    {
        vehiclecount++;


    }


    
    bool foundvehi=false;
    
    for (int x=0;x<vehiclecount;x++)
    {
        if(add[x].vehicleregno==vehiid)
        {

            foundvehi=true;
            char y;
            cout<<endl<<"what are the update u need to do" <<endl;
            cout<<"\n 1. New Vehical registration number"<<endl<<" 2. Vehical Type"<<endl<<" 3. Vehical model"<<"\n 4. price per kilometer "
            << "\n 5. availability "<<endl<<endl;
            cin>>y;
		
   
        switch (y)
        {
        case '1':
            cout <<"\nEnter New Vehical registration number :  ";
            cin >> add[x].vehicleregno;
            
            break;
        case '2':
        cout <<"\n Enter Vehical Type :  ";
        cin >> add[x].vehicletype;
       
        break;
        

        case '3':
        cout <<"\n Enter vehical model :  ";
        cin >> add[x].vehiclemodel;
        
        break;

        case '4':
        cout <<"\n Enter price per kilometer :  ";
        cin >> add[x].PPkm;
        
        break;

        

        case '5':

        cout <<"\n Enter availability (yes=1   no =0):  ";

        cin >> avail;
        while (avail !=0 && avail!=1)
        {
         cout<<endl<<endl<<"invalid choice please enter valid choice"<<endl;
         break;
        }
        add[x].available=avail;
       
        break;

        default:
        cout<<endl<<endl<<"invalid choice please enter valid choice"<<endl<<endl;
            return;
        }
        
        cout <<endl<<endl<< "............... Vehical Updated successfully ..............."<<endl<<endl;

        break;
        }

    }
    
    
    if(!foundvehi)
    {
        cout<<"invalid registration number";
        
    }
    
    ofstream vehicaloutfile("vehicals.txt" , ios::trunc);

     if(!vehicaloutfile.is_open())
     {
        cout<<"file not found"<<endl;
        return;
    }

    for (int x=0;x < vehiclecount;x++)
    {
        
                vehicaloutfile << add[x].vehicleregno << " " <<add[x].vehicletype<< " " <<add[x].vehiclemodel<<"  "<<add[x].PPkm<<"  "   
                <<add[x].available<<"  "<<endl;
    }
         
    vehicaloutfile.close();

returnkey();
};

//delete vehicles

void deletevehicle(){
cout <<endl<<endl<< "............... Delete Vehicals  ..............."<<endl<<endl;
string vehiid,z;
    cout<<"Enter vehical registration number to delete vehical :";
    cin>>vehiid;


    ifstream vehicalinfile("vehicals.txt");
    if(!vehicalinfile.is_open()){
        cout<<"file not found"<<endl;
    }


    vehiclecount=0;
    while (vehicalinfile>>add[vehiclecount].vehicleregno >>add[vehiclecount].vehicletype>>
            add[vehiclecount].vehiclemodel>>add[vehiclecount].PPkm>>add[vehiclecount].available)
    {
        

           vehiclecount++;
    }
         vehicalinfile.close();



    bool foundvehi=false;
    int deletevehi=0;
 
    for (int y=0;y<vehiclecount;y++){
        if(add[y].vehicleregno==vehiid){

            foundvehi=true;
            deletevehi=y;
            
        cout<<"\nVehical Registration NO : "<<add[y].vehicleregno<<endl;
        cout<<"Vehical Type : "<<add[y].vehicletype<<endl;
        cout<<"Vehical model : "<<add[y].vehiclemodel<<endl;
        cout<<"Price per Kilometer: "<<add[y].PPkm<<endl;

            int z;
            cout << endl << endl<<"To confirm deleting vehical press 1  ,  ";
            cout << "To go back to main menu press 2 " << endl;
            cin>> z;

        
          

        if(z==1)
        {

            for (int y=deletevehi;y<vehiclecount-1;y++){
            add[y]=add[y+1];
            }
        vehiclecount--;

        ofstream vehicaloutfile("vehicals.txt");
        if(!vehicaloutfile.is_open()){
        cout<<"file not found"<<endl;
        return;
        }


        for (int y=0;y< vehiclecount;y++)
        {
        vehicaloutfile << add[y].vehicleregno << "   "
                    <<add[y].vehicletype<<"  "
                    <<add[y].vehiclemodel<<" "
                    <<add[y].PPkm<<"  "
                    <<add[y].available<<endl;
				
        }
        vehicaloutfile.close();


        cout<<endl<<".............. vehical " <<add[y].vehicleregno <<" deleted successfully .............."<<endl;
        };

    }
        if(!foundvehi){
            cout <<endl<<endl<< "invalid registration number";
        return;
        }
    

}
};



//adding sales
void addsales(){
static int id=0;
addsalescl sales;
bool c=false;


addvehicle v;
    cout <<endl<<endl<< "............... add sales details  ..............."<<endl<<endl;
    string vehino;


    if (vehiclecount==0){
        cout<<".................... No vehicle data found ..................."<<endl<<endl;
        cout<<"............ cant add sale details without vehicles ..................."<<endl<<endl;
    }


    else{

    viewvehicles();


    cout <<"\n Enter Vehical registration number :  ";
        cin >>vehino;

        
    
    ifstream vehicalfile("vehicals.txt");


    
    while (vehicalfile>>v.vehicleregno>>v.vehicletype>>v.vehiclemodel>>v.PPkm>>v.available)
    {
        if(v.vehicleregno==vehino)
       
        {

             c=true;
            cin.ignore();
            cout <<"\n Enter customer name :  ";
            getline(cin,sales.customerName);
    
            cout <<"\n Enter Date of booking (YYYY.MM.DD):  ";
            getline(cin,sales.bookeddate);
            
            cout <<"\n Enter distance (in Km) :  ";
            cin >> sales.distance;

            if(sales.distance<=0){
                 cout << endl<<endl<<"............... invalid distance  ..............."<<endl<<endl;
                 return;


            }

            sales.totalcost=sales.distance*v.PPkm;
            if (sales.customerName.empty() or sales.bookeddate.empty()){

                 cout << endl<<endl<<"............... please enter every details  ..............."<<endl<<endl;
                cout << endl<<endl<<"............... try again  ..............."<<endl<<endl;
                

            }
            else{

            ofstream addsale("sales.txt", ios::app);
			
			if(addsale.is_open())
            {
				addsale  << " " <<v.vehicleregno<<" " << sales.customerName<<" ";
                addsale << sales.bookeddate<<" "<<v.PPkm<<" "<<sales.distance<<" "<<sales.totalcost<<endl;
				addsale.close();
                cout << endl<<endl<<"............... Sales added successfully ..............."<<endl<<endl;
                
                return;
			} 
        
            else
            {
				cout << "please try again" << endl<<endl;
			}
        }   
        }
    }

     if(!c){
            cout << "Invalid vehical registration number" << endl<<endl;
        }

         
    }
       

};


//viewing sales
void viewsales(){

       cout << endl<<endl<<"............... view Sales ..............."<<endl<<endl;

        ifstream salesfile("sales.txt");
        if (!salesfile.is_open()) {
            cout << "Error opening sales.txt" << endl;
            return ;
        }
        string  salesid,vehicleregno ;
        string bookeddate,customerName;
        double distance;
        double totalcost,PPkm;
        int i=0;
        bool file=true;

        while (salesfile >> vehicleregno >> customerName>>bookeddate>>PPkm>>distance>>totalcost) {

          ++i;
            cout<<endl<<"Sales id : "<<i;
            cout<<"\nVehical Registration NO : "<<vehicleregno<<endl;
            
           cout<<"Customer Name : "<<customerName<<endl;
           cout<<"Booked date   : "<<bookeddate<<endl;
           cout<<"Price per Kilometer: "<<PPkm<<endl;
           cout<<"Distance: "<<distance<<endl;
           
            cout<<"Total cost : "<<totalcost<<endl;
            }
        
        if (i==0){
         cout<<"No sales Data found"<<endl ;  
        }

        
        salesfile.close();
        
};


//viewing company details
void companydetails(){

    cout<<" \n ........................ COMPANY DETAILS ..............................."<<endl<<endl;
    cout<<"\n Address  :  No 123,kandy road ,kandy";
    cout<<"\n contact number  :  084 243 4432";
    cout<<"\n Email  :  SerendibCabs@info.lk";
    
};


//main menu for admins
bool mainmenuadmin(){
    
    do{
    char menuchoice;
    cout <<endl<<endl<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "<<endl<<endl;
    cout << "--------------------     Welcome to Serendib Cabs    ------------------- "<<endl<<endl;
    cout << "----------------------------- Admin menu --------------------------------- "<<endl<<endl;

    cout<< "select your choice"<<endl<<endl;
    cout<<"1. View available vehical details\n";
	cout<<"2. Add vehical details\n";
	cout<<"3. Update vehical details\n";
    cout<<"4. delete vehical details\n";
	cout<<"5. Add sales\n";
	cout<<"6. View Sales\n";
	cout<<"7. company details\n";
	cout<<"8. Logout\n";
	
	cout<<endl;
	cout<<"Please Enter your choice: \n";
    cin>>menuchoice;

    switch (menuchoice)
    {
    case '1':
        viewvehicles();
        returnkey();
        break;
    case '2':
        addvehicles();
        returnkey();
        break;
    case '3':
        updatevehicle();
        break;

    case '4':
        deletevehicle();
        returnkey();
        break;
    case '5':
        addsales();
        returnkey();
        break;
    case '6':
        viewsales();
        returnkey();

        break;
    case '7':
        companydetails();
        returnkey();
        break;
    case '8':
       
        cout<<"loging out..."<<endl<<endl;
        return false;

    default:
        cout<<"\n Invalid chioice ";
        break;
    }

        }    while (true);



};


//main menu for users
bool mainmenuuser(){
    
do{
    char menuchoice;
    cout <<endl<<endl<< "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "<<endl<<endl;
    cout << "--------------------Welcome to Serendib Cabs ------------------- "<<endl<<endl;
    cout << "-----------------------------Main menu--------------------------------- "<<endl<<endl;

    cout<< "select your choice"<<endl<<endl;
    cout<<"1. View available vehicle details\n";
	cout<<"2. company details\n";
	cout<<"3. Logout\n";
    cout<<"4. Exit\n";
	
	cout<<endl;
	cout<<"Please Enter your choice: \n";
    cin>>menuchoice;

    switch (menuchoice)
    {
    case '1':
        viewvehicles();
        returnkey();
        break;
    case '2':
        companydetails();
        returnkey();
        break;
    case '3':
       
        cout<<"loging out...";
        return false;
    case '4':

    return 0;

    default:
        cout<<"Invalid chioice ";
        returnkey();
        break;
    }

} 

while(true);

    };


//registration menu

class loginMenu
{

    private:
        string username,password;
    public:
        
    void regiUser()
        {
            bool aduse=false;

		cout << "--------------- Resgister New account ---------------" << endl<< endl;
			
		cout << "\n Enter Username:   ";
			cin >> username;
			
        if(username=="admin")
        {
          cout<<"Username already exists please use different username"<<endl;
        }
        else{
		cout <<endl<<endl<< " Enter Password:   ";
			cin >> password;
            
            ofstream loginfile("users.txt", ios::app);
			
			if(loginfile.is_open())
            {
				loginfile << username << " " << password << endl;
				loginfile.close();
                cout <<endl << ".................. Registration successful .................. "<<endl<<endl;
			} 

            else
            {
				cout << "please try again" << endl<<endl;
			}
        }

        }
   
};


int main()
{

    loginMenu reg;
    char log;
    bool loginloop=true;

    while (loginloop)
    {
        cout <<endl<<endl<< "|--------------------------------------------------------------------| "<<endl;
        cout<< "|``````````````````````      Serendib Cabs      ``````````````````````|"<<endl;

        cout <<"|____________________________________________________________________| "<<endl<<endl;


    cout<< "please log into account to access Serendib Cabs "<<endl;
    cout<< "1.Login "<<endl<< "2.Register new account"<<endl<<"3.Exit"<<endl;
    cin>>log;

        switch(log)
        {
           case '1': {
    string username, password, checkuser, checkpass;
    bool loggedin = false;

    cout <<endl<<endl<< "---------------- Login Menu ----------------" <<endl<< endl;
    cout <<endl<< " Enter Username: ";
    cin >> username;
    cout<<endl << " Enter Password: ";
    cin >> password;
    cout<<endl<<endl;

    if (username == "admin") {
        if(password == "1234"){
            mainmenuadmin();
            loggedin = true;
        }
        else{
            cout<<"............. invalid paasword ..........."<<endl<<endl;
            break;
        }
        
    }
    
    else {
        ifstream loginfile("users.txt");
        if (!loginfile.is_open()) {
            cout << "Error opening users.txt" << endl;
            break;
        }

        while (loginfile >> checkuser >> checkpass) {
            if (username == checkuser) {
                if (password == checkpass) {  
                    cout << "Login successful!" << endl;
                    mainmenuuser();
                    loggedin = true;
                } else {
                    cout << "Incorrect password!" << endl;
                }
                break;
            }
        }
        loginfile.close();

        if (!loggedin) {
            cout << endl << "Invalid username" << endl << endl;
        }
    }
    break;
}



    case '2':
    
    reg.regiUser();
    
     break;
    

    case '3':
    
        cout<<"Exiting"<<endl;
        return 0;
       break;
    default:
    
    cout<<"\n Invalid choice"<<endl<<endl;
    returnkey();
    break;   
        }
    



}       



}
