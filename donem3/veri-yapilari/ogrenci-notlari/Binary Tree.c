#include <stdio.h>
#include <stdlib.h>

/**
 * İkili ağaç yapısı
 * @author Yunus Emre AK
 */


/**
 * İkili ağaç yapısında, daldaki değerden
 *  küçük ise soluna
 *  büyük ise sağına yazılır.
 *
 *       11
 *     /  \
 *      7    14
 *        / \   / \
 *       3   8  12  18
 *
 */
typedef struct _dal{
 int veri;
 
 _dal* solundaki;
 _dal* sagindaki;
}dal;

// Kullanıcı arayüzünüdeki yazıları oluşturan fonksiyon (Anlaşılabilirlik için.)
void menu();
// Kullanıcı arayüzünü oluşturan fonksiyon (Anlaşılabilirlik için.)
void loop(dal **);
// Ağacı oluşturmak için kullanılan fonksiyon.
void create(dal **);
// Bellek ayırmak için fonksiyon. (Tamamen kolaylık amaçlıdır.)
dal* get_leaf();
// İkili ağaç yapısına veri ekleme fonksiyonu.
void insert(dal*);
// Ağactaki verileri sıralayıp ekrana yazan fonksiyon (Anlaşılabilirlik için.)
void sort_disploy(dal*);
// Ağacta veri arama ve verinin bulundağı dalı geri döndüren fonksiyon.
dal* search(dal*, int);
// Ağacın dalları silen fonksiyon.
void destroy_leaf(dal*);
// Ağacı komple silen fonksiyon
void destroy_tree(dal**);


int main(){
 dal *agacim = NULL; 
  
 loop(&agacim);
}

// Fonksiyonlar;
dal* get_leaf(){
 return (dal*)malloc(sizeof(dal));
}

void insert(dal* gelen_dal, int veri){
 // Eğer gelen dal boş ise, yeni dal oluşturup veriyi atıyoruz.
 if(gelen_dal == NULL){
  printf("\n Agac yapisi mevcut degil. Lutfen once agaci olusturunuz.");
  
  return;
 }
 
 // Öncelikle gelen verinin baslangıç verimizden küçük olma durumunu inceliyoruz.
 if(veri < gelen_dal->veri){
  /**
   *  Eğer gelen veri, baş veriden "küçükse" dallarındaki diğer verileriyle de kıyaslamamız
   * lazım. Bu kıyaslama işlemi, küçük olma durumunu incelediğimiz için ağacın
   * başlangıcınının sol tarafında dal olmayana kadar devam etmeli.
   */
  if(gelen_dal->solundaki != NULL)
   /**
    *  Eğer dalın sonundaki null değilse, tekrardan ekleme fonksiyonunu çağırcağız.
    * Bu sayede her alt dal için başlangıç dalına uygulamış olduğumuz işlemler
    * uygulanacak.
    */
   insert(gelen_dal->solundaki, veri);
  /**
   *  Eğer dalın solunda başka dal yoksa, soluna yeni bir dal uluşturup veriyi atıyacağız.
      *           11
   *     /
    *    (Yeni Dal)
    *    /       \
    *   NULL      NULL
   */
  else{
   // Yeni dalımız için gelen dalın soluna dal oluşturuyoruz.
   gelen_dal->solundaki = get_leaf();
   // Gelen dalın soluna eklenen dala, gelen veriyi atıyoruz.
   gelen_dal->solundaki->veri = veri;
   /**
    *  Gelen dalın solunda oluşturulan daldan sonra dal olmadığı için her yönüne
    * de NULL atıyoruz.
    */
   gelen_dal->solundaki->solundaki = NULL;
   gelen_dal->solundaki->sagindaki = NULL;
  }  
 } 
 
  /**
   *  Eğer gelen veri, baş veriden "küçük değilse" dallarındaki diğer verileriyle de kıyaslamamız
   * lazım. Bu kıyaslama işlemi, küçük olma durumunu incelediğimiz için ağacın
   * başlangıcınının sağ tarafında dal olmayana kadar devam etmeli.
   */
 else{
  if(gelen_dal->sagindaki != NULL)
   /**
    *  Eğer dalın sonundaki null değilse, tekrardan ekleme fonksiyonunu çağırcağız.
    * Bu sayede her alt dal için başlangıç dalına uygulamış olduğumuz işlemler
    * uygulanacak.
    */
   insert(gelen_dal->sagindaki, veri);
   
  /**
   *  Eğer dalın sağında başka dal yoksa, sağında yeni bir dal uluşturup veriyi atıyacağız.
      *           11
   *      \
    *        (Yeni Dal)
    *         /       \
    *      NULL      NULL
   */
  else{
   // Yeni dalımız için gelen dalın sağına dal oluşturuyoruz.
   gelen_dal->sagindaki = get_leaf();
   // Gelen dalın sağına oluşturulan yeni dala veriyi atıyoruz.
   gelen_dal->sagindaki->veri = veri;
   /**
    *  Gelen dalın sağında oluşturulan daldan sonra dal olmadığı için her yönüne
    * de NULL atıyoruz.
    */
   gelen_dal->sagindaki->sagindaki = NULL;
   gelen_dal->sagindaki->solundaki = NULL;
  }
 } 
}

