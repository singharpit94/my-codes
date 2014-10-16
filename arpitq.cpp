#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
using namespace::std;
 void display(int**,int ,int);
 void convert(int**,int,int ,int);

 void groupno(int**,int ,int ,int);
 void cost(int**,int,int,int);
 int  compare(int**,int ,int,int,int);
 void essp(int **,int ,int,int );
 int sizex,sizey,i,sum;
 int *arp=new int[10];
 int  **mat=new int*[5000];
 
  int **mad=new int*[5000];
  int **pi=new int*[500];
 int *earp=new int[10];
 int *ess=new int[1024];
 int *ess1=new int[1024];
 int *long1=new int[1024];
 int *long2=new int[1024];
 int *row2=new int[1024];
 int *row1 =new int[1024];
 int *arr=new int[1024];
 int *arr2=new int[1024];
 int longl(int **,int ,int );
 int row(int **,int ,int );
 int *ness=new int[1024];
 int ns=0;
 void cost(int **,int ,int);
 void lrc(int **pi,int sizex,int sizey);
 static int arpit=1;
 int nd=2;
    
 int main()
 {
 	
 	
 	cout<<"\t\tThis is a C++ program to implement the Quine Mcclauskey Method"<<"\t\tto minimize the given Boolean function\n";
 	cout<<"\t\t"<<"Created by Arpit Kumar Singh 13\\CS\\31 B.Tech 3rd Semester\n";
 		
 	for(i=0;i<5000;i++)
    {
    	mad[i]=new int[5000];
    }
 	int nv,nmin,i,j,k,s,q=0,r=0,h,ctr,o,t,y,x,v,x1,ctr5,flag,roll,choice;
 	
 	cout<<"Enter your roll no\n";
 	cin>>roll;
 	
	 cout<<"Enter no of variables\n";
 	cin>>nv;
 	
 	
 	
 	
 	
 	
 	
 	cout<<"Enter no of minterms\n";
    cin>>nmin;
 	//nmin=(rand()% int(pow(2,nv)) + 0);
 	//cout<<nmin<<"\n";
 	
 	sizex=nmin;
 	sizey=(nv+4);
 	vector<int> min(nmin);
 	
 	cout<<"\nEnter 1 to enter the minterms manually\nEnter 2 to generate the minterms randomly\n";
 	cin>>choice;
 	if(choice==1)
 	{
 	   for(i=0;i<nmin;i++)
 //min[i]=(rand()%int(pow(2,nv)) +0);
 	   cin>>min[i];
     cout<<"The minterms  are\n"; 
 	for(i=0;i<nmin;i++)
    	cout<<min[i]<<" ";
    }
    else
    {    
    	for(i=0;i<nmin;i++)
        min[i]=(rand()%int(pow(2,nv)) +0);
 	
     cout<<"The minterms generated are\n"; 
 	for(i=0;i<nmin;i++)
    	cout<<min[i]<<" ";
    }
    	for(i=0;i<5000;i++)
    {
    	mat[i]=new int[5000];
    }
    
    for(i=0;i<5000;i++)
    {
    	for(j=0;j<5000;j++)
    	mat[i][j]=0;
    }
    
   
    for(i=0;i<nmin;i++)
    mat[i][0]=min[i];
    for(i=0;i<nmin;i++)
    convert(mat,min[i],i,nv);
    
    groupno(mat,sizex,sizey,nv);
    cost(mat,sizex,sizey,nv);
  
    s=compare(mat,sizex,sizey,nv,nd);
    
    //display(mat,arp[0],arp[1]);
    //display(mad,earp[0],earp[1]);
   
      if(s==1)
   {
     while(1)
    {   nd*=2;

    
    	s=compare(mat,arp[0],arp[1],nv,nd);
    	if(s==2)
    	break;
    	
    }
  }
    cout<<"\nThe second last table\n";
    display(mat,arp[0],arp[1]);
    cout<<"\nThe last table \n";
    display(mad,earp[0],earp[1]);
    
   
    for(i=0;i<arp[0];i++)
    {   if(mat[i][1]!=0||nd==2) 
	   	{
	   	  if(mat[i][nv+(nd/2)+2]==0)
    	   q++;
        }
    }
   // cout<<q<<"\n";
    
    
    for(i=0;i<earp[0];i++)
    {
    	if(mad[i][1]!=0)
    	r++;
    }//cout<<r<<"\n";
    for(i=0;i<(q+r+2);i++)
    {
    	pi[i]=new int[nmin+3];
    }
    
    for(i=0;i<(q+r+2);i++)
    {
    	for(j=0;j<nmin+3;j++)
    	pi[i][j]=0;
    }
    
     pi[0][0]=pow(2,nv);
     for(j=1;j<nmin+1;j++)
     pi[0][j]=min[j-1];
     for(i=1;i<(q+r+1);i++)
     pi[i][0]=i;
     pi[q+r+1][0]=pow(2,nv)+1;
     for(i=1,j=0;i<r+1;j++)
     {
             if(mad[j][1]!=0)
             {
                 pi[i][nmin+1]=mad[j][nv+nd+1];
                 i++;
             }
     
     }
     for(i=r+1,j=0;i<q+r+1;j++)
     {
     	   if(mat[i][1]!=0||nd==2)
      {
      
     	   
		 
		 if(mat[j][nv+(nd/2)+2]==0)
     	{
     		pi[i][nmin+1]=mat[j][nv+(nd/2)+1];
     		i++;
     	}
      }
     }
     for(i=1,j=0;i<r+1;j++)
     {
     	if(mad[j][1]!=0)
     	{
     		for(h=0;h<nd;h++)
     		{
     			for(k=1;k<nmin+1;k++)
     			{
     				if(mad[j][h]==pi[0][k])
     				{
     					pi[i][k]=1;
     				}
     			}
     		}
     		i++;
     	}
     	
     }
     for(i=r+1,j=0;i<q+r+1;j++)
     {
     	
		 if(mat[j][1]!=0||nd==2)
		 {
		 
		   if(mat[j][nv+(nd/2)+2]==0)
     	  {
     		for(h=0;h<nd/2;h++)
     		{
     			for(k=1;k<nmin+1;k++)
     			{
     				if(mat[j][h]==pi[0][k])
     				{
     					pi[i][k]=1;
     				}
     			}
     		}
     		i++;
     	}
    
         }
     }
     
     //display(pi,q+r+2,nmin+3);
     
     t=0;
     for(i=1;i<nmin+1;i++)
     {   ctr=0;
     	for(j=1;j<q+r+1;j++)
     	{   
     		if(pi[j][i]==1)
     		{
     		  ctr++;
     		  o=j;
     	    }
     	}
     	if(ctr==1)
     	{
     	     ess[t]=o;
     	     t++;
     	}
     }
     y=0;
      for(i=0;i<t;i++)
      {  ctr=0;
      	for(j=i+1;j<t;j++)
      	{
      		if(ess[i]==ess[j])
      		ctr++;
      		
      	}
      	if(ctr==0)
      	{
      		ess1[y]=ess[i];
      		y++;
      	}
      	
      }
      cout<<"\n";
     // for(i=0;i<y;i++)
     // {
     // 	cout<<ess1[i]<<" ";
     // }
    //start
    cout<<"\n The essential prime implicants are\n";
      for(i=0;i<y;i++)
      {
      	for(j=1;j<q+r+2;j++)
      	{
      		if(pi[j][0]==ess1[i])
      		{    x=0;
      			for(k=1;k<nmin+1;k++)
      			{
      				if(pi[j][k]==1)
      				{
      				   arr[x]=pi[0][k];
      				   x++;
      		        }
      			}
      		}
      	} 
		 /* cout<<"\n";  
      	for(h=0;h<x;h++)
      	cout<<arr[h]<<" ";*/
      	
      	if(x<nd||nd==2)
      	{
      	
          for(j=0;j<arp[0];j++)
          {   
          	if(mat[j][1]!=0||nd==2)
		 {     
		    ctr5=0,x1=0,flag=0;
		 
		   if(mat[j][nv+(nd/2)+2]==0)
     	  {       flag=1;
     		     for(h=0;h<x;h++)
				  {
				  	if(arr[h]!=mat[j][h])
				  	ctr5++;
				  	
				  } 
          }
          
          
          if(ctr5==0&&flag==1)
          {
          	for(h=nd/2;h<(nd/2)+nv;h++)
          	{
          		arr2[x1]=mat[j][h];
          		x1++;
          	}
          	cout<<"\n";
          	for(h=0;h<x1;h++)
          	{
          		if(arr2[h]==0)
          		cout<<char(65+h)<<"'";
          		else if(arr2[h]==1)
          		cout<<char(65+h);
          	//	else
          	//	cout<<"1";
          		
          		
          	}
          	
          }
          
   }
    
        
      }
}


   else
   {
   	    for(j=0;j<earp[0];j++)
          {   
          	if(mad[j][1]!=0)
		 {     
		    ctr5=0,x1=0;
		 
		   
     	  {       
     		     for(h=0;h<x;h++)
				  {
				  	if(arr[h]!=mad[j][h])
				  	ctr5++;
				  	
				  } 
          }
          
          
          if(ctr5==0)
          {
          	for(h=nd;h<(nd)+nv;h++)
          	{
          		arr2[x1]=mad[j][h];
          		x1++;
          	}
          	cout<<"\n";
          	for(h=0;h<x1;h++)
          	{
          		if(arr2[h]==0)
          		cout<<char(65+h)<<"'";
          		else if(arr2[h]==1)
          		cout<<char(65+h);
          	//	cout<<"1";
          		
          		
          	}
          	
          }
          
   }
    
        
      }
   	
   }
}
   
   
   if(y>0)
   essp(pi,q+r+2,nmin+3,y);
   else
   lrc(pi,q+r+2,nmin+3);
   //for(i=0;i<ns;i++)
   //cout<<ness[i]<<" ";
   //display(pi,q+r+2,nmin+3);
   cout<<"\nThe non - essential prime implicants are\n";
   for(i=0;i<ns;i++)
      {
      	for(j=1;j<q+r+2;j++)
      	{
      		if(pi[j][0]==ness[i])
      		{    x=0;
      			for(k=1;k<nmin+1;k++)
      			{
      				if(pi[j][k]==1)
      				{
      				   arr[x]=pi[0][k];
      				   x++;
      		        }
      			}
      		}
      	} 
		 /* cout<<"\n";  
      	for(h=0;h<x;h++)
      	cout<<arr[h]<<" ";*/
      	
      	if(x<nd||nd==2)
      	{
      	
          for(j=0;j<arp[0];j++)
          {   
          	if(mat[j][1]!=0||nd==2)
		 {     
		    ctr5=0,x1=0,flag=0;
		 
		   if(mat[j][nv+(nd/2)+2]==0)
     	  {       flag=1;
     		     for(h=0;h<x;h++)
				  {
				  	if(arr[h]!=mat[j][h])
				  	ctr5++;
				  	
				  } 
          }
          
          
          if(ctr5==0&&flag==1)
          {
          	for(h=nd/2;h<(nd/2)+nv;h++)
          	{
          		arr2[x1]=mat[j][h];
          		x1++;
          	}
          	cout<<"\n";
          	for(h=0;h<x1;h++)
          	{
          		if(arr2[h]==0)
          		cout<<char(65+h)<<"'";
          		else if(arr2[h]==1)
          		cout<<char(65+h);
          	//	else
          	//	cout<<"1";
          		
          		
          	}
          	
          }
          
   }
    
        
      }
}


   else
   {
   	    for(j=0;j<earp[0];j++)
          {   
          	if(mad[j][1]!=0)
		 {     
		    ctr5=0,x1=0;
		 
		   
     	  {       
     		     for(h=0;h<x;h++)
				  {
				  	if(arr[h]!=mad[j][h])
				  	ctr5++;
				  	
				  } 
          }
          
          
          if(ctr5==0)
          {
          	for(h=nd;h<(nd)+nv;h++)
          	{
          		arr2[x1]=mad[j][h];
          		x1++;
          	}
          	cout<<"\n";
          	for(h=0;h<x1;h++)
          	{
          		if(arr2[h]==0)
          		cout<<char(65+h)<<"'";
          		else if(arr2[h]==1)
          		cout<<char(65+h);
          		//cout<<"1";
          		
          		
          	}
          	
          }
          
   }
    
        
      }
   	
   }
}
 
   
   
   
   
   
    
 	return 0;
 }
 
 void display(int **jee,int sizex,int sizey)
 {   int i,j,ctr;
 	for(i=0;i<sizex;i++)
    {   
      ctr=0;
    	
    	
    	
		  for(j=0;j<sizey;j++)
		  {
		  	if(jee[i][j]!=0)
		  	ctr++;
		  }
		  if(ctr)
		  {  cout<<"\n";
		  	for(j=0;j<sizey;j++)
		  	cout<<jee[i][j]<<" ";
		  	
		  }
    	  
         
    }
 	
 	
 	
 }
 void convert(int **mat,int mint,int pos,int n)
 {     int i;
       i=n;
      while(mint>0)
      {
      	mat[pos][i]=mint%2;
      	i--;
      	mint=mint/2;
      }
 }
 /*void count1(int **mat,int sizex,int sizey,int nv)
 
 {
 	int i,j,k,ctr;
 	j=nv+1;
 	for(i=0;i<sizex;i++)
 	{    ctr=0;
 		for(k=1;k<(nv+1);k++)
 		{
 			if(mat[i][k]==1)
 			ctr++;
 		}
 		mat[i][j]=ctr;
 	}
 }*/
 void groupno(int **mat,int sizex,int sizey,int nv)
 {
 	int i,j,k,ctr;
 	j=nv+1;
 		for(i=0;i<sizex;i++)
 	{    ctr=0;
 		for(k=1;k<(nv+1);k++)
 		{
 			if(mat[i][k]==1)
 			ctr++;
 		}
 		mat[i][j]=ctr;
 	}
 	
 }
 void cost(int **mat,int sizex,int sizey,int nv)
 {
 	int i,j,k,ctr;
 	j=nv+2;
 	for(i=0;i<sizex;i++)
 	{
 		ctr=0;
 		for(k=1;k<(nv+1);k++)
 		{
 			if(mat[i][k]==1||mat[i][k]==0)
 			ctr++;
 		}
 		mat[i][j]=ctr;
 	}
 }
 int compare(int **mat,int sizex,int sizey,int nv,int nd)
 {
 	
	 
	 int i,j,k,ctr,a=0,d,e,w,x,h,b,c,p,sum1,sum2,g,q,flag=0,ftr;
     
    for(i=0;i<5000;i++)
    {
    	for(j=0;j<5000;j++)
    	mad[i][j]=0;
    }
    k=nv+(nd/2);
    for(i=0;i<sizex;i++)
    {   
    	for(j=0;j<sizex;j++)
    	{   ctr=0;
    		if(mat[i][k]==mat[j][k]-1)
    		{    d=i,e=j;
    			for(h=(nd/2);h<nv+(nd/2);h++)
    			{
    				if(mat[i][h]!=mat[j][h])
    				ctr++;
    			} 
    			if(ctr==1)
    			{   
    			     mat[i][nv+(nd/2)+2]=1;//for selection of primne implicants
    			     mat[j][nv+(nd/2)+2]=1;
    			
    			    p=0;
    				for(b=0;b<2;b++)//for decimal values
    				{
    					for(c=0;c<(nd/2);c++)
    					{
    						mad[a][p]=mat[d][c];
    						
    						p++;
    						
    						
    					}
    					d=e;
    				}
    				
    				w=nd;
    					for(x=nd/2;x<nv+(nd/2);x++)//for compared values
    					{
    						if(mat[i][x]!=mat[j][x])
    						{
    						    mad[a][w]=mat[j][x]+1;
    						    w++;
    				     	}
    						else
    						{
    						   mad[a][w]=mat[j][x];
    						   w++;
    					    }
    					}
    					mad[a][w]=mat[j][nv+(nd/2)]+10;//insert new group no;
    					w++;
    					mad[a][w]=mat[j][nv+(nd/2)+1]-1;//insert cost;
    					w++;
    					a++;
    					
    					
    					
    					
    				
    				
    			}
    			else
    			continue;
    		}
    		
    	}
    }
   for(i=0;i<a;i++)
    {    
    	for(j=i+1;j<a;j++)
    	{    ctr=0;
    		for(h=nd;h<(nd+nv);h++)
    		{    
    		     if(mad[i][h]!=mad[j][h])
    		     ctr++;
    		}
    		if(ctr==0)
    		for(h=0;h<w+1;h++)
    		mad[j][h]=0;
    	}
    }
    
    cout<<"\nThe prime impicants after  "<<arpit<<"   comparisons\n";
    arpit++;
    for(i=0;i<a;i++)
    {    ftr=0;
    	for(h=0;h<nd;h++)
    	       
    	{
    		if(mad[i][h]!=0)
    		ftr++;
    	}
    	if(ftr)
    	{   cout<<"\n";
    	   for(h=0;h<nd;h++)
    	   cout<<mad[i][h]<<" ";
        }
    }
   
   //display(mad,a,w+1);
  
   nd=2*nd;
   k=nv+(nd/2);
    for(i=0;i<a;i++)
    {   
    	for(j=0;j<a;j++)
    	{   ctr=0;
    		if(mad[i][k]==mad[j][k]-1)
    		{    //d=i,e=j;
    			for(h=(nd/2);h<nv+(nd/2);h++)
    			{
    				if(mad[i][h]!=mad[j][h])
    				ctr++;
    			} 
    			if(ctr==1)
    			{         
    			        for(i=0;i<5000;i++)
                        {
    	                   for(j=0;j<5000;j++)
    	                   mat[i][j]=0;
                        }
                        g=0;
                        for(i=0;i<a;i++)
                        {   //if(mad[i][1]!=0)
                        
                        	{   g++;
                        	   for(j=0;j<w+1;j++)
                        	   mat[i][j]=mad[i][j];
                            }
                        }
                        //display(mat,g,w+1);
                        
                      flag=1;
                      break;  
                   
    			}
    		
    				
    			
    			
    			
    			
    			
    			
    			
   
           }
           
      }
	  if(flag==1)
           break;
       
       
       
    }
    if(flag==1)
   
    {
    	
    	arp[0]=g;
        arp[1]=w+1;
        earp[0]=a;
        earp[1]=w+1;
        
        
    
      /* for( i = 0; i < 5000; i++) {
       delete [] mad[i];
                                }
        delete [] mad;*/
    
        return 1;
    	
    	
    	
    	
    }
    else
    {
      /*	for(i=0;i<5000;i++)
    	{
    		eprime[i]=new int[5000];
    	}
    	for(i=0;i<5000;i++)
    	{
    		for(j=0;j<5000;j++)
    		eprime[i][j]=0;
    	}
    	
    	
    
    	                q=0;
                        for(i=0;i<a;i++)
                        {   if(mad[i][1]!=0)
                        
                        	{   q++;
                        	   for(j=0;j<w;j++)
                        	   eprime[i][j]=mad[i][j];
                            }
                        }
                        	display(mad,a,w+1);
                        earp[0]=q;
                        earp[1]=w+1;*/
                       
					   
					   
					   
					   
					   
					   
					   /*for(i=0;i<a;i++)
                        {   if(mad[i][1]!=0)
                        
                        	   q++;}
                        	   display(mad,a,w+1);*/
					    arp[0]=sizex;
					    arp[1]=sizey;
						 earp[0]=a;
                        earp[1]=w+1 ;return 2;
    	
    }
    
    
   
    
}


