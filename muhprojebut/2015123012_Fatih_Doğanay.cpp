//MUHENDÝSLÝK PROJESÝ BÜTÜNLEME ÖDEVÝ
//2015123012
//FATÝH DOÐANAY
#include <iostream> // cout,cin vs. için 
#include <conio.h> //getch(); fonksiyonu için
#include <fstream> // dosyalama iþlemleri için 
#include <string> // string türü için 
#include <clocale> // Türkçe karakter için
#include <iomanip> //setw() için eklenen kütüphane
#include <stdio.h>
using namespace std;
int main()
{
	string ogrAdi;	string ogrSoyadi;	int ogrNo;	int ogrSinif; string bolum;//ogrencýler ýcýn degýskenler
	string dersAdi; string dersBolum; //ders modulu icin degiskenlerimiz
	int modul;//proje modullerý
	int secim;	int tercih;	int cevap;//switch case yapýlarýndaký secýmler 	
	string hocaAdi;	string hocaSoyadi;	string hocaBolum;int sicilNo;//ogretým elemanlarý ýcýn degýskenler 
	FILE *fp;	
	moduller://ilk acýlan ana sayfamýz/modullerýmýz
	cout<<"***** MODUL SECINIZ *****"<<endl<<endl;
	cout<<"1- OGRENCI MODULU "<<endl;
	cout<<"2- OGRETIM ELEMANI MODULU "<<endl;
	cout<<"3- DERS MODULU "<<endl;
	cout<<"4- NOT MODULU "<<endl;
	cout<<"5- CIKIS "<<endl<<endl;
	cout<<"Modul Seciniz : ";cin>>modul;
	system("cls");
	switch(modul)
	{
		case 1://OGRENCI MODULU 
		{
			ogrenci:
			cout<<"** OGRENCI MODULU **"<<endl<<endl;
			cout<<"1- OGRENCI KAYIT"<<endl;
			cout<<"2- OGRENCI ARAMA"<<endl;
			cout<<"3- OGRENCI LISTELEME"<<endl;
			cout<<"4- OGRENCI BILGILERI DUZENLEME"<<endl;
			cout<<"5- Ana Menuye Don "<<endl;
			cout<<"  Islem seciniz: ";cin>>secim;
			system("cls");
			switch(secim)
			{
				case 1://ogrenci kayýt ekleme 
				{
					ekle:
					cout<<" OGRENCI KAYIT "<<endl;
					ofstream ogrEkle;
					ogrEkle.open("ogrenci.txt",ios::out | ios::in | ios::app);//dosyaya yazma iþlemi için gerkli satýrlar
					cout<<"Ogrenci Numarasi :";cin>>ogrNo;
					cout<<"Ogrenci Adi      :";cin>>ogrAdi;
					cout<<"Ogrenci Soyadi   :";cin>>ogrSoyadi;
					cout<<"Ogrenci Sinifi   :";cin>>ogrSinif;
					cout<<"Ogrenci Bolumu   :";cin>>bolum;
					ogrEkle<<ogrNo<<" "<<ogrAdi<<" "<<ogrSoyadi<<" "<<ogrSinif<<" "<<bolum<<endl<<endl;//dosyaya yazma iþlemi
					cout<<endl;
					ogrEkle.close(); //dosya kapatma
 					cout<<"Yeni ogrenci Kaydi basarili bir sekilde yapilmistir."<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";
 					getch();
 					system("cls");
					goto ogrenci;
					break;
				}
				case 2://ogrenci ARAMA
				{
					cout<<"OGRENCI ARAMA"<<endl;
					cout<<"1- Ogrenci Adina Gore Arama"<<endl;
					cout<<"2- Ogrenci No'ya Gore Arama"<<endl;
					cout<<"3- Bir ust menuye gidin "<<endl;
					cout<<" Secim yapiniz:";cin>>secim;
					system("cls");
					switch(secim)
					{
						case 1://ogrenci adýna gore arama
						{
							cout<<"OGRENCI ADINA GORE ARAMA "<<endl<<endl;
							string arananAd;
							ifstream ogrAraAd;//dosyadan okuma iþlemi ve dosyayý acma 
							ogrAraAd.open("ogrenci.txt",ios::in);
							cout<<"Ogrenci Adi Giriniz:"; cin>>arananAd;
							cout<<endl;
							do 
					        { 	ogrAraAd>>ogrNo>>ogrAdi>>ogrSoyadi>>ogrSinif>>bolum; //dosya icidenki degiskenlerin okunmasý
					            if (arananAd == ogrAdi) //eger consola gýrýlen deger ile dosya içindeki degerler ayný ise ogrenci bilgileri yazdýrýlýr
								{ 
								cout<<"** OGRENCI BILGILERI **"<<endl;
								cout<<"Ogrenci No    :"<<ogrNo<<endl;
								cout<<"Ogrenci Adi   :"<<ogrAdi<<endl;
								cout<<"Ogrenci Soyadi:"<<ogrSoyadi<<endl;
								cout<<"Ogrenci Sinif :"<<ogrSinif<<endl;
								cout<<"Ogrenci Bolumu:"<<bolum<<endl<<endl;  
								} 
					        } while (!ogrAraAd.eof()); 
					        ogrAraAd.close();
							cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
							getch();
							system("cls");
							goto ogrenci;
							break;
						}
						case 2://ogrenci no ya gore arama 
						{
							cout<<"OGRENCI NO'YA GORE ARAMA "<<endl;
							ifstream ogrAraNo;//dosya okuma ve dosyayý acma 
							ogrAraNo.open("ogrenci.txt",ios::in);
							int arananNo;
							cout<<"Ogrenci No Giriniz:";
							cin>>arananNo;
							cout<<endl;
							do 
					        { 	
								ogrAraNo>>ogrNo>>ogrAdi>>ogrSoyadi>>ogrSinif>>bolum; //dosya ýcýndeki degiskenlerin okunmasý
					            if (arananNo == ogrNo) //consalo girilen deger dosya ýcýersinde mevcut ise bilgiler yazdýrýlýr
								{ 
								cout<<"** OGRENCI BILGILERI **"<<endl;
								cout<<"Ogrenci No    :"<<ogrNo<<endl;
								cout<<"Ogrenci Adi   :"<<ogrAdi<<endl;
								cout<<"Ogrenci Soyadi:"<<ogrSoyadi<<endl;
								cout<<"Ogrenci Sinif :"<<ogrSinif<<endl;
								cout<<"Ogrenci Bolumu:"<<bolum<<endl;  
								} 
					        } while (!ogrAraNo.eof()); //eof=end of FÝLE (dosya sonuna varýlýncaya kadar)
					        ogrAraNo.close(); //dosya kapatma
							cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
							getch();
							system("cls");
							goto ogrenci;
							break;
						}
						case 3:
						{
							goto ogrenci;//ust menuye donme 
						}	
						default:// farklý býr rakam gýrýlýnce verýlen uyarý 
						cout<<"Lutfen 1 le 3 arasinda bir rakam giriniz:";
						break;
					}
					
				}
				case 3://OGRENCÝ LÝSTELEME
				{
					liste:
					cout<<"OGRENCI LISTELEME"<<endl;
					cout<<"1- Ogrenci Sinifina Gore Listeleme"<<endl;
					cout<<"2- Ogrenci Bolumune Gore Listeleme"<<endl;
					cout<<"3- Bir ust menuye gidin "<<endl;
					cout<<" Secim yapiniz:";cin>>secim;
					system("cls");
					switch(secim)
					{
						case 1://SINIFA GORE LISTELEME 
						{
							cout<<"OGRENCI SINIFINA GORE LISTELEME "<<endl;
							ifstream listeleSinif;
							listeleSinif.open("ogrenci.txt",ios::in); //dosya okuma ve dosyayý acma
    						int girilensinif; 
    						cout << "Aranilacak Sinif :" ; 
    						cin >> girilensinif;
					        do 
					        { 
					            listeleSinif >> ogrNo >> ogrAdi >> ogrSoyadi >> ogrSinif >> bolum; //degýskenlerýn okunmasý
					            if (ogrSinif == girilensinif) 
								{ //gýrýlen deger eger dosya ýcerýsýnde mevcur ýse tum degerler yazdýrýlýr
								cout<<"** OGRENCI BILGILERI **"<<endl;
								cout<<"Ogrenci No    :"<<ogrNo<<endl;
								cout<<"Ogrenci Adi   :"<<ogrAdi<<endl;
								cout<<"Ogrenci Soyadi:"<<ogrSoyadi<<endl;
								cout<<"Ogrenci Sinif :"<<ogrSinif<<endl;
								cout<<"Ogrenci Bolumu:"<<bolum<<endl<<endl;  
								} 
					        } while (!listeleSinif.eof()); //dosya býtene dek okur
					        listeleSinif.close(); //dosya kapama
							cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
							getch();
 							system("cls");
							goto liste;
							break;
						}
						case 2://OGRENCI BOLUME GORE LISTELEME 
						{
							cout<<"OGRENCI BOLUMUNE GORE LISTELEME "<<endl;
							ifstream listeleBolum;
							listeleBolum.open("ogrenci.txt",ios::in); 
    						string girilenBolum; 
    						cout << "Aranilacak Bolum :"; 
    						cin >> girilenBolum;
					        do 
					        { 
					            listeleBolum>>ogrNo>>ogrAdi>>ogrSoyadi>>ogrSinif>>bolum; 
					            if (bolum == girilenBolum) 
								{ //girilen bolum ýle dosya ýcerýsýndeký bolumlerden ayný olanlarý yazdýrýr
								cout<<"** OGRENCI BILGILERI **"<<endl;
								cout<<"Ogrenci No    :"<<ogrNo<<endl;
								cout<<"Ogrenci Adi   :"<<ogrAdi<<endl;
								cout<<"Ogrenci Soyadi:"<<ogrSoyadi<<endl;
								cout<<"Ogrenci Sinif :"<<ogrSinif<<endl;
								cout<<"Ogrenci Bolumu:"<<bolum<<endl<<endl;  
								} 
					        } while (!listeleBolum.eof()); 
					        listeleBolum.close(); 
							cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
							getch();
 							system("cls");
							goto liste;
							break;
						}
						case 3:
						{
							goto ogrenci;
						}
						default:
						cout<<"Lutfen 1 le 3 arasinda bir rakam giriniz:";
						break;	
					}	
				}
				case 4://ogrenci bilgilerini DUZENLEME - GUNCELLEME
				{
					ifstream dosya;//okuma yapmak ýcýn 
					ofstream yeni;//yazma yapmak ýcýn 
					int duzenleOgrenci;
					cout<<"Duzenleme yapilacak ogrenci no :"; 	cin>>duzenleOgrenci;
					dosya.open("ogrenci.txt",ios::in);//okunacak dosya acýlýyor
					yeni.open("gecici_ogrenci.txt",ios::app);//yazýlacak dosya acýlýyor
					while(!dosya.eof())//dosya sonun kadar okuma
					{
						dosya>>ogrNo>>ogrAdi>>ogrSoyadi>>ogrSinif>>bolum; 
						//dosya ýcerýsýndeký degerler tek tek okunur
					   if(ogrNo == duzenleOgrenci)
					   {//gýrýlen no ýle ogrNo ayný ýse degýsýklýge ýzýn verýlýr
					   	  	cout<<"Bilgilerinizi Duzenleyin"<<endl;//yeni bilgileri al.
						  	cout<<"Ogrenci No   : "; cin>>ogrNo;
					      	cout<<"Ogrenci Adi  : "; cin>>ogrAdi;
						  	cout<<"Ogrenci Soyad: "; cin>>ogrSoyadi;
						  	cout<<"Ogrenci Sinif: "; cin>>ogrSinif;
						  	cout<<"Ogrencinin Bolumu: ";cin>>bolum;
					   }
						yeni<<ogrNo<<" "<<ogrAdi<<" "<<ogrSoyadi<<" "<<ogrSinif<<" "<<bolum<<endl;
						//yený adlý dosya etýketýne yený býlgýler yazýlýr
					}
					dosya.close();//kapatýlýr
					yeni.close();//kapatýlýr
					remove("ogrenci.txt");//bu ýsýmlý dosya sýlýnýr.
					rename("gecici_ogrenci.txt","ogrenci.txt");//gecýcý adlý dosyanýn adý ogrencý olarak degýstýrýlýp kayýt edýlýr
					cout<<"Ogrenci bilgileri basarili bir sekilde guncellenmistir."<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";				 
					getch();
					system("cls");
					goto ogrenci;
					break;
				}
				case 5://ana manuye donme
				{
					goto moduller;	
				}
				default:
					cout<<"Lutfen 1 le 5 arasinda bir rakam giriniz"<<endl;
					break;			
			}
		}
		case 2://OGRETIM ELEMANI MODULU 
		{
			hocalar:
			cout<<"** OGRETIM ELEMANI MODULU **"<<endl<<endl;
			cout<<"1- OGRETIM ELEMANI KAYIT"<<endl;
			cout<<"2- OGRETIM ELEMANI ARAMA"<<endl;
			cout<<"3- OGRETIM ELEMANLARINI LÝSTELEME"<<endl;
			cout<<"4- OGRETIM ELEMANI BILGILERINI DÜZENLEME"<<endl;
			cout<<"5- Ana Menuye Don "<<endl;
			cout<<"  Islem seciniz: ";cin>>secim;
			system("cls");
			switch(secim)
			{
				case 1://ogretým elemaný kayýt etme
				{
					cout<<" OGRETIM ELEMANI KAYIT "<<endl;
					ofstream hocaEkle; //yazmak ýcýn nesne olusturulur
					hocaEkle.open("ogrelemani.txt",ios::app);
					cout<<"Ogretim Elemani Sicil No :";cin>>sicilNo;
					cout<<"Ogretim Elemani Adi      :";cin>>hocaAdi;
					cout<<"Ogretim Elemani Soyadi   :";cin>>hocaSoyadi;
					cout<<"Ogretim Elemani Bolumu   :";cin>>hocaBolum;
					hocaEkle<<sicilNo<<" "<<hocaAdi<<" "<<hocaSoyadi<<" "<<hocaBolum<<" "<<endl<<endl;
					hocaEkle.close(); 
					cout<<"Yeni ogretim elemani kaydi basarili bir sekilde yapilmistir."<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";
					getch();
					system("cls");
					goto hocalar;	
					break;
				}
				case 2://ogretým elemanýný sicil No ýle arama
				{
					cout<<"OGRETIM ELEMANI  ARAMA "<<endl;
					ifstream hocaAra;//dosya okuma ve dosyayý acma 
					hocaAra.open("ogrelemani.txt",ios::in);
					int arananSicil;
					cout<<"Ogretim Elemani Sicil No Giriniz:";
					cin>>arananSicil;
					cout<<endl;
					do 
			        { 	
						hocaAra>>sicilNo>>hocaAdi>>hocaSoyadi>>hocaBolum; //dosya ýcýndeki degiskenlerin okunmasý
			            if (arananSicil == sicilNo) //consalo girilen deger dosya ýcýersinde mevcut ise bilgiler yazdýrýlýr
						{ 
						cout<<"** OGRETIM ELEMANI BILGILERI **"<<endl;
						cout<<"Ogretim Elemani Sicil No:"<<sicilNo<<endl;
						cout<<"Ogretim Elemani   Adi   :"<<hocaAdi<<endl;
						cout<<"Ogretim Elemani Soyadi  :"<<hocaSoyadi<<endl;
						cout<<"Ogretim Elemani Bolumu  :"<<hocaBolum<<endl;  
						} 
			        } while (!hocaAra.eof()); //eof=end of FÝLE (dosya sonuna varýlýncaya kadar)
			        hocaAra.close(); //dosya kapatma
					cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
					getch();
					system("cls");
					goto hocalar;
					break;
					
				}
				case 3://ogretým elemanlarýný lýsteleme
				{
					cout<<"OGRETIM ELEMANI LISTELEME "<<endl<<endl;
					ifstream hocaListele;
					hocaListele.open("ogrelemani.txt",ios::in); 
					string girilenBolum; 
					cout << "Listelenecek bolumu giriniz : "; 
					cin >> girilenBolum;
			        do 
			        { 
			            hocaListele>>sicilNo>>hocaAdi>>hocaSoyadi>>hocaBolum; 
			            if (girilenBolum==hocaBolum) 
						{ 
							cout<<"Ogretim Elemani Sicil No :"<<sicilNo<<endl;
							cout<<"Ogretim Elemani Adi      :"<<hocaAdi<<endl;
							cout<<"Ogretim Elemani Soyadi   :"<<hocaSoyadi<<endl;
							cout<<"Ogretim Elemani Bolumu   :"<<hocaBolum<<endl<<endl; 
						} 
			        } while (!hocaListele.eof()); 
			        hocaListele.close(); 
					cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
					getch();
					system("cls");
					goto hocalar;
					break;
					
				}
				case 4://ogretým elemaný bilgilerini duzenleme
				{
					ifstream dosya;//okuma yapmak ýcýn 
					ofstream yeni;//yazma yapmak ýcýn 
					int duzenleHoca;
					cout<<"Duzenleme yapilacak Ogretim Elamani Sicil No :"; 	
					cin>>duzenleHoca;
					dosya.open("ogrelemani.txt",ios::in);//okunacak dosya acýlýyor
					yeni.open("gecici_ogrelemani.txt",ios::app);//yazýlacak dosya acýlýyor
					while(!dosya.eof())//dosya sonun kadar okuma
					{
						dosya>>sicilNo>>hocaAdi>>hocaSoyadi>>hocaBolum; 
						//dosya ýcerýsýndeký degerler tek tek okunur
					   if(sicilNo == duzenleHoca)
					   {//gýrýlen no ýle ogrNo ayný ýse degýsýklýge ýzýn verýlýr
					   	  	cout<<"Bilgilerinizi Duzenleyin"<<endl;//yeni bilgileri al.
						  	cout<<"Ogretim Elamani Sicil No   : "; cin>>sicilNo;
					      	cout<<"Ogretim Elamani Adi  : "; cin>>hocaAdi;
						  	cout<<"Ogretim Elamani Soyad: "; cin>>hocaSoyadi;
						  	cout<<"Ogretim Elamani Bolumu: ";cin>>hocaBolum;
					   }
						yeni<<sicilNo<<" "<<hocaAdi<<" "<<hocaSoyadi<<" "<<hocaBolum<<endl;
						//yený adlý dosya etýketýne yený býlgýler yazýlýr
					}
					dosya.close();//kapatýlýr
					yeni.close();//kapatýlýr
					remove("ogrelemani.txt");//bu ýsýmlý dosya sýlýnýr.
					rename("gecici_ogrelemani.txt","ogrelemani.txt");//gecýcý adlý dosyanýn adý ogrencý olarak degýstýrýlýp kayýt edýlýr
					cout<<"Ogretim elamani bilgileri basarili bir sekilde guncellenmistir."<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";				 
					getch();
					system("cls");
					goto hocalar;
					break;			 		
				}
				case 5://ana menuye donus
				{
					goto moduller;
				}
				default:
					cout<<"Lutfen 1 le 5 arasinda bir rakam giriniz "<<endl;
					goto hocalar;
					break;	
			}
			
		}
		case 3://DERS MODULU 
		{
			dersler:
				dersler1:
			cout<<"*** DERS MODULU ***"<<endl<<endl;
			cout<<"1- DERS KAYIT"<<endl;
			cout<<"2- DERS ARAMA"<<endl;
			cout<<"3- DERS LISTELEME"<<endl;
			cout<<"4- DERS BILGILERI DUZENLEME"<<endl;
			cout<<"5- Ana Menuye Don "<<endl;
			cout<<"  Islem seciniz: ";cin>>secim;
			system("cls");
			switch(secim)
			{
				case 1://ders ekleme
				{
					cout<<" DERS KAYIT "<<endl;
					ofstream dersEkle; 
					dersEkle.open("ders.txt",ios::app);
					cout<<"Dersin Adi      :";cin>>dersAdi;
					cout<<"Dersin Bolumu   :";cin>>dersBolum;
					dersEkle<<dersAdi<<" "<<dersBolum<<" "<<endl;
					dersEkle.close(); 
					cout<<"Yeni ders kaydi basarili bir sekilde yapilmistir."<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";
					getch();
					system("cls");
					goto dersler1;	
					break;
				}
				case 2://ders arama
				{
					cout<<"DERS ARAMA "<<endl;
					ifstream dersAra;//dosya okuma ve dosyayý acma 
					dersAra.open("ders.txt",ios::in);
					string arananDers;
					cout<<"Ders Adi Giriniz:";
					cin>>arananDers;
					cout<<endl;
					do 
			        { 	
						dersAra>>dersAdi>>dersBolum; //dosya ýcýndeki degiskenlerin okunmasý
			            if (arananDers == dersAdi) //consalo girilen deger dosya ýcýersinde mevcut ise bilgiler yazdýrýlýr
						{ 
						cout<<"**DERS BILGILERI **"<<endl;
						cout<<"Ders Adi   :"<<dersAdi<<endl;
						cout<<"Ders Bolumu:"<<dersBolum<<endl;
						} 
			        } while (!dersAra.eof()); //eof=end of FÝLE (dosya sonuna varýlýncaya kadar)
			        dersAra.close(); //dosya kapatma
					cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
					getch();
					system("cls");
					goto dersler;
					break;
				}
				case 3://ders listeleme
				{
					ifstream dersListele;
					dersListele.open("ders.txt",ios::in); 
					string girilenders; 
					cout<<"Listelenecek dersi giriniz : " ; 
					cin>>girilenders;
			        do 
			        { 
			            dersListele>>dersAdi>>dersBolum; 
			            if (girilenders==dersAdi) 
						{ 
							cout<<"** DERS BILGILERI **"<<endl<<endl;
							cout<<"Dersin Adi      :"<<dersAdi<<endl;
							cout<<"Dersin Bolumu   :"<<dersBolum<<endl; 
						} 
			        } while (!dersListele.eof()); 
			        dersListele.close(); 
					cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
					getch();
					system("cls");
					goto dersler;
					break;
				}
				case 4://ders bilgileri duzenleme
				{
					ifstream dosya;
					ofstream yeni;
					string duzenleDers;
					cout<<"Duzenlenecek dersin adi :"; cin>>duzenleDers;
					dosya.open("ders.txt",ios::in);
					yeni.open("gecici_ders.txt",ios::app);
					while(!dosya.eof())
					{
					   dosya >> dersAdi >> dersBolum ;
					   if(dersAdi == duzenleDers)
					   {
					   	  	cout<<"** Yeni Bilgiler **"<<endl;//yeni bilgileri al.
					      	cout<<"Ders Adi   : "; cin>>dersAdi;
						  	cout<<"Ders Bolumu: "; cin>>dersBolum;
					   }
						yeni<<dersAdi<<" "<<dersBolum<<" "<<endl;
					}
					dosya.close();
					yeni.close();
					remove("ders.txt");
					rename("gecici_ders.txt","ders.txt");
					cout<<"Ders bilgileri basarili bir sekilde guncellenmistir."<<endl<<"Ust menuye donmek icin lutfen 1 e basiniz...";				 
					getch();
					system("cls");
					goto dersler;
					break;
				}
				case 5:
				{
					goto moduller;
					break;
				}
				default:
				cout<<"Lutfen 1 le 5 arasinda rakam giriniz "<<endl;
				goto dersler;
				break;			
			}
		}
		case 4://NOT GÝRÝÞÝ MODULU 
		{
			cout<<"***************************************************************"<<endl;
			cout<<"**                                                           **"<<endl;
			cout<<"**           BU MODULUMUZ HIZMETE GIRMEMISTIR...             **"<<endl;
			cout<<"**                                                           **"<<endl;
			cout<<"**                       UZGUNUZ                             **"<<endl;
			cout<<"**                                                           **"<<endl;
			cout<<"**          Ana menuye donmek icin 1 e basiniz               **"<<endl;
			cout<<"**                                                           **"<<endl;
			cout<<"***************************************************************"<<endl;
				getch();
				system("cls");
				goto moduller;
				break;
		}
		case 5://cikiþ için
		{
			return 0;
			break;
		}
		default:
			cout<<"Lutfen 1 le 5 arasinda rakam giriniz "<<endl;
			goto moduller;
			break;	
	}
	

	
}


