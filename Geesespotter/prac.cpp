#include <iostream>
int main();
int main(){
int n{0};
double m{0};
std::cout<<"Please enter an integer"<<std::endl;
std::cin>>n;
std::cout<<"Please enter a double"<<std::endl;
std::cin>>m;
if(m>n){
    if (m>2023){
        std::cout<<m<<" is greater than "<<n<<" and 2023"<<std::endl;}
    else{
        std::cout<<m<<" is greater than "<<n<<" but not 2023"<<std::endl;
    }    
    
    
    }
    else{
       if (n>2023){
        std::cout<<n<<" is greater than "<<m<<" and 2023"<<std::endl;}
    else{
        std::cout<<n<<" is greater than "<<m<<" but not 2023"<<std::endl;
    }




}

}




