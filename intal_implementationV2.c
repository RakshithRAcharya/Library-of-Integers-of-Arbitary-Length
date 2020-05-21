#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

static void swap(const char **str1_ptr, const char **str2_ptr) 
{ 
  char *temp = *str1_ptr; 
  *str1_ptr = *str2_ptr; 
  *str2_ptr = temp; 
}   

static int min(int a,int b)
{
	return(a<b)?a:b;
}


static char* leading_zeros(const char* a) 
{ 
	int n = strlen(a);
	char* b = a, count = 0;
	int i; 
	for (i = 0; i < n; i++)
	{
		if(b[i] == '0')
		{
			count++;
		}
		else
		{
			break;
		}
	}
	for (i = 0; i < n; i++)
	{
		b[i] = b[i+count];
	}
	int j = 0;
	while(count)
	{
		b[n-j] = '\0';
		count--;
		j++;
	}
	return a;
} 


int intal_compare(const char* intal1, const char* intal2)
{
	int length1 = strlen(intal1);
	int length2 = strlen(intal2);
	if(length1 > length2)
		return 1;
	else if(length1 < length2)
		return -1;
	else if(length1 == length2)
	{
		int i;
		for(i=0; i<length1; i++)
		{
			if(intal1[i]!=intal2[i])
				break;
		}
		if(i==length1)
			return 0;
		else if(intal1[i]>intal2[i])
			return 1;
		else 
			return -1;
	}
}


char* intal_add(const char* intal1, const char* intal2)
{
    char* result =(char*)malloc(1001*sizeof(char));
	int i,j,k;
    int length1=strlen(intal1);
    int length2=strlen(intal2);
    i=length1-1;
    j=length2-1;
    k=length1>length2?length1:length2;
    result[k]='\0';
    k--;
    int carry = 0, sum;
    while(i>=0 && j>=0)
    {     
    	sum = (intal1[i--]-'0') + (intal2[j--]-'0') + carry;
        result[k--] = sum%10 + '0';
        carry=sum/10;
    } 
    if(i>=0)
    {
        while(i>=0)
        {
        	sum=(intal1[i--]- '0')+carry;
            result[k--]=sum%10 + '0';
            carry=sum/10;
        }  
    }
    else if(j>=0)
    {
    	while(j>=0)
        {
	        sum=(intal2[j--]- '0')+carry;
            result[k--]=sum%10 + '0';
            carry=sum/10;
        }        
    }
    if(carry>0)
    {
    	for(i=strlen(result); i>=0; i--)
    	{
    		result[i+1]=result[i];
		}
    	result[0]=carry + '0';
	}
	leading_zeros(result);
	return result;
}	

//SUBTRACTION
char* intal_diff(const char* intal1, const char* intal2)
{
    int greater = strlen(intal1)>strlen(intal2)?strlen(intal1):strlen(intal2);
	if(intal_compare(intal1,intal2)==-1)
		swap(&intal1,&intal2);
    char* result = malloc((greater+1)*sizeof(char));
    char* ptr1 = malloc((strlen(intal1)+1)*sizeof(char));
    char* ptr2 = malloc((strlen(intal2)+1)*sizeof(char));
    int i,j,k;
    strcpy(ptr1,intal1);
    strcpy(ptr2,intal2);
    if(intal_compare(ptr1, ptr2)==-1)
    {
		char* temp = ptr1;
		ptr1 = ptr2;
		ptr2 = temp;
	} 
    int length1=strlen(ptr1);
    int length2=strlen(ptr2);   
    i=length1-1;
    j=length2-1;
    k=length1>length2?length1:length2;
    *(result + k)='\0';
    k--;
    int borrow = 0;
	int diff;
    while(i>=0 && j>=0)
    {
    	diff=(ptr1[i--] - '0') - (ptr2[j--] - '0') - borrow;
        if(diff<0)
        {
        	diff+=10;
        	borrow=1;
        }
        else
        {
        	borrow = 0;
        }
        result[k--] = diff + '0';
	}
    if(i>=0)
    {
    	while(i>=0)
        {              
	        result[k--] = ptr1[i--] - borrow;
            borrow = 0;
        }
     
    }
    else if(j>=0)                                                                        
    {
    	while(j>=0)
        {    
        	result[k--] = ptr2[j--] - borrow;
            borrow = 0;
        }
           
    }
    int m=0;
    while(*(result + (m)) == '0' && m>=0)
		m++;
    if(m==strlen(result))
        return "0";
    char * final_ans = malloc((strlen(result)+1)*sizeof(char));
    for(int i =0 ; i<strlen(result);i++)
    {
      	*(final_ans + i)= *(result + m); 
		m++;
    }
    free(ptr1);
    free(ptr2);
    free(result);
    ptr1=NULL;
    ptr2=NULL;
    result=NULL;
    return final_ans;      
}

