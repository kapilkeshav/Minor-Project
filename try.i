
int i;                    
char c = 'c';             
double val = 2.5, res[6]; 
double *p;                			  
p = &res; 
for(i = 0; i < 10; i++){ 
	if(i > 5){ 
    	break;
	}
	else if(i == 5){
		i = 2 * i;
		val = func1();
		*p = add(val, i);
		print(res[i]);
		print("\n");
		continue;
	}
	else{
		*p = add(val, i);
    	        val = res[i];
   	 	print(res[i]);
    	        print("\n");
    	        p = p + 1;
	}
	
	if(i == 2 && val == 4.5){ 
		print("iteration: 3\n");
	}
}
while(i < 12){ 
	print(i);
	print(" ");
	func2(c);
	i++;
}
