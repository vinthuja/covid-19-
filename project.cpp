#include<iostream>
using namespace std;

string countries[]={"Sri Lanka","Malaysia","Singapore"};
string dates[]={"Dec26","Dec27","Dec28","Dec29"};
int data[4][3]={{598,635,102},{674,796,134},{549,894,127},{453,925,142}};
int selection;
void Menu()
{
    cout<<"\n"<<"******COVID-19 DATA******"<<"\n";
    cout<<"1 - Number of new cases in each country."<<endl;
    cout<<"2 - Number of new cases in each date."<<endl;
    cout<<"3 - Number of new cases identified in a specific date in particular country"<<endl;
    cout<<"4 - Highest reported case record"<<endl;
    cout<<"5 - Lowest report case record"<<endl;
    cout<<"6 - Total number of COVID-19 new cases in the duration of 26th December 2020 to 29th December 2020"<<endl;
    cout<<"7 - Exit the program"<<endl;

    cout<<endl;
    
}
void newcasesincountry()
{
    cout<<"Number of new cases in each country."<<"\n";
    for(int i=0;i<3;i++)//0//1//2//3
    {
        int total=0;//598//1272//1821//2274
        cout<<"Total new cases in "<<countries[i]<<":";//sri lanka//

        for(int j=0;j<4;j++)//0//1//2//3//4
        {
            //cout<<data[j][i]<<" ";
            total=data[j][i]+total;//598+0=598//598+674=1272//549+1272=1821//453+1821=2274
            
        }
        cout<<total<<endl;   
    }  
    
}
void newcasesindates()
{
    cout<<"Number of new cases in each dates."<<"\n";
    for(int row=0;row<4;row++)//0//1//2
    {
        int total=0;
        cout<<"Total new cases in "<<dates[row]<<":";//Dec 26
        for(int column=0;column<3;column++)//0//1//2//3
        {
            total+=data[row][column];//0+598=598//598+635=
        }
        cout<<total<<endl;
    }
   
}
void newcases()
{
    cout<<"Enter the date :"<<endl;
    cout<<"0-dec26, 1-dec27 2-dec28 3-dec29"<<endl;
    int dateinput;//2
    cin>>dateinput;

    cout<<"Enter the country :"<<endl;
    cout<<"0-SriLanka 1-Malaysia  2-Singapore"<<endl;
    int countryinput;//1
    cin>>countryinput;

    cout<<"Number of cases in "<< countries[countryinput] <<" on "<<dates[dateinput]<<" : "<<data[dateinput][countryinput]<<endl;
   
}
void highreport()
{
    int hic,hid,highestrecord = data[0][0];//635
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(data[i][j]>highestrecord)//635>598
            {
                highestrecord=data[i][j];
                hic=j;
                hid=i;

            }
                
        }
    }

    cout<<"The highest record was " << highestrecord<<" found in "<<countries[hic] <<" on "<<dates[hid]<<endl;
    
}
void lowestreport()
{
    int lic,lid,lowestrecord = data[0][0];
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(data[i][j]<lowestrecord)
            {
                lowestrecord=data[i][j];
                lic=j;
                lid=i;

            }
                
        }
    }

    cout<<"The lowest record was " << lowestrecord <<" found in "<<countries[lic] <<" on "<<dates[lid]<<endl;
 
}
void totalcase()
{
    int totalcases = 0;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<3;j++)
        {
            totalcases+=data[i][j];
        }
    }
    cout<<"The total cases reported in all countries during the period : "<<totalcases<<endl;
  
}

int main()
{
    Menu();
    option:
    {
        cout<<"Enter the number to select the menu: ";
        cin>>selection;  //3  //1     
    }
    if(selection>=1 && selection<=7)
    {
        switch(selection)
         {
            case 1:
                newcasesincountry();
                goto option;
                break;
            case 2:
                newcasesindates();
                goto option;
                break;
            case 3:
                newcases();
                goto option;
                break;
            case 4:
                highreport();
                goto option;
                break;
            case 5:
                lowestreport();
                goto option;
                break;
            case 6:
                totalcase();
                goto option;
                break;
            case 7:
                cout<<"---Quitting---";
                break;
        }

    }
    else
    {
        cout<<"selection is wrong please select a valid number"<<endl;
        goto option;

    }
    
    
        return 0;
}