void essp(int **pi,int sizex,int sizey,int y)
{
	int i,j,l,r,ctr,flag=0;
	
	for(i=0;i<y;i++)
    {
    	for(j=1;j<sizey-2;j++)
    	{
    		if(pi[ess1[i]][j]==1)
    		{
    			pi[sizex-1][j]=1;
    		}
    	}
    }
     for(i=1;i<sizex-1;i++)
     {   ctr=0;
     	for(j=1;j<sizey-2;j++)
     	{
     		if(pi[sizex-1][j]==0&&pi[i][j]==1)
     		ctr++;
     	}
     	if(ctr==0)
     	pi[i][sizey-1]=1;
     }
    
    
    
    
   //display(pi,sizex,sizey);

   sum=0;
    for(i=1;i<(sizex-1);i++)
    {
    	sum+=pi[i][sizey-1];
    }
	if(sum==sizex-2)
	cout<<"\n"<<"\n";
	else
	{   l=longl(pi,sizex,sizey);
		  if(l==sizex-2)
		  cout<<"\n";
		   
		  r=row(pi,sizex,sizey);
		  if(r==sizex-2)
		  cout<<"\n";
		while(!(r==0||(r==0&&l==0)))
		{   
		  l=longl(pi,sizex,sizey);
		  if(l==sizex-2)
		  cout<<"\n";
		   
		  r=row(pi,sizex,sizey);
		  if(r==sizex-2)
		  cout<<"\n";
		  
		  
			
		}
	//	display(pi,sizex,sizey);
	    sum=0;
    for(i=1;i<(sizex-1);i++)
    {
    	sum+=pi[i][sizey-1];
    }
		if(sum!=sizex-2)
		{
			cost(pi,sizex,sizey);
			
		}
		
		
		
	}
	
		
	
	
}


