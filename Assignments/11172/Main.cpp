#include <iostream>

 #define endl "\n"

using namespace std;

 int  main(){
    int c,l,r,i=0;
    cin>>c;
     while(i<c){
        cin>>l>>r;
        if(l<r){
           cout<<'<'<<endl;
         }else if(l>r){
            cout<<'>'<<endl;
         }else{
            cout<<'='<<endl;
        }
        i++;
     }
     return 0;
 }