//FACTORIAL
char * intal_factorial(unsigned int n)
{ 
    int s=2;
    int *arr = malloc(1001*sizeof(int));
    char *res = malloc(1001*sizeof(char));
    arr[0] = 1;
    int len = 1;
    int x = 0;
    int num = 0;
    while(s<=n)
    {
        x=0;
        num =0;
        while(x<len)
        {
            arr[x] = arr[x] *s;
            arr[x] = arr[x]+num;
            num = arr[x]/10;
            arr[x] = arr[x]%10;
            x++;
        }
        while(num!=0)
        {
            arr[len] = num%10;
            num = num/10;
            len++;
        }
        s++;
    }
    len--;
    int k=0;
    while(len>=0)
    {
        res[k++]=arr[len--]+'0';

    }
    res[k]='\0';
    free(arr);
    return res;
}


char* intal_multiply(const char* intal1, const char* intal2)
{
	int i,j;
	int temp,final_len;
    int length1 = strlen(intal1);
	int length2 = strlen(intal2); 
	int *ptr1 = malloc(sizeof(int)*length1);
	int *ptr2 = malloc(sizeof(int)*length2);
	int *ans = calloc((length1+length2),sizeof(int));
	for(i = length1-1,j=0;i>=0;i--,j++)
    	ptr1[j] = intal1[i]-'0';
    for(i = length2-1,j=0;i>=0;i--,j++)
        ptr2[j] = intal2[i]-'0';
    for(i = 0;i < length2;i++)
    {
        for(j = 0;j < length1;j++)
		{
            ans[i+j] += ptr2[i]*ptr1[j];
		}
    }
    for(i = 0;i < length1+length2;i++)
    {
        temp = ans[i]/10;
        ans[i] = ans[i]%10;
        ans[i+1] = ans[i+1] + temp;
    }
    for(i; i>=0; i--)
    {
        if(ans[i] >=0 && ans[i] <=9)
            break;
    }
	final_len = i;
    char* final_res = calloc(final_len,sizeof(int));
    for(j=0; i>=0; i--)
    {
		    if(ans[i] >=0 && ans[i] <=9)
			      final_res[j++] = ans[i] + '0';
		    else
		    {
			      final_res[j++] = '\0';
			      break;
		    }
    }
	free(ans);
	free(ptr1);
	free(ptr2);
	leading_zeros(final_res);
	return final_res;
}


char* intal_pow(const char* intal1, unsigned int n)
{
	char *result = "1";
	char * base =(char*)malloc(sizeof(char)*1001);
	strcpy(base,intal1);
	if(base == "0")
		return "0";
	while(n>0)
	{
		if(n & 1)
		{
			result = intal_multiply(result,base);
		}
		n = n>>1;
		base = intal_multiply(base,base); 		
	} 
	return result;
}

//FIBONACCI
char* intal_fibonacci(unsigned int n)
{ 
    char* fib1=malloc(sizeof(char)*2); 
    fib1[0]='0'; 
    fib1[1]='\0'; 
    char* fib2=malloc(sizeof(char)*2); 
    fib2[0]='1'; 
    fib2[1]='\0'; 
    char* temp; 
    for(int i=2;i<=n;i++)
    { 
           temp=fib1; 
           fib1=fib2; 
           fib2=intal_add(temp,fib2);         
    } 
    return fib2; 
}


char* intal_mod(const char* intal1, const char* intal2)
{
	char *result=(char *)malloc(strlen(intal2)*sizeof(char));
	char *divportion=(char *)malloc(1001*sizeof(char));
	int j=0;
	while(intal1[j]!='\0')
	{
		while(intal_compare(divportion,intal2)==-1)
		{
			char temp[2];
			temp[0] = intal1[j];
			temp[1] = '\0';
			if(intal_compare(divportion,"0") == 0)
				strcpy(divportion,temp);
			else
				strcat(divportion,temp);
			j++;
		}
		while(intal_compare(divportion,intal2)!=-1)
			strcpy(divportion,intal_diff(divportion,intal2));
	}
	strcpy(result,divportion);
	free(divportion);
	return result;
}