int longl(int **pi,int sizex,int sizey)
{
	int i,j,k,l,l1,ctr,ctr1,ctr2,m,n,flag=0,z;
	for(i=1;i<(sizey-2);i++)
  {      l=0,ctr=0;
		if(pi[sizex-1][i]==0)
		{
			for(j=1;j<(sizex-1);j++)
			{
				if(pi[j][i]==1&&pi[j][sizey-1]==0)
				{
				    ctr++;
			     	long1[l]=j;
			     	l++;
			    }
			}
			for(k=i+1;k<(sizey-2);k++)
			{    l1=0,ctr1=0;
				if(pi[sizex-1][k]==0)
				{
					for(m=1;m<(sizex-1);m++)
					{
						if(pi[m][k]==1&&pi[m][sizey-1]==0)
						{
						  ctr1++;
						   long2[l1]=m;
						   l1++;
					    }
					}
				
			
			       if(l>l1)
			       {   ctr2=0;
				      for(n=0;n<l1;n++)
				    {  
				       for(z=0;z<l;z++)
				       {
				       	if(long2[n]==long1[z])
				       	ctr2++;
				       }
				       
				    }
				     if(ctr2==l1)
				    {
					   pi[sizex-1][i]=1;
					   flag=1;
			     	}
		 	       }
		 	       else if(l<l1)
		 	       {
		 	       	  ctr2=0;
				      for(n=0;n<l;n++)
				    {  
				       for(z=0;z<l1;z++)
				       {
				       	if(long1[n]==long2[z])
				       	ctr2++;
				       }
				       
				    }
				     if(ctr2==l)
				    {
					   pi[sizex-1][k]=1;
					   flag=1;
			     	}
		 	       	
		 	       	
		 	       	
		 	       }
		  }
		  
		}
     }
	}
	for(i=1;i<sizex-1;i++)
     {   ctr=0;
     	for(j=1;j<sizey-2;j++)
     	{
     		if(pi[sizex-1][j]==0&&pi[i][j]==1)
     		ctr++;
     	}
     	if(ctr==0)
     	pi[i][sizey-1]=1;
     }
	if(flag==1)
	{
	     sum=0;
    for(i=1;i<(sizex-1);i++)
    {
    	sum+=pi[i][sizey-1];
    }
	if(sum==sizex-2)
	return sum;
	else
	return 1;
	}
	else
	return 0;
	
}

