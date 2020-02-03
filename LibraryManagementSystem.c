#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#include<locale.h>
#define RETURNTIME 15

void kitapEkle();
int sayiAzalt();
void kitapSil();
void kitapDuzenle();
void kitapAra();
void kitapVer();
void kitapGor();
void donusFonk();
void anaMenu();
void uygKapat();
int  veriAl();
int  noKontrol(int);
int t(void);
void verdiKaydi();
int gun();
int yil();
int ay();
char kategoriler[][15]={"Tarih","Psikoloji","Bilim Kurgu","Fantastik","Polisiye","Saðlýk"};
FILE *fp,*ft,*fs;


int s;
char kitaparamadegiskeni;

struct meroDate
{
    int mm,dd,yy;
};
struct kitaplar
{
    int numara;
    char ogrenciismi[20];
    char kitapismi[20];
    char yazar[20];   
    float ucret;
    int count;
    int kitaplikno;
    char *cat;
    struct meroDate duedate;
    int adet;
};
struct kitaplar a;

int main()
{   
    setlocale(LC_ALL, "Turkish");
    anaMenu();
    getch();
    return 0;
}
void anaMenu()
{
	system("cls");	
	int i,j;
	printf("\n\n\t\t********************************** ANA MENÜ **********************************");
	printf("\n\n\t\t> 1. Yeni Kitap Ekle");
	printf("\n\n\t\t> 2. Kitap Sil");
	printf("\n\n\t\t> 3. Kitap Ara");
	printf("\n\n\t\t> 4. Kitap Ödünç Verme Menüsü");
	printf("\n\n\t\t> 5. Kitap Listesini Görüntüle");
	printf("\n\n\t\t> 6. Eklenmiþ Bir Kitabýn Kaydýný Düzenle");
	printf("\n\n\t\t> 7. Uygulamayý kapat");
	printf("\n\n\t\t******************************************************************************");
	t();
	printf("\n\n\n\t\t>Seçiminizi Giriniz:");
	switch(getch())
    {
    case '1':
        kitapEkle();
        break;
    case '2':
        kitapSil();
        break;
    case '3':
        kitapAra();
        break;
    case '4':
        kitapVer();
        break;
    case '5':
        kitapGor();
        break;
    case '6':
        kitapDuzenle();
        break;
    case '7':
    {
        system("cls");
        printf("\tKütüphane Yönetim Sistemi\n\n");
        printf("\t2019-2020 Guz\n\n");
        printf("\tAhmet Buðra Yiðiter\n\tÝsmail Çýnar\n\tAbdurrahman Yorulmaz\n");
        printf("\n\tProgram 5 saniye icinde kapanacak...........>\n");
        Sleep(5000);
        exit(0);
    }
    default:
    {
        printf("\aYanlýþ Giriþ!!Lütfen Doðru Giriþ Yapýnýz!\n");
        if(getch())
            anaMenu();
    }
    
    }
    }
    void kitapEkle()
    {
        system("cls");
        int i;
        clock_t start = clock();
		printf("\n\n\t\t*********** KATEGORÝLER ***********");
        printf("\n\n\t\t**** 1. Tarih");
        printf("\n\n\t\t**** 2. Psikoloji");
        printf("\n\n\t\t**** 3. Bilim Kurgu");
        printf("\n\n\t\t**** 4. Fantastik");
        printf("\n\n\t\t**** 5. Polisiye");
        printf("\n\n\t\t**** 6. Saðlýk");
        printf("\n\n\t\t****************************");
        printf("\n\n\t\t**** 7. Ana menüye dön");
        printf("\n\n\t\tSeçiminizi giriniz:");
        scanf("%d",&s);
        if(s==7)
            anaMenu() ;
        system("cls");
		fp=fopen("Veriler.txt","ab+");
        if(veriAl()==1)
        {
             
			a.cat=kategoriler[s-1];
            fseek(fp,0,SEEK_END);
            fwrite(&a,sizeof(a),1,fp);
            fclose(fp);
            printf("\nKayýt baþarýyla kaydedildi\n");         
			clock_t stop = clock();
   			double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
  			printf("\nKitap ekleme iþlemi kategori seçtiðiniz andan itibaren %.0f milisaniyede gerçekleþtirildi.\n", elapsed);

            printf("\nBaþka kaydetmek ister misiniz?(E / H):\n");
            if(getch()=='h')
                anaMenu();
            else
                system("cls");
            kitapEkle();
        }
    }
    void kitapSil()
    {
        system("cls");
        int d;
        char another='e';
        while(another=='e')
        {
            system("cls");
            printf("Silmek istediðiniz kitabýn ID'sini giriniz:\n");
            clock_t start = clock();
			scanf("%d",&d);
            fp=fopen("Veriler.txt","rb+");
            rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.numara==d)
            {
                printf("Kitap kaydi mevcuttur\n");
                printf("Kitap ismi %s\n",a.kitapismi);
                printf("Kitaplik Numarasi %d\n",a.kitaplikno);
                kitaparamadegiskeni='t';
            }
        }
        if(kitaparamadegiskeni!='t')
        {
            printf("Hicbir kayit bulunamadi aramayi deðiþtir\n");
            printf("Ana Menüye dönmek için bir tuþa basýnýz..");
            if(getch())
            
                anaMenu();
        }
        if(kitaparamadegiskeni=='t' )
        {
            printf("Silmek ister misiniz?(E/H):\n");
            if(getch()=='e')
            {
                ft=fopen("Test.txt","wb+");
                rewind(fp);
                while(fread(&a,sizeof(a),1,fp)==1)
                {
                    if(a.numara!=d)
                    {
                        fseek(ft,0,SEEK_CUR);
                        fwrite(&a,sizeof(a),1,ft);
                    }
                }
                fclose(ft);
                fclose(fp);
                
                if(kitaparamadegiskeni=='t')
                {
					printf("Kayýt baþarýyla silinmiþtir.\n");
					clock_t stop = clock();
   					double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
  					printf("\nKitap silme iþleminiz ID'yi girdiðiniz andan itibaren %.0f milisaniyede gerçekleþtirildi.\n", elapsed);
                    printf("Baþka kayýt silmek ister misiniz?(E/H)\n");
                }
                remove("Veriler.txt");
                rename("Test.txt","Veriler.txt");
                fp=fopen("Veriler.txt","rb+");
            }
            else
                anaMenu();
            fflush(stdin);
            another=getch();
        }
    }
    anaMenu();
    }
    void kitapAra()
    {
        system("cls");
        int d;
        printf("**********Kitap Arama************\n");
        printf("**** 1. Kitap kimliði ile arama\n");
        printf("**** 2. Adiyla ara\n");
        printf("**** 3. Ana menüye dön\n");
        printf("Seçiminizi giriniz\n");
        fp=fopen("Veriler.txt","rb+");
        rewind(fp);
        switch(getch())
        {
            case '1':
            {
                system("cls");
                printf("** Kayýt numarasý ile ara **\n");
                printf("Kayýt numarasýný giriniz:\n");
               	clock_t start = clock();
                scanf("%d",&d);
                printf("Aranýyor........\n");
                kitaparamadegiskeni='o';
                while(fread(&a,sizeof(a),1,fp)==1)
                {
                    if(a.numara==d)
                    {
                        printf("Kitap mevcuttur\n");
                        printf("********************\n");
                        printf("** Kayýt numarasý : %d\n",a.numara);
                        printf("**\n");
                        printf("** Kitap ismi : %s\n",a.kitapismi);
                        printf("**\n");
                        printf("** Yazar : %s \n",a.yazar);
                        printf("**\n");
                        printf("** Adet : %d \n",a.adet);
                        printf("**\n");
                        printf("**\n");
                        printf("** Fiyat : %.2f\n",a.ucret);
                        printf("**\n");
                        printf("** Kitaplýk numarasý :%d \n",a.kitaplikno);
                        printf("**\n");
                        printf("********************\n");
                        kitaparamadegiskeni='t';
                        clock_t stop = clock();
					    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
					  	printf("\nKitabý ID ile arama iþleminiz ID'yi girdiðiniz andan itibaren %.0f milisaniyede gerçekleþtirildi.\n", elapsed);
                    }
    
                }
                if(kitaparamadegiskeni!='t')
                {
                    printf("\n**************");
                    printf("\n**");
                    printf("\n**");
                    printf("\n**************");
                    printf("\n\aKayýt bulunamadý");
                    clock_t stop = clock();
				    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
				  	printf("\nKitabý ID ile arama iþleminiz ID'yi girdiðiniz andan itibaren %.0f milisaniyede gerçekleþtirildi.\n", elapsed);
                }
                printf("\nBaþka bir arama yapmak ister misiniz ?(E/H)");
                if(getch()=='e' || getch()=='E')
                    kitapAra();
                else
                    anaMenu();
            }
            case '2':
            {
                char s[15];
                system("cls");
                printf("** Kitap adi ile arama **");
                printf("\nKitabin adini giriniz:");
                clock_t start = clock();
                scanf("%s",s);
                int d=0;
                while(fread(&a,sizeof(a),1,fp)==1)
                {
                    if(strcmp(a.kitapismi,(s))==0)
                    {
                        printf("Kitap mevcuttur\n");
                        printf("********************\n");
                        printf("** Kayit numarasi : %d\n",a.numara);
                        printf("**\n");
                        printf("** Kitap ismi : %s\n",a.kitapismi);
                        printf("**\n");
                        printf("** Yazar : %s \n",a.yazar);
                        printf("**\n");
                        printf("** Adet : %d \n",a.adet);
                        printf("**\n");
                        printf("**\n");
                        printf("** Fiyat : Rs.%.2f\n",a.ucret);
                        printf("**\n");
                        printf("** Kitaplýk numarasi : %d\n",a.kitaplikno);
                        printf("**\n");
                        printf("********************\n");
                        d++;
                        clock_t stop = clock();
					    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
					  	printf("\nKitabý adý ile arama iþleminiz kitabýný adýný girdiðiniz andan itibaren %.0f milisaniyede gerçekleþtirildi.\n", elapsed);
                    }
                }
                if(d==0)
                {
                    printf("**************\n");
                    printf("**\n");
                    printf("**");
                    printf("**************\n");
                    printf("\aKayýt bulunamadý\n");
                    clock_t stop = clock();
   					double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
  					printf("\nKitabý adý ile arama iþleminiz kitabýný adýný girdiðiniz andan itibaren %.0f milisaniyede gerçekleþtirildi.\n", elapsed);
                }
                printf("Baþka bir arama yapmayý dener misiniz?(E/H)\n");
                if(getch()=='e')
                    kitapAra();
                else
                    anaMenu();
                break;
            }
            case '3': {
                anaMenu() ;
                break;
            }
            default :
                getch();
            anaMenu();
        }
    fclose(fp);
    }
    void kitapVer()
    {
        int t;
        system("cls");
        printf("********* KÝTAP ÖDÜNÇ VERME MENÜSÜ *******");
        printf("\n**** 1. Kitap Ödünç Ver");
        printf("\n**** 2. Alýnmýþ kitaplarý görüntüle");
        printf("\n**** 3. Ödünç verilen kitabý sorgula");
        printf("\n**** 4. Ödünç verilen kitabý geri al");
        printf("\n**** 5. Ana menüye dön");
        printf("\nSeçiminizi giriniz:");
        switch(getch())
        {
            case '1':
            {
                system("cls");
                int c=0;
                char another='e';
                while(another=='e')
                {
                    system("cls");
                    printf("*Ödünç kitap bolumu***");
                    printf("\n\tKitap kimligini giriniz:");
                    scanf("%d",&t);
                    fp=fopen("Veriler.txt","rb");
                    fs=fopen("odunc.txt","ab+");
                    ft=fopen("Test.txt","wb+");
                    if(noKontrol(t)==0)
                    {
                        if(a.adet !=0){

                       printf("\n\nKitap kaydý mevcuttur");
                       printf("\n\nKutuphanede bu kitaptan %d adet mevcut ",a.adet);
                       printf("\n\nKitabýn adý : %s",a.kitapismi);
                       printf("\n\nÖðrenci adýný giriniz :");
                       scanf("%s",a.ogrenciismi);
                       
                       printf("\n\nÖdünç alma tarihi: %d-%d-%d",gun(),ay(),yil());
                       printf("\n\n%d Numaralý kitap ödünç verilmiþtir.",a.numara);
                       a.duedate.dd=gun()+RETURNTIME;
                       a.duedate.mm=ay();
                       a.duedate.yy=yil();
                       if(a.duedate.dd>30)
                       {
                           a.duedate.mm+=a.duedate.dd/30;
                           a.duedate.dd-=30;
                       }
                       if(a.duedate.mm>12)
                       {
                           a.duedate.yy+=a.duedate.mm/12;
                           a.duedate.mm-=12;
                       }
                       
                       printf("\n\nGeri alinacak tarih:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
                       fseek(fs,sizeof(a),SEEK_END);
                       fwrite(&a,sizeof(a),1,fs);
                       rewind(fp);
                       
						while(fread(&a,sizeof(a),1,fp)==1){
						
						if(a.numara!=t) {
						
						fseek(ft,0,SEEK_CUR);
						fwrite(&a,sizeof(a),1,ft); 
						}
                   if(a.numara==t){
                        
                      a.adet--;
                      
                      fseek(ft,0,SEEK_CUR);
                      fwrite(&a,sizeof(a),1,ft);
						}		
						}
						fclose(ft);
						fclose(fp);
						remove("Veriler.txt");
						rename("Test.txt","Veriler.txt");
						fp = fopen("Veriler.txt","rb+");
                       fclose(fs);
                       c=1;
                   }
                   else{
                    printf("Kitap kütüphanede þu an mevcut deðil.\nKitabýn kim tarafýndan ödünç alýndýðýný görmek için ödünç alýnanlar listesine gidiniz\n");
                    c=1;
}
                    }
                    
                        
                    if(c==0)
                    {
                        printf("Kayit bulunamadi\n");
                    }
                    printf("\n\nBaþka kitap ister misiniz(E/H):\n");
                    fflush(stdin);
                    another=getche();
                    fclose(fp);
                }
    
                break;
            }
            case '2':
            {
                system("cls");
                int j=4;
                printf("**********Odunc Kitap Listesi**********\n");
                printf("OGRENCI ADI\t\t\tKATEGORI\t\t\tKITAP NUMARASI\t\t\tKITAP ADI\t\tODUNÇ ALINMA TARIHI\t\tGERI DONUS TARIHI\n");
                fs=fopen("odunc.txt","rb");
                while(fread(&a,sizeof(a),1,fs)==1)
                {
                    printf("%-20s\t\t",a.ogrenciismi);
                    printf("%-20s\t\t\t",a.cat);
                    printf("%-20d\t",a.numara);
                    printf("%-20s\t",a.kitapismi);
                    printf("%d-%d-%d\t\t\t\t",gun(),ay(),yil());
                    printf("%d-%d-%d\t\t\t\n",a.duedate.dd,a.duedate.mm,a.duedate.yy);
                    j++;
                }
                fclose(fs);
                donusFonk();
            }
                break;
            case '3':
            {
                system("cls");
                printf("\nKitap kayit numarasini giriniz:");
                int p,c=0;
                char another='e';
                while(another=='e')
                {
                    scanf("%d",&p);
                    fs=fopen("odunc.txt","rb");
                    while(fread(&a,sizeof(a),1,fs)==1)
                    {
                        if(a.numara==p)
                        {
                            verdiKaydi();
                            printf("\nHerhangi bir sey giriniz.......");
                            getch();
                            verdiKaydi();
                            c=1;
                        }
                    }
                    fflush(stdin);
                    fclose(fs);
                    if(c==0)
                    {
                        printf("\nKayit bulunamadi");
                    }
                    printf("\nBaþka Arama Yapacak mýsýnýz?(E/H)");
                    another=getch();
                }
            }
                break;
            case '4':
            {
                system("cls");
                int b;
                FILE *fg;
                char another='e';
                while(another=='e')
                {
                    printf("\nGeri alýnacak kitabýn id'sini giriniz:\n");
                    scanf("%d",&b);
                    fs=fopen("odunc.txt","rb+");
                    fp=fopen("Veriler.txt","rb");
                    
                    ft=fopen("Test.txt","wb+");
                    while(fread(&a,sizeof(a),1,fs)==1)
                    {
                        if(a.numara==b)
                        {
                            verdiKaydi();
                            kitaparamadegiskeni='t';
                        }
                        if(kitaparamadegiskeni =='t')
                        {
                            printf("\nKaldirmak ister misiniz?(E/H): ");
                            if(getch()=='e')
                            {
                            
                                fg=fopen("kayit.txt","wb+");
                                rewind(fs);
                                while(fread(&a,sizeof(a),1,fs)==1)
                                {
                                    if(a.numara!=b)
                                    {
                                        fseek(fs,0,SEEK_CUR);
                                        fwrite(&a,sizeof(a),1,fg);
                                    }
                                }
                                while(fread(&a,sizeof(a),1,fp)==1){
	                                if(a.numara!=b){
	                                fseek(ft,0,SEEK_CUR);
	                                fwrite(&a,sizeof(a),1,ft);
									}
									if(a.numara==b){
									a.adet++;
									fseek(ft,0,SEEK_CUR);
									fwrite(&a,sizeof(a),1,ft);
									}
								}
								fclose(fp);
								fclose(ft);
								remove("Veriler.txt");
								rename("Test.txt","Veriler.txt");
                                fclose(fs);
                                fclose(fg);
                                remove("odunc.txt");
                                rename("kayit.txt","odunc.txt");
                                printf("\nOdunc alinan kitap listeden kaldirildi\n");
                            }
                        }
                        if(kitaparamadegiskeni!='t')
                        {
                            printf("\nKayýt bulunamadý");
                            break;
                        }
                    }
                    printf("\nBaska silmek ister misiniz?(E/H) : ");
                    another=getch();
                }
                
            }
            case '5': {
                anaMenu() ;
                break;
            }
            default:
                printf("\nBir Onceki Menuye Dönmek için Herhangi Bir Tuþa Basýnýz...");
            getch();
            kitapVer();
            break;
        }
        donusFonk();
    }
    void kitapGor()
    {
        int i=0,j;
        system("cls");
        printf("*******************Kitap Listesi*********************");
        printf("\n\nKategori\t\tKimlik\t\tKitap Adi\t\tYAZAR\t\tAdet\t\tFiyat\t\tKitaplik Numarasi\n\n");
        j=4;
        fp=fopen("Veriler.txt","rb");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            
            printf("%s\t\t\t",a.cat);
            printf("%d\t\t",a.numara);
            printf("%s\t\t\t",a.kitapismi);
            printf("%s\t\t",a.yazar);
            printf("%d\t\t",a.adet);
            printf("%.2f\t\t",a.ucret);
            printf("%d\t\t",a.kitaplikno);
            printf("\n");
            j++;
            i=i+a.adet;
        }
        printf("Tum Kitaplar =%d",i);
        fclose(fp);
        donusFonk();
    }
    void kitapDuzenle()
    {
        system("cls");
        int c=0;
        int d,e;
        printf("\n\n\t\t********* Eklenmiþ Bir Kitabin Kaydýný Duzenle *********");
        char another='y';
        while(another=='y')
        {
            system("cls");
            printf("\nDüzenlemek istediðiniz kitabin Numarasini giriniz :");
            scanf("%d",&d);
            fp=fopen("Veriler.txt","rb+");
            while(fread(&a,sizeof(a),1,fp)==1)
            {
                if(noKontrol(d)==0)
                {
                    printf("\nKitap mevcuttur");
                    printf("\nKitap kayit numarasi:%d",a.numara);
                    printf("\nYeni isim giriniz:");scanf("%s",a.kitapismi);
                    printf("\nYeni yazar giriniz:");scanf("%s",a.yazar);
                    printf("\nYeni adet giriniz:");scanf("%d",&a.adet);
                    printf("\nYeni fiyat giriniz:");scanf("%f",&a.ucret);
                    printf("\nYeni kitaplik numarasi giriniz:");scanf("%d",&a.kitaplikno);
                    printf("\n Kitabinizin kaydýbaþarýyla düzenlenmiþtir.");
                    fseek(fp,ftell(fp)-sizeof(a),0);
                    fwrite(&a,sizeof(a),1,fp);
                    fclose(fp);
                    c=1;
                }
                if(c==0)
                {
                    printf("\nKayit bulunamadi");
                }
            }
            printf("\nBaþka bir kitabi düzenlemek ister misiniz? (E/H)");
            fflush(stdin);
            another=getch();
        }
        donusFonk();
    }
    void donusFonk()
    {
        {
        printf("\n\nAna menüye dönmek için ENTER tuþuna basiniz.");
        }
    a:
        if(getch()==13)
            anaMenu();
        else
            goto a;
    }
    int veriAl()
    {
        int t;
        printf(">>Lütfen aþaðýdaki bilgileri doldurunuz.\n");
        printf("******************\n");
        printf("*ÝKÝ KELÝME ARASINDA SPACE (BOÞLUK) BIRAKMAYINIZ!");
        printf("\n***ALT ÇÝZGÝ (_) KULLANINIZ !");
        printf("\n\n\nKategori:\t");
        printf("%s",kategoriler[s-1]);
        printf("\n\nBook ID:\t");
        scanf("%d",&t);
        if(noKontrol(t) == 0)
        {
            printf("\n\aKitap kimliði zaten var.\a");
            getch();
            anaMenu();
            return 0;
        }
        a.numara=t;
        printf("\nKitap Adý : ");
        scanf("%s",a.kitapismi);
        printf("\nYazar : ");
        scanf("%s",a.yazar);
        
        printf("\nFiyat : ");
        scanf("%f",&a.ucret);
        printf("\nKitaplýk numarasý : ");
        scanf("%d",&a.kitaplikno);
        printf("\nAdet : ");
        scanf("%d",&a.adet);
        return 1;
    }
    int noKontrol(int t)
    {
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        if(a.numara==t)
        return 0;
        return 1;
    }
    int t()
    {
        time_t t;
        time(&t);
        printf("\n\n\t\tAnlýk Tarih ve Zaman:\t%s\n",ctime(&t));
        return 0 ;
    }
    void verdiKaydi()
    {
        system("cls");
        printf("Kitap Sayýn %s tarafýndan ödünç alýnmýþtýr\n\n",a.ogrenciismi);
        printf("Kitabýn ödünç verildiði tarih: %d-%d-%d\n\n",gun(),ay(),yil());
        printf("Kitabýn geri getirilmesi gereken tarih: %d-%d-%d\n\n",a.duedate.dd,a.duedate.mm,a.duedate.yy);
    }
    int gun()
    {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
  
        return tm.tm_mday;
    }
    int yil()
    {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
  
        return tm.tm_year + 1900;
    }
    int ay()
    {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
  
        return tm.tm_mon + 1;
    }
