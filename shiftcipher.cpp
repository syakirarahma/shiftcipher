/*	Nama 		: Syakira Rahma Fauziyah
	NPM	 		: 140810190013
	Kelas		: A 
	Deskripsi 	: Program Enkripsi & Deskripsi Shift Cipher
*/

#include <iostream>
using namespace std;

void enkripsi(string plain, int key){
	int i;
	string cipher = "";

	for (i=0; i<plain.length(); i++){
		if (plain[i] == 32){	// ASCII spasi = 32
			cipher += plain[i];
		}
		// mengenkripsi huruf kapital dimulai dari ASCII 65
		else if (isupper(plain[i])){
			//ASCII S -> (83+3-65)%26 + 65 = 21+65 = 86 ASCII = V
			cipher += char(int((plain[i] + key - 65) % 26) + 65); 
		}
		// mengenkripsi huruf kecil dimulai dari ASCII 97
		else
			cipher += char(int((plain[i] + key - 97) % 26) + 97);
	}
	cout << "Ciphertext : " << cipher << endl;	
}

void deskripsi(string cipher, int key){
	int i;
	string plain = "";
	
	for (i=0; i<cipher.length(); i++){
		if (cipher[i] == 32){
			plain += cipher[i];
		}
		// mendeskripsi huruf kapital dimulai dari ASCII 65
		else if (isupper(cipher[i])){
			if (cipher[i] - key < 65){
				plain += char(int(26 + (cipher[i] - key)));
			}
			else
			plain += char(int((cipher[i] - key - 65) % 26) + 65);
		}
		// mendeskripsi huruf kecil dimulai dari ASCII 97
		else
			if (cipher[i] - key < 97){
				plain += char(int(26 + (cipher[i] - key)));
			}
			else
				plain += char(int((cipher[i] - key - 97) % 26) + 97);
	}
	cout << "Plaintext : " << plain << endl;
}

void enkripsideskripsi(string plain, int key){
	int i;
	string cipher = "";

	for (i=0; i<plain.length(); i++){
		if (plain[i] == 32){
			cipher += plain[i];
		}
		else if (isupper(plain[i])){
			cipher += char(int((plain[i] + key - 65) % 26) + 65); 
		}
		else
			cipher += char(int((plain[i] + key - 97) % 26) + 97);
	}

	cout << "Ciphertext : " << cipher << endl;

	deskripsi(cipher, key);
}

int main(){
	string plain, cipher;
	int key, choose;
	char jawab;
	cout << "Program Shift Cipher" << endl;
	do{
		cout<<"\n==== Menu ====";
		cout<<"\n1. Enkripsi";
		cout<<"\n2. Deskripsi";
		cout<<"\n3. Enkripsi & Deskripsi";
		cout<<"\n4. Exit";
		cout<<"\nPilih Menu : "; cin >> choose; cout << endl;
		switch(choose){
			case 1:
			cout << "Plaintext : "; cin.ignore(); getline(cin, plain);
			cout << "Key: "; cin >> key;
			enkripsi(plain,key);
			break;
			
			case 2:
			cout << "Ciphertext : "; cin.ignore(); getline(cin, cipher);
			cout << "Key: "; cin >> key;
			deskripsi(cipher,key); 
			break;
			
			case 3:
			cout << "Plaintext : "; cin.ignore(); getline(cin, plain);
			cout << "Key: "; cin >> key;
			enkripsideskripsi(plain,key);
			break;
			
			default:
			return 0;
		}
	cout << endl;
    cout << "Ingin memilih menu lain (y/n)? ";
    cin >> jawab;
    cout << endl;
  }
  while (jawab == 'y' || jawab == 'Y');
  cout << "Terimakasih...";
  return 0;

}

