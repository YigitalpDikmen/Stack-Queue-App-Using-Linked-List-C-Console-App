#include <iostream> // C++ için temel kütüphane  
#include <cstdlib>  // malloc fonksiyonunun çalýþmasý için gerekli olan kütüphane
#include<locale.h> // Türkçe karakterlerin düzgün görüntülenmesi için gerekli olan kütüphane, görsellik 10 puan olduðu için eklemek daha iyi olur.
#include <bits/stdc++.h> // Ortaya eleman eklemek için gerekli hare ve tortoise algoritmasýnda kullanýlan fast-slow pointer mantýðýyla çalýþan kodlar için olan kütüphane  
using namespace std; // her seferinde std:: yapmamak için gerekli kod  

/* -----------------    ---------------   Burasý Stack yani Yýðýn için Ana menüdeki 1 numaralý kýsýmýn Baþlangýcý --------------------------   */

class Node {  // Temel Düðüm yapýsý: Veri ve Adres
public: // class tanýmlandýðýnda private olarak gelir dolayýsýyla public'e çevirmez isek eriþim saðlanamayacaðýndan kod çalýþmayabilir. 
   int data; // Düðümün veri tutan kýsýmý 
   class Node *next; // Düðümün adresi ''&'' tutan kýsmý
}; // Sýnýf tanýmýmýzý sonlandýrdýk


class Node* top = NULL;  // Yýðýn yapýsýnda en üst kýsmý baþlangýçta boþ olarak belirlemek için
void push(int deger) { // Yýðýn yapýsýnýn Çalýþma mantýðý FÝFO first in first out'a göre yaptýðýmýz void tipinde bir push yani eleman ekleme fonksiyonu  
   class Node* newnode = (class Node*) malloc(sizeof(class Node));  /* malloc() fonksiyonu tahsis edilmiþ belleðin baþlangýcýný gösteren bir iþaretçi geri verir. 
   Tahsis edilmek istenen bellek ihtiyacýný karþýlayamadýðýnda, NULL bir iþaretçi geri verir. Dolayýsýyla Malloc kullanýmý þu iþe yarar, kullanacaðýnýz deðerleri bilirsiniz, 
   o deðerlerin kaplayacaðý alandan daha fazlasýný bilgisayara yüklemezsiniz,
     */     
   newnode->data = deger; // Yýðýn için gerekli yapý
   newnode->next = top;   //  Yýðýn için gerekli yapý
   top = newnode; // Yýðýn için gerekli yapý
}
void pop() {  // Þimdi de Yýðýnýn çalýþma mantýðý FÝFO'ya göre bir pop yaný çýkarma fonksiyonunu void tipinde oluþturuyoruz. 
   if(top==NULL) // en üst boþ ise bunu yapsýn
      cout<<"Yýðýn Boþ olduðu için Eleman Çýkarýlamamaktadýr"<<endl;
   else {  // en üst boþ deðil ise bunu yapsýn
      cout<<"Yýðýndan Çýkarýlan Elemanýn Deðeri :  "<< top->data <<endl;
      top = top->next; // En üst ün bir sonraki elemana aktarýlmasý için gerekli kod 
   }
}
void display() { // Yýðýndaki elemanlarý göstermek için gerekli void tipinde display fonksiyonu 
   class Node* ptr;
   if(top==NULL) 
      cout<<"Yýðýnda Eleman Bulunmamaktadýr, Yýðýn Boþtur. ";
   else {   
      ptr = top; // Yýðýn için gerekli yapý
      cout<<"Yýðýn Elemanlarý Þunlardýr (Sonuncu Eleman en yukarýdaki elemandýr): "<<endl;
       
      while (ptr != NULL) { // hiç bir yere iþaret edilmiyorsa þunu yapsýn 
         cout<< ptr->data <<" "<<endl; 
         ptr = ptr->next; 
      } 
   }
   cout<<endl;
}

int count_recursive(Node* top) {   // Eleman "sayýsýný" gösteren kod int tipinde öz yinelemeli rekürsif  kod parçasý      
   if (top == NULL) // en üst boþ ise; 
      return 0; // sýfýr gönder 
   return 1 + count_recursive(top->next); // deðilse 1 gönder ve þunu ekle 
}   

