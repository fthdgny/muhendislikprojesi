//MUHEND�SL�K PROJES� B�T�NLEME �DEV�
//2015123012
//FAT�H DO�ANAY
#include <iostream> // cout,cin vs. i�in 
#include <conio.h> //getch(); fonksiyonu i�in
#include <fstream> // dosyalama i�lemleri i�in 
#include <string> // string t�r� i�in 
#include <clocale> // T�rk�e karakter i�in
#include <iomanip> //setw() i�in eklenen k�t�phane
#include <stdio.h>
using namespace std;
int main()
{
	string ogrAdi;	string ogrSoyadi;	int ogrNo;	int ogrSinif; string bolum;//ogrenc�ler �c�n deg�skenler
	string dersAdi; string dersBolum; //ders modulu icin degiskenlerimiz
	int modul;//proje moduller�
	int secim;	int tercih;	int cevap;//switch case yap�lar�ndak� sec�mler 	
	string hocaAdi;	string hocaSoyadi;	string hocaBolum;int sicilNo;//ogret�m elemanlar� �c�n deg�skenler 
	FILE *fp;	
	moduller://ilk ac�lan ana sayfam�z/moduller�m�z
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
				case 1://ogrenci kay�t ekleme 
				{
					ekle:
					cout<<" OGRENCI KAYIT "<<endl;
					ofstream ogrEkle;
					ogrEkle.open("ogrenci.txt",ios::out | ios::in | ios::app);//dosyaya yazma i�lemi i�in gerkli sat�rlar
					cout<<"Ogrenci Numarasi :";cin>>ogrNo;
					cout<<"Ogrenci Adi      :";cin>>ogrAdi;
					cout<<"Ogrenci Soyadi   :";cin>>ogrSoyadi;
					cout<<"Ogrenci Sinifi   :";cin>>ogrSinif;
					cout<<"Ogrenci Bolumu   :";cin>>bolum;
					ogrEkle<<ogrNo<<" "<<ogrAdi<<" "<<ogrSoyadi<<" "<<ogrSinif<<" "<<bolum<<endl<<endl;//dosyaya yazma i�lemi
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
						case 1://ogrenci ad�na gore arama
						{
							cout<<"OGRENCI ADINA GORE ARAMA "<<endl<<endl;
							string arananAd;
							ifstream ogrAraAd;//dosyadan okuma i�lemi ve dosyay� acma 
							ogrAraAd.open("ogrenci.txt",ios::in);
							cout<<"Ogrenci Adi Giriniz:"; cin>>arananAd;
							cout<<endl;
							do 
					        { 	ogrAraAd>>ogrNo>>ogrAdi>>ogrSoyadi>>ogrSinif>>bolum; //dosya icidenki degiskenlerin okunmas�
					            if (arananAd == ogrAdi) //eger consola g�r�len deger ile dosya i�indeki degerler ayn� ise ogrenci bilgileri yazd�r�l�r
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
							ifstream ogrAraNo;//dosya okuma ve dosyay� acma 
							ogrAraNo.open("ogrenci.txt",ios::in);
							int arananNo;
							cout<<"Ogrenci No Giriniz:";
							cin>>arananNo;
							cout<<endl;
							do 
					        { 	
								ogrAraNo>>ogrNo>>ogrAdi>>ogrSoyadi>>ogrSinif>>bolum; //dosya �c�ndeki degiskenlerin okunmas�
					            if (arananNo == ogrNo) //consalo girilen deger dosya �c�ersinde mevcut ise bilgiler yazd�r�l�r
								{ 
								cout<<"** OGRENCI BILGILERI **"<<endl;
								cout<<"Ogrenci No    :"<<ogrNo<<endl;
								cout<<"Ogrenci Adi   :"<<ogrAdi<<endl;
								cout<<"Ogrenci Soyadi:"<<ogrSoyadi<<endl;
								cout<<"Ogrenci Sinif :"<<ogrSinif<<endl;
								cout<<"Ogrenci Bolumu:"<<bolum<<endl;  
								} 
					        } while (!ogrAraNo.eof()); //eof=end of F�LE (dosya sonuna var�l�ncaya kadar)
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
						default:// farkl� b�r rakam g�r�l�nce ver�len uyar� 
						cout<<"Lutfen 1 le 3 arasinda bir rakam giriniz:";
						break;
					}
					
				}
				case 3://OGRENC� L�STELEME
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
							listeleSinif.open("ogrenci.txt",ios::in); //dosya okuma ve dosyay� acma
    						int girilensinif; 
    						cout << "Aranilacak Sinif :" ; 
    						cin >> girilensinif;
					        do 
					        { 
					            listeleSinif >> ogrNo >> ogrAdi >> ogrSoyadi >> ogrSinif >> bolum; //deg�skenler�n okunmas�
					            if (ogrSinif == girilensinif) 
								{ //g�r�len deger eger dosya �cer�s�nde mevcur �se tum degerler yazd�r�l�r
								cout<<"** OGRENCI BILGILERI **"<<endl;
								cout<<"Ogrenci No    :"<<ogrNo<<endl;
								cout<<"Ogrenci Adi   :"<<ogrAdi<<endl;
								cout<<"Ogrenci Soyadi:"<<ogrSoyadi<<endl;
								cout<<"Ogrenci Sinif :"<<ogrSinif<<endl;
								cout<<"Ogrenci Bolumu:"<<bolum<<endl<<endl;  
								} 
					        } while (!listeleSinif.eof()); //dosya b�tene dek okur
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
								{ //girilen bolum �le dosya �cer�s�ndek� bolumlerden ayn� olanlar� yazd�r�r
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
					ifstream dosya;//okuma yapmak �c�n 
					ofstream yeni;//yazma yapmak �c�n 
					int duzenleOgrenci;
					cout<<"Duzenleme yapilacak ogrenci no :"; 	cin>>duzenleOgrenci;
					dosya.open("ogrenci.txt",ios::in);//okunacak dosya ac�l�yor
					yeni.open("gecici_ogrenci.txt",ios::app);//yaz�lacak dosya ac�l�yor
					while(!dosya.eof())//dosya sonun kadar okuma
					{
						dosya>>ogrNo>>ogrAdi>>ogrSoyadi>>ogrSinif>>bolum; 
						//dosya �cer�s�ndek� degerler tek tek okunur
					   if(ogrNo == duzenleOgrenci)
					   {//g�r�len no �le ogrNo ayn� �se deg�s�kl�ge �z�n ver�l�r
					   	  	cout<<"Bilgilerinizi Duzenleyin"<<endl;//yeni bilgileri al.
						  	cout<<"Ogrenci No   : "; cin>>ogrNo;
					      	cout<<"Ogrenci Adi  : "; cin>>ogrAdi;
						  	cout<<"Ogrenci Soyad: "; cin>>ogrSoyadi;
						  	cout<<"Ogrenci Sinif: "; cin>>ogrSinif;
						  	cout<<"Ogrencinin Bolumu: ";cin>>bolum;
					   }
						yeni<<ogrNo<<" "<<ogrAdi<<" "<<ogrSoyadi<<" "<<ogrSinif<<" "<<bolum<<endl;
						//yen� adl� dosya et�ket�ne yen� b�lg�ler yaz�l�r
					}
					dosya.close();//kapat�l�r
					yeni.close();//kapat�l�r
					remove("ogrenci.txt");//bu �s�ml� dosya s�l�n�r.
					rename("gecici_ogrenci.txt","ogrenci.txt");//gec�c� adl� dosyan�n ad� ogrenc� olarak deg�st�r�l�p kay�t ed�l�r
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
			cout<<"3- OGRETIM ELEMANLARINI L�STELEME"<<endl;
			cout<<"4- OGRETIM ELEMANI BILGILERINI D�ZENLEME"<<endl;
			cout<<"5- Ana Menuye Don "<<endl;
			cout<<"  Islem seciniz: ";cin>>secim;
			system("cls");
			switch(secim)
			{
				case 1://ogret�m eleman� kay�t etme
				{
					cout<<" OGRETIM ELEMANI KAYIT "<<endl;
					ofstream hocaEkle; //yazmak �c�n nesne olusturulur
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
				case 2://ogret�m eleman�n� sicil No �le arama
				{
					cout<<"OGRETIM ELEMANI  ARAMA "<<endl;
					ifstream hocaAra;//dosya okuma ve dosyay� acma 
					hocaAra.open("ogrelemani.txt",ios::in);
					int arananSicil;
					cout<<"Ogretim Elemani Sicil No Giriniz:";
					cin>>arananSicil;
					cout<<endl;
					do 
			        { 	
						hocaAra>>sicilNo>>hocaAdi>>hocaSoyadi>>hocaBolum; //dosya �c�ndeki degiskenlerin okunmas�
			            if (arananSicil == sicilNo) //consalo girilen deger dosya �c�ersinde mevcut ise bilgiler yazd�r�l�r
						{ 
						cout<<"** OGRETIM ELEMANI BILGILERI **"<<endl;
						cout<<"Ogretim Elemani Sicil No:"<<sicilNo<<endl;
						cout<<"Ogretim Elemani   Adi   :"<<hocaAdi<<endl;
						cout<<"Ogretim Elemani Soyadi  :"<<hocaSoyadi<<endl;
						cout<<"Ogretim Elemani Bolumu  :"<<hocaBolum<<endl;  
						} 
			        } while (!hocaAra.eof()); //eof=end of F�LE (dosya sonuna var�l�ncaya kadar)
			        hocaAra.close(); //dosya kapatma
					cout<<"Ust menuye donmek icin lutfen 1 e basiniz...";
					getch();
					system("cls");
					goto hocalar;
					break;
					
				}
				case 3://ogret�m elemanlar�n� l�steleme
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
				case 4://ogret�m eleman� bilgilerini duzenleme
				{
					ifstream dosya;//okuma yapmak �c�n 
					ofstream yeni;//yazma yapmak �c�n 
					int duzenleHoca;
					cout<<"Duzenleme yapilacak Ogretim Elamani Sicil No :"; 	
					cin>>duzenleHoca;
					dosya.open("ogrelemani.txt",ios::in);//okunacak dosya ac�l�yor
					yeni.open("gecici_ogrelemani.txt",ios::app);//yaz�lacak dosya ac�l�yor
					while(!dosya.eof())//dosya sonun kadar okuma
					{
						dosya>>sicilNo>>hocaAdi>>hocaSoyadi>>hocaBolum; 
						//dosya �cer�s�ndek� degerler tek tek okunur
					   if(sicilNo == duzenleHoca)
					   {//g�r�len no �le ogrNo ayn� �se deg�s�kl�ge �z�n ver�l�r
					   	  	cout<<"Bilgilerinizi Duzenleyin"<<endl;//yeni bilgileri al.
						  	cout<<"Ogretim Elamani Sicil No   : "; cin>>sicilNo;
					      	cout<<"Ogretim Elamani Adi  : "; cin>>hocaAdi;
						  	cout<<"Ogretim Elamani Soyad: "; cin>>hocaSoyadi;
						  	cout<<"Ogretim Elamani Bolumu: ";cin>>hocaBolum;
					   }
						yeni<<sicilNo<<" "<<hocaAdi<<" "<<hocaSoyadi<<" "<<hocaBolum<<endl;
						//yen� adl� dosya et�ket�ne yen� b�lg�ler yaz�l�r
					}
					dosya.close();//kapat�l�r
					yeni.close();//kapat�l�r
					remove("ogrelemani.txt");//bu �s�ml� dosya s�l�n�r.
					rename("gecici_ogrelemani.txt","ogrelemani.txt");//gec�c� adl� dosyan�n ad� ogrenc� olarak deg�st�r�l�p kay�t ed�l�r
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
					ifstream dersAra;//dosya okuma ve dosyay� acma 
					dersAra.open("ders.txt",ios::in);
					string arananDers;
					cout<<"Ders Adi Giriniz:";
					cin>>arananDers;
					cout<<endl;
					do 
			        { 	
						dersAra>>dersAdi>>dersBolum; //dosya �c�ndeki degiskenlerin okunmas�
			            if (arananDers == dersAdi) //consalo girilen deger dosya �c�ersinde mevcut ise bilgiler yazd�r�l�r
						{ 
						cout<<"**DERS BILGILERI **"<<endl;
						cout<<"Ders Adi   :"<<dersAdi<<endl;
						cout<<"Ders Bolumu:"<<dersBolum<<endl;
						} 
			        } while (!dersAra.eof()); //eof=end of F�LE (dosya sonuna var�l�ncaya kadar)
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
		case 4://NOT G�R��� MODULU 
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
		case 5://ciki� i�in
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


