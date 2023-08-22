#include <bits/stdc++.h>
#include <windows.h>
#include <string.h>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
using namespace std;
class date{
private:
    string t="";
public:
    void meetandgreet();
    void dt();
    void tim();
    void getdt_time();};
class websearch{
    string term;
public:
    void gsearch(string a);
    void tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out);
    void ytsearch();
    void openweb();
};
void websearch::openweb(){
    cout<<"opening the web \n enter webpage url or enter  keyword \'name\' for entering website name:- ";
                    cin>> term;
                    string b;
                    b="start ";
                    string temp=term;
                    if (temp == "name")
                    {   b+="https://www.";
                        cout<<"opening the web \n enter website name :- " ;
                        cin>> term;
                        b+=term;
                        cout<<"enter webpage domain name :- ";
                        cin >>term;
                        temp=term;
                        if (temp.find(".")==0){b+=term;}
                        else{b+=".com";}
                        system(b.c_str());}
                    else{b+=term;system(b.c_str());}
}
void websearch:: tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out)
{
    // construct a stream from the string
    std::stringstream ss(str);
 
    std::string s;
    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
}
void websearch::gsearch(string a){
    
    string b,str1;
    std::vector<std::string> out;
    tokenize(a, ' ', out);
            
    for (auto &b : out) 
    {   
        str1+=b;  
        str1+="+";                  
    }
    cout<<str1;
    b="start https://www.google.co.in/search?q=" + str1 ;
    system(b.c_str());}

void date::meetandgreet()
{
    time_t current = time(0);
    tm*time = localtime(&current);
    if (time-> tm_hour <12)
    {
        cout<<"Have A Good Morning\n";
    }
    else if (time-> tm_hour>=12 && time->tm_hour<=16)
    {
        cout<<"Have A Good Afternoon \n";
    }
    else if (time-> tm_hour >16 && time-> tm_hour<24)
    {
        cout<<"Have A Good Evening \n";
        
    }


}
void date::getdt_time()
    {   time_t current = time(0);
        t = ctime(&current);
    }
void date::dt()
{
    getdt_time();
    string r = t.substr(0, 10) +t.substr(19,6);
    cout<<"The current date is "<<r<<"\n";
}
void date::tim()
{   getdt_time();
    string r = t.substr(10,10) ;
    time_t current = time(0);
    tm*time = localtime(&current);
    if (time-> tm_hour <12)
    {
        if (time-> tm_hour=00)
        {
            r[1]='1';
            r[2]='2';
        }
        cout<<"The current time is"<<r<<"A.M.";
    }
    else if (time-> tm_hour>=12 && time->tm_hour<=19)
    {
        r[1]='0';
        r[2]=t[12] - 2;
        cout<<"The current time is"<<r<<"P.M.\n";
    }
    else
    {
        switch (time-> tm_hour)
        {
        case 20:
            r[1]='0';
            r[2]='8';
            break;
        case 21:
            r[1]='0';
            r[2]='9';
            break;
        case 22:
            r[1]='1';
            r[2]='0';
            break;
        case 23:
            r[1]='1';
            r[2]='1';
            break;
        }
        cout<<"The current time is"<<r<<"P.M.";}
}
void websearch:: ytsearch(){
    cout<<"starting youtube for you \n enter title for video search:- ";
                    string phrase ;
                    getline(cin,phrase);
                    string b,str1;
                    std::vector<std::string> out;
                    tokenize(phrase, ' ', out);
                    
                        for (auto &b : out) 
                        {   
                        str1+=b;
                        str1+="+";                        
                        }
                    string cmnd = "start https://www.youtube.com/results?search_query=";
                    cmnd+=str1;
                    const char *charCommand = cmnd.c_str();
                    system(charCommand);
}

int main()
{
    //system("cls");

    cout<<"**********THIS IS YOUR CHAT ASSISSTANT************* ";
    cout<<"\n\n";
    
    string pswd;
    string cmnd;
    string a;
    date obj1;
    websearch obj2;

    do
    {

        cout<<" \n HEY user TO PROCEED PLEASE ENTER YOUR PASSWORD \n";
        
        getline(cin,pswd);

        STARTUPINFO startInfo = {0};
        PROCESS_INFORMATION processInfo = {0};

        if(pswd=="jarvis")
        {
            obj1.meetandgreet();
            do{
                cout<<"\n What can I do for you? \n";

                string phrase = "What can I do for you";
                

                cout<<"\nPlease write your question:\n";
                getline(cin,cmnd);

                cout<<"Answering your query:";

                if(cmnd =="hii" || cmnd=="hey" )
                {
                    cout<<"hello sir \n";
                    
                }
                else if(cmnd=="what is the time")
                {

                    obj1.tim();
                }
                
                else if(cmnd=="what is the date")
                {

                    obj1.dt();
                }
                else if(cmnd =="what is the date and time")
                {
                    obj1.dt();obj1.tim();
                }

                else if(cmnd =="what is your name" || cmnd =="who am I speaking with")
                {
                    cout<<"My name is Jarvis.I am a voice assistant who is created by Utkarsh.\n";
                    
                }


                else if(cmnd=="open notepad")
                {
                    cout<<"opening your notepad \n";
                    CreateProcess(TEXT("C:\\Windows\\notepad.exe"), NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &startInfo, &processInfo);
                }



                else if(cmnd =="open paint")
                {
                    cout<<"opening paint for you \n";
                    
                    CreateProcess(TEXT("C:\\Program Files\\WindowsApps\\Microsoft.MSPaint_6.2203.1037.0_x64__8wekyb3d8bbwe\\PaintStudio.View.exe"), NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &startInfo, &processInfo);
                }

                else if(cmnd =="open google")
                {   
                    cout<<"opening google search for you \n enter search term:- ";
                    getline(cin,a);
                    obj2.gsearch(a);
                }
                else if (cmnd=="open webpage")
                {
                    obj2.openweb();
                }
                
                else if(cmnd =="open youtube")
                {
                    obj2.ytsearch();
                    
                }

                else if(cmnd =="close edge")
                {
                    cout<<"edge is being closed for you \n";
                    
                    system("TASKKILL /IM msedge.exe /F");
                }


                else if(cmnd=="open photos")
                {
                    cout<<"your photo is being opened \n";
                    
                    CreateProcess(TEXT("C:\\Program Files\\WindowsApps\\Microsoft.Windows.Photos_2022.31090.23006.0_x64__8wekyb3d8bbwe\\PhotosApp.exe"), NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &startInfo, &processInfo);
                }

                else if(cmnd== "drop my needle")
                {

                    cout<<"your favorite song is being played";
                    system("start https://www.youtube.com/watch?v=pAgnJDJN4VA");
                    //ShellExecute(NULL,"open","BTS_-_Euphoria.mp3",NULL, NULL, SW_NORMAL);
                }
                else if(cmnd =="bye" || cmnd =="leaving")
                {
                    cout<<"It was good to meet you.Hope to see you again \n";
                    exit(0);
                }

                else
                {
                    cout<<"Your command is not clear.\n";
                    string phrase = "Your command is not clear";
                    
                }


            }while(1);
        }
        else if (pswd=="bye")
        {
            cout<<"It was good to meet you.Hope to see you again \n";
            exit(0);
        }
        
        else
                {
                    system("cls");

                    cout << "*****YOUR PASSWORD IS INCORRECT***** \n\n\n";
                }
    } while (1);


    return 0;
}

