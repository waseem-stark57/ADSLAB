#define MAX 10
#include <iostream>
#include <stdlib.h>
using namespace std;
class HashTable{
    private:
        int *ht;
    public:
        HashTable(){
            ht=(int *)calloc(MAX,sizeof(int));
            
        }
        int hashKey(int val){
            int i;
            i=val%10;
            return i;
        }
        void insert(int val){
            int index;
            index=hashKey(val);
            ht[index]=val;
            
        }
        int search(int val){
            int i;
            i=hashKey(val);
            if(ht[i]==val){
                return  i;
            }
            else{
                return -1;
                
            }
        }
        void remove(int val){
            int i;
            i=search(val);
            if(i==-1){
                cout<<"\n no such element";
            }
            else{
                ht[i]=0;
                cout<<"Element removed...";
            }
        }
        
};
int main(){
    HashTable obj;
    int a[5]={24,36,45,90,22};
    for(int i=0;i<5;i++)
        obj.insert(a[i]);
    obj.insert(25);
    obj.insert(90);
    int p=obj.search(36);
    if(p==-1){
        cout<<"\n Element not found...";
            
        }
    else{
        cout<<"Element found at "<<p<<" position";
        }
    return 0;
    
}
