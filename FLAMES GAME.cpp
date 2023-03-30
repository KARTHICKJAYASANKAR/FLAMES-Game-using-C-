#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    char data;       // data stored in the node
    Node* next;     // pointer to the next node in the list
    
    Node(char val) {    // constructor to initialize node
        data = val;
        next = nullptr;
    }
};



int main()
{
   int t,lc; 
   stack<char>s;
   string name1,name2;
   vector<char>v1;
   vector<char>v2;
   
   
   int s1,s2,newS1,newS2,sum;
   
   cout<<"Enter your name : ";
   getline(cin,name1);
   cout<<"Enter your friend's name : ";
   getline(cin,name2);
   
   
   name1.erase(remove(name1.begin(), name1.end(), ' '), name1.end());
   name2.erase(remove(name2.begin(), name2.end(), ' '), name2.end());
   
   
   for(auto x : name1)
   {
       v1.push_back(tolower(x));
   }
   
   for(auto x : name2)
   {
       v2.push_back(tolower(x));
   }


   
   
// cout<<"\n before reducing name : ";
 s1 = v1.size();
 s2 = v2.size();
 //cout<<" s1 s2 are "<<s1<<" and "<<s2<<endl;

   
  for(int i=0 ; i<s1 ; i++)
  {
      for(auto j : v2)
      {
          if(v1[i] == j)
          {
              v1[i] = '0';
            
             auto f = find(v2.begin(),v2.end(),j);
             
             if(f != v2.end())
             {
                 v2.erase(f);
             }
              break;
          }
      }
  }
  
  
  //--------------------checking------------------------------//
//   for(auto it : v2)
//   cout<<" "<<it<<" ";
//   cout<<'\n';
//   for(auto it : v1)
//   cout<<" "<<it<<" ";
//   cout<<'\n';
  //--------------------checking---------------------------------------------//
  
  
  
 
  v1.erase( remove(v1.begin() , v1.end() , '0') , v1.end() );

//for(auto it : v1)
 // cout<<" "<<it<<" ";  //checking
  
  
  newS1 = v1.size();
  newS2 = v2.size();
  sum = newS1 + newS2;
  //cout<<"\nThe new size of S1 and S2 is : "<<newS1<<" and "<<newS2<<" and the sum is "<<sum<<endl;
  
//   for(int i=0,j=0 ; s.size()!=5 ;  )
//   {
//       //total number of reduced sum reah aanaa intha if//
//       if(j == sum-1)
//       {
//           cout<<F[i]<<" ";
//           s.push(F[i]);
//           F[i]='0';
//           j=0;
//       }
      
//       i++;
//       if(F[i]!='0')
//       j++;
      
//       if(i==6)
//       i=0;
      
//   }


//--------------------------------------using circular linked list--------------------------//

Node* Node1 = new Node('F');
Node* Node2 = new Node('L');
Node* Node3 = new Node('A');
Node* Node4 = new Node('M');
Node* Node5 = new Node('E');
Node* Node6 = new Node('S');

Node1->next = Node2;
Node2->next = Node3;
Node3->next = Node4;
Node4->next = Node5;
Node5->next = Node6;
Node6->next = Node1;



Node* temp;
Node* prev;
temp = Node1;
t=1;
lc = 6;
while(lc)
{
    

while(t!=sum)
{
    prev = temp;
    temp = temp->next;
    t++;
    
}
// cout<<" "<<temp->data<<" ";
prev->next = temp->next;
temp->next = NULL;
s.push(temp->data);
lc--;
temp = prev->next;
t=1;

} 
  
switch(s.top())
{
    case 'F' :
    cout<<"Relationship between "<<name1<<" and "<<name2<<" is FRIENDSHIP !!";
    break;
    
    case 'L' :
    cout<<"Relationship between "<<name1<<" and "<<name2<<" is LOVE !!";
    break;
    
    case 'A' :
    cout<<"Relationship between "<<name1<<" and "<<name2<<" is AFFECTION !!";
    break;
    
    case 'M' :
    cout<<"Relationship between "<<name1<<" and "<<name2<<" is MARRIAGE !!";
    break;
    
    case 'E' :
    cout<<"Relationship between "<<name1<<" and "<<name2<<" is ENEMY !!";
    break;
    
    case 'S' :
    cout<<"Relationship between "<<name1<<" and "<<name2<<" is SIBLINGS !!";
    break;
}

}
