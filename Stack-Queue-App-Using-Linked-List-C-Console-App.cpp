#include <iostream> // C++ i�in temel k�t�phane  
#include <cstdlib>  // malloc fonksiyonunun �al��mas� i�in gerekli olan k�t�phane
#include<locale.h> // T�rk�e karakterlerin d�zg�n g�r�nt�lenmesi i�in gerekli olan k�t�phane, g�rsellik 10 puan oldu�u i�in eklemek daha iyi olur.
#include <bits/stdc++.h> // Ortaya eleman eklemek i�in gerekli hare ve tortoise algoritmas�nda kullan�lan fast-slow pointer mant���yla �al��an kodlar i�in olan k�t�phane  
using namespace std; // her seferinde std:: yapmamak i�in gerekli kod  

/* -----------------    ---------------   Buras� Stack yani Y���n i�in Ana men�deki 1 numaral� k�s�m�n Ba�lang�c� --------------------------   */

class Node {  // Temel D���m yap�s�: Veri ve Adres
public: // class tan�mland���nda private olarak gelir dolay�s�yla public'e �evirmez isek eri�im sa�lanamayaca��ndan kod �al��mayabilir. 
   int data; // D���m�n veri tutan k�s�m� 
   class Node *next; // D���m�n adresi ''&'' tutan k�sm�
}; // S�n�f tan�m�m�z� sonland�rd�k


class Node* top = NULL;  // Y���n yap�s�nda en �st k�sm� ba�lang��ta bo� olarak belirlemek i�in
void push(int deger) { // Y���n yap�s�n�n �al��ma mant��� F�FO first in first out'a g�re yapt���m�z void tipinde bir push yani eleman ekleme fonksiyonu  
   class Node* newnode = (class Node*) malloc(sizeof(class Node));  /* malloc() fonksiyonu tahsis edilmi� belle�in ba�lang�c�n� g�steren bir i�aret�i geri verir. 
   Tahsis edilmek istenen bellek ihtiyac�n� kar��layamad���nda, NULL bir i�aret�i geri verir. Dolay�s�yla Malloc kullan�m� �u i�e yarar, kullanaca��n�z de�erleri bilirsiniz, 
   o de�erlerin kaplayaca�� alandan daha fazlas�n� bilgisayara y�klemezsiniz,
     */     
   newnode->data = deger; // Y���n i�in gerekli yap�
   newnode->next = top;   //  Y���n i�in gerekli yap�
   top = newnode; // Y���n i�in gerekli yap�
}
void pop() {  // �imdi de Y���n�n �al��ma mant��� F�FO'ya g�re bir pop yan� ��karma fonksiyonunu void tipinde olu�turuyoruz. 
   if(top==NULL) // en �st bo� ise bunu yaps�n
      cout<<"Y���n Bo� oldu�u i�in Eleman ��kar�lamamaktad�r"<<endl;
   else {  // en �st bo� de�il ise bunu yaps�n
      cout<<"Y���ndan ��kar�lan Eleman�n De�eri :  "<< top->data <<endl;
      top = top->next; // En �st �n bir sonraki elemana aktar�lmas� i�in gerekli kod 
   }
}
void display() { // Y���ndaki elemanlar� g�stermek i�in gerekli void tipinde display fonksiyonu 
   class Node* ptr;
   if(top==NULL) 
      cout<<"Y���nda Eleman Bulunmamaktad�r, Y���n Bo�tur. ";
   else {   
      ptr = top; // Y���n i�in gerekli yap�
      cout<<"Y���n Elemanlar� �unlard�r (Sonuncu Eleman en yukar�daki elemand�r): "<<endl;
       
      while (ptr != NULL) { // hi� bir yere i�aret edilmiyorsa �unu yaps�n 
         cout<< ptr->data <<" "<<endl; 
         ptr = ptr->next; 
      } 
   }
   cout<<endl;
}

int count_recursive(Node* top) {   // Eleman "say�s�n�" g�steren kod int tipinde �z yinelemeli rek�rsif  kod par�as�      
   if (top == NULL) // en �st bo� ise; 
      return 0; // s�f�r g�nder 
   return 1 + count_recursive(top->next); // de�ilse 1 g�nder ve �unu ekle 
}   

