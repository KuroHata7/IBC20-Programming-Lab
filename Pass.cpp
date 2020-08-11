#include<iostream>
#include<string>
using namespace std;
string user_name="MyUser",Pass="MyPass",s1,s2;
int main()
{
    for(int i=0;i<3;i++)
    {
        cout<<"Please enter your Username followed by your Password:";
        cin>>s1>>s2;
        if(s1==user_name&&s2==Pass)
        {
            cout<<"Access Granted\n";
            return 0;
        }
        cout<<"Access Denied\n";
    }
    cout<<"You have run out of attempts, the system will now shut down\n";
    return 0;
}
