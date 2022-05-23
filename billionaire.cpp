#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

void hint(string question, string a, string b, string c, string d, string cor, string an)
{
    srand(time(NULL));
    if (an == "Ask")
    {
        cout << "\t\tAsk the Audience\n"<<endl;
        int clv= rand()%100 , av = ((rand()%100)-clv) , bv = ((rand()%100)-clv) , cv = ((rand()%100)-clv) , dv = ((rand()%100)-clv);
        if(clv < av || clv < bv || clv < cv || clv < dv)
        {
            do
            {
                clv+=clv%100;
            }while(clv < av || clv < bv || clv < cv || clv < dv);
        }
        if (clv > 100)
            clv = 99;
        if (a == "")
            av = 0;
        else if(cor != a && av < 0)
            av *= -1;
        else if (cor == a)
            av = clv;
        if (b == "")
            bv = 0;
        else if (cor != b && bv < 0)
            bv *= -1;
        else if (cor == b)
            bv = clv;
        if (c == "")
            cv = 0;
        else if (cor != c && cv < 0)
            cv *= -1;
        else if (cor == c)
            cv = clv;
        if (d == "")
            dv = 0;
        else if (cor != d && dv < 0)
            dv *= -1;
        else if (cor == d)
            av = clv;
        for(int i = 0; i <= av; i++)
        {
            if(i==0)
                cout << endl << endl << "a: " << av << "% ";
            if (av == 0)
                break;
            cout <<char(219);
        }
        for(int i = 0; i <= bv; i++)
        {
            if(i==0)
                cout << endl << endl << "b: " << bv << "% ";
            if (bv == 0)
                break;
            cout <<char(219);
        }
        for(int i = 0; i <= cv; i++)
        {
            if(i==0)
                cout << endl << endl << "c: " << cv << "% ";
            if (cv == 0)
                break;
            cout <<char(219);
        }
        for(int i = 0; i <= dv; i++)
        {
            if(i==0)
                cout << endl << endl << "d: " << dv << "% ";
            if (dv == 0)
                break;
            cout <<char(219);
        }
        
    }else if (an == "Call")
    {
        cout << "\n\t\tCall A Friend\n\n\tWho do you want to call?\n>";
        string name;
        cin.ignore();
        getline(cin, name);
        string dialoge = "\n" + name + ": Hello?\nYou: Hey " + name + " I have a question I want to ask you, do you think you can help?\n" + name + ": How should I know? You have to tell me the question first!\n The question is:\n\t" + question + "\n" + a + " \n" + b + "\n" + c + "\n" + d + "\n\nYou: What do you think?\n" + name + ": Hmmm let me think.\n";
        cout << "Calling " << name;
        int ran = rand()%4,r=rand()%4;
        for(int i=0;i<3;i++)
        {
            cout << ".";
            Sleep(1000);
        }
        for(int i=0;i<dialoge.length();i++)
        {   cout << dialoge[i];
            Sleep(20);
        }
        cout <<endl;
        if(ran == 0)
            dialoge = name + ": I think it's the a: " + a + "\nYou: Are you sure?\n";
        else if (ran == 1)
            dialoge = name + ": I think it's the b: " + b + "\nYou: How confident are you about your answer?\n";
        else if (ran == 2)
            dialoge = name + ": I think it's the c: " + c + "\nYou: Are you Having Doubts?\n";
        else if(ran == 3)
            dialoge = name + ": I think it's the d: " + d + "\nYou: Do you know that\n";
        for(int i=0;i<dialoge.length();i++)
        {   cout << dialoge[i];
            Sleep(20);
        }
        if(r == 0)
            dialoge = name + ": I'm 100% sure that's the answer\nYou: Wow ok, I'll choice that one then! Thank's a lot" + name + " byeee!"; 
        else if (r == 1)
            dialoge = name + ": I pretty sure this is the answer\nYou: Ok, Thank's" + name;
        else if (r == 2)
            dialoge = name + ": I'm not so sure, but I believe this is the answer\nYou: Ok... thank's I guess...";
        else if(r == 3)
            dialoge = name + ": I don't know for sure, but if you win you'll give me a 10%\nYou: Lower it down to 5% and I'll make it happen, HAHAHA\n" + name + ": YOU LITTLE SH...";
        for(int i=0;i<dialoge.length();i++)
        {   cout << dialoge[i];
            Sleep(20);
        }
        cout << "\n--------------------------------------------------------------\n\t\tThe Call Has Ended\n--------------------------------------------------------------" << "Producer: What a nice person!"<<endl;
    }
    cout<<endl<<endl;
    system("pause");
    system("CLS");
}