void deleteList(Node** top) /* T�m y���n� temizlemek/silmek i�in gerekli fonksiyon, ampersant & adres de�eri isteyen void tipinde */ 
{  
      
/* y���n�n ger�ek ba��na ula�mak i�in �uanki y���n ba��n� referanstan ��kar�yoruz */
Node* current1 = *top;  
Node* next;  
  
while (current1 != NULL)  // �uanki d���m bir yeri i�aret etmiyosa
{  
    next = current1->next;  // Y���n i�in gerekli yap�
    free(current1);  // Y���n i�in gerekli yap�
    current1 = next;  // Y���n i�in gerekli yap�
}  
      

*top = NULL;  /* Y���n�n ger�ek ba��n� rek�rsif olarak �a��r�c� da etkileyebilmek i�in bunu yazd�k */
}  


/* ------------ ---------  Buras� Stack yani Y���n i�in Ana men�deki 1 numaral� k�s�m�n Sonu --------------------------------------  */ 
/* -----------------    ---Buras� Queue yani Kuyruk i�in Ana men�deki 2 numaral� k�s�m�n Ba�lang�c� --------------------------   */

class Nodekuyruk { // Temel d���m yap�s� 
public:	
   int datakuyruk;
   class Nodekuyruk *next2;
};
class Nodekuyruk* front2 = NULL; // kuyruk �n� 
class Nodekuyruk* rear2 = NULL;  // kuyruk arkas� 
class Nodekuyruk* temp2; // ge�ici temporary 
void Insert2() { // kuyru�a eleman ekleme 
   int deger2; // de�er - value 
   cout<<"Kuyru�a eklenecek eleman�n de�erini giriniz : "<<endl;
   cin>>deger2; // de�eri kullan�c�dan almak i�in 
   if (rear2 == NULL) { // arka bo� ise 
      rear2 = (class Nodekuyruk *)malloc(sizeof(class Nodekuyruk)); // Kuyruk i�in gerekli yap�
      rear2->next2 = NULL; // Kuyruk i�in gerekli yap�
      rear2->datakuyruk = deger2; // Kuyruk i�in gerekli yap�
      front2 = rear2; // Kuyruk i�in gerekli yap�
   } else {  // arka bo� de�ilse 
      temp2=(class Nodekuyruk *)malloc(sizeof(class Nodekuyruk));
      rear2->next2 = temp2; // Kuyruk i�in gerekli yap�
      temp2->datakuyruk = deger2; // Kuyruk i�in gerekli yap�
      temp2->next2 = NULL; // Kuyruk i�in gerekli yap�
      rear2 = temp2; // Kuyruk i�in gerekli yap�
   }
}
void Delete2() { // Last in first out L�FO mant��� ile kuyruk yap�s� i�in eleman silme, ��karma fonksiyonu, yine void tipinde 
   temp2 = front2;
   if (front2 == NULL) {
      cout<<"Kuyruk Bo� oldu�u i�in Eleman ��kar�lamamaktad�r"<<endl;
      return;
   }
   else
   if (temp2->next2 != NULL) {
      temp2 = temp2->next2;
      cout<<"Kuyruktan ��kar�lan Eleman : "<<front2->datakuyruk<<endl;
      free(front2);  /* C ++ 'daki free () i�levi daha �nce calloc, malloc veya realloc i�levleri kullan�larak ayr�lan bir bellek blo�unu 
yeniden konumland�r�r ve b�ylece daha fazla ay�rma i�in kullan�labilir hale getirir. 
fonksiyon, <cstdlib> ba�l�k, header dosyas�nda tan�ml�d�r */
      front2 = temp2;
   } else {
      cout<<"Kuyruktan ��kar�lan Eleman : "<<front2->datakuyruk<<endl;
      free(front2);
      front2 = NULL;
      rear2 = NULL;
   }
}
void Display2() { // kuyruk elemanlar�n� g�stermek i�in 
   temp2 = front2;
   if ((front2 == NULL) && (rear2 == NULL)) {
      cout<<"Kuyrukta hi� eleman yoktur, kuyruk bo�tur. "<<endl;
      return;
   }
   cout<<"Kuyruk Elemanlar� �unlard�r (En soldaki eleman ilk elemand�r) : ";
   while (temp2 != NULL) {
      cout<<temp2->datakuyruk<<" ";
      temp2 = temp2->next2;
   }
   cout<<endl; 
}