char* intal_gcd(const char* intal1, const char* intal2)
{
	char *res=(char *)malloc(1001*sizeof(char));
	strcpy(res,"0");
	if(intal_compare(intal2,"0") == 0)
	{
		strcpy(res,intal1);
		return res;
	}
	char* temp = intal_mod(intal1, intal2);
	return intal_gcd(intal2,temp);
}


char* intal_bincoeff(unsigned int n, unsigned int k)
{
    char **c =(char**)malloc((k+1) * sizeof(char*));
	int i,j;
    for(j=0; j<n; j++)
    {
        c[j] = (char*)malloc(1001 * sizeof(char));
    }
    for(j=0; j<=k; j++)
    {
             c[j]="0";
    }
    c[0]="1";
    char*temp;
    char*temp1; 
    for(i=1; i<=n; i++)
    { 
        for(j=min(i,k); j>0; j--)
        { 
             temp=c[j];
             temp1=c[j-1];
             temp=intal_add(temp,temp1);
             c[j]=temp;                   
        }
    } 
    return c[k]; 
}


int intal_max(char **arr, int n)
{
	int i, k=0;
	for(i=0; i<n; i++)
	{
		if(intal_compare(*(arr+i),*(arr+k)) == 1)
		{
			k=i;
		}
	}
	return k;
}


int intal_min(char **arr, int n)
{
	int i, k=0;
	for(i=0; i<n; i++)
	{
		if(intal_compare(*(arr+i),*(arr+k)) == -1)
		{
			k=i;
		}
	}
	return k;
}


int intal_search(char **arr, int n, const char* key)
{
	int i, k=0;
	for(i=0; i<n; i++)
	{
		if(intal_compare(arr[i], key) == 0)
		{
			k=i;
			return k;
		}
	}
	if(i == n)
		return -1;
}


int intal_binsearch(char **arr, int n, const char* key)
{
	if(n<=0)
		return -1;
	else
	{		
		int start = 0, end = n;
		while(start <= end)
		{	
			int mid = start+(end-start)/2;
			if(intal_compare(key,arr[mid]) == 0)
				return mid;
			else if(intal_compare(key,arr[mid]) == -1)
				end = mid-1;
			else
				start = mid+1;
		}
	}
	return -1;
}


static void Merge(char** arr, int l, int m, int e)
{
	int i,j,k;
	int n1 = m-l+1;
	int n2 = e-m;
	char** Left_half =(char**)malloc(n1*sizeof(char*));
	char** Right_half =(char**)malloc(n2*sizeof(char*));
	for(i=0; i<n1; i++)
	{
		Left_half[i] = arr[l+i];
	}
	for(j=0; j<n2; j++)
	{
		Right_half[j] = arr[m+j+1];
	}
	i=0; j=0; k=l;
	while(i<n1 && j<n2)
	{
		if(intal_compare(*(Left_half+i),*(Right_half+j)) != 1)
		{
			arr[k] = Left_half[i];
			i++;
		}
		else if(intal_compare(*(Left_half+i),*(Right_half+j)) == 1)
		{
			arr[k] = Right_half[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k] = Left_half[i];
		i++; k++;
	}
	while(j<n2)
	{
		arr[k] = Right_half[j];
		j++; k++;
	}
	free(Left_half);
	free(Right_half);
}


static void MergeSort(char** arr, int start, int end)
{
	if(start<end)
	{
		int mid = (start+end)/2;
		MergeSort(arr, start, mid);
		MergeSort(arr, mid+1, end);
		Merge(arr, start, mid, end);
	}
}



void intal_sort(char **arr, int n)
{
	int start = 0, end = n-1;
	MergeSort(arr, start, end);
}



char* coin_row_problem(char **arr, int n)
{
	if(n ==0)
	{
		return "0";
 	}
    char* prev = "0";
    char* cur = arr[0];
    char* next;
	int i;
    for(i=2; i<=n; i++)
	{
    	char* arrvalue=arr[i-1];
        char* temp=intal_add(prev,arrvalue);
        int value=intal_compare(temp,cur);
        if(value==1)
	    {
        	next=temp;
        }
        else
	 	{
            next=cur;
        }
        prev=cur;
        cur=next;
        }
	return cur;
}






