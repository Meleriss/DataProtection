#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#include <map> 
using namespace std;

bool isPrime(unsigned long long int p)
{
   if (p<=1) return false;
     
   unsigned long long int b=(unsigned long long int)pow(p,0.5); 
    
   for(unsigned long long int i=2;i<=b;++i)
      if ((p%i)==0) return false;           

   return true;  
}

long long int generatePrimeNumber (long long min, long long int max) {
    long long int x;
    do {
      x = (rand()) % (max - min) + min;
    } while (isPrime(x) == false);
    return x;
}

unsigned long long int gcd (unsigned long long int a, unsigned long long int b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

unsigned long long int mod_pow(unsigned long long int a, unsigned long long int x, unsigned long long int p) {
    unsigned long long int y = 1;
    while (x)
    {
        if (x & 1) {
          y = (y * a) % p;
        }//
        a = (a * a) % p;
        x = x >> 1;
    } 
	return y;
}

bool Ferma(unsigned long long int P) {
    long long int a;
     /*int count = 0;
     srand(time(NULL));
    for(int i = 0; i<10; i++) {
      a = rand() % P;
      if ((mod_pow(a, P-1, P)) != 1)
        count++;
    }
    if (count == 0)
      return true;
    else
      return false; */
    a = rand() % P;
      if ((mod_pow(a, P-1, P)) == 1)
        return true;
      else
        return false;
}

void evklid(long long int a, long long int b, long long int *rez, long long int *x, long long int *y) {
	if (a<b) {long long int t = a; a = b; b = t;}
	long long int U1 = a, U2 = 1, U3 = 0, V1 = b, V2 = 0, V3 = 1, T1, T2, T3, q;
	while (V1 != 0) {
		q = U1 / V1;
		//cout<<q<<endl;
		T1 = U1 % V1; T2 = U2 - q*V2; T3 = U3 - q*V3;
		U1=V1; U2=V2; U3=V3;
		V1=T1; V2=T2; V3=T3;
	}
	 *rez=U1;  *x=U2;  *y=U3;
}

void diffyhellman(long long int *Z1, long long int *Z2) {
  long long int P, Q, g = 0;
  bool t = false;
  srand(time(NULL));
  while (t != true) {
    Q = generatePrimeNumber(1, 1000000000);
    P = 2*Q + 1;
    t = Ferma(P);
  }
  //cout << Q << " " << P << endl;
  do { 
   // g = rand() * 100;
    g = rand() % (P-1 - 1) + 1;
  } while (mod_pow(g, Q, P) == 1);

 // cout << g << endl;

  long long int Ya, Yb, Xa, Xb, Zab, Zba;

  Xa = rand() % P;
  Xb = rand() % P;

 // cout << Xa << " " << Xb << endl;

  Ya = mod_pow(g, Xa, P);
  Yb = mod_pow(g, Xb, P);

  Zab = mod_pow(Yb, Xa, P);
  Zba = mod_pow(Ya, Xb, P);

  *Z1 = Zab;
  *Z2 = Zba;
}

 unsigned long long int little_big_step(unsigned long long int a, unsigned long long int p, unsigned long long int y) {
  unsigned long long int x, i=0, j=0;
  unsigned long long int m = floor((unsigned long long int)sqrt((double)p)) + 1;
  unsigned long long int k = m;
  cout << "m= " << m << "k= "<<k<<endl;
    unsigned long long int A[m], B[k];
  for(i=0; i<m; i++) {
    //A[i] = (y * (long long int)pow(a, i)) % p;
    A[i] = mod_pow(mod_pow(a, i, p) * mod_pow(y, 1, p), 1, p);
    //cout << A[i] << " ";
  }
  cout << endl;
  for(j=1; j<=k; j++) {
    B[j] = mod_pow(a, j*m, p);
    //cout << B[j] << " ";
  }
cout << endl;
  map<unsigned long long int,long long int> dict;
  for(i=1; i<m; ++i)
    dict[A[i]]=i;
  for(i=1; i<k; ++i)
    if(dict.count(B[i]))
    {
      cout << i << " " << dict[B[i]] << endl;
      x = i * m - dict[B[i]];
      break;
    } 
  return x;
} 

int main()
{
  srand(time(NULL));
  long long int p;
  long long int a = rand() % 1000000000;
  long long int x = rand() % 1000000000;
  do {
    p = rand() % 1000000000;
  } while (gcd(a,p) != 1);
  long long int b = rand() % 1000000000;
  long long int y = rand() % p;
  long long int Zab, Zba, rez;
  int input_menu, input_way;
  cout<<"1.mod_pow"<<endl;
  cout<<"2.Evklid"<<endl;
  cout<<"3.Diffi-Hellman"<<endl;
  cout<<"4.Little-big steps"<<endl;
  cout<<"Input function:"<<endl;
  cin>>input_menu;
  switch(input_menu){
    case 1:
    cout<<"1.Random"<<endl;
    cout<<"2.Lapkami"<<endl;
    cin>>input_way;
    switch(input_way){
      case 1:
        cout << a << " " << x << " " << p << endl;
        cout << mod_pow(a,x,p)<<endl;
      break; 
      case 2:
        cin>>a>>x>>p;
        cout<<mod_pow(a,x,p)<<endl;
      break;  
      default:
        cout<<"Error!!!!";
    }
      break;
      case 2:
        cout<<"1.Random"<<endl;
        cout<<"2.Lapkami"<<endl;
        cin>>input_way;
       switch(input_way){
         case 1:
          cout << a << " " << b << endl;
          evklid(a, b, &rez, &x, &y);
          cout<<rez<<" "<<x<<" "<<y<<endl;
        break; 
        case 2:
          cin>>a>>b;
          evklid(a, b, &rez, &x, &y);
          cout<<rez<<" "<<x<<" "<<y<<endl;
        break;  
        default:
          cout<<"Error!!!!";
      }
      break;
      case 3:
        diffyhellman(&Zab, &Zba);
        cout<<Zab<<" "<< Zba<<endl;
      break;
      case 4:
        cout<<"1.Random"<<endl;
        cout<<"2.Lapkami"<<endl;
        cin>>input_way;
        switch(input_way){
          case 1:
          cout << "a=" << a << " p=" << p << " y=" << y << endl;
            cout <<"x="<< little_big_step(a,p,y) << endl;
          break; 
          case 2:
            cin>>a>>p>>y;
            cout<<"x="<< little_big_step(a,p,y) << endl;
          break;   
          default:
            cout<<"Error!!!!";
          break; 
        } 
      

      break;


  }
 /* long long int a, b;

//cin>>a>>x>>p;
cin >>a>>b;
//cout<<mod_pow(a,x,p)<<endl;
 long long int rez, x, y;
evklid(a,b,&rez,&x,&y);
//diffyhellman(&a, &b);
//cout << a << " " << b << endl;
cout<<rez<<" "<<x<<" "<<y<<endl;
//}
 // cin >>x;
  
 // cout<<isPrime(x)<<endl;
  
  
  
  srand(time(NULL));
 
   unsigned long long int range=1000000000;

  do{
      x=rand()%range;
    }while(isPrime(x)==false);
    
 cout<<x<<endl;  
  
    
//system("pause");    */
return 0;
}