int count_recursive2(Nodekuyruk* front2) {  // kuyruk elemanlar�n� saymak i�in     
   if (front2 == NULL)
      return 0;
   return 1 + count_recursive2(front2->next2); 
}  // bu fonksiyon ile elemanlar� say�yoruz 


/* T�m kuyru�u temizlemek/silmek i�in gerekli fonksiyon */
void deleteList2(Nodekuyruk** front2)  
{  
      
/* kuyru�un ger�ek ba��na ula�mak i�in �uanki kuyruk ba��n� referanstan ��kar�yoruz */
Nodekuyruk* current2 = *front2;  
Nodekuyruk* next2;  
   
while (current2 != NULL)  
{  
    next2 = current2->next2;  
    free(current2);  
    current2 = next2;  
}  
      
/* kuyru�un ger�ek ba��n� rek�rsif olarak �a��r�c� da etkileyebilmek i�in bunu yazd�k */
*front2 = NULL;  
}  

/* -----------------    ---Buras� Queue yani Kuyruk i�in Ana men�deki 2 numaral� k�s�m�n Sonu --------------------------   */
/* -----------------    ---Buras� Singly Linked List yani Tek Y�nl� Ba�l� liste i�in Ana men�deki 3 numaral� k�s�m�n Ba�lang�c� --------------------------   */

class Node_tek_liste { // temel d���m yap�s�, yine ayn� �eyler 
public: 
   int data_liste;  
   class Node_tek_liste *next3; 
}; 


class Node_tek_liste* top3 = NULL;  
void push3(int deger3) { 
   class Node_tek_liste* newnode3 = (class Node_tek_liste*) malloc(sizeof(class Node_tek_liste));  
   newnode3->data_liste = deger3; 
   newnode3->next3 = top3; 
   top3 = newnode3; 
}
void pop3() {
   if(top3==NULL)
      cout<<"Tek y�nl� liste Bo� oldu�u i�in Eleman ��kar�lamamaktad�r"<<endl;
   else {
      cout<<"Tek y�nl� listeden ��kar�lan Eleman�n De�eri :  "<< top3->data_liste <<endl;
      top3 = top3->next3;
   }
}
void display3() {
   class Node_tek_liste* ptr3;
   if(top3==NULL)
      cout<<"Tek y�nl� listede Eleman Bulunmamaktad�r, Liste Bo�tur. ";
   else {   
      ptr3 = top3; 
      cout<<"Tek y�nl� liste elemanlar� �unlard�r: (Sonuncu Eleman en yukar�daki elemand�r): "<<endl;
       
      while (ptr3 != NULL) { 
         cout<< ptr3->data_liste <<" "<<endl; 
         ptr3 = ptr3->next3; 
      } 
   }
   cout<<endl;
}

int count_recursive3(Node_tek_liste* top3) {        
   if (top3 == NULL)
      return 0;
   return 1 + count_recursive3(top3->next3); 
}  // bu fonksiyon ile elemanlar� say�yoruz 


/* T�m listeyi temizlemek/silmek i�in gerekli fonksiyon */
void deleteList3(Node_tek_liste** top3)  
{  
      
/* listenin ger�ek ba��na ula�mak i�in �uanki y���n ba��n� referanstan ��kar�yoruz */
Node_tek_liste* current3 = *top3;  
Node_tek_liste* next3;  
  
while (current3 != NULL)  
{  
    next3 = current3->next3;  
    free(current3);  
    current3 = next3;  
}  
      
/* listenin ger�ek ba��n� rek�rsif olarak �a��r�c� da etkileyebilmek i�in bunu yazd�k */
*top3 = NULL;  
}  


// ------------------ Ortaya Eleman Ekleme Denemesi --------------------------------------------------------------------------

// function to create and return a node 
Node_tek_liste* getNode(int data_liste) 
{ 
    // allocating space 
    Node_tek_liste* newnode3 = (Node_tek_liste*)malloc(sizeof(Node_tek_liste)); 
  
    // inserting the required data 
    newnode3->data_liste = data_liste; 
    newnode3->next3 = NULL; 
} 
  