void deleteList(Node** top) /* Tüm yýðýný temizlemek/silmek için gerekli fonksiyon, ampersant & adres deðeri isteyen void tipinde */ 
{  
      
/* yýðýnýn gerçek baþýna ulaþmak için þuanki yýðýn baþýný referanstan çýkarýyoruz */
Node* current1 = *top;  
Node* next;  
  
while (current1 != NULL)  // þuanki düðüm bir yeri iþaret etmiyosa
{  
    next = current1->next;  // Yýðýn için gerekli yapý
    free(current1);  // Yýðýn için gerekli yapý
    current1 = next;  // Yýðýn için gerekli yapý
}  
      

*top = NULL;  /* Yýðýnýn gerçek baþýný rekürsif olarak çaðýrýcý da etkileyebilmek için bunu yazdýk */
}  


/* ------------ ---------  Burasý Stack yani Yýðýn için Ana menüdeki 1 numaralý kýsýmýn Sonu --------------------------------------  */ 
/* -----------------    ---Burasý Queue yani Kuyruk için Ana menüdeki 2 numaralý kýsýmýn Baþlangýcý --------------------------   */

class Nodekuyruk { // Temel düðüm yapýsý 
public:	
   int datakuyruk;
   class Nodekuyruk *next2;
};
class Nodekuyruk* front2 = NULL; // kuyruk önü 
class Nodekuyruk* rear2 = NULL;  // kuyruk arkasý 
class Nodekuyruk* temp2; // geçici temporary 
void Insert2() { // kuyruða eleman ekleme 
   int deger2; // deðer - value 
   cout<<"Kuyruða eklenecek elemanýn deðerini giriniz : "<<endl;
   cin>>deger2; // deðeri kullanýcýdan almak için 
   if (rear2 == NULL) { // arka boþ ise 
      rear2 = (class Nodekuyruk *)malloc(sizeof(class Nodekuyruk)); // Kuyruk için gerekli yapý
      rear2->next2 = NULL; // Kuyruk için gerekli yapý
      rear2->datakuyruk = deger2; // Kuyruk için gerekli yapý
      front2 = rear2; // Kuyruk için gerekli yapý
   } else {  // arka boþ deðilse 
      temp2=(class Nodekuyruk *)malloc(sizeof(class Nodekuyruk));
      rear2->next2 = temp2; // Kuyruk için gerekli yapý
      temp2->datakuyruk = deger2; // Kuyruk için gerekli yapý
      temp2->next2 = NULL; // Kuyruk için gerekli yapý
      rear2 = temp2; // Kuyruk için gerekli yapý
   }
}
void Delete2() { // Last in first out LÝFO mantýðý ile kuyruk yapýsý için eleman silme, çýkarma fonksiyonu, yine void tipinde 
   temp2 = front2;
   if (front2 == NULL) {
      cout<<"Kuyruk Boþ olduðu için Eleman Çýkarýlamamaktadýr"<<endl;
      return;
   }
   else
   if (temp2->next2 != NULL) {
      temp2 = temp2->next2;
      cout<<"Kuyruktan Çýkarýlan Eleman : "<<front2->datakuyruk<<endl;
      free(front2);  /* C ++ 'daki free () iþlevi daha önce calloc, malloc veya realloc iþlevleri kullanýlarak ayrýlan bir bellek bloðunu 
yeniden konumlandýrýr ve böylece daha fazla ayýrma için kullanýlabilir hale getirir. 
fonksiyon, <cstdlib> baþlýk, header dosyasýnda tanýmlýdýr */
      front2 = temp2;
   } else {
      cout<<"Kuyruktan Çýkarýlan Eleman : "<<front2->datakuyruk<<endl;
      free(front2);
      front2 = NULL;
      rear2 = NULL;
   }
}
void Display2() { // kuyruk elemanlarýný göstermek için 
   temp2 = front2;
   if ((front2 == NULL) && (rear2 == NULL)) {
      cout<<"Kuyrukta hiç eleman yoktur, kuyruk boþtur. "<<endl;
      return;
   }
   cout<<"Kuyruk Elemanlarý Þunlardýr (En soldaki eleman ilk elemandýr) : ";
   while (temp2 != NULL) {
      cout<<temp2->datakuyruk<<" ";
      temp2 = temp2->next2;
   }
   cout<<endl; 
}

int count_recursive2(Nodekuyruk* front2) {  // kuyruk elemanlarýný saymak için     
   if (front2 == NULL)
      return 0;
   return 1 + count_recursive2(front2->next2); 
}  // bu fonksiyon ile elemanlarý sayýyoruz 