int row(int **pi,int sizex,int sizey)
{
	int i,j,k,l,flag,n,flag1,flag2,m,r,r1,ctr,z;
	for(i=1;i<(sizex-1);i++)
	{    
	    if(pi[i][sizey-1]==0)
	     
	  {
	    r=0,flag=0;
	     
		for(j=1;j<(sizey-2);j++)
		{
			if(pi[i][j]==1&&pi[sizex-1][j]==0)
			{
				row1[r]=j;
				r++;
				flag=1;
				
			}
		}
		if(flag==1)
		{
		
		for(k=i+1;k<(sizex-1);k++)
		{     if(pi[k][sizey-1]==0) 
		      
	      {
	      
		        r1=0,flag1=0,ctr=0;
		      for(m=1;m<(sizey-2);m++)
			  {
			  	if(pi[k][m]==1&&pi[sizex-1][m]==0)
			     {row2[r1]=m;
			  	   r1++;
			  	   flag1=1;
			     }
			  }	
			  
			  if(flag1==1)
			  {
			  	if(r1>r)
			  	{
			  		for(n=0;n<r;n++)
			  		{
			  			
						  for(z=0;z<r1;z++)
						  
						  {
						    if(row1[n]==row2[z])
			  			     ctr++;
			  			}
			  		}
			  		if(ctr==r)
			  		{
			  			pi[i][sizey-1]=1;
			  			flag2=1;
			  			
			  		}
			  	}else if(r1<r)
			  	{
			  		for(n=0;n<r1;n++)
			  		{
			  			 for(z=0;z<r;z++)
						  
						  {
						    if(row2[n]==row1[z])
			  			     ctr++;
			  			}
			  		}
			  		if(ctr==r1)
			  		{
			  			pi[k][sizey-1]=1;
			  			flag2=1;
			  			
			  		}
			  	}
			  }
		}
          }
	   
	    }
      }
	}
	
	
    
	if(flag2==1)
	{
	sum=0;
    for(i=1;i<(sizex-1);i++)
    {
    	sum+=pi[i][sizey-1];
    }
	if(sum==sizex-2)
      return sum;
      else
      return 1;
	}
	else
	return 0;
}