int selection(string question, string a, string b, string c, string d, string correct,string cl, bool &b50, bool &ba, bool &bc, int me)
{
    string choice="";
    srand(time(NULL));
    do
    {
        cout << "\t\tQuestion "<< (me/1000)+1 << "\n\t" << question << "\t\t\tBank Account: " << me << "$\n\n\ta. " << a << "\t\t\t b. " << b << endl << "\tc. " << c << "\t\t\t d. " << d << endl << endl << "\t50/50 \t 'Call' a friend\t\t 'Ask' for help from the Audience\n>";
        cin >> choice;
        if (choice >= "a" && choice <="d")
        {
            if (choice == cl)
            {
                me += 1000;
                cout << "Correct Answer!!! You have " << me << "$ dollars"<<endl;
                break;
            }else
            {
                cout << "Unfortunately that's not correct. I'm sorry but you have lost!"<<endl;
                Sleep(900);
                return me=0;
            }
        }else if (choice == correct)
        {
            me += 1000;
            cout << "Correct Answer!!! You have " << me << "$ dollars"<<endl;
            break;
        }else if ((choice == "50/50" || choice == "50:50") && b50 == true)
        {
            b50 = false;
            srand(time(NULL));          // 98 lines of code
            int ran=rand()%2,sel=rand()%2;
            if(correct==a)
            {
                if(sel==0)
                {
                    if(ran==1)
                    {
                        b="";
                        d="";
                    }else if(ran==0)
                    {
                        c="";
                        d="";
                    }    
                }else if(sel==1)
                    if(ran==1)
                    {
                        b="";
                        c="";
                    }else if(ran==0)
                    {
                        d="";
                        c="";
                    }
            }
            if(correct==b)
            {
                if(sel==0)
                {
                    if(ran==1)
                    {
                        a="";
                        d="";
                    }else if(ran==0)
                    {
                        c="";
                        d="";
                    }    
                }else if(sel==1)
                    if(ran==1)
                    {
                        a="";
                        c="";
                    }else if(ran==0)
                    {
                        d="";
                        c="";
                    }
            }
            if(correct==c)
            {
                if(sel==0)
                {
                    if(ran==1)
                    {
                        b="";
                        d="";
                    }else if(ran==0)
                    {
                        a="";
                        d="";
                    }    
                }else if(sel==1)
                    if(ran==1)
                    {
                        b="";
                        a="";
                    }else if(ran==0)
                    {
                        d="";
                        a="";
                    }
            }
            if(correct==d)
            {
                if(sel==0)
                {
                    if(ran==1)
                    {
                        b="";
                        a="";
                    }else if(ran==0)
                    {
                        c="";
                        a="";
                    }    
                }else if(sel==1)
                    if(ran==1)
                    {
                        b="";
                        c="";
                    }else if(ran==0)
                    {
                        a="";
                        c="";
                    }
            }
            system("CLS");
            cout << "50/50" <<endl;         //98 lines of code
        }else if ((choice == "50/50" || choice == "50:50") && b50 == false)
        {
            cout << "You have already used it once! You can't take 50/50 chance again."<<endl;
            Sleep(3000);
            system("CLS");
        }else if ((choice == "Ask" || choice == "ASK") && ba == true)
        {
            ba = false;
            hint(question,a,b,c,d,correct,choice);
        }else if ((choice == "Ask" || choice == "ASK") && ba == false)
        {
            cout << "You have already used it once! You can't take help from the crowd again."<<endl;
            Sleep(3000);
            system("CLS");
        }
        else if ((choice == "Call" || choice == "Call") && bc == true)
        {
            bc = false;
            hint(question,a,b,c,d,correct,choice);
        }else if ((choice == "Call" || choice == "Call") && bc == false)
        {
            cout << "You have already used it once! You can't call anyone again."<<endl;
            Sleep(3000);
            system("CLS");
        }
        else 
        {
            system("CLS");
            cout << "\t\tInvalid choice!! Try again!" <<endl;
            Sleep(900);
            system("CLS");
        }
    }while(choice!="");
    return me;
}