/* Tüm kuyruðu temizlemek/silmek için gerekli fonksiyon */
void deleteList2(Nodekuyruk** front2)  
{  
      
/* kuyruðun gerçek baþýna ulaþmak için þuanki kuyruk baþýný referanstan çýkarýyoruz */
Nodekuyruk* current2 = *front2;  
Nodekuyruk* next2;  
   
while (current2 != NULL)  
{  
    next2 = current2->next2;  
    free(current2);  
    current2 = next2;  
}  
      
/* kuyruðun gerçek baþýný rekürsif olarak çaðýrýcý da etkileyebilmek için bunu yazdýk */
*front2 = NULL;  
}  

/* -----------------    ---Burasý Queue yani Kuyruk için Ana menüdeki 2 numaralý kýsýmýn Sonu --------------------------   */
/* -----------------    ---Burasý Singly Linked List yani Tek Yönlü Baðlý liste için Ana menüdeki 3 numaralý kýsýmýn Baþlangýcý --------------------------   */

class Node_tek_liste { // temel düðüm yapýsý, yine ayný þeyler 
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
      cout<<"Tek yönlü liste Boþ olduðu için Eleman Çýkarýlamamaktadýr"<<endl;
   else {
      cout<<"Tek yönlü listeden Çýkarýlan Elemanýn Deðeri :  "<< top3->data_liste <<endl;
      top3 = top3->next3;
   }
}
void display3() {
   class Node_tek_liste* ptr3;
   if(top3==NULL)
      cout<<"Tek yönlü listede Eleman Bulunmamaktadýr, Liste Boþtur. ";
   else {   
      ptr3 = top3; 
      cout<<"Tek yönlü liste elemanlarý þunlardýr: (Sonuncu Eleman en yukarýdaki elemandýr): "<<endl;
       
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
}  // bu fonksiyon ile elemanlarý sayýyoruz 


/* Tüm listeyi temizlemek/silmek için gerekli fonksiyon */
void deleteList3(Node_tek_liste** top3)  
{  
      
/* listenin gerçek baþýna ulaþmak için þuanki yýðýn baþýný referanstan çýkarýyoruz */
Node_tek_liste* current3 = *top3;  
Node_tek_liste* next3;  
  
while (current3 != NULL)  
{  
    next3 = current3->next3;  
    free(current3);  
    current3 = next3;  
}  
      
/* listenin gerçek baþýný rekürsif olarak çaðýrýcý da etkileyebilmek için bunu yazdýk */
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
 // ------------------Ortadan Eleman Silme Denemesi Baþlangýç --------------------------------------------------------------------------------------------
 
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



/* -----------------    ---Burasý Singly Linked List yani Baðlý liste için Ana menüdeki 3 numaralý kýsýmýn Sonu --------------------------   */
/* -----------------    ---4 Numaralý Kýsým Çýkýþ-Exit için herhangi özel bir kod bulunmamaktadýr --------------------------   */
/* ----------------------------------------------------------------- MAÝN FONKSÝYONUNA GÝRÝÞ !!!!!!!-------------------------------------- */


int main() {
   setlocale(LC_ALL, "Turkish"); // LC_ALL diyerek tüm koddaki türkçe karakterleri görüntülenebilir yaptýk. LC_TIME vb. gibi farklý kullanýmlarý mevcuttur. 
   int genel, deger, deger3, yigin, kuyruk, liste, ekleliste, cikarliste; // switch case için gerekli deðerler 
 
  
   
   cout<<"1) Yýðýn Uygulamasý"<<endl; // arayüz 
   cout<<"2) Kuyruk Uygulamasý"<<endl;
   cout<<"3) Tek Yönlü Baðlý Liste Uygulamasý"<<endl;
   cout<<"4) Programdan Çýkýþ "<<endl; 
   
   
    do {  // Programdan 4 tuþuna basýlýnca çýkýþ yapýlmasý için do-while ile çözüm ürettim 
   
   

    
	  cout<<"Ana Menüde Yapmak istediðiniz iþlemin numarasýný tuþlayýnýz (1-4 arasý): "<<endl;
    
   
    
      cin>>genel;  // switch case için deðer giriþi 
      switch(genel) { 
      
       /*  ---------------------------------- Yýðýn Kýsmý Baþlangýç Case 1 --------------------- */
         
		 case 1: { 
		 
   cout<<"1) Yýðýna Eleman Ekle"<<endl;
   cout<<"2) Yýðýndan Eleman Çýkar"<<endl;
   cout<<"3) Yýðýný Temizle"<<endl;
   cout<<"4) Yýðýn Elemanlarýný Göster"<<endl;
   cout<<"5) Yýðýndaki Eleman Sayýsýný Göster"<<endl;
   cout<<"6) Ana Menüye Dön "<<endl;
		 
	 	  
            
              do{
              
              cout<<"Yigin Uygulamasýnda Yapmak istediðiniz iþlemin numarasýný tuþlayýnýz (1-6 arasý): "<<endl;
              cin>>yigin;
              switch(yigin) { 
              
               case 1:
			    {
			cout<<"Yýðýna Eklenecek Elemanýn Deðerini Giriniz:"<<endl;
            cin>>deger;
            push(deger);
               	
               break; } // break koymazsak sonsuz döngüye girebilir istenmeyen þeyler oluþabilir, break önemli 
                       
               case 2:
			    {
			        pop();
               	
               break; }
               
               case 3:
			    {
			    	
			    	cout << "Yýðýn Temizlenmiþtir/Silinmiþtir"<<endl;  
                    deleteList(&top);  
               	
               break; }
               
               case 4:
			    {
			    	 
			    	display();
               	
               break; }
               
               case 5:
			    {
			    	 
			    	cout << "Yýðýndaki Eleman Sayýsý: " << count_recursive(top)<<endl;
               	
               break; }
               
               case 6:
			    {
			    	 
			    	cout<<"Ana menüye geri döndünüz "<<endl;
               	
               break; }
               
               default: { // farklý numara girilmesi ihtimaline karþýn default önemli 
            cout<<"Yanlýþ Numara, Lütfen 1 ile 6 arasýnda bir deðer tuþlayýnýz"<<endl;
            break;
                           }
			  
			  }
			  
		} while(yigin !=6); // 6 olunca ana menüye dönüyo 
	break;
	}
			   
    /*  ---------------------------------- Yýðýn Kýsmý Son Case 1 --------------------- */        
        
    /*  ---------------------------------- Kuyruk Kýsmý Baþlangýç Case 2 --------------------- */    
         
         
         case 2: {
         	
   
   cout<<"1) Kuyruða Eleman Ekle"<<endl;
   cout<<"2) Kuyruktan Eleman Çýkar"<<endl;
   cout<<"3) Kuyruðu Temizle"<<endl;
   cout<<"4) Kuyruk Elemanlarýný Göster"<<endl;
   cout<<"5) Kuyruktaki Eleman Sayýsýný Göster"<<endl;
   cout<<"6) Ana Menüye Dön "<<endl;
		 
	 	  
            
              do{
              
              cout<<"Kuyruk Uygulamasýnda Yapmak istediðiniz iþlemin numarasýný tuþlayýnýz (1-6 arasý): "<<endl;
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
			    	cout << "Kuyruk Temizlenmiþtir/Silinmiþtir"<<endl;  
                    deleteList2(&front2);  
               	
               break; }
               
               case 4:
			    {
			    	 Display2();
			    
               	
               break; }
               
               case 5:
			    {
			    	 
			   cout << "Kuyruktaki Eleman Sayýsý: " << count_recursive2(front2)<<endl;
               	
               break; }
               
               case 6:
			    {
			    	 
			    	cout<<"Ana menüye geri döndünüz "<<endl;
               	
               break; }
               
               default: {
            cout<<"Yanlýþ Numara, Lütfen 1 ile 6 arasýnda bir deðer tuþlayýnýz"<<endl;
            break;
                           }
			  
			  }
			  
		} while(kuyruk !=6);
         	
            
         	
            break;
         }   
         
    /*  ---------------------------------- Kuyruk Kýsmý Son Case 2 --------------------- */   
	     
    /*  ---------------------------------- Baðlý Liste Kýsmý Baþlangýç Case 3 --------------------- */     
         
         case 3: { // Case yapýsýnýn içindeki Case yapýsýnýn Case yapýsý, Ýnception gibi. 3 tane iç içe Nested switch - Case var alt menüler için  
         	
         	
   cout<<"1) Listeye Eleman Ekle"<<endl;
   cout<<"2) Listeden Eleman Çýkar"<<endl;
   cout<<"3) Listeyi Temizle"<<endl;
   cout<<"4) Liste Elemanlarýný Göster"<<endl;
   cout<<"5) Listedeki Eleman Sayýsýný Göster"<<endl;
   cout<<"6) Ana Menüye Dön "<<endl;
		 
	 	  
            
              do{
              
              cout<<"Liste Uygulamasýnda Yapmak istediðiniz iþlemin numarasýný tuþlayýnýz (1-6 arasý): "<<endl;
              cin>>liste;
              switch(liste) {  
              
               case 1:
			    {
			    	
   // burdan baþlýyo
   
   cout<<"1) Araya Eleman Ekle"<<endl;
   cout<<"2) Sona Eleman Ekle"<<endl;
   cout<<"3) Liste iþlemlerine dön "<<endl;
   
	 	           
              do{
              
              cout<<" Ekleme Türünü Seçiniz (1-3 arasý): "<<endl;
              cin>>ekleliste;
              switch(ekleliste) {  
              
               case 1:
			    {
			cout<<"Listenin Araya Eleman Eklenmeden önceki hali: "<<endl;
			display3();
            cout<<"Listede Araya/Ortaya Ekleyeceðiniz Elemanýn Deðeri: "<<endl;
            cin>>deger3;
            insertAtMid(&top3, deger3);
            
            cout<<"Listenin Araya Eleman Eklendikten sonraki hali "<<endl;
			display3();  
           
               	
               break; 
			    }
                       
               case 2:
			    {
			cout<<"Listeye Eklenecek Elemanýn Deðerini Giriniz:"<<endl;
            cin>>deger3;
            push3(deger3);
               	
               break; }
               
               case 3:
			    {
			  cout<<"Liste iþlemleri menüsüne döndünüz"<<endl;
               	
               break; }
               
               
               default: {
            cout<<"Yanlýþ Numara, Lütfen 1 ile 3 arasýnda bir deðer tuþlayýnýz"<<endl;
            break;
                           }
			  
			  }
			  
		} while(ekleliste !=3);
         	
            
			
        // burda son     
               	
               break; 
			    }
			    
                       
               case 2:
			    {
			     
				   // burda baþlýyo
				 
   cout<<"1) Aradan eleman çýkar "<<endl;
   cout<<"2) Sondan eleman çýkar "<<endl;
   cout<<"3) Liste iþlemlerine dön "<<endl;
   
	 	           
              do{
              
              cout<<" Çýkarma Türünü Seçiniz (1-3 arasý): "<<endl;
              cin>>cikarliste;
              switch(cikarliste) {  
              
               case 1:
			    {
			    	
			cout<<"Listenin Aradan Eleman çýkarýlmadan önceki hali: "<<endl;
			display3();
            delete_node_middle(&top3);
            cout<<"Listenin Aradan Eleman çýkarýldýktan sonraki hali "<<endl;
			display3();   
           

              break; 
			    }
                       
               case 2:
			    {
			    
				pop3();
               	
               break; }
               
               case 3:
			    {
			   cout<<"Liste iþlemleri menüsüne döndünüz"<<endl;
               	
               break; }
               
               
               default: {
            cout<<"Yanlýþ Numara, Lütfen 1 ile 3 arasýnda bir deðer tuþlayýnýz"<<endl;
            break;
                           }
			  
			  }
			  
		} while(cikarliste !=3);
         	
            
			    // burda son
			   
			   break; 
			   }
               
               
			   case 3:
			    {
			    	
					cout << "Liste Temizlenmiþtir/Silinmiþtir"<<endl;  
                    deleteList3(&top3); 
               	
               break; }
               
               case 4:
			    {
			    	 
			    	display3();
               	
               break; }
               
               case 5:
			    {
			    	 
			   cout << "Listedeki Eleman Sayýsý: " << count_recursive3(top3)<<endl;
               	
               break; }
               
               case 6:
			    {
			    	 
			    	cout<<"Ana menüye geri döndünüz "<<endl;
               	
               break; }
               
               default: {
            cout<<"Yanlýþ Numara, Lütfen 1 ile 6 arasýnda bir deðer tuþlayýnýz"<<endl;
            break;
                           }
			  
			  }
			  
		} while(liste !=6);
         	
            
         	
            
            break;
         }
         
         
          /*  ---------------------------------- Ýç Menü Baðlý Liste Kýsmý Son Case 3 --------------------- */  
          
           /*  ---------------------------------- Ana Menü Exit - Çýkýþ Kýsmý Baþlangýç Case 4 --------------------- */  
         
		 
		 case 4: {
            cout<<"Çýkýþ yaptýnýz, konsol ekranýný kapatmak için herhangi bir tuþa basýnýz "<<endl;
            break;
         }
         
         /*  ---------------------------------- Ana Menü Exit - Çýkýþ Kýsmý Son Case 4 --------------------- */ 
         
		 default: { // farklý bi sayýya basýlýrsa burasý müdahale ediyor. 
            cout<<"Yanlýþ Numara, Lütfen 1 ile 4 arasýnda bir deðer tuþlayýnýz"<<endl;
         }
      }
   } 
     while(genel!=4); // çýkýþý burasý saðlýyo 
      return 0;  
   }
    
  
