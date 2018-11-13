#include <iostream>
#include<string>
#include <stdio.h>
#include<string.h>
#include <sstream>

using namespace std;
static int nn=0;
string neg(string a){
                    if(a=="~p"){
                    a="p";}
                    else if(a=="p"){
                    a="~p";}
                    else if(a=="~q"){
                    a="q";}
                    else if(a=="q"){
                    a="~q";}
                    else if(a=="r"){
                    a="~r";}
                    else if(a=="~r"){
                    a="r";}
                    else if(a=="s"){
                    a="~s";}
                    else if(a=="~s"){
                    a="s";}
                    else if(a=="t"){
                    a="~t";}
return a;
}

void sep(string a,string arr[],char b){
istringstream ss(a);
string token;
int i=0;
    while (getline(ss, token,b)){
                arr[i]=token;

                i++;
            }
nn=i;
}

string check(string aa[],string ab[]){
    string c;
if(aa[0]==neg(ab[0])&&aa[1]==neg(ab[1])||aa[0]==neg(ab[1])&&aa[1]==neg(ab[0])){
    c="\0";
    }
else if(aa[0]==neg(ab[0])){
    if(aa[1]=="\0"){
        c=ab[1];
    }
    if(ab[1]=="\0"){
        c=aa[1];
    }
    else
    c=aa[1]+"v"+ab[1];
}
else if(aa[0]==neg(ab[1])){
    if(aa[1]=="\0"){
        c=ab[0];
    }
    if(ab[0]=="\0"){
        c=aa[1];
    }
    else
    c=aa[1]+"v"+ab[0];
}
else if(aa[1]==neg(ab[0])){
    if(aa[0]=="\0"){
        c=ab[1];
    }
    if(ab[1]=="\0"){
        c=aa[0];
    }
    else
    c=aa[0]+"v"+ab[1];
}
else if(aa[1]==neg(ab[1])){
    if(aa[0]=="\0"){
        c=ab[0];
    }
    if(ab[0]=="\0"){
        c=aa[0];
    }
    else
    c=aa[0]+"v"+ab[0];
}

else

return c;
}

int main()
{
    string p,premises[10],clauses[20],conclusion[2];
    int i=0,j=0,t=0,o=0,w=0;
    cout<<"Write the premises seperated by (,)"<<endl;
    getline(cin,p);

    sep(p,premises,',');
    i=nn;

/* Convert each premise into clauses */
    for(int k=0;k<=i;k++){
    istringstream st(premises[k]);

    if(strstr(premises[k].c_str(),">"))
   {
            string pq[2];
            sep(premises[k],pq,'>');
            clauses[t]=neg(pq[0])+"v"+pq[1];
             t++;
   }


   else if(strstr(premises[k].c_str(),"^"))
   {
        string pw[2];
        sep(premises[k],pw,'^');
        for(int in=0;in<2;in++){
                clauses[t]=pw[in];
                t++;}

   }

    else if(strstr(premises[k].c_str(),"v"))
   {
   clauses[t]=premises[k];
   t++;
   }
// For Loop ends
}



/*  To check the conclusion and negate it */
    if(strstr(premises[i-1].c_str(),">"))
   {
        string pp[2];
        sep(premises[i-1],pp,'>');
        conclusion[0]=pp[0];
        conclusion[1]=neg(pp[1]);
   }
    else if(strstr(premises[i-1].c_str(),"^"))
   {
       string py[2];
       sep(premises[i-1],py,'^');
        conclusion[0]=neg(py[0])+"v"+neg(py[1]);
   }
   else if(strstr(premises[i-1].c_str(),"v"))
   {
       string pr[2];
       sep(premises[i-1],pr,'v');
        conclusion[0]=neg(pr[0]);
       conclusion[1]=neg(pr[1]);
   }
   else {
    conclusion[0]=neg(premises[i-1]);
   }
    cout<<endl; //~p^q,r>p,~r>s,s>t,t
    int yu=0;
    while(yu<i){
    cout<<" Premise "<<yu<<": "<<premises[yu]<<endl;
    yu++;
    }
    cout<<endl;
    while(o<i){
                cout<<" Clauses "<<o<<": "<<clauses[o]<<endl;
                o++;
    }
cout<<endl;
cout<<"applying resolution law"<<endl;
   int ti=1;
   string pe[2],pq[2],c,co[2];
   c=clauses[t-t];
while(ti<t){
    sep(c,pe,'v');
    sep(clauses[ti],pq,'v');
    if(check(pe,pq)=="\0"){
        cout<<check(pe,pq)<<endl;
    }
    else
    c=check(pe,pq);
    cout<<ti<<"==="<<c<<endl;

ti++;
}
string pip[2];
sep(c,co,'v');
cout<<co[0]<<conclusion[0]<<endl;
cout<<co[1]<<conclusion[1]<<endl;

c=check(co,conclusion);
cout<<"RESULT "<<c<<endl;


return 0;
}
