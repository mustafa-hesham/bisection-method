//This code is written by Mustafa Hesham Mohamed to find the root of a function using Bisection method.
#include<iostream>
#include <cmath>
using namespace std;
int main(){
	double xu, xl, xr, accerror, apperror, resultu, resultl, resultr;
	double totalxr[100];
	int n, ite,iten;
	cout<<"Please enter number of terms: "<<endl;
	cin>>n;
	double coeff[n];
	double power[n];
	cout<<"Please enter X upper: "<<endl;
	cin>>xu;
	cout<<"Please enter X lower: "<<endl;
	cin>>xl;
	
	for (int i=0; i<n; i++) {
		cout<<"Please enter coefficient number "<<i+1<<endl;
		cin>>coeff[i];
		cout<<"Please enter power number "<<i+1<<endl;
		cin>>power[i];
	}
	cout<<"Please enter the accepted error (percent): "<<endl;
	cin>>accerror;
	
	for (ite=0; ite<100; ite++){
		resultu = 0;
		resultl = 0;
		resultr = 0;
	xr = (xu + xl)/2;
	totalxr[ite] = xr;
	for (int i=0; i<n; i++){
	resultu += coeff[i]*pow(xu, power[i]);
	resultl += coeff[i]*pow(xl, power[i]);
	resultr += coeff[i]*pow(xr, power[i]);
	}
	if ((resultu < 0 && resultr < 0) || (resultu > 0 && resultr > 0)) xu = xr;
	if ((resultl < 0 && resultr < 0) || (resultl > 0 && resultr > 0)) xl = xr;
	
	if (ite==0){
	cout <<"The relative error isn't defined yet!"<<endl;
	cout <<"The f(xu) is "<<resultu<<endl;
	cout <<"The f(xl) is "<<resultl<<endl;	
	cout <<"The f(xr) is "<<resultr<<endl;
	cout <<"The X root is "<<xr<<endl;
	cout <<"-----------------------------------------"<<endl;
}
	if(ite>0){
		apperror = (totalxr[ite] - totalxr[ite-1])*100/totalxr[ite];
		if (apperror<0) apperror *= -1;
		cout<<"The percentage error is: "<<apperror<<"%"<<endl;
		cout <<"The f(xu) is "<<resultu<<endl;
		cout <<"The f(xl) is "<<resultl<<endl;	
		cout <<"The f(xr) is "<<resultr<<endl;
		cout <<"The X root is "<<xr<<endl;
		cout <<"The new X upper is "<<xu<<endl;
		cout <<"The new X lower is "<<xl<<endl;
		cout <<"-----------------------------------------"<<endl;
		iten = ite;
		if (accerror > apperror) ite= ite+3;
	}
	}
	
	cout<<"Number of iterations: "<<iten+1<<endl;
	return 0;
}