// function to insert node at the middle 
// of the linked list 
void insertAtMid(Node_tek_liste** top3, int deger3) 
{ 
    // if list is empty 
    if (*top3 == NULL) 
        *top3 = getNode(deger3); 
  
    else {  
        // get a new node 
        Node_tek_liste* newnode3 = getNode(deger3); 
  
        // assign values to the slow and fast  
        // pointers 
        Node_tek_liste* slow = *top3; 
        Node_tek_liste* fast = (*top3)->next3; 
  
        while (fast && fast->next3) { 
  
            // move slow pointer to next node 
            slow = slow->next3; 
  
            // move fast pointer two nodes at a time 
            fast = fast->next3->next3; 
        } 
  
        // insert the 'newNode' and adjust the 
        // required links 
        newnode3->next3 = slow->next3; 
        slow->next3 = newnode3; 
    } 
} 
  
// function to display the linked list 
void display_orta(Node_tek_liste* top3) 
{ 
    while (top3 != NULL) { 
        cout << top3->data_liste << " "; 
        top3 = top3->next3; 
    } 
} 

 // ------------------ Ortaya Eleman Ekleme Denemesi Son --------------------------------------------------------------------------------------------------
 // ------------------Ortadan Eleman Silme Denemesi Ba�lang�� --------------------------------------------------------------------------------------------
 
//Delete the middle node from the linked list
void delete_node_middle(Node_tek_liste** top3){
    if((*top3)->next3==NULL){
        *top3=NULL;
        return;
    }
    class Node_tek_liste* fast=(*top3)->next3;
    class Node_tek_liste* slow=*top3;
    while(fast && fast->next3 && fast->next3->next3){
        slow=slow->next3;
        fast=fast->next3->next3;
    }
    slow->next3=slow->next3->next3;
}
 
 // ------------------Ortadan Eleman Silme Denemesi Son --------------------------------------------------------------------------------------------



/* -----------------    ---Buras� Singly Linked List yani Ba�l� liste i�in Ana men�deki 3 numaral� k�s�m�n Sonu --------------------------   */
/* -----------------    ---4 Numaral� K�s�m ��k��-Exit i�in herhangi �zel bir kod bulunmamaktad�r --------------------------   */
/* ----------------------------------------------------------------- MA�N FONKS�YONUNA G�R�� !!!!!!!-------------------------------------- */


