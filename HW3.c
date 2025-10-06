//Soru 1 

int fun(int n){ 

	int count = 0; 

	for(int i=n; i>o; i/=2)   // i her adimda yariya iniyor 

		for(int j=0;jzi;j++)  // j i kadar doner 

			count +=1; 

		return count; 

} 

/*Dis dongude n ile baslar ve i>0 oldugu surece devam eder i her adimda ikiye bolunuyor, yaklasik logn kadar calisir.  

Icteki dongude basta i n kez calisir, sonra n/2, sonra n/4... bu sekilde ½ kati olarak devam eder en sonda ise 1 kez calisir. 
Bunlarin toplami : n + n/2 + n/4 + ... + 1	= n (1+ ½ + ¼ + ... )  = 2n 

Buradan da time complexity = O(n) olur. */
  

//Soru 2 

int a =0, b=0; 

for(i=0; i<N;i++){    // Burada rand() O(1) zaman aldigindan time complexity O(N) olur. 

	a =a +rand(); 

} 

for(j=0;j<M; j++){ 

	b=b +rand();  // Burada rand() O(1) zaman aldigindan time complexity O(M) olur. 

} 

/*For donguleri bagimsiz oldugu icin time complexity = O(N) + O(M) yani: 

Time complexity = O(N + M) olur. */

 
//Soru 3 

for (int i=n; i>0; i=i/2){  // 1.Dongu 

	for (int j=1;j<n;j=j*2){  // 2.Dongu 

		for (int k=0;k<n;k=k+2){  // 3.Dongu 

			//some logic with complexity X 
		} 
	} 
} 

/*1. dongude her adimda i ikiye bolunuyor yani logn kadar calisiyor. 
2. dongude her adimda j iki katina cikiyor yani yine logn kez calisiyor. 
3. dongudeyse k 0 ‘dan baslayip 2’serli artiyor yani buradan da O(n) sonucuna ulasiyoruz. 
Time complexityi bulmak icin logn × n × n = nlog2n 

Buradan time complexity = O( nlog2n ) olur. */
 
//Soru 4 

for (int i=0;i<n;i++){ 
	i*=k; 
} 

/*Burada i hicbir zaman artmaz hep 0 olarak kalir ve i < n kosulu her seferinde karsilanir. Yani sonsuz donguye girer. 

Time complexity = O(logn) olur. */
 
//Soru 5 

int i, j, k=0; 

for(i=n/2;i<=n;i++){ 
	for(j=2;j<=n;j=j*2){ 
		k=k+n/2; 
	} 
} 

/*Dis dongu n/2 ‘den n’e kadar gidiyor yani buradan O(n) elde ederiz. 
Ic dongude ise j her adimda 2 katina cikiyor buradan da logn sonucuna variriz. 
Ic dongude yapilan k=k+n/2 isleminden de O(1) elde ederiz. 

Buradan time complexity = O(n)  × O(logn) × O(1)  

Time complexity = O( n logn) olur. */

//Soru 6 

int a=0, i=N; 
while(i>0){ 
	a+=i; 
	i/=2; 
} 

/*I baslangicta  N fakat her turda 2 ye bolunuyor bu N, N/2, N/4 seklinde gidiyor buradan log(N) kadar donuyor diyebiliriz. 
Dongu icindeki a+=i ise O(n)’e es olur. 

Buradan time complexity = O( log N ) olur. */

//Soru 7 

int value =0; 
for(int i=0;i<n;i++){ 

	for(int j=0;j<i;j++){ 
		value+=1; 
	} 
} 

/*Distaki dongu ne kez calisir buradan  O(n) elde edilir. 
Icteki dongu ise 0 dan I'ye kadar gider yani n-1 kez doner buradan da O(n-1) elde ederiz. 
Buradan time complexity = O(n) × O(n-1) 

Time complexity = O(n²) olur. */