void cost(int **pi,int sizex,int sizey)
{
	int i,j,k,l,ctr=0,pos,min,ctr1,ctr2,l1,r;
	int *try1=new int[1024];
	for(i=0;i<1024;i++)
	try1[i]=0;
	for(i=1;i<sizex-1;i++)
	{    if(pi[i][sizey-1]==0)
	  {
	  
		for(j=i+1;j<sizex-1;j++)
		{      if(pi[j][sizey-1]==0)
		{
		
			if(pi[i][sizey-2]!=pi[j][sizey-2])
			{
			    ctr++;
			    break;
		    }
		}
	   }
		
		
		}if(ctr)
		break;
	}
	if(ctr)
	{
		min=pi[1][sizey-2];
		
		for(i=1;i<sizex-1;i++)
		{    if(pi[i][sizey-1]==0)
		{
		
			if(pi[i][sizey-2]<min)
			{
			   min=pi[i][sizey-2];
			
		    }
		}
	   }
		l1=0;
		for(i=1;i<sizex-1;i++)
		{    if(pi[i][sizey-1]==0)
		{
		
			if(pi[i][sizey-2]==min)
			{
				try1[l1]=i;
				l1++;
			}
		}
	  }ctr1=0;
		for(i=0;i<l1;i++)
		{   ctr2=0;
			for(k=1;k<sizey-2;k++)
			{
				if(pi[try1[i]][k]==1&&pi[sizex-1][k]==0)
				{
					ctr2++;
				}
				
			}
			if(ctr2>ctr1)
				{
					ctr1=ctr2;
					pos=try1[i];
				}
		}
		ness[ns]=pos;
		ns++;
		for(j=1;j<sizey-2;j++)
    	{
    		if(pi[pos][j]==1)
    		{
    			pi[sizex-1][j]=1;
    		}
    	}
    	
		for(i=1;i<sizex-1;i++)
     {   ctr=0;
     	for(j=1;j<sizey-2;j++)
     	{
     		if(pi[sizex-1][j]==0&&pi[i][j]==1)
     		ctr++;
     	}
     	if(ctr==0)
     	pi[i][sizey-1]=1;
     }
     sum=0;
    for(i=1;i<(sizex-1);i++)
    {
    	sum+=pi[i][sizey-1];
    }
	if(sum==sizex-2)
	cout<<"\n";
	else
	{
		l=longl(pi,sizex,sizey);
		  if(l==sizex-2)
		  cout<<"\n";
		   
		  r=row(pi,sizex,sizey);
		  if(r==sizex-2)
		  cout<<"\n";
		while(!(r==0||(r==0&&l==0)))
		{   
		  l=longl(pi,sizex,sizey);
		  if(l==sizex-2)
		  cout<<"\n";
		   
		  r=row(pi,sizex,sizey);
		  if(r==sizex-2)
		  cout<<"\n";
		  
		  
			
		}
	//	display(pi,sizex,sizey);
		if(sum!=sizex-2)
		{
			cost(pi,sizex,sizey);
			
		}
	}
		
		
	}
	else
	{    l1=0;
	       for(i=1;i<sizex-1;i++)
		{    if(pi[i][sizey-1]==0)
		{
		
			
			
				try1[l1]=i;
				l1++;
			
		}
	}
	ctr1=0;
		for(i=0;i<l1;i++)
		{   ctr2=0;
			for(k=1;k<sizey-2;k++)
			{
				if(pi[try1[i]][k]==1&&pi[sizex-1][k]==0)
				{
					ctr2++;
				}
				
			}
			if(ctr2>ctr1)
				{
					ctr1=ctr2;
					pos=try1[i];
				}
		}
		ness[ns]=pos;
		ns++;
		for(j=1;j<sizey-2;j++)
    	{
    		if(pi[pos][j]==1)
    		{
    			pi[sizex-1][j]=1;
    		}
    	}
    	
		for(i=1;i<sizex-1;i++)
     {   ctr=0;
     	for(j=1;j<sizey-2;j++)
     	{
     		if(pi[sizex-1][j]==0&&pi[i][j]==1)
     		ctr++;
     	}
     	if(ctr==0)
     	pi[i][sizey-1]=1;
     }
	 sum=0;
    for(i=1;i<(sizex-1);i++)
    {
    	sum+=pi[i][sizey-1];
    }
	if(sum==sizex-2)
	cout<<"\n";
	else
	{
		l=longl(pi,sizex,sizey);
		  if(l==sizex-2)
		  cout<<"\n";
		   
		  r=row(pi,sizex,sizey);
		  if(r==sizex-2)
		  cout<<"\n";
		while(!(r==0||(r==0&&l==0)))
		{   
		  l=longl(pi,sizex,sizey);
		  if(l==sizex-2)
		  cout<<"\n";
		   
		  r=row(pi,sizex,sizey);
		  if(r==sizex-2)
		  cout<<"\n";
		  
		  
			
		}
	//	display(pi,sizex,sizey);
		if(sum!=sizex-2)
		{
			cost(pi,sizex,sizey);
			
		}
	}
	
		
	}
}   

void lrc(int **pi,int sizex,int sizey)
{    int l,r,i,j,k;
      l=longl(pi,sizex,sizey);
		  if(l==sizex-2)
		  cout<<"\n";
		   
		  r=row(pi,sizex,sizey);
		  if(r==sizex-2)
		  cout<<"\n";
		while(!(r==0||(r==0&&l==0)))
		{   
		  l=longl(pi,sizex,sizey);
		  if(l==sizex-2)
		  cout<<"\n";
		   
		  r=row(pi,sizex,sizey);
		  if(r==sizex-2)
		  cout<<"\n";
		  
		  
			
		}
	//	display(pi,sizex,sizey);
	    sum=0;
    for(i=1;i<(sizex-1);i++)
    {
    	sum+=pi[i][sizey-1];
    }
		if(sum!=sizex-2)
		{
			cost(pi,sizex,sizey);
			
		}
		
		
			
}



 
 	
 