void play()
{
    int money_earned=0;
    bool b50 = true, ba = true, bc = true;
    string q="The Windows OS belongs to...", a="Apple", b="AKMI", c="Microsoft", d="Google", cor=c,col="c"; //Question 1
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        cout << "Great you find it! Now let's continue for the " << money_earned+1000 << "$ dollars." << endl << endl;
        system("pause");
        system("CLS");
    }else return;
    q="To which level category does C++ programming language belong?", a="High Level", b="Middle Level", c="Low Level", d="Ultra Level", cor=b,col="b"; //Question 2
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        cout << "Great you find it! Now let's continue for the " << money_earned+1000 << "$ dollars." << endl << endl;
        system("pause");
        system("CLS");
    }else return;
    q="Which language does Unreal Engine use on top of Blueprints?", a="C#", b="C", c="C++", d="all of them", cor=c,col="c"; //Question 3
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        cout << "Great you find it! Now let's continue for the " << money_earned+1000 << "$ dollars." << endl << endl;
        system("pause");
        system("CLS");
    }else return;
    q="Who is the king of Pop Music;", a="Michael Jackson", b="Justin Bieber", c="Elton John", d="Ariana Grande", cor=a,col="a"; //Question 4
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        cout << "Great you find it! Now let's continue for the " << money_earned+1000 << "$ dollars." << endl << endl;
        system("pause");
        system("CLS");
    }else return;
    q="Was an author of Marvel Comics", a="Stan Lee", b="Malcolm Wheeler-Nicholson", c="Jim Lee", d="Mark Ruffalo", cor=a,col="a"; //Question 5
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        cout << "Great you find it! Now let's continue for the " << money_earned+1000 << "$ dollars." << endl << endl;
        system("pause");
        system("CLS");
    }else return;
    q="Which company is the biggest gaming industry?", a="Ubisoft", b="Epic Games", c="Jumbo", d="Tencent", cor=d,col="d"; //Question 6
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        cout << "Great you find it! Now let's continue for the " << money_earned+1000 << "$ dollars." << endl << endl;
        system("pause");
        system("CLS");
    }else return;
    q="C++ is used to create scripts for...", a="system applications", b="mathematical calculations", c="all of them", d="Games", cor=c,col="c"; //Question 7
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        cout << "Great you find it! Now let's continue for the " << money_earned+1000 << "$ dollars." << endl << endl;
        system("pause");
        system("CLS");
    }else return;
    q="Which language did C and C++ originally implemented in?", a="Unix", b="Assembly", c="Java", d="Python", cor=a,col="a"; //Question 8
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        cout << "Great you find it! Now let's continue for the " << money_earned+1000 << "$ dollars." << endl << endl;
        system("pause");
        system("CLS");
    }else return;
    q="When did Greece win the EURO (UEFA European Championship)?", a="2001", b="2004", c="2007", d="2008", cor=b,col="b"; //Question 9
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        cout << "Great you find it! Now let's continue for the " << money_earned+1000 << "$ dollars." << endl << endl;
        system("pause");
        system("CLS");
    }else return;
    q="What year C++ programming language first appeared?", a="1972", b="1991", c="1981", d="1985", cor=d,col="d"; //Question 10
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        cout << "Great you find it! Now let's continue for the " << money_earned+1000 << "$ dollars." << endl << endl;
        system("pause");
        system("CLS");
    }else return;
    q="Bitcoin is... at it's core", a="Open Source", b="Closed Source", c="SHA-256 Functions", d="none of them", cor=a,col="a"; //Question 11
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        cout << "Great you find it! Now let's continue for the " << money_earned+1000 << "$ dollars." << endl << endl;
        system("pause");
        system("CLS");
    }else return;
    q="Facebook was released in...", a="2002", b="2004", c="2001", d="2003", cor=b,col="b"; //Question 12
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        cout << "Great you find it! Now let's continue for the " << money_earned+1000 << "$ dollars." << endl << endl;
        system("pause");
        system("CLS");
    }else return;
    q="Who created Netflix?", a="Dennis Ritchie & Ken Thompson", b="Reed Hastings & Marc Randolph", c="Bill Gates & Satoshi Nakamoto", d="none of them", cor=b,col="b"; //Question 13
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        cout << "Great you find it! Now let's continue for the " << money_earned+1000 << "$ dollars." << endl << endl;
        system("pause");
        system("CLS");
    }else return;
    q="How long did World War II last?", a="4", b="8", c="9", d="5", cor=c,col="c"; //Question 14
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        cout << "Great you find it! Now let's continue for the " << money_earned+1000 << "$ dollars." << endl << endl;
        system("pause");
        system("CLS");
    }else return;
    q="Who developed C++ programming language?", a="Dennis Ritchie", b="Bjarne Stroustrup", c="James Gosling", d="Guido van Rossum", cor=b,col="b"; //Question 15
    money_earned = selection(q,a,b,c,d,cor,col,b50,ba,bc,money_earned);
    if (money_earned > 0)
    {
        system("CLS");
        cout << "\n\n----------------------------------------------------------------------------------------------------\n\n\t\t\tCongrats!!!! You have won " << money_earned << "$ dollars.\n\n----------------------------------------------------------------------------------------------------" <<endl;
        Sleep(2000);
    }else return;
}

int main()
{
    string x="";
    do
    {
        system("CLS");
        cout << "\t\tWelcome to Who wants to be a millionaire\n\n\t1. PLAY\n\t2. HELP\n\t3. EXIT\n\t>";
        cin >> x;
        system("CLS");
        if (x == "1" || x =="play" || x=="PLAY")
        {
            play();
        }else if (x=="2" || x=="help" || x=="HELP")
        {
            cout << "\n  There will be 15 questions that you have to answer with 'a','b','c', or 'd' and for each correct answer\n you will earn a thousand dollars untill you have a million\n-------------------------------------------------------------------------------------------------------------" <<endl;
            system("pause");
        }
    }while (x!="3");
    return 0;
}