int main() {
   setlocale(LC_ALL, "Turkish"); // LC_ALL diyerek t�m koddaki t�rk�e karakterleri g�r�nt�lenebilir yapt�k. LC_TIME vb. gibi farkl� kullan�mlar� mevcuttur. 
   int genel, deger, deger3, yigin, kuyruk, liste, ekleliste, cikarliste; // switch case i�in gerekli de�erler 
 
  
   
   cout<<"1) Y���n Uygulamas�"<<endl; // aray�z 
   cout<<"2) Kuyruk Uygulamas�"<<endl;
   cout<<"3) Tek Y�nl� Ba�l� Liste Uygulamas�"<<endl;
   cout<<"4) Programdan ��k�� "<<endl; 
   
   
    do {  // Programdan 4 tu�una bas�l�nca ��k�� yap�lmas� i�in do-while ile ��z�m �rettim 
   
   

    
	  cout<<"Ana Men�de Yapmak istedi�iniz i�lemin numaras�n� tu�lay�n�z (1-4 aras�): "<<endl;
    
   
    
      cin>>genel;  // switch case i�in de�er giri�i 
      switch(genel) { 
      
       /*  ---------------------------------- Y���n K�sm� Ba�lang�� Case 1 --------------------- */
         
		 case 1: { 
		 
   cout<<"1) Y���na Eleman Ekle"<<endl;
   cout<<"2) Y���ndan Eleman ��kar"<<endl;
   cout<<"3) Y���n� Temizle"<<endl;
   cout<<"4) Y���n Elemanlar�n� G�ster"<<endl;
   cout<<"5) Y���ndaki Eleman Say�s�n� G�ster"<<endl;
   cout<<"6) Ana Men�ye D�n "<<endl;
		 
	 	  
            
              do{
              
              cout<<"Yigin Uygulamas�nda Yapmak istedi�iniz i�lemin numaras�n� tu�lay�n�z (1-6 aras�): "<<endl;
              cin>>yigin;
              switch(yigin) { 
              
               case 1:
			    {
			cout<<"Y���na Eklenecek Eleman�n De�erini Giriniz:"<<endl;
            cin>>deger;
            push(deger);
               	
               break; } // break koymazsak sonsuz d�ng�ye girebilir istenmeyen �eyler olu�abilir, break �nemli 
                       
               case 2:
			    {
			        pop();
               	
               break; }
               
               case 3:
			    {
			    	
			    	cout << "Y���n Temizlenmi�tir/Silinmi�tir"<<endl;  
                    deleteList(&top);  
               	
               break; }
               
               case 4:
			    {
			    	 
			    	display();
               	
               break; }
               
               case 5:
			    {
			    	 
			    	cout << "Y���ndaki Eleman Say�s�: " << count_recursive(top)<<endl;
               	
               break; }
               
               case 6:
			    {
			    	 
			    	cout<<"Ana men�ye geri d�nd�n�z "<<endl;
               	
               break; }
               
               default: { // farkl� numara girilmesi ihtimaline kar��n default �nemli 
            cout<<"Yanl�� Numara, L�tfen 1 ile 6 aras�nda bir de�er tu�lay�n�z"<<endl;
            break;
                           }
			  
			  }
			  
		} while(yigin !=6); // 6 olunca ana men�ye d�n�yo 
	break;
	}
			   
    /*  ---------------------------------- Y���n K�sm� Son Case 1 --------------------- */        
        
    /*  ---------------------------------- Kuyruk K�sm� Ba�lang�� Case 2 --------------------- */    
         
         
         case 2: {
         	
   
   cout<<"1) Kuyru�a Eleman Ekle"<<endl;
   cout<<"2) Kuyruktan Eleman ��kar"<<endl;
   cout<<"3) Kuyru�u Temizle"<<endl;
   cout<<"4) Kuyruk Elemanlar�n� G�ster"<<endl;
   cout<<"5) Kuyruktaki Eleman Say�s�n� G�ster"<<endl;
   cout<<"6) Ana Men�ye D�n "<<endl;
		 
	 	  
            
              do{
              
              cout<<"Kuyruk Uygulamas�nda Yapmak istedi�iniz i�lemin numaras�n� tu�lay�n�z (1-6 aras�): "<<endl;
              cin>>kuyruk;
              switch(kuyruk) { 
              
               case 1:
			    {
			
			Insert2();
            
               	break; }
                       
               case 2:
			    {
			       Delete2();
               	
               break; }
               
               case 3:
			    {
			    	cout << "Kuyruk Temizlenmi�tir/Silinmi�tir"<<endl;  
                    deleteList2(&front2);  
               	
               break; }
               
               case 4:
			    {
			    	 Display2();
			    
               	
               break; }
               
               case 5:
			    {
			    	 
			   cout << "Kuyruktaki Eleman Say�s�: " << count_recursive2(front2)<<endl;
               	
               break; }
               
               case 6:
			    {
			    	 
			    	cout<<"Ana men�ye geri d�nd�n�z "<<endl;
               	
               break; }
               
               default: {
            cout<<"Yanl�� Numara, L�tfen 1 ile 6 aras�nda bir de�er tu�lay�n�z"<<endl;
            break;
                           }
			  
			  }
			  
		} while(kuyruk !=6);
         	
            
         	
            break;
         }   
         
    /*  ---------------------------------- Kuyruk K�sm� Son Case 2 --------------------- */   
	     
    /*  ---------------------------------- Ba�l� Liste K�sm� Ba�lang�� Case 3 --------------------- */     
         
         case 3: { // Case yap�s�n�n i�indeki Case yap�s�n�n Case yap�s�, �nception gibi. 3 tane i� i�e Nested switch - Case var alt men�ler i�in  
         	
         	
   cout<<"1) Listeye Eleman Ekle"<<endl;
   cout<<"2) Listeden Eleman ��kar"<<endl;
   cout<<"3) Listeyi Temizle"<<endl;
   cout<<"4) Liste Elemanlar�n� G�ster"<<endl;
   cout<<"5) Listedeki Eleman Say�s�n� G�ster"<<endl;
   cout<<"6) Ana Men�ye D�n "<<endl;
		 
	 	  
            
              do{
              
              cout<<"Liste Uygulamas�nda Yapmak istedi�iniz i�lemin numaras�n� tu�lay�n�z (1-6 aras�): "<<endl;
              cin>>liste;
              switch(liste) {  
              
               case 1:
			    {
			    	
   // burdan ba�l�yo
   
   cout<<"1) Araya Eleman Ekle"<<endl;
   cout<<"2) Sona Eleman Ekle"<<endl;
   cout<<"3) Liste i�lemlerine d�n "<<endl;
   
	 	           
              do{
              
              cout<<" Ekleme T�r�n� Se�iniz (1-3 aras�): "<<endl;
              cin>>ekleliste;
              switch(ekleliste) {  
              
               case 1:
			    {
			cout<<"Listenin Araya Eleman Eklenmeden �nceki hali: "<<endl;
			display3();
            cout<<"Listede Araya/Ortaya Ekleyece�iniz Eleman�n De�eri: "<<endl;
            cin>>deger3;
            insertAtMid(&top3, deger3);
            
            cout<<"Listenin Araya Eleman Eklendikten sonraki hali "<<endl;
			display3();  
           
               	
               break; 
			    }
                       
               case 2:
			    {
			cout<<"Listeye Eklenecek Eleman�n De�erini Giriniz:"<<endl;
            cin>>deger3;
            push3(deger3);
               	
               break; }
               
               case 3:
			    {
			  cout<<"Liste i�lemleri men�s�ne d�nd�n�z"<<endl;
               	
               break; }
               
               
               default: {
            cout<<"Yanl�� Numara, L�tfen 1 ile 3 aras�nda bir de�er tu�lay�n�z"<<endl;
            break;
                           }
			  
			  }
			  
		} while(ekleliste !=3);
         	
            
			
        // burda son     
               	
               break; 
			    }
			    
                       
               case 2:
			    {
			     
				   // burda ba�l�yo
				 
   cout<<"1) Aradan eleman ��kar "<<endl;
   cout<<"2) Sondan eleman ��kar "<<endl;
   cout<<"3) Liste i�lemlerine d�n "<<endl;
   
	 	           
              do{
              
              cout<<" ��karma T�r�n� Se�iniz (1-3 aras�): "<<endl;
              cin>>cikarliste;
              switch(cikarliste) {  
              
               case 1:
			    {
			    	
			cout<<"Listenin Aradan Eleman ��kar�lmadan �nceki hali: "<<endl;
			display3();
            delete_node_middle(&top3);
            cout<<"Listenin Aradan Eleman ��kar�ld�ktan sonraki hali "<<endl;
			display3();   
           

              break; 
			    }
                       
               case 2:
			    {
			    
				pop3();
               	
               break; }
               
               case 3:
			    {
			   cout<<"Liste i�lemleri men�s�ne d�nd�n�z"<<endl;
               	
               break; }
               
               
               default: {
            cout<<"Yanl�� Numara, L�tfen 1 ile 3 aras�nda bir de�er tu�lay�n�z"<<endl;
            break;
                           }
			  
			  }
			  
		} while(cikarliste !=3);
         	
            
			    // burda son
			   
			   break; 
			   }
               
               
			   case 3:
			    {
			    	
					cout << "Liste Temizlenmi�tir/Silinmi�tir"<<endl;  
                    deleteList3(&top3); 
               	
               break; }
               
               case 4:
			    {
			    	 
			    	display3();
               	
               break; }
               
               case 5:
			    {
			    	 
			   cout << "Listedeki Eleman Say�s�: " << count_recursive3(top3)<<endl;
               	
               break; }
               
               case 6:
			    {
			    	 
			    	cout<<"Ana men�ye geri d�nd�n�z "<<endl;
               	
               break; }
               
               default: {
            cout<<"Yanl�� Numara, L�tfen 1 ile 6 aras�nda bir de�er tu�lay�n�z"<<endl;
            break;
                           }
			  
			  }
			  
		} while(liste !=6);
         	
            
         	
            
            break;
         }
         
         
          /*  ---------------------------------- �� Men� Ba�l� Liste K�sm� Son Case 3 --------------------- */  
          
           /*  ---------------------------------- Ana Men� Exit - ��k�� K�sm� Ba�lang�� Case 4 --------------------- */  
         
		 
		 case 4: {
            cout<<"��k�� yapt�n�z, konsol ekran�n� kapatmak i�in herhangi bir tu�a bas�n�z "<<endl;
            break;
         }
         
         /*  ---------------------------------- Ana Men� Exit - ��k�� K�sm� Son Case 4 --------------------- */ 
         
		 default: { // farkl� bi say�ya bas�l�rsa buras� m�dahale ediyor. 
            cout<<"Yanl�� Numara, L�tfen 1 ile 4 aras�nda bir de�er tu�lay�n�z"<<endl;
         }
      }
   } 
     while(genel!=4); // ��k��� buras� sa�l�yo 
      return 0;  
   }
    
  