dal *search(dal* gelen_dal, int istenen_veri){
 // Sadece gelen dalda veri olduğu sürece işlem yapabiliriz.
 if(gelen_dal != NULL){
  // İlk olarak istenen veri gelen dalın verisi olup olmadığını kontrol ediyoruz.
  if(gelen_dal->veri == istenen_veri)
   return gelen_dal;
  
  /**
   *  Eğer istenen veri gelen daldan küçükse;
   * Ekleme yaparken küçük verileri gelen dalın soluna eklediğimiz için, bu fonksiyonu
   * gelen dalın solundaki dalı parametre vererek tekrar çağıracağız.
   */
  if(istenen_veri < gelen_dal->veri)
   search(gelen_dal->solundaki, istenen_veri);
   
  /**
   *  Eğer istenen veri gelen daldan küçük değilse yani gelen daldan büyük veya dala eşitse;
   * Ekleme yaparken küçük olmayan verileri gelen dalın sağına eklediğimiz için, bu fonksiyonu
   * gelen dalın sağındaki dalı parametre vererek tekrar çağıracağız.
   */
  else
   search(gelen_dal->sagindaki, istenen_veri);
  
  // Hiçbir koşul gerçekleşmiyorsa, istenen veri dalda mevcut değil demektir.
 }
 else
  return NULL;
}

void destroy_leaf(dal *gelen_dal){
/**
* (Agacın kökü (en üst verisi) gönderilirse, tüm ağacı siler.)
*        11                   11
*     /  \                /     \
*      7    14     ->      7        14
*        / \   / \           /  \    /    \
*       3   8  12  18      NULL NULL NULL NULL
*
* Alttan üste doğru silme işlemi yapmalıyız.
*
*/

 // Öncelikle gelen dal boş (NULL) değilse işlem yapılır.
 if(gelen_dal != NULL){
  /**
  *  Ağacın verileri silmeden önce ağacın dallarını temizlememiz gerekiyor,
  * aksi halde diğer dallara erişimimiz kesilecek ve dallar için ayrılan bellekleri
  * serbest bırakamayacağız. Bu sebeple bu fonksiyonu ağacın hem sağındaki hem de
  * solundaki dalları için tekrar çağırmamız, en sonda ağacın verisini silmemiz
  * gerekir.
  */
  destroy_leaf(gelen_dal->sagindaki);
  destroy_leaf(gelen_dal->solundaki);
  
  
  // Sağındaki ve solundaki tüm dallar silindikten sonra, ağacın baş verisi silinir.
  free(gelen_dal);
  
  
 }
}

void destroy_tree(dal **gelen_agac){
 // Öncelikle gelen dal boş (NULL) değilse işlem yapılır.
 if(*gelen_agac != NULL){
   // Agacin dallarını sildiriyoruz.
   destroy_leaf(*gelen_agac);
     
   // Gelen agacta dal kalmadığı için agaca NULL atıyoruz.
   *gelen_agac = NULL;
 }
}

void display_tree(dal *gelen_dal){
 if(gelen_dal != NULL){
  if(gelen_dal->solundaki != NULL)
   printf("| %d", gelen_dal->solundaki->veri);
  if(gelen_dal->sagindaki != NULL)
   printf("| %d", gelen_dal->sagindaki->veri);
 }
}

void sort_display(dal *gelen_dal){
 if(gelen_dal == NULL){
  printf("\nGosterilecek agac yok.");
  
  return;
 }
 
 if(gelen_dal->solundaki != NULL){
  sort_display(gelen_dal->solundaki);
 }
 
 printf("%d-",gelen_dal->veri);
 
 if(gelen_dal->sagindaki != NULL)
  sort_display(gelen_dal->sagindaki);
}

void menu(){
  printf("\n***************************\n");
 // Görsel hizalama için "%30s" 30 karakterlik alana sağa dayalı yazdırdık.
 printf("->%30s\n"," Agaci olusturmak icin 1'e");
 printf("->%30s\n"," Agaca sayi eklemek icin 2'e");
 printf("->%30s\n"," Agaci gostermek icin 3'e");
 printf("->%30s\n"," Agaci silmek icin 4'e");
 printf("->%30s\n"," Cikmak icin 0'a");
}

void loop(dal **agacim){ 
  int x = 5;
  
  while(x !=0){
  
  menu();
  
  /**
   *  Dipnot : Boşluk %c (" %c") yazılırsa, öncesinde basılan enter'ı veri olarak ("\n") görmez, hatalar engellenir.
    * %d kullanımı için bir satır atlatma karakteri algılama durumu olmaz. 
   */
  scanf("%d", &x);
  
  switch(x){
   case 1:
    create(agacim);
    
    break;
    
   case 2:
    printf("\nLutfen eklemek istediginiz veriyi giriniz:\t");
    
    int eklenecek_veri;
    
    scanf(" %d",&eklenecek_veri);
    
    insert(*agacim, eklenecek_veri);
    
    break;
   
   case 3:
    printf("Agacin verilerinin siralanmis hali:\n");
    sort_display(*agacim);
    
    break;
   
   case 4:
    printf("\nAgac silindi.\n");
    
    destroy_tree(agacim);
    
    break;
    
   default:
    break;
  }
 }
}

void create(dal **agac){
 if(*agac == NULL)
  *agac =get_leaf();
 
 printf("\nAgacin ilk verisini giriniz:\t");
 
 int bas_veri;
 
 scanf(" %d", &bas_veri);
 
 (*agac)->veri = bas_veri; 
 (*agac)->sagindaki = NULL;
 (*agac)->solundaki = NULL;
 
 printf("\nAgac %d verisiyle olusturuldu.", bas_veri);
}