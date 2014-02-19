#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <unistd.h>
using namespace std;


struct heap{
 int *els;//pointer to dynamic array of elements
 int numels;//number of elements
 void buildheap(/*source array*/int[],/*size of source array*/int);
 void reheapup(int values[],int root,int bottom);//sort an insertion from the bottom up
 void reheapdown(int values[],int root,int bottom);//sort an insertion from the top down.
 void freeheap();//delete the dynamic array of pointers. ready for rebuild
 heap sortmin();//returns an array sorted from min to max
 heap sortmax();//returns an array sorted from max to min

};
void heap::buildheap(/*source array*/int src[],/*size of source array*/int size){
 numels=size;
 els=new int[numels+1];
 cout<<"initial: "<<endl;
 for(int n=0;n<numels;++n){
  els[n]=src[n];
 }
 for(int n=numels/2+1;n>=0;--n){
  reheapdown(els,n,numels);
 }
 cout<<"heapified :"<<endl;

}

void heap::reheapdown(int rels[],int root,int bottom){
 int cmax,cl,cr;
 cl=root*2+1;//index of left child of parent
 cr=root*2+2;//index of right child of parent
 if(cl<=bottom){
  if(cl==bottom){
   cmax=cl;
  }else{
   if(rels[cl]<=rels[cr]){
    cmax=cr;
   }else{
    cmax=cl;
   }
  }
  if(rels[root]<rels[cmax]){
   swap(rels[root],rels[cmax]);
   reheapdown(rels,cmax,bottom);
  }
 }
}
void heap::reheapup(int values[],int root,int bottom){

}
void swap(int &p,int &c){
 int temp=p;
 p=c;
 c=temp;
}


heap heap::sortmin(){

 heap newh;
 newh.buildheap(els,numels);
 cout<<"sort started"<<endl;

 for(int n=newh.numels-1;n>0;--n){
  swap(newh.els[n],newh.els[0]);
  reheapdown(newh.els,0,n-1);
 }

 return newh;
}
heap heap::sortmax(){
  heap newh;


  return newh;
}
void heap::freeheap(){
 delete[] els;
}
void printheap(){

}
int main(){

 

 //////////////////////fill source array
 int source[100000];
 for(int n=0;n<100000;++n){
  source[n]=100000-n;
 }

 heap h;
 heap minmaxh;
 h.buildheap(source,100000);
 minmaxh=h.sortmin();
 for(int n=0;n<100000;++n){
  cout<<minmaxh.els[n]<<endl;
 }


 h.freeheap();
 minmaxh.freeheap();



 return 0;
}

