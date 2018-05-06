#include<iostream>


/* CURRENT SUPPORT(GREEDY)
 * .  - any letter ..
 * \w - any word(letter,underscore or space)
 * \s - any space  
 * *  - any number(whole) TBD 
 * +  - any number(natural) TBD
 * ?  - any number([+-*,1]) TBD
 */ 
using namespace std;

int GetTheSpace(char* strptr, string& match)
{
    int len = 0;
    while((*strptr) == ' ' || (*strptr) == '\t')
    {
        match += (*strptr);
        strptr++;
        len++;
    }

    return len;
}

int GetTheWord(char* ptr,string &match)
{
    int len = 0;
    while(((*ptr) >= 'a' && (*ptr) <= 'z') || ((*ptr)>='A' && (*ptr) <= 'Z') || (*ptr) == '_' )
    {
        match += (*ptr);
        ptr++;
        len++;
    }
    return len;
}

string FindPattern(string str,string regex)
{
    int creg = 0,cstr=0;
    string match = "";
    //cout<<str<<regex<<"\n";

    while( cstr<str.length() )
    {
        if(str[cstr] == regex[creg] || regex[creg]=='.')
        {
            match+=str[cstr];
            creg++;
            cstr++;
        }
        else if ( regex[creg] == '\\')
        {
            switch(regex[creg+1])
            {
                case 'w':
                cstr += GetTheWord(&str[cstr],match);
                break;
                case 's':
                cstr += GetTheSpace(&str[cstr],match);
                break;
            }
            creg+=2;
        }
        else
        {
            break;
        }

    }
    //cout<<str[cstr]<<" "<<regex[creg]<<"\n";
    return match;
}
int main(int argv, char** argc)
{
    string instr,inregex,outstr;

    getline(cin,instr);
    getline(cin,inregex);

    string outmatch = FindPattern(instr,inregex);
    cout<<outmatch<<" "<<(int)outmatch[outmatch.length()]<<"\n";
}